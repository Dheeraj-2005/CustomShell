#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>


void mv(char *command_buf)
{
    char *space[100], option[200];
    char *token;
    int i = 0;
    token = strtok(command_buf, " ");
    char old_file[520], new_file[520];
    while (token != NULL)
    {

        space[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    
        if (strcmp(space[1],"-i")==0)
        {
            strcpy(option, space[1]);
            strcpy(old_file, space[2]);
            strcpy(new_file, space[3]);
            int fd_in, fd_out;
            size_t num_read;
            char buf[512];

            if ((fd_in = open(old_file, O_RDONLY)) == -1)
            {
                perror(old_file);
                return;
            }

            if ((strcmp(option, "-i") == 0) && (access(new_file, F_OK) == 0))
            {
                char response;
                printf("cp: overwrite '%s'? (y/n) ", new_file);
                scanf(" %c", &response);
                if (response == 'n')
                {
                    printf("cp: '%s' not overwritten\n", new_file);
                    return;
                }
            }

            if ((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
            {
                perror(new_file);
                return;
            }

            while ((num_read = read(fd_in, buf, 512)) > 0)
            {
                if (write(fd_out, buf, num_read) != num_read)
                {
                    perror("write");
                    return;
                }
            }

            if (num_read == -1)
            {
                perror("read");
                return;
            }

            if (close(fd_in) == -1)
            {
                perror("close input");
                return;
            }

            if (close(fd_out) == -1)
            {
                perror("close output");
                return;
            }
            remove(space[2]);
        }
    else if(strcmp(space[1],"-n")==0)

{
        strcpy(option, space[1]);
            strcpy(old_file, space[2]);
            strcpy(new_file, space[3]);
            int fd_in, fd_out;
            size_t num_read;
            char buf[512];

            if ((fd_in = open(old_file, O_RDONLY)) == -1)
            {
                perror(old_file);
                return;
            }

            if ((strcmp(option, "-n") == 0) && (access(new_file, F_OK) == 0))
            {
                printf("cp: '%s' already exists (not overwritten)\n", new_file);
                return;
            }

            if ((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
            {
                perror(new_file);
                return;
            }

            while ((num_read = read(fd_in, buf, 512)) > 0)
            {
                if (write(fd_out, buf, num_read) != num_read)
                {
                    perror("write");
                    return;
                }
            }

            if (num_read == -1)
            {
                perror("read");
                return;
            }

            if (close(fd_in) == -1)
            {
                perror("close input");
                return;
            }

            if (close(fd_out) == -1)
            {
                perror("close output");
                return;
            }
        remove(space[2]);
}
else if(strcmp(space[1],"-v")==0)
{
strcpy(option, space[1]);
strcpy(old_file, space[2]);
    strcpy(new_file, space[3]);
    
    int fd_in, fd_out;
    size_t num_read;
    char buf[512];

    if ((fd_in = open(old_file, O_RDONLY)) == -1)
    {
        perror(old_file);
    }

    if ((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
    {
        perror(new_file);
    }

    while ((num_read = read(fd_in, buf, 512)) > 0)
    {
        if (write(fd_out, buf, num_read) != num_read)
        {
            perror("write");
        }
    }

    if (num_read == -1)
    {
        perror("read");
    }

    if (close(fd_in) == -1)
    {
        perror("close input");
    }

    if (close(fd_out) == -1)
    {
        perror("close output");
    }

    printf("'%s'  -> '%s'\n",space[2],space[3]);
    remove(space[2]);
    
}

else if (strcmp(space[1], "-f") == 0)
    {
        // force mode
        strcpy(old_file, space[2]);
        strcpy(new_file, space[3]);

        int fd_in, fd_out;
        size_t num_read;
        char buf[512];

        if ((fd_in = open(old_file, O_RDONLY)) == -1)
        {
            perror(old_file);
            return;
        }

        if ((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
        {
            perror(new_file);
            return;
        }

        while ((num_read = read(fd_in, buf, 512)) > 0)
        {
            if (write(fd_out, buf, num_read) != num_read)
            {
                perror("write");
                return;
            }
        }

        if (num_read == -1)
        {
            perror("read");
            return;
        }

        if (close(fd_in) == -1)
        {
            perror("close input");
            return;
        }

        if (close(fd_out) == -1)
        {
            perror("close output");
            return;
        }
        remove(space[2]);
    }
    
            
    
        

else
{
    strcpy(old_file, space[1]);
    strcpy(new_file, space[2]);
    
    int fd_in, fd_out;
    size_t num_read;
    char buf[512];

    if ((fd_in = open(old_file, O_RDONLY)) == -1)
    {
        perror(old_file);
    }

    if ((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
    {
        perror(new_file);
    }

    while ((num_read = read(fd_in, buf, 512)) > 0)
    {
        if (write(fd_out, buf, num_read) != num_read)
        {
            perror("write");
        }
    }

    if (num_read == -1)
    {
        perror("read");
    }

    if (close(fd_in) == -1)
    {
        perror("close input");
    }

    if (close(fd_out) == -1)
    {
        perror("close output");
    }
    remove(space[1]);
}
}