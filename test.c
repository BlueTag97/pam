#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SYS_GET_PID_INFO 548

int get_pid_info(int pid)
{
	return syscall(SYS_GET_PID_INFO, pid);
}

int main(int argc, char **argv)
{
	if (argc == 2){
		if (0 == get_pid_info(atoi(argv[1])));
	}
	return 0;
}
