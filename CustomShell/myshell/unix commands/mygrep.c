#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>


#define MAX_LINE_LENGTH 256

int grep(char *command_buf)
{
    char *hole[1000];
    int i = 0;

    
    char *token = strtok(command_buf, " ");

    while (token != NULL)
    {
        hole[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    if (strcmp(hole[1], "-H") == 0)
    {
        {
            char *search_term = hole[2];
            char *filename = hole[3];

            FILE *file = fopen(filename, "r");
            if (file == NULL)
            {
                fprintf(stderr, "Error opening file %s\n", filename);
                return 1;
            }

            char line[MAX_LINE_LENGTH];
            while (fgets(line, MAX_LINE_LENGTH, file))
            {
                if (strstr(line, search_term))
                {
                    printf("%s:%s", filename, line);
                }
            }

            fclose(file);
        }
    }
    else if (strcmp(hole[1], "-n") == 0)
    {
        char *search_term = hole[2];
        char *filename = hole[3];

        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error opening file %s\n", filename);
            return 1;
        }

        char line[MAX_LINE_LENGTH];
        int line_number = 0;
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            line_number++;
            if (strstr(line, search_term))
            {
                printf("%d:%s", line_number, line);
            }
        }

        fclose(file);
    }
    else if (strcmp(hole[1], "-c") == 0)
    {
        char *search_term = hole[2];
        char *filename = hole[3];

        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error opening file %s\n", filename);
            return 1;
        }

        char line[MAX_LINE_LENGTH];
        int count = 0;
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            if (strstr(line, search_term))
            {
                count++;
            }
        }

        printf("%d\n", count);

        fclose(file);
    }
    else if (strcmp(hole[1], "-v") == 0)
    {
        char *search_term = hole[2];
        char *filename = hole[3];

        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error opening file %s\n", filename);
            return 1;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            if (!strstr(line, search_term))
            {
                printf("%s", line);
            }
        }

        fclose(file);
    }

    else
    {
        char *search_term = hole[1];
        char *filename = hole[2];

        FILE *file = fopen(filename, "r");
        if (file == NULL)
        {
            fprintf(stderr, "Error opening file %s\n", filename);
            return 1;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, MAX_LINE_LENGTH, file))
        {
            if (strstr(line, search_term))
            {
                printf("%s", line);
            }
        }

        fclose(file);
    }
}