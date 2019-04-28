#include "unp.h"

void err_sys(const char* x, ...)
{
    perror(x);
    exit(1);
}

void err_quit(const char* y, ...)
{
    perror(y);
    exit(1);
}
