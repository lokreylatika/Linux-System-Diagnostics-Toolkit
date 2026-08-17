#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/diagnostics.h"

int main()
{
    char *line;

    printf("===== Linux System Diagnostics Toolkit =====\n");

    while(1)
    {
        printf("\n1. Show System Uptime\n");
        printf("2. Show RAM Information\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        line = read_line();

        if(strcmp(line, "1") == 0)
        {
            showUptime();
        }
        else if(strcmp(line, "2") == 0)
        {
            showMemory();
        }
        else if(strcmp(line, "3") == 0)
        {
            free(line);
            printf("Exiting Toolkit...\n");
            break;
        }
        else
        {
            printf("Invalid Choice\n");
        }

        free(line);
    }

    return 0;
}
