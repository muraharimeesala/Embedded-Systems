#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meesala");
MODULE_DESCRIPTION("Module A");

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }

int mod(int a, int b) { return a % b; }

EXPORT_SYMBOL(add);
EXPORT_SYMBOL(sub);
EXPORT_SYMBOL(mul);
EXPORT_SYMBOL(div);
EXPORT_SYMBOL(mod);

static int __init module_a_init(void) {
  printk(KERN_INFO "Module A Loaded\n");
  return 0;
}

static void __exit module_a_exit(void) {
  printk(KERN_INFO "Module A Unloaded\n");
}

module_init(module_a_init);
module_exit(module_a_exit);
