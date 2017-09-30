#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include "get_pid_info.h"

asmlinkage long sys_get_pid_info(struct pid_info *ret, int pid)
{
	struct task_struct *process;
	struct pid_info *info;

	for_each_process(process){
		if (process->pid == pid){
			info = kmalloc(sizeof(struct pid_info), GFP_KERNEL);
			if (info == NULL)
				return -1;
			info->pid = process->pid;
			info->name = process->comm;
			info->state = process->state;
			if (0 > copy_to_user(ret, info, sizeof(struct pid_info)))
				return -1;
			return 0;
		}
	}
	return -1;
}
