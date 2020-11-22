#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Simone Perriello");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

static void
task_explore(void) {
  struct task_struct *ts;
  int pid, tgid;
  void *vstack;

  struct thread_struct tds;
  unsigned long vsp, vsp0, usp;

  ts = get_current();
  pid = ts->pid;
  tgid = ts->tgid;
  printk(KERN_INFO "PID %d\n", pid, tgid);
  vstack = ts->stack;
  printk(KERN_INFO "vstack is %p\n", vstack);

  tds = ts->thread;
  vsp = tds.sp;
  printk(KERN_INFO "sp = %lu\n", vsp);

  // Not working on recent Linux kernels
  /* vsp0 = tds.sp0; */
  /* printk(KERN_INFO "sp0 = %lu\n", vsp0); */
  /* usp = tds.usersp; */
  /* printk(KERN_INFO "up = %lu\n", usp); */
}

  static int __init axo_init(void) {
    // KERN_INFO is a flag to declare logging priority (note comma absence)
    printk(KERN_INFO "Inserted module axo\n");
    task_explore();
    return 0;
  }

  static void __exit axo_exit(void) {
    printk("Removed module axo\n");
    printk("Bye\n");
  }

  module_init(axo_init);
  module_exit(axo_exit);
