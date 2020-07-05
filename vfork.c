#include <unistd.h>

int main ()
{
	char *c_arr[4];
	c_arr[0] = "ls";
	c_arr[1] = "-l";
	c_arr[2] = "-t";
	c_arr[3] = "al";
	int c_pid = vfork();
	if (c_pid == 0) {
		execvp("/bin/ls", c_arr);
		_exit(0);
	}
	else 
		wait(c_pid);
}
