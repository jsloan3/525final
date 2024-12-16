# 525 final project
Made for group CWE-415, Double-Free
## Compiling
Use `make` to compile the program using the makefile. Note that `main.c` requires the `malloc.c` and `malloc.h` included, an older version of the C memory allocator, to work properly (as recommended by the professor).
## Usage
Run the compiled binary and it will give you input instructions! Note that `main` is intentionally written with use-after-free and double-free bugs built-in, so it may crash in unexpected ways. We had trouble with just a simple double-free exploit, so under the professor's recommendation we did a use-after-free exploit too.

This is meant to be run on the same university lab servers that was used for everything else in the semester.

The goal is to get the program to tell you the secret password! (which isn't so secret if you look at the sourcecode.)
## Exploit
`exploit.sh` is a shell script that will put in the inputs required to pull off the exploit, giving you the secret string.

## Explanation:
`exploit.sh` works by exploiting both a double free and use-after-free vulnurability in the code.

First, we allocate the dead() function on ptr1. 

We then deallocate (free) ptr1. This marks the dead() ptr to be free in memory.

We then allocate the telljoke function on ptr2. Because the part of memory where dead() was is now free, the allocator puts telljoke() in the same bit of memory.

ptr1 and ptr2 are now pointing to the same chunk in memory, where the telljoke() pointer is.

We then free ptr1, again. This is a staggered double free: its the second time that ptr1 has been free'd! Recall that ptr1 was pointing to where the telljoke() function pointer is, and where ptr2 is pointing as well.

The spot in memory where ptr1 and ptr2 were both pointing is now free.

We now allocate getsecret() to ptr3. If ptr3 is attempted to be used, it will refuse to tell the secret.

However, ptr1 and ptr2 are now pointing to this bit of memory as well, as getsecret() has overwritten the free bit of memory they were just pointing to.

We now use the function that ptr2 is pointing to: which is now getsecret(). It will give us the secret without complaining now!
