# Writeup

This first challenge is simple, although the fact that I never actually sit down to build a base64 encoder
made it quite challenging. CMake and tests will be added in the future, as complexity grows.

base64 is a very simple, very basic encoding format. In its core, it represents 3 bytes into four 6-bits digit
sequences. If the final sequence ends up being less than 6 bits, padding (=) is added to fill the gap.

The source code is comprised of three files, `hex2base64.c`, `hex2base64.h` and `main.c`. The filenames are
quite self-explanatory:
* `hex2base64.c` contains the base64 encoder source code.
* `main.c` handles errors and input/output.
* `hex2base64.h` is the header file.
