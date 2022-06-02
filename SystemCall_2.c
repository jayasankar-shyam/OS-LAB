#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <time.h>
void printFileProperties(struct stat stats)
{
    struct tm dt;
    	printf("\nUser ID : %d\n",stats.st_uid);
	printf("Block Size : %ld\n",stats.st_blksize);
	dt = *(gmtime(&stats.st_atime));
    printf("Last acess time: %d-%d-%d %d:%d:%d\n", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,dt.tm_hour, dt.tm_min, dt.tm_sec);
	dt = *(gmtime(&stats.st_mtime));
    printf("Last modified time : %d-%d-%d %d:%d:%d\n", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,dt.tm_hour, dt.tm_min, dt.tm_sec);
	printf("Production Mode : %d\n",stats.st_mode);
	printf("Size of file : %ld\n",stats.st_size);
	printf("Number of links : %ld\n",stats.st_nlink);
}
int main()
{
    char path[100];
    struct stat stats;
    printf("Enter source file path: ");
    scanf("%s", path);
    if (stat(path, &stats) == 0)
    {
        printFileProperties(stats);
    }
    else
    {
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n", path);
    }

    return 0;
}
