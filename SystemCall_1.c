#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	int pid;
	printf("The process id of the current process : %d\n",getpid());
	printf("Calling the function fork()");
	if(fork()!=0)
	{
		printf("Parent process starts and wait() executes\n");
		wait(NULL);
		printf("Waiting and executes another function");
		char *args[]={"ls",NULL};
		execvp(args[0],args);
		exit(0);
		printf("Execution not ends and parent ends\n");
	}
	else
		printf("Child process starts and ends\n");
	printf("exit function\n");
	exit(0);
	printf("Exit not executing");
	return 0;
}
