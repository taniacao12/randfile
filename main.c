#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // open
#include <unistd.h> // close
#include <time.h>

int main() {
	int fd_write, fd_read, size;

	printf("Generating random numbers: \n");
	int array[10];
	srand(time(NULL));
	for (int num = 0; num < 10; num++)
		array[num] = rand();
	
	for (int num = 0; num < 10; num++)
		printf("    random %d: %d\n", num, array[num]);

	printf("\nWriting numbers to file...\n");
	fd_write = open("file.txt", O_WRONLY | O_CREAT);
	size_t num_written = write(fd_write, &array, sizeof(array));
  	close(fd_write);

	printf("\nReading numbers from file...\n");
  	fd_read = open("file.txt", O_RDONLY | O_CREAT);
  	int copy[10];
  	size_t num_read = read(fd_read, &copy, sizeof(copy));
	close(fd_read);
 
	printf("\nVerification that written values were the same: \n");
	for (int num = 0; num < 10; num++)
		printf("    random %d: %d\n", num, copy[num]);

	return 0;

}
