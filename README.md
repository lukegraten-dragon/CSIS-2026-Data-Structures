## CSIS 255 Data Structures

Repository for CSIS 255 C++ code. Includes examples and assignments/labs completed in class. 
Each category of content will be placed in its own respective folder (e.g. source code for labs goes in a dedicated labs folder).

My local setup (**Apple Silicon Mac**) has extra compiler flags not provided by the default generated build tasks.json file. These local flags are used to catch memory
corruption bugs that appear in my code as a guardrail against undefined behavior and potential security issues. 
The code I will be pushing to the private GitHub repository and Smoke will not have these custom Clang++ flags bundled with them.
I'm committed to writing more safe and correct code from the start as a habit.

### Compiler flags I use on my local machine:

```
    "-std=c++26",
    "-fcolor-diagnostics",
    "-fansi-escape-codes",
    "-g",
    "-Wall",
    "-Wextra",
    "${file}",
    "-Wsign-conversion",
    "-Wconversion",
    "-Wshadow",
    "-Wnull-dereference",
    "-Wunsafe-buffer-usage",
    "-Wimplicit-fallthrough",
    "-Wcast-qual",
    "-fsanitize=address,undefined",
    "-fno-omit-frame-pointer",
    "-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_EXTENSIVE",
    "-fstack-protector-strong",
    "-mbranch-protection=standard", // Supported on ARM v8.5+ or v9.0+ CPUs that only have Branch Target Identification (BTI) mitigation (e.g. Apple M2)
    "-o",
    "${workspaceFolder}/build/${fileBasenameNoExtension}"
```

### AI Use Policy

Labs or Assignments that have AI-generated code will be developed in a separate branch from the development branch. With a separate git commit history before being merged
back into ``dev``.

Prompt history and responses will be uploaded in a separate text file or document.

Inside the source files, detailed comments will be used to indicate where AI generated code is present.

```
## Model: Model Name (e.g. Gemma 4 12B)
## BEGIN AI-GENERATED CODE

Code...

### END AI-GENERATED CODE
```