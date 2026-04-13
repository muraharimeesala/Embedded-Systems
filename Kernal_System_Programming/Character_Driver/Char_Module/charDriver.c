#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NANI");
MODULE_DESCRIPTION("Simple Character Driver");

static int __init mymod_init(void) {
  dev_t devno;
  int ret;
  devno = MKDEV(42, 0);
  ret = register_chrdev_region(devno, 1, "mydev");
  if (ret < 0) {
    printk("Failed to register the driver as char driver\n");
  }
  printk("Device number registerd successfully\n");
  return 0;
}

static void __exit mymod_exit(void) {
  dev_t devno;
  devno = MKDEV(42, 0);
  unregister_chrdev_region(devno, 1);
  printk("Device number is unregistered\n");
}

module_init(mymod_init);
module_exit(mymod_exit);
