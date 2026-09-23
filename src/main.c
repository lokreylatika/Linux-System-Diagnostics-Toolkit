#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/input.h"
#include "../include/parser.h"
#include "../include/diagnostics.h"
#include "../include/process.h"
#include "../include/builtin.h"
#include "../include/signals.h"

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

        tokens = parse_line(line);

        if(tokens[0] != NULL)
        {
            if(execute_builtin(tokens) == 0)
            {
                if(strcmp(tokens[0],"uptime")==0)
                {
                    showUptime();
                }
                else if(strcmp(tokens[0],"memory")==0)
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
