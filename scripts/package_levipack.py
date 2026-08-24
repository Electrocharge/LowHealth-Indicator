#!/usr/bin/env python3
import json
import shutil
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "LowHealthOverlay.levipack"

# Change this if your build output path differs.
LIB = ROOT / "build" / "android" / "arm64-v8a" / "release" / "libLowHealthOverlay.so"
MANIFEST = ROOT / "manifest.json"

if not LIB.exists():
    raise SystemExit(f"Missing compiled library: {LIB}")

with zipfile.ZipFile(OUT, "w", zipfile.ZIP_DEFLATED) as z:
    z.write(MANIFEST, "manifest.json")
    z.write(LIB, "libLowHealthOverlay.so")

print(f"Created {OUT}")
