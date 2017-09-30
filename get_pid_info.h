#ifndef _GET_PID_INFO_H_
#define _GET_PID_INFO_H_

struct pid_info {
	char *name;
	long pid;
	long state;
};

asmlinkage long sys_get_pid_info(struct pid_info *ret, int pid);

#endif
