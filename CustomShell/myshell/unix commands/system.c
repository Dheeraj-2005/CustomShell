#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>

char *command_buf;
void ls_s();
void ls_a();
void ls_U();
void ls_r();
void ls_l();
void ls();
void cp(char *);
void mv(char *);
int grep(char *);
int main()
{
    char hostname[100], str[200];
    gethostname(hostname, 100);
    char *user = getlogin();
    char path[100];
    getcwd(path, 100);
    strcat(user, "@");
    strcat(user, hostname);
    strcat(user, ":~");
    strcat(user, path);
    strcat(user, "$ ");

    while (1)
    {
        command_buf = readline(user);

        if (strlen(command_buf) > 0)
        {
            add_history(command_buf);
        }

        if (!strcmp(command_buf, "help"))
        {
            system("bash -c help");
        }
        else if (!strcmp(command_buf, "clear"))
        {
            system("clear");
        }
        else if (!strcmp(command_buf, "exit") || !strcmp(command_buf, "quit") || !strcmp(command_buf, "e") || !strcmp(command_buf, "q"))
        {
            printf("exited from terminal\n");
            break;
        }
        if (strstr(command_buf, "ls") != NULL)
        {
            if (strstr(command_buf, "-s") != NULL)
            {
                ls_s();
            }
            else if (strstr(command_buf, "-r") != NULL)
            {
                ls_r();
            }
            else if (strstr(command_buf, "-U") != NULL)
            {
                ls_U();
            }
            else if (strstr(command_buf, "-a") != NULL)
            {
                ls_a();
            }
            else if (strstr(command_buf, "-l") != NULL)
            {
                ls_l();
            }
            else 
            {
                ls();
            }
        }
        else if (strstr(command_buf, "cp") != NULL)
        {
            cp(command_buf);
        }
        else if (strstr(command_buf, "mv") != NULL)
        {
            mv(command_buf);
        }
        else if (strstr(command_buf, "grep") != NULL)
        {
            grep(command_buf);
        }
    }
}
