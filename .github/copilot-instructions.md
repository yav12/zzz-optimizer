This repository is a Qt (C++17) desktop application used as a "zzz" optimizer. The goal of this guidance is to make AI coding agents immediately productive by focusing on the repository's structure, conventions, build/test/debug commands, and common change patterns.

Summary (big picture)
- Language & framework: C++17 + Qt6 Widgets (see `CMakeLists.txt`).
- App type: single-process Qt GUI application. Entry point is `main.cpp` which constructs a `QApplication` and shows the `window` (class in `window.h/window.cpp`).
- Data vs. code: a lot of static game data lives in code (not JSON) — for example `wengine.cpp` contains hundreds of hard-coded wengine definitions (name, rarity, specialty, image resource path, effect text). Treat these as data-authoring files: changes often mean editing strings and resource paths, not algorithmic changes.

What to read first to get productive
- `README.md` — informal build hints (uses CMake + Ninja). Use it to confirm quick local build steps.
- `CMakeLists.txt` — project targets, required Qt components, resource compilation (rc). Important for adding new source files or resources.
- `main.cpp` and `window.h/.cpp` — app entry and primary UI wiring.
- `wengine.cpp` — canonical example of project-specific pattern: large, repetitive, static initializers representing game items. Use it as model when adding new wengine entries.
- `assets/` — contains `characters/`, `discs/`, `wengines/` images referenced by resource paths in code (e.g. ":/wengines/attack/CordisGermina.png").

Build / run / debug
- Standard (recommended):
  cmake -G Ninja -S . -B build
  cmake --build build
  ./build/zzz-optimizer
- If using Qt Creator: open the project folder or the `CMakeLists.txt` and let Creator handle the CMake configuration. The README's alternative is to open and Run from Qt Creator when CMake rules are unclear.
- Notes:
  - The project enables `CMAKE_AUTORCC ON` — resources listed in `resources.qrc` are compiled into the binary; update `resources.qrc` and re-run CMake if you add new image assets.
  - Target links Qt::Widgets; when adding new Qt modules, update `find_package` and `target_link_libraries` in `CMakeLists.txt`.

Testing and quick validation
- There are no automated unit tests in the repo. Fast validation for UI changes: build and run the app and exercise the UI path that uses the changed data (for example, add or modify a wengine entry and open the part of the UI that lists or displays wengines).

Project-specific conventions and patterns
- Data-in-code: Many domain items are implemented as C++ objects initialized with literal fields. See `wengine.cpp` for the pattern:
  - Each wengine instance sets fields like `name`, `rarity`, `specialty`, `baseAtk`, `stat`, `statPercent`, `effect`, `image`.
  - Images are referenced via Qt resource paths (":/wengines/<category>/<file>.png"). Keep resource paths consistent with `assets/` and `resources.qrc`.
- Minimal OOP UI: UI classes are simple QWidget subclasses (e.g. `window`). Prefer small, local changes and keep UI wiring minimal.
- Formatting: no strict formatter enforced in repo. Preserve existing style when editing (mostly compact, no extra whitespace changes).

Integration points and external dependencies
- Qt6 (Core & Widgets) is required. The system needs a Qt6 development environment to build and run. Package names vary by distro (e.g., `qt6-base-dev` / `qtbase6-dev` + appropriate Qt6 Widgets dev packages).
- CMake (>= 3.19) and Ninja (common generator used in README/CMake). Use the same generator if adding CI scripts.

Examples to reference
- Add a new wengine: copy the pattern in `wengine.cpp` and add a new instance initializer that sets the same fields. Add the corresponding PNG under `assets/wengines/<category>/` and add it to `resources.qrc` if the resource path isn't an automatically discovered one.
- Add a new source file: update `CMakeLists.txt` in the `qt_add_executable(...)` list and re-run CMake.

What to avoid / gotchas
- Don't split the large data blobs into many small revisions in the same commit — keep data edits atomic and documented. The data is easy to accidentally corrupt (missing quotes, stray characters) and will cause build or runtime issues.
- Don't assume runtime assets are on disk at runtime — they are compiled into Qt resources. Update `resources.qrc` for new assets and reconfigure CMake.
- Because many strings are user-facing (effect descriptions), pay attention to escaping and raw string literals. `wengine.cpp` uses R"(...)" raw string literals for multi-line text — follow the same pattern.

File references (high value)
- `CMakeLists.txt` — build config and where to add sources/modules
- `main.cpp` — application entry
- `window.h`, `window.cpp` — primary UI
- `wengine.cpp` — large data authoring pattern (search for "name = " to find entries)
- `resources.qrc` and `assets/` — images used by UI

If you need more
- If anything in this file is unclear or you want me to expand particular sections (CI, packaging, test harness, or help converting data to external JSON), tell me which area to expand and I'll iterate.
