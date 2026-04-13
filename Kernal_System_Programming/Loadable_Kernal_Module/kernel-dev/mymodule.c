#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NANI");
MODULE_DESCRIPTION("Simple Kernel Module");

static int __init mymodule_init(void) {
  pr_info("NANI: Kernel Module Loaded!\n");
  return 0;
}

static void __exit mymodule_exit(void) {
  pr_info("NANI: Kernel Module Removed!\n");
}

module_init(mymodule_init);
module_exit(mymodule_exit);
