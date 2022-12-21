#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ayush Chauhan");
MODULE_VERSION("0.01");

int pid = 0;

module_param(pid,int,0);

static int __init kmd_init(void) {
 pid_t task_pid ;
 uid_t task_uid ;
 pid_t task_pgid;
 struct task_struct *task;
 task = pid_task(find_vpid(pid), PIDTYPE_PID);
 if(!task)
 {
    return -ESRCH;
 }
 task_pid = task->pid;
 task_uid = task->cred->uid.val;
 task_pgid = task->group_leader->pid;
 printk(KERN_INFO "pid: %d\n",task_pid);
 printk(KERN_INFO "uid: %d\n",task_uid);
 printk(KERN_INFO "pgid: %d\n",task_pgid);
 printk(KERN_INFO "comm: %s\n",task->comm);
 return 0;
}
static void __exit kmd_exit(void) {
 printk(KERN_INFO "Bye\n");
}
module_init(kmd_init);
module_exit(kmd_exit);