#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	int rv;
	switch(pid=fork())
	{
		
		case -1:
			perror("fork");
			exit(1);
			
		case 0:
			printf("\n CHILD: This is the child process!\n");
			fflush(stdout);
			printf("\n CHILD:My PID is %d",getpid());
			printf("\n CHILD:My parents PID is %d",getpid());
			printf("\n CHILD:Enter my exit status (make it small):");
			printf("\n CHILD:I'm out here");
			scanf("%d",&rv);
			exit(rv);
			
			printf("\n Parent: This is the parent process");
			printf("\n Parent: My PID is %d\n",getpid());
			fflush(stdout);
			
			wait(&rv);
			fflush(stdout);
			printf("\n PARENT: My child's PID is %d\n",pid);
			printf("\n Parent: I'm now waiting for my child to exit()...");
			fflush(stdout);
			printf("\n Parent: My child exit status is:%d",WEXITSTATUS(rv));
			printf("\nParent:I'm outta here!\n");
	}
}
