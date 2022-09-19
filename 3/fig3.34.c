#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	
	pid_t pid, pid1; 

	/* fork a child process */
	pid = fork();

	if(pid < 0){ /* error occured */
		fprintf(stderr, "Fork Failed\n");
		return -1;
	}else if(pid == 0){ /* child process */
		pid1 = getpid();
		if(pid1 < 0){
			printf("getpid failed\n");
		}
		printf("child: pid = %d\n", pid); /* A */
		printf("child: pid1 = %d\n", pid1); /* B */
	}else{ /* parent process */
		pid1 = getpid();
		if(pid1 < 0){
			printf("getpid failed\n");
		}
		printf("parent: pid = %d\n", pid); /* C */
		printf("parent: pid1 = %d\n", pid1); /* D */
		if(wait(NULL) == -1){
			printf("Wait Failed\n");
		}
	}
	return 0;
}
