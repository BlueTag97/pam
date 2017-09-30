#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/get_pid_info.h>

#define SYS_GET_PID_INFO 548

int get_pid_info(struct pid_info *ret, int pid)
{
	return syscall(SYS_GET_PID_INFO, ret, pid);
}

int main(int argc, char **argv)
{
	struct pid_info	pid;

	if (argc == 2)
	{
		if (0 == get_pid_info(&pid, atoi(argv[1])))
		{
			printf("%s\n", pid.name);
		}
	}
	return 0;
}
