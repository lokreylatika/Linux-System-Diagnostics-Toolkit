#include <stdio.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo info;

    if(sysinfo(&info)==0)
    {
        printf("===== Linux System Diagnostics Toolkit =====\n");
        printf("System Uptime : %ld seconds\n", info.uptime);
        printf("Total RAM     : %lu MB\n",
               info.totalram/(1024*1024));
        printf("Free RAM      : %lu MB\n",
               info.freeram/(1024*1024));
    }

    return 0;
}
