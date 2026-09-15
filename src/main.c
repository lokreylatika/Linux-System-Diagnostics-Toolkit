#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/parser.h"
#include "../include/diagnostics.h"
#include "../include/process.h"

void showHelp()
{
    printf("\n===== Available Commands =====\n");
    printf("uptime       - Show system uptime\n");
    printf("memory       - Show memory information\n");
    printf("free -h      - Show detailed RAM usage\n");
    printf("df -h        - Show disk space usage\n");
    printf("date         - Show current date and time\n");
    printf("whoami       - Show current username\n");
    printf("ls           - List files and folders\n");
    printf("ps           - Show running processes\n");
    printf("hostname     - Show system hostname\n");
    printf("help         - Show this command list\n");
    printf("exit         - Exit the toolkit\n");
    printf("==============================\n\n");
}

int main()
{
    char *line;
    char **tokens;

    printf("===== Linux System Diagnostics Toolkit =====\n");
    printf("Type 'help' to see available commands.\n");

    while(1)
    {
        printf("\ndiagnostics> ");

        line = read_line();

        if(strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        tokens = parse_line(line);

        if(tokens[0] != NULL)
        {
            if(strcmp(tokens[0], "help") == 0)
            {
                showHelp();
            }
            else
            {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Exiting Toolkit...\n");

    return 0;
}
