# Operating Systems Programming Assignment 01: Core C Utilities & Build Engineering 

A comprehensive, production-grade C project implementing low-level software engineering principles, modular program structures, custom library creation (static and dynamic), build automation via Makefiles, manual documentation (man pages), and professional Git/GitHub version control lifecycles.

---

## 🌟 Project Overview & Objectives
This project centers on building a reusable general-purpose utility library named **`libmyutils`**, accompanied by a test driver program (`client`). The assignment spans the full software development lifecycle, moving from raw source compilation to static archiving, shared object linkage, system-wide installation, and structured technical reporting.

By completing this assignment, the project demonstrates proficiency in:
* **Modular Architecture:** Splitting code into clean, decoupled header (`.h`) and implementation (`.c`) modules.
* **Build Automation:** Crafting extensible `Makefiles` utilizing macros, pattern matching, recursive structures, and installation targets.
* **Static vs. Dynamic Linking:** Managing static archives (`.a`) via `ar`/`ranlib` versus position-independent shared objects (`.so`) compiled with `-fPIC`.
* **System Diagnostics & Binary Analysis:** Inspecting symbol tables, headers, and dependencies using tools like `nm`, `objdump`, `readelf`, and `ldd`.
* **Professional Version Control:** Managing multi-branch features (`multifile-build`, `static-build`, `dynamic-build`, `man-pages`), annotated tagging, and GitHub release asset management.

---

## 📂 Repository Architecture

```text
BSDSF24M004-OS-M04/
├── src/                 # Implementation source code (.c)
│   ├── main.c           # Driver program testing all utility modules
│   ├── mystrfunctions.c # Custom string operations implementation
│   └── myfilefunctions.c# Custom file operations implementation
├── include/             # Interface header files (.h)
│   ├── mystrfunctions.h # Declarations for string utilities
│   └── myfilefunctions.h# Declarations for file utilities
├── lib/                 # Compiled library outputs (libmyutils.a, libmyutils.so)
├── bin/                 # Compiled executable binaries (client variants)
├── obj/                 # Intermediate compiled object files (.o)
├── man/                 # System manual files (groff format)
│   └── man3/            # Section 3 programmer manual pages (e.g., mycat.1)
├── REPORT.md            # Comprehensive technical analysis report
└── Makefile             # Centralized build automation & installation script# BSDSF24M004-OS-M04


# # **Feature Breakdown & Implementation Milestones:**

**1. Feature 1:** Project Scaffolding & Version Control
Initialized a standardized directory structure (src, include, lib, bin, obj, man).

Implemented clean atomic commits tracking foundational changes under version control.

**2. Feature 2: **Multi-File Build (v0.1.1-multifile)
Core Task: Implemented custom functions for string operations (mystrlen, mystrcpy, mystrncpy, mystrcat) and file analysis (wordCount, mygrep).

Build Strategy: Wrote a multi-target Makefile to compile all source files directly into bin/client.

**3. Feature 3:** Static Library (v0.2.1-static)
Core Task: Refactored object compilation to bundle binary artifacts into a static archive (lib/libmyutils.a) using the ar archiver tool.

Analysis: Inspected symbol binding using nm and objdump, verifying that static code is directly embedded into the executable binary.

**4. Feature 4:** Dynamic Library (v0.3.1-dynamic)
Core Task: Compiled position-independent object code using -fPIC and generated a shared object library (lib/libmyutils.so) via gcc's -shared flag.

Loader Management: Handled runtime resolution via dynamic paths and verified dependency linkage using system loader tools.

**5. Feature 5: **Documentation & Installation (v0.4.1-final)
Documentation: Created standard Linux manual files (man/man3/mycat.1) using groff text formatting markup (.TH, .SH NAME, .SH SYNOPSIS, .SH DESCRIPTION, .SH AUTHOR).

Automation: Embedded an install target inside the Makefile to copy binaries and manual files into target system directories.

# Build, Test, & Installation Commands
Build and execute components easily in your terminal using mingw32-make

**Build Default Target (Dynamic Build):**  mingw32-make
**Run Executable Driver:**  ./bin/client_dynamic.exe
**Clean Build Artifacts:**  mingw32-make clean
**Run Automated System Installation:** mingw32-make install

 ## Version History & Release Tagging
Stable development milestones are tagged and published with compiled assets:

**v0.1.1-multifile:** Baseline multi-file compilation.

**v0.2.1-static:** Static archive library linking (.a).

**v0.3.1-dynamic:** Modular shared object library linking (.so).

**v0.4.1-final:** Complete build package featuring man pages and installation targets.