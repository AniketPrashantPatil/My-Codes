
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h> 

int main()
{

	int i,pid;
	pid=fork();
	if(pid==-1)
	{
		printf("\n fork failed");
		exit(0);
	}
	else if(pid==0)
	{
		printf("\n Child process starts");
		for(i=0;i<5;i++)
		{
			printf("\n child process %d is called",i);
		}
		printf("\n Child process ends");
	}
	else
	{
		wait(0);
		printf("\n Parent process ends");
	}
	exit(0);
}
