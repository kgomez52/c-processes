#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>

int main(){

	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096;

	/* name of the shared memory object */
	const char *name = "OS_krgomez";

	/* shared memory file descriptor */
	int fd;

	/* pointer to shared memory object */
	char *ptr;

	/* open the shared memory object */
	if((fd = shm_open(name, O_RDONLY, 0666)) < 0){
		printf("shm_open failed\n");
	}

	/* memory map the shared memory object */
	if((ptr = (char *) mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0)) < 0){
		printf("mmap Failed\n");
	}

	/* read from the shared memory object */
	printf("%s\n", (char *)ptr);

	/* remove the shared memory object */
	shm_unlink(name);

	return 0;
}
