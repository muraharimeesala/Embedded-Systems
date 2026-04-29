#include  <linux/init.h>
#include  <linux/module.h>
#include  <linux/kernel.h>
#include  <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define  DEVICE_NAME  "sample"
#define  DEVICE_MAJOR  42
#define  DEVICE_MINOR  0
#define  NO_DEVICE 1

#define  BUFFER_SIZE  1024

static int  device_open(struct inode *, struct file *);
static int  device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *file, char __user *buffer,size_t count, loff_t *offset);
static ssize_t device_write(struct file *file,const char __user *buffer,size_t count, loff_t *offset);

static struct file_operations  fops = {
	.owner   = THIS_MODULE,
	.open    = device_open,
	.release = device_release,
	.read    = device_read,
	.write   = device_write
};

typedef struct {
	char  buffer[BUFFER_SIZE];
	int  nobytes;
	struct cdev  my_dev;
}  device_t;

static device_t  device;

static int device_open(struct inode *inode, struct file *file){
	printk(KERN_INFO "device_opened\n");
	file->private_data = &device;
	return  0;
}
static int device_release(struct inode *inode, struct file *file){
	printk(KERN_INFO "device_released\n");
	return 0;
}

static ssize_t device_read(struct file *file, char __user *buffer, size_t count,loff_t *offset){
	printk(KERN_INFO "Data read from user space\n");
	device_t *dev=file->private_data;
	if(count > dev->nobytes){
		count = dev->nobytes;
	}
	if(copy_to_user(buffer,dev->buffer,count)){
		return -EFAULT;
	}
	printk(KERN_INFO "Data sent to user space\n");
	
	return  count;
}

static ssize_t device_write(struct file *file, const char __user *buffer, size_t count,loff_t *offset){
	printk(KERN_INFO "Data written to user space\n");
	device_t *dev = file->private_data;
	if(count > BUFFER_SIZE){
		count = BUFFER_SIZE;
	}
	if(copy_from_user(dev->buffer,buffer,count)){
		return -EFAULT;
	}
	dev->nobytes=count;
	printk(KERN_INFO "Data received from kernel space\n");
	return count;
	
}

static int __init mycharmod_init(void){
	dev_t devno;
	devno = MKDEV(DEVICE_MAJOR,DEVICE_MINOR);
	int ret = register_chrdev_region(devno,NO_DEVICE,DEVICE_NAME);
	if(ret<0){
		printk(KERN_INFO "register_chrdev_region failed\n");
		return ret;
	}
	cdev_init(&device.my_dev,&fops);

	ret = cdev_add(&device.my_dev,devno,NO_DEVICE);
	if(ret<0){
		printk("cdev_add failed\n");
		unregister_chrdev_region(devno,NO_DEVICE);
		return ret;
	}
	printk(KERN_INFO "Character device registered succesfully\n");
	return 0;
}

static void __exit mycharmod_exit(void){
	dev_t devno;
	devno = MKDEV(DEVICE_MAJOR,DEVICE_MINOR);
	cdev_del(&device.my_dev);
	unregister_chrdev_region(devno,NO_DEVICE);

	printk(KERN_INFO "Character device unrigstered successfully\n");

}
module_init(mycharmod_init);
module_exit(mycharmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NANI");
MODULE_DESCRIPTION("Simple Character Driver");

