#!/usr/bin/env bash
# The refactor gate: rebuild, check every version, refresh the reports, fail if the match drops.
#
#   bash tools/check_all.sh
#
# Order matters: version_sync runs in the container first, version_report on the host last. The
# container's Python sums floats differently from CI's, so the host must write the reports CI checks.
set -euo pipefail
cd "$(dirname "$0")/.."

run() { bash tools/docker/run.sh "$@"; }

run bash tools/build_sn.sh | tail -6
rm -rf build-sn/overlays/report
run python3 tools/gen_progress_report.py --no-build | tail -1
run python3 tools/version_sync.py run | tail -3
for version in us pal_v1 jp; do
    python3 tools/version_report.py --version "$version" | tail -1
done
python3 tools/gen_progress_report.py --check
python3 tools/move_src.py --check
python3 tools/check_docs.py
python3 tools/check_no_retail.py
python3 tools/check_syntax.py
python3 tools/ratchets.py --check

python3 - <<'EOF'
import json, subprocess, sys
from pathlib import Path

bad = 0
for path in sorted(Path("progress").rglob("report.json")):
    old = subprocess.run(["git", "show", f"HEAD:{path}"], capture_output=True, text=True)
    if old.returncode:
        continue
    was = json.loads(old.stdout)["measures"]["fuzzy_match_percent"]
    now = json.loads(path.read_text())["measures"]["fuzzy_match_percent"]
    print(f"{path}: {was} -> {now}")
    bad += now < was
sys.exit(f"*** match dropped in {bad} report(s)" if bad else 0)
EOF
