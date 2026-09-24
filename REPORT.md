# Operating Systems Programming Assignment 01 - Analysis Report

## Part 2: Multi-file Project & Build Basics

### 1. Explain the linking rule in this part's Makefile: `$(TARGET): $(OBJECTS)`. How does it differ from a Makefile rule that links against a library?
* **Explanation:** The rule specifies that the final target executable depends on all individual compiled object files. When any source file changes, `make` recompiles only the modified file and relinks the final binary.
* **Difference:** Direct multi-file linking combines all raw object files together into an executable in a single step. In contrast, linking against a library connects the target program to a pre-compiled archive (`.a`) or shared object (`.so`) file using library search paths (`-L`) and library specifier flags (`-l`).

### 2. What is a git tag and why is it useful in a project? What is the difference between a simple tag and an annotated tag?
* **Git Tag:** A git tag is a permanent pointer/reference to a specific commit, typically used to mark release milestones (e.g., version numbers).
* **Usefulness:** They make it easy to fetch, reference, and deploy stable iterations of code without relying on shifting commit hashes.
* **Simple vs. Annotated Tags:** A *lightweight (simple)* tag is just a pointer to a commit. An *annotated* tag stores extra metadata, including the tagger's name, email, date, and an optional release message, making it cryptographically signable and ideal for official releases.

### 3. What is the purpose of creating a "Release" on GitHub? What is the significance of attaching binaries (like your client executable) to it?
* **Purpose:** A GitHub Release packages a specific version tag into an official project milestone with release notes and downloadable source code archives.
* **Significance of Binaries:** Attaching compiled binaries allows end-users or evaluators to run and test the compiled software immediately without needing to set up a C compiler or build environment from scratch.

---

## Part 3: Static Libraries

### 4. Compare the Makefile from Part 2 and Part 3. What are the key differences in the variables and rules that enable the creation of a static library?
* **Variables & Rules:** Part 2 compiled all source files directly into a single binary command. Part 3 introduces intermediate object compilation rules (`-c`), uses the archiving tool `ar` to bundle those object files into `lib/libmyutils.a`, and updates the linking rule to leverage library paths (`-Llib -lmyutils`).

### 5. What is the purpose of the `ar` command? Why is `ranlib` often used immediately after it?
* **`ar` Purpose:** The archiver tool (`ar`) combines multiple object files into a single static archive library file (`.a`).
* **`ranlib` Purpose:** It generates an index of the symbols (functions/variables) contained inside the static archive. This index allows the linker to quickly locate symbols. *(Note: modern versions of `ar` often include options like `rcs` that handle indexing automatically).*

### 6. When you run `nm` on your client static executable, are the symbols for functions like `mystrlen` present? What does this tell you about how static linking works?
* **Presence of Symbols:** Yes, the symbols are directly embedded in the executable's symbol table.
* **Implication:** This confirms that static linking copies the actual machine code of the required library functions directly into the final executable binary, making it completely self-contained.

---

## Part 4: Dynamic Libraries

### 7. What is Position-Independent Code (`-fPIC`) and why is it a fundamental requirement for creating shared libraries?
* **Definition:** `-fPIC` instructs the compiler to generate machine code that executes properly regardless of where it is loaded in memory absolute addresses are replaced with relative offsets.
* **Requirement:** Because shared libraries can be loaded into arbitrary memory addresses chosen by the operating system at runtime, the code must be position-independent to prevent memory conflicts.

### 8. Explain the difference in file size between your static and dynamic clients. Why does this difference exist?
* **Difference:** The statically linked executable has a much larger file size than the dynamically linked client.
* **Reason:** Static linking embeds a duplicate copy of every library function used directly into the binary. Dynamic linking only stores references and symbol tables in the binary, as the actual implementation code resides separately in the shared library (`.so`).

### 9. What is the `LD_LIBRARY_PATH` environment variable? Why was it necessary to set it for your program to run, and what does this tell you about the responsibilities of the operating system's dynamic loader?
* **Definition:** An environment variable that specifies extra directories where the dynamic loader should search for shared libraries at runtime.
* **Necessity:** It was required because the OS dynamic loader searches standard system paths by default and didn't automatically know where to find custom project libraries.
* **Loader Responsibility:** This highlights that the dynamic loader is responsible for resolving runtime dependencies and mapping shared libraries into memory when an application starts.