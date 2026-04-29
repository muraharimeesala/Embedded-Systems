#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "MultiDeviceDrivers"
#define DEVICE_MAJOR 42
#define DEVICE_NUMS 3
#define DEVICE_BUFFER_SIZE 1024

typedef struct {
	char buffer[DEVICE_BUFFER_SIZE];
	int nobytes;
	struct cdev my_cdev;
} my_device_t;

static int my_open(struct inode *, struct file *);
static int my_release(struct inode *, struct file *);
static ssize_t my_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t my_write(struct file *, const char __user *, size_t, loff_t *);

static my_device_t my_device[DEVICE_NUMS];

struct file_operations my_fops = {
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_release,
};

static int my_open(struct inode *inode, struct file *file){
	int minor = iminor(inode);

	if(minor >= DEVICE_NUMS){
		return -ENODEV;
	}
	file->private_data  = &my_device[minor];
	printk(KERN_INFO "Device %d opened\n",minor);
	return 0;
}

static int my_release(struct inode *inode ,struct file *file){
	printk(KERN_INFO "Device %d closed\n",iminor(inode));
	return 0;
}

static ssize_t my_read(struct file *file ,char __user *buf,size_t count ,loff_t *offset){
	my_device_t *dev = file->private_data;
	printk(KERN_INFO "Read called, offset=%lld\n", *offset);

	/* EOF condition */
    	if (*offset >= dev->nobytes) {
        	printk(KERN_INFO "EOF reached\n");
        	return 0;
	}

	if(count > dev->nobytes - *offset){
		count  = dev->nobytes - *offset;
	}
	if(copy_to_user(buf,dev->buffer+*offset,count)){
		return -EFAULT;
	}
	*offset += count;
	printk(KERN_INFO "Read %zu bytes from device at offset %lld\n",count,*offset);
	return count;
}

static ssize_t my_write(struct file *file,const char __user *buf,size_t count,loff_t *offset){
	my_device_t *dev = file->private_data;

	if(count > DEVICE_BUFFER_SIZE){
		count = DEVICE_BUFFER_SIZE;
	}
	if(copy_from_user(dev->buffer,buf,count)){
		return -EFAULT;
	}
	dev->nobytes = count;
	*offset = 0;
	printk(KERN_INFO "Write %zu bytes to device\n",count);
	return count;
}

static int __init my_init(void){
	dev_t devno = MKDEV(DEVICE_MAJOR,0);
	int ret;

	ret = register_chrdev_region(devno,DEVICE_NUMS,DEVICE_NAME);
	if(ret < 0){
		printk(KERN_INFO "Device registration failed\n");
		return ret;
	}
	printk(KERN_INFO "Device registered\n");

	for(int i = 0;i < DEVICE_NUMS;i++){
		cdev_init(&my_device[i].my_cdev,&my_fops);
		my_device[i].my_cdev.owner = THIS_MODULE;
		my_device[i].nobytes = 0;
		
		ret = cdev_add(&my_device[i].my_cdev,MKDEV(DEVICE_MAJOR,i),1);
		if(ret < 0){
			printk(KERN_INFO "cdev_add failed\n");
			return ret;
		}
	}
	printk(KERN_INFO "MultiDeviceDrivers loaded\n");
	return 0;
}

static void __exit my_exit(void){
	dev_t devno = MKDEV(DEVICE_MAJOR,0);

	for(int i = 0;i < DEVICE_NUMS;i++){
		cdev_del(&my_device[i].my_cdev);
	}
	unregister_chrdev_region(devno,DEVICE_NUMS);
	printk(KERN_INFO "MultiDeviceDrivers unloaded\n");
	return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meesala");
MODULE_DESCRIPTION("MultiDeviceDrivers");

