#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int val = 10;
static char *msg = "Murahari";

module_param(val, int, 0644);
MODULE_PARM_DESC(val, "AN Integer Parameter");

module_param(msg, charp, 0644);
MODULE_PARM_DESC(msg, "A String Parameter");

static int __init pass_param_init(void) {
  printk("Passed Parameter Module Loaded\n");

  printk("Passed Parameter Value is %d\n", val);
  printk("Passed Parameter String is %s\n", msg);
  return 0;
}

static void __exit pass_param_exit(void) {
  printk("Passed Parameter Module Unloaded\n");

  printk("Passed Parameter Value is %d\n", val);
  printk("Passed Parameter String is %s\n", msg);
}

MODULE_LICENSE("GPL");

module_init(pass_param_init);
module_exit(pass_param_exit);
