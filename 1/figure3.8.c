#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main(){

	pid_t pid;

	/*fork a child process */
	pid = fork();

	if(pid < 0){ /* error occured */
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if(pid == 0){ /* Child process */
		if(execlp("/bin/ls", "ls", NULL) == -1){
			printf("exec failed\n");
		}
	}
	else{ /* parent process */
		if(wait(NULL) == -1){
			printf("Wait has failed\n"); //Parent process will wait for the child to complete
		}else{
			printf("Child complete\n");
		}
	}

	return 0;
}
