/**
¾²Ì¬±àÒë£º
gcc -static-libgcc -static main.c
$ file a.out 
a.out: ELF 64-bit LSB executable, x86-64, version 1 (GNU/Linux), statically linked, for GNU/Linux 2.6.32, BuildID[sha1]=84dc50b7e63f468b834c56dded84f4c50a0f82f4, not stripped

$ ldd a.out 
        not a dynamic executable
        
¶¯Ì¬±àÒë£º
gcc main.c

$ file a.out 
a.out: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 2.6.32, BuildID[sha1]=99c1f1652984773fdf0f26280615fa0ef07cd9c1, not stripped

$ ldd a.out 
        linux-vdso.so.1 =>  (0x00007ffed23c0000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f2c29b19000)
        /lib64/ld-linux-x86-64.so.2 (0x000055c1e0043000)

¾²Ì¬Á´½Ó±È¶¯Ì¬Á´½Ó´ó10±¶×óÓÒ

*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("hello world.\n");
    
    return 0;
}