#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init my_module_init(void) {
  printk(KERN_INFO "Hello World\n");
  return 0;
}

static void __exit my_module_exit(void) { printk(KERN_INFO "Goodbye World\n"); }

module_init(my_module_init);
module_exit(my_module_exit);
