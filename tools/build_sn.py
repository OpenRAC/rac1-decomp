#!/usr/bin/env python3
"""Run the canonical PAL build from Python or build_sn.bat."""
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def build_environment() -> tuple[str, dict[str, str]]:
    env = os.environ.copy()
    path = [str(Path(sys.executable).parent), *env.get("PATH", "").split(os.pathsep)]
    search = path
    if os.name == "nt":
        git_dirs = [
            Path(os.environ.get("ProgramFiles", r"C:\Program Files")) / "Git" / "bin",
            Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)")) / "Git" / "bin",
        ]
        if git := shutil.which("git", path=os.pathsep.join(path)):
            git_dirs.insert(0, Path(git).parent.parent / "bin")
        wsl_launcher_dirs = [Path(os.environ.get("SystemRoot", r"C:\Windows"))]
        if app_data := os.environ.get("LOCALAPPDATA"):
            wsl_launcher_dirs.append(Path(app_data) / "Microsoft" / "WindowsApps")
        search = [str(d) for d in git_dirs] + [
            d for d in path if d and not any(Path(d).is_relative_to(root) for root in wsl_launcher_dirs)
        ]
    bash = shutil.which("bash", path=os.pathsep.join(search))
    if not bash:
        sys.exit("*** Bash not found. Install Git Bash on Windows or run tools/build_sn.sh from Bash.")
    env["PATH"] = os.pathsep.join(path)
    return str(Path(bash).absolute()), env


def run_build() -> int:
    bash, env = build_environment()
    return subprocess.run([bash, "tools/build_sn.sh"], cwd=ROOT, env=env).returncode


if __name__ == "__main__":
    sys.exit(run_build())
