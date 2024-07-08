#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <fcntl.h>

#define BUF_SIZE 1024
int compare_strings(const void *a, const void *b)
{
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcmp(s1, s2);
}

void ls()
{
    int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        if (dirp->d_name[0] == '.')
        {
            continue;
        }
        strings[i] = dirp->d_name;
        // printf("%s\n",dirp->d_name);

        i++;
    }
    qsort(strings, i, sizeof(char *), compare_strings);
    for (int j = 0; j < i; j++)
    {
        printf("%s ", strings[j]);
    }
    printf("\n");

    closedir(dp);
}
void ls_l()
{
    int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        if (dirp->d_name[0] == '.')
        {
            continue;
        }
        strings[i] = dirp->d_name;
        // printf("%s\n",dirp->d_name);

        i++;
    }
    qsort(strings, i, sizeof(char *), compare_strings);

    struct stat file_stat;
    int blocks=0;
    for (int j = 0; j < i; j++)
    {

        stat(strings[j], &file_stat);
        blocks=blocks+file_stat.st_blocks;
    }
    printf("Total %d\n",blocks/2);
    for (int j = 0; j < i; j++)
    {

        stat(strings[j], &file_stat);
        
        printf("%c%c%c%c%c%c%c%c%c%c ",
               (S_ISDIR(file_stat.st_mode)) ? 'd' : '-',
               (file_stat.st_mode & S_IRUSR) ? 'r' : '-',
               (file_stat.st_mode & S_IWUSR) ? 'w' : '-',
               (file_stat.st_mode & S_IXUSR) ? 'x' : '-',
               (file_stat.st_mode & S_IRGRP) ? 'r' : '-',
               (file_stat.st_mode & S_IWGRP) ? 'w' : '-',
               (file_stat.st_mode & S_IXGRP) ? 'x' : '-',
               (file_stat.st_mode & S_IROTH) ? 'r' : '-',
               (file_stat.st_mode & S_IWOTH) ? 'w' : '-',
               (file_stat.st_mode & S_IXUSR) ? 'x' : '-');
        printf("%ld ", file_stat.st_nlink);
        struct passwd *pw = getpwuid(file_stat.st_uid);
        printf(" %s ", pw->pw_name);
        struct group *gr = getgrgid(file_stat.st_gid);
        printf("%s ", gr->gr_name);
        printf("%8ld ", file_stat.st_size);
        char *c = ctime(&file_stat.st_mtime);
        c[16] = '\0';
        printf("%s ", c + 4);
        printf("%s \n", strings[j]);

    }
    
    closedir(dp); }
    void ls_r()
    {
        int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        if (dirp->d_name[0] == '.')
        {
            continue;
        }
        strings[i] = dirp->d_name;
        // printf("%s\n",dirp->d_name);

        i++;
    }
    qsort(strings, i, sizeof(char *), compare_strings);
        
    for (int j = 0; j < i; j++)
    {
        printf("%s ", strings[i-1-j]);
    }
    printf("\n");

    closedir(dp);
}
void ls_U()
{
   int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        if (dirp->d_name[0] == '.')
        {
            continue;
        }
        strings[i] = dirp->d_name;
        // printf("%s\n",dirp->d_name);

        i++;
    }
    for(int j=0;j<i;j++)
                     {
                        printf("%s ",strings[j]);
                     }
     printf("\n");
     closedir(dp);
}
void ls_a()
{
    int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        
        strings[i] = dirp->d_name;
    

        i++;
    }
    qsort(strings, i, sizeof(char *), compare_strings);
        
    for (int j = 0; j < i; j++)
    {
        printf("%s ", strings[j]);
    }
    printf("\n");

    closedir(dp);                        
}
void ls_s()
         {
            int i = 0;
    DIR *dp;
    struct dirent *dirp;
    char *strings[1024];
    dp = opendir(".");
    while ((dirp = readdir(dp)) != NULL)
    {
        if (dirp->d_name[0] == '.')
        {
            continue;
        }
        strings[i] = dirp->d_name;
        // printf("%s\n",dirp->d_name);

        i++;
    }
    qsort(strings, i, sizeof(char *), compare_strings);

    struct stat file_stat;
    int blocks=0;
    for (int j = 0; j < i; j++)
    {

        stat(strings[j], &file_stat);
        blocks=blocks+file_stat.st_blocks;
    }
    printf("Total %d\n",blocks/2);
    for (int j = 0; j < i; j++)
    {

        stat(strings[j], &file_stat);
        printf("%ld %s  ",file_stat.st_blocks/2,strings[j]);
    }
    
    printf("\n");
    closedir(dp);

         }
 /*void cp() {
    char old_file[520],new_file[520];
    scanf("%s %s",old_file,new_file);
    int fd_in, fd_out;
    size_t num_read;
    char buf[BUF_SIZE];



    if((fd_in = open(old_file, O_RDONLY)) == -1) {
        perror(old_file);
        return 1;
    }

    if((fd_out = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
        perror(new_file);
        return 1;
    }

    while((num_read = read(fd_in, buf, BUF_SIZE)) > 0) {
        if(write(fd_out, buf, num_read) != num_read) {
            perror("write");
            return 1;
        }
    }

    if(num_read == -1) {
        perror("read");
        return 1;
    }

    if(close(fd_in) == -1) {
        perror("close input");
        return 1;
    }

    if(close(fd_out) == -1) {
        perror("close output");
        return 1;
    }

    char *space[100];
    char *token = strtok(command_buf," ");
    while (token ! = NULL)
    {
        int i=0;
        space[i]=token;
        i++;
        token=strtok(NULL," ");
    }*/




    
