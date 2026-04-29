#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meesala");
MODULE_DESCRIPTION("Module B");

extern int add(int, int);
extern int sub(int, int);
extern int mul(int, int);
extern int div(int, int);
extern int mod(int, int);

static int __init module_b_init(void) {
  printk(KERN_INFO "Module B is loaded\n");
  int res;
  printk(KERN_INFO "add(20,10)=%d\n", res);
  res = sub(20, 10);
  printk(KERN_INFO "sub(20,10)=%d\n", res);
  res = mul(20, 10);
  printk(KERN_INFO "mul(20,10)=%d\n", res);
  res = div(20, 10);
  printk(KERN_INFO "div(20,10)=%d\n", res);
  res = mod(20, 10);
  printk(KERN_INFO "mod(20,10)=%d\n", res);

  return 0;
}

static void __exit module_b_exit(void) {
  printk(KERN_INFO "Module B is unloaded\n");
}

module_init(module_b_init);
module_exit(module_b_exit);
