#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXSTRLEN 1024
#define NUM 64
void GetCommand(char *command, int size)
{
    char *r = fgets(command, size - 1, stdin);
    if (r == NULL)
    {
        // return -1;
        return;
    }
    command[strlen(command) - 1] = '\0';
}

void AnalyseCommand(char *command, char *argv[])
{
    int n = 0;
    argv[n++] = strtok(command, " ");
    // printf("%s",argv[n]);
    while (argv[n++] = strtok(NULL, " "))
        ;
}
void run(char *argv[])
{
    int pid = fork();
    if (pid < 0)
    {
        perror("fork");
    }
    else if (pid == 0) // 子进程
    {
        execvp(argv[0], argv);
        exit(1);
    }
    else
    { // 父进程
        int status;
        waitpid(-1, &status, 0);
        if (status)
        {
            if (!WIFEXITED(status))
            {
                printf("please enter command -parameter\n");
            }
        }
    }
}
int main()
{
    // extern char** environ;

    while (1)
    {
        char command[MAXSTRLEN];
        printf("[%s]", getenv("PWD"));
        // 获取指令
        GetCommand(command, sizeof(command));
        // 解析指令
        char *argv[NUM];
        AnalyseCommand(command, argv);

        // 运行指令
        run(argv);
    }
}