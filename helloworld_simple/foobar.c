#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foobar.h"

int g_foo = 100;
int g_foo_bss;
static int g_foo_static;

int foobar(int i)
{
    int l_foo = 250;
    int l_foo_bss;
    static int l_foo_static;
    char bar_buf[32];
    
    strcpy(bar_buf, "hello world\n");

    printf(bar_buf);
    
    return 0;
}