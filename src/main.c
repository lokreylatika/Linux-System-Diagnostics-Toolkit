#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/parser.h"
#include "../include/diagnostics.h"
#include "../include/process.h"
#include "../include/builtin.h"
#include "../include/signals.h"
#include "../include/pipes.h"

static void tokenize(char *str, char **argv)
{
    int i = 0;

    char *token = strtok(str, " \t\n");

    while(token != NULL)
    {
        argv[i++] = token;
        token = strtok(NULL, " \t\n");
    }

    argv[i] = NULL;
}

int main()
{
    char *line;
    char **tokens;

    initialize_signals();

    printf("===== Linux System Diagnostics Toolkit =====\n");
    printf("Type 'help' to see available commands.\n");

    while(1)
    {
        printf("\ndiagnostics> ");

        line = read_line();

        if(line == NULL)
            break;

        /* Pipe Support */
        if(strchr(line, '|') != NULL)
        {
            char *argv1[64];
            char *argv2[64];

            char *left = strtok(line, "|");
            char *right = strtok(NULL, "|");

            if(left == NULL || right == NULL)
            {
                printf("Invalid pipe command\n");
                free(line);
                continue;
            }

            tokenize(left, argv1);
            tokenize(right, argv2);

            execute_pipe(argv1, argv2);

            free(line);
            continue;
        }

        tokens = parse_line(line);

        if(tokens[0] != NULL)
        {
            if(execute_builtin(tokens) == 0)
            {
                if(strcmp(tokens[0], "uptime") == 0)
                {
                    showUptime();
                }
                else if(strcmp(tokens[0], "memory") == 0)
                {
                    showMemory();
                }
                else
                {
                    execute(tokens);
                }
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Exiting Toolkit...\n");

    return 0;
}
