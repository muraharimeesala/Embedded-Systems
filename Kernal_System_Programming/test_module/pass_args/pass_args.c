#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

char *name = "Murahari";
module_param(name, charp, 0660);
MODULE_PARM_DESC(name, "An String Value");
int age = 25;
module_param(age, int, 0660);
MODULE_PARM_DESC(age, "An Integer Value");

static int __init param_init(void) {
  printk("String: %s\n", name);
  printk("Age: %d\n", age);
  return 0;
}

static void __exit param_exit(void) { printk("Parameters Module Removed\n"); }

module_init(param_init);
module_exit(param_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Murahari");
MODULE_DESCRIPTION("Module demonstrating parameter passing");
