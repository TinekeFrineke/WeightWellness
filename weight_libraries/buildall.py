import os
import subprocess
from pathlib import Path

# Configuration
generators = {
    "Visual Studio 16 2019": ["Win32", "x64"],
    "Visual Studio 17 2022": ["Win32", "x64"]
}

generator_acronyms = {
    "Visual Studio 16 2019": "vs2019",
    "Visual Studio 17 2022": "vs2022"
}

configs = ["Debug", "Release"]
source_dir = Path(__file__).resolve().parent

for gen, archs in generators.items():
    acronym = generator_acronyms[gen]
    for arch in archs:
        for cfg in configs:
            build_dir = source_dir / f"build/{acronym}/{arch}/{cfg.lower()}"
            os.makedirs(build_dir, exist_ok=True)

            print(f"\n=== Configuring: {gen} / {arch} / {cfg} ===")
            cmake_configure = [
                "cmake", "-S", str(source_dir), "-B", str(build_dir),
                "-G", gen, "-A", arch,
                f"-DCMAKE_CONFIGURATION_TYPES=Debug;Release"
            ]
            result = subprocess.run(cmake_configure)

            if result.returncode != 0:
                print("CMake configuration failed. Skipping build.")
                continue

            print(f"=== Building: {gen} / {arch} / {cfg} ===")
            cmake_build = [
                "cmake", "--build", str(build_dir),
                "--config", cfg
            ]
            build_result = subprocess.run(cmake_build)

            if build_result.returncode != 0:
                print(f"Build failed for {gen} / {arch} / {cfg}")
