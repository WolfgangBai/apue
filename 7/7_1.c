#include "apue.h"
#include <sys/resource.h>

#define do_it(name) pr_limits(#name, name)
static void pr_limits(char *, int);


int main(void)
{
    do_it(RLIMIT_AS);

}

static void
pr_limits(char *name, int resource)
{
    struct rlimit limit;
    unsigned long long lim;

    if (getrlimit(resource, &limit) < 0) {
        err_sys("getrlimit error for %s", name);
    }
    printf("%-14s ", name);
    if (limit.rlim_cur == RLIM_INFINITY) {
        printf("(infinite) ");
    } else {
        lim = limit.rlim_cur;
        printf("%10lld", lim);
    }
}
