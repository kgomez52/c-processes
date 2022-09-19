#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>

int main(){

	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096;
	/* name of the shared memory object */
	const char *name = "OS_krgomez";
	/* strings written to shared memory */
	const char *message_0 = "Helo";
	const char *message_1 = "World!";

	/* shared memory file descriptor */
	int fd;
	/* pointer to shared memory object */
	char *ptr;

	/* create the shared memory object */
	if((fd = shm_open(name, O_CREAT | O_RDWR, 0666)) == -1){
		printf("shm_open Failed\n");
	}

	/* configure the size of the shared memory object */
	if(ftruncate(fd, SIZE) == -1){
		printf("Ftruncate Failed\n");
	}

	/* memory map the shared memory object */
	if((ptr = (char *)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) < 0){
		printf("mmap Failed\n");
	}

	/* write to the shared memory object */ 
	sprintf(ptr, "%s", message_0);
	ptr += strlen(message_0);
	sprintf(ptr, "%s", message_1);
	ptr+= strlen(message_1);

	return 0;
}
