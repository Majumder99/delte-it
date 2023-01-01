#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
/*
struct stat {
               dev_t     st_dev;         / ID of device containing file /
               ino_t     st_ino;         / inode number /
               mode_t    st_mode;        / protection /
               nlink_t   st_nlink;       / number of hard links /
               uid_t     st_uid;         / user ID of owner /
               gid_t     st_gid;         / group ID of owner /
               dev_t     st_rdev;        / device ID (if special file) /
               off_t     st_size;        / total size, in bytes /
               blksize_t st_blksize;     / blocksize for filesystem I/O /
               blkcnt_t  st_blocks;      / number of 512B blocks allocated /


               struct timespec st_atim;  / time of last access /
               struct timespec st_mtim;  / time of last modification /
               struct timespec st_ctim;  / time of last status change /

           };

*/

/*
A structure holding information about the directory entry.
struct dirent {
    ino_t          d_ino;       / inode number /
    off_t          d_off;       / offset to the next dirent /
    unsigned short d_reclen;    / length of this record /
    unsigned char  d_type;      / type of file; not supported
                                   by all file system types /
    char           d_name[256]; /filename
};
*/

void listdir(char *name)
{
    printf("%s\n",name);
    int i=0;
    fflush(stdout);
    DIR *dir;   //Like a file pointer
    struct dirent *entry;
    struct stat buf;
    

    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do
    {

        //Calculating path for file/folders in directory
        char path[1024];

        //snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name); // ALTERNATE

        char slash[] = "/";
        strcpy(path,name);
        strcat(path,slash);
        strcat(path,entry->d_name);

        //Calculating path for file/folders in directory


        if (entry->d_type == DT_DIR)
        {

 
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            printf(" [%s]\n", entry->d_name);
            stat(path,&buf);
            printf("size=%d\n",buf.st_size);
            listdir(path);
        }
        else
        {

            printf(" - %s\n", entry->d_name);
            stat(path,&buf);
            printf("size=%d\n",buf.st_size);
        }
    }
    while (entry = readdir(dir));
    closedir(dir);
}

int main(void)
{
    char cwd[100];
    getwd(cwd); // set cwd to path of current working directory like pwd command

    listdir(cwd);
    return 0;
}
