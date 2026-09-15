#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int execute_builtin(char **args)
{
    char cwd[1024];

    if(args[0] == NULL)
        return 1;

    /* exit */
    if(strcmp(args[0], "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    /* pwd */
    if(strcmp(args[0], "pwd") == 0)
    {
        if(getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s\n", cwd);
        else
            perror("pwd");

        return 1;
    }

    /* cd */
    if(strcmp(args[0], "cd") == 0)
    {
        if(args[1] == NULL)
        {
            printf("Usage: cd directory\n");
        }
        else
        {
            if(chdir(args[1]) != 0)
                perror("cd");
        }

        return 1;
    }

    /* clear */
    if(strcmp(args[0], "clear") == 0)
    {
        system("clear");
        return 1;
    }

    /* help */
    if(strcmp(args[0], "help") == 0)
    {
        printf("\n===== Linux System Diagnostics Toolkit =====\n");
        printf("\nBuilt-in Commands\n");
        printf("---------------------------\n");
        printf("cd <directory>  - Change directory\n");
        printf("pwd             - Show current directory\n");
        printf("clear           - Clear the screen\n");
        printf("help            - Show available commands\n");
        printf("env             - Show environment variables\n");
        printf("exit            - Exit the toolkit\n");

        printf("\nDiagnostic Commands\n");
        printf("---------------------------\n");
        printf("uptime          - Show system uptime\n");
        printf("memory          - Show memory information\n");

        printf("\nLinux Commands\n");
        printf("---------------------------\n");
        printf("ls              - List files and folders\n");
        printf("free -h         - Show RAM usage\n");
        printf("df -h           - Show disk usage\n");
        printf("ps              - Show running processes\n");
        printf("date            - Show date and time\n");
        printf("whoami          - Show current username\n");
        printf("hostname        - Show system hostname\n");

        return 1;
    }

    /* environment variables */
    if(strcmp(args[0], "env") == 0)
    {
        printf("HOME = %s\n", getenv("HOME"));
        printf("USER = %s\n", getenv("USER"));
        printf("PATH = %s\n", getenv("PATH"));
        printf("SHELL = %s\n", getenv("SHELL"));
        printf("PWD = %s\n", getenv("PWD"));

        return 1;
    }

    return 0;
}
