#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t cpid;
	char buf;
	if(argc !=2)
	{
		fprintf(stderr, "Usage:%s <string>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	if(pipe(pipefd[2])==-1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if(cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	/*return from child*/
	if(cpid==0)
	{
		/*close the write side of pipe*/
		close(pipefd[1]);
		while(read(pipefd[0], &buf, 1)>0)
		{
			write(STDOUT_FILENO, &buf, 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	}
	else /*return from parent, write arg[1] to pipe*/
	{
		close(pipefd[0]);
		write(pipefd[1],argv[1],1);
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return 0;
}