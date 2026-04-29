#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/wait.h>

#define MAJOR_NUM 42
#define MINOR_NUM 0
#define DEV_NAME  "mychrmod"
#define DEV_NUMS  1

DECLARE_WAIT_QUEUE_HEAD(wq);

// Function prototypes
static int dev_open(struct inode *, struct file *);
static int dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char __user *, size_t, loff_t *);

// Device structure
typedef struct {
    char buff[512];
    int noofbytes;
    struct cdev my_dev;
} mydev_t;

static mydev_t my_dev;

static struct file_operations fops = {
    .owner   = THIS_MODULE,
    .open    = dev_open,
    .release = dev_release,
    .read    = dev_read,
    .write   = dev_write,
};

// Module init
static int __init mychrmod_init(void)
{
    dev_t devno = MKDEV(MAJOR_NUM, MINOR_NUM);
    int ret;

    ret = register_chrdev_region(devno, DEV_NUMS, DEV_NAME);
    if (ret < 0) {
        printk("register_chrdev_region failed: %d\n", ret);
        return ret;
    }

    printk("Registered device major=%d minor=%d\n", MAJOR_NUM, MINOR_NUM);

    cdev_init(&my_dev.my_dev, &fops);

    ret = cdev_add(&my_dev.my_dev, devno, DEV_NUMS);
    if (ret < 0) {
        printk("cdev_add failed: %d\n", ret);
        unregister_chrdev_region(devno, DEV_NUMS);
        return ret;
    }

    printk("Character device added successfully\n");
    return 0;
}

// Module exit
static void __exit mychrmod_exit(void)
{
    dev_t devno = MKDEV(MAJOR_NUM, MINOR_NUM);

    cdev_del(&my_dev.my_dev);
    unregister_chrdev_region(devno, DEV_NUMS);

    printk("Device removed major=%d minor=%d\n", MAJOR_NUM, MINOR_NUM);
}

// Open
static int dev_open(struct inode *inode, struct file *file)
{
    printk("Device opened\n");
    file->private_data = &my_dev;
    return 0;
}

// Release
static int dev_release(struct inode *inode, struct file *file)
{
    printk("Device closed\n");
    return 0;
}

// Read
static ssize_t dev_read(struct file *file, char __user *buff, size_t count, loff_t *offset)
{
    mydev_t *dev = file->private_data;
    
    wait_event(wq, dev->noofbytes > 0);

    printk("Read requested: %zu bytes\n", count);

    if (dev->noofbytes == 0)
        return 0; // No data

    if (copy_to_user(buff, dev->buff, dev->noofbytes))
        return -EFAULT;

    int ret = dev->noofbytes;
    dev->noofbytes = 0; // Clear buffer

    return ret;
}

// Write
static ssize_t dev_write(struct file *file, const char __user *buff, size_t count, loff_t *offset)
{
    mydev_t *dev = file->private_data;

    printk("Write requested: %zu bytes\n", count);

    if (count > sizeof(dev->buff))
        count = sizeof(dev->buff);

    if (copy_from_user(dev->buff, buff, count))
        return -EFAULT;

    dev->noofbytes = count;
    wake_up(&wq);

    return count;
}

module_init(mychrmod_init);
module_exit(mychrmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meesala");
MODULE_DESCRIPTION("My Character Device Driver");
