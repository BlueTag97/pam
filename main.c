#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

#define SYS_GET_PID_INFO 548

long	get_pid_info(int pid)
{
	return syscall(SYS_GET_PID_INFO, pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 2)
		if ((pid = atoi(argv[1])) > 0)
			get_pid_info(pid);
	return 0;
}
