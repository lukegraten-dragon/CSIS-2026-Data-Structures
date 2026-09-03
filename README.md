## CSIS 255 Data Structures

Repository for CSIS 255 C++ code. Includes examples and assignments/labs completed in class. 
Each category of content will be placed in its own respective folder (e.g. source code for labs goes in a dedicated labs folder).

My local setup (**Apple Silicon Mac**) has extra compiler flags not provided by the default generated build tasks.json file. These local flags are used to catch memory
corruption bugs that appear in my code as a guardrail against undefined behavior and potential security issues. 
The code I will be pushing to the private GitHub repository and Smoke will not have these custom Clang++ flags bundled with them.
I'm committed to writing more safe and correct code from the start as a habit.

### Compiler flags I use on my local machine:

```
                "-std=c++14",
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                "-g",
                "-Wall",
                "-Wextra",
                "-Werror",
                "${file}",
                "-Wconversion",
                "-Wsign-conversion",
                "-Wshadow",
                "-Wnull-dereference",
                "-Wunsafe-buffer-usage",
                "-Wimplicit-fallthrough",
                "-Wcast-qual",
                "-fsanitize=address,undefined",
                "-fno-omit-frame-pointer",
                "-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_EXTENSIVE",
                "-fstack-protector-strong",
                "-mbranch-protection=standard",
                "-o",
                "${workspaceFolder}/build/${fileBasenameNoExtension}"
```