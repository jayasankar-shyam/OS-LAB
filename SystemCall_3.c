#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(int argc,char *argv[]){
	char buff[256];
	DIR *dirp;
	printf("\nEnter the directory name : ");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL){
		printf("ERROR\n");
		exit(1);
	}
	while(dptr=readdir(dirp))
		printf("%s\n",dptr->d_name);
	closedir(dirp);
}
