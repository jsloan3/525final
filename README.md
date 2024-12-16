# 525 final project
Made for group CWE-415 (though this is a use-after free, not a double free, at the professor's recommendation.)
## Compiling
Use `make` to compile the program using the makefile. Note that `main.c` requires `malloc.c` and `malloc.h`, an older version of the C memory allocator, to work properly.
## Usage
Run the compiled binary and it will give you input instructions! Note that `main` is intentionally written with use-after-free bugs built in, so it may crash in unexpected ways.

The goal is to get the program to tell you the secret password! (which isn't so secret if you look at the sourcecode.)
## Exploit
`exploit.sh` is a shell script that will put in the inputs required to pull off the exploit, giving you the secret string.
