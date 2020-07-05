#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int fd = open ("test.txt", O_RDWR | O_CREAT, 0666);
	char *buf =  (char*)malloc(10);
	buf = "dsdsdsd23a";
	printf ("%d\n", lseek(fd, 0, SEEK_CUR));
	write (fd, buf, 10);
	printf ("%d\n", lseek(fd, 0, SEEK_SET));
//printf ("%d", ftell(fd));
	buf = "";
	int ret = read(fd,buf,10);
	printf ("%s\n", buf);
	close (fd);
}
