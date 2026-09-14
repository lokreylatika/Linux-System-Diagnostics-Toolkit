#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/parser.h"
#include "../include/diagnostics.h"

int main()
{
    char *line;
    char **tokens;

    printf("===== Linux System Diagnostics Toolkit =====\n");

    while(1)
    {
        printf("diagnostics> ");

        line = read_line();

        if(strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        tokens = parse_line(line);

        if(tokens[0] != NULL)
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
                printf("Unknown Command\n");
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
