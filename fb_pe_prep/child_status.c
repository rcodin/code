#include <stdio.h>
#include <unistd.h>

int main ()
{
	int pid;
	int status = -11;
	pid = fork();
	if (pid) {
		wait(&status);
	}
	else {
		int *A;
		int m;
		A = &m;
		A = A + 10000;
		m = *A;

	}
	printf ("%d\n", status);
	return 0;
}
