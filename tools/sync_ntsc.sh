#!/usr/bin/env bash
# Follow the NTSC decomp: bump the submodule versions/ntsc to its latest upstream commit, rebuild
# and verify it with its own tools, refresh the PAL <-> NTSC-U carry list, and commit the bump.
#
#   tools/sync_ntsc.sh            # latest origin/main of the NTSC decomp
#   tools/sync_ntsc.sh <commit>   # a given commit
#   NTSC_SKIP_BUILD=1 tools/sync_ntsc.sh   # no rebuild (a host without its toolchain)
#
# The NTSC decomp is Lombyte's project (https://github.com/mateuszklysz/Lombyte), the NTSC-U
# version of this repository (docs/VERSIONS.md). It is only ever read from here: nothing is
# committed into the submodule and nothing is pushed to it. Matches that should go there (the
# "to the NTSC decomp" rows of config/versions/us/carry.tsv) go to it as pull requests on its repo.
#
# Steps:
#   1. git fetch in versions/ntsc and check out the commit;
#   2. tools/build_ntsc.sh: its setup.sh, `make elf` and `make overlays`, each ending in PASS
#      (needs Linux, its toolchain, and baserom/us/SCUS_971.99 or the disc image; see the script);
#   3. python3 tools/version_sync.py ntsc: config/versions/us/carry.tsv from the submodule's own
#      report and our C checked against the NTSC-U bytes (config/versions/us/map.tsv);
#   4. git commit of versions/ntsc and config/versions/us/carry.tsv (only those paths).
set -euo pipefail
cd "$(dirname "$0")/.."
sub=versions/ntsc
git submodule update --init "$sub"
old=$(git -C "$sub" rev-parse HEAD)
GIT_TERMINAL_PROMPT=0 git -C "$sub" fetch --quiet origin
want=${1:-$(git -C "$sub" rev-parse origin/HEAD 2>/dev/null || git -C "$sub" rev-parse origin/main)}
git -C "$sub" checkout --quiet "$want"
new=$(git -C "$sub" rev-parse HEAD)
echo "the NTSC decomp: ${old:0:10} -> ${new:0:10}"
if [ "${NTSC_SKIP_BUILD:-}" != 1 ]; then
  bash tools/build_ntsc.sh
fi
python3 tools/version_sync.py ntsc
if [ "$old" = "$new" ] && git diff --quiet -- config/versions/us/carry.tsv; then
  echo "nothing to commit"
  exit 0
fi
git add -- "$sub" config/versions/us/carry.tsv
git commit -m "chore(ntsc): follow the NTSC decomp to ${new:0:10}" -- "$sub" config/versions/us/carry.tsv
