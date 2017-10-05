#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include "get_pid_info.h"

asmlinkage long sys_get_pid_info(int pid)
{
	struct task_struct *process;

	for_each_process(process){
		if (process->pid == pid){
			printk("%s\n", process->comm);
		}
	}
	return 0;
}
