#include <stdio.h>
#include <sys/sysinfo.h>
#include "../include/diagnostics.h"

void showUptime()
{
    struct sysinfo info;
    sysinfo(&info);

    printf("System Uptime: %ld seconds\n", info.uptime);
}

void showMemory()
{
    struct sysinfo info;
    sysinfo(&info);

    printf("Total RAM: %lu MB\n",
           info.totalram/(1024*1024));

    printf("Free RAM: %lu MB\n",
           info.freeram/(1024*1024));
}
