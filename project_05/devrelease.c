#include"prototypes.h"
int devrelease(struct inode *inodep,struct file *filep)
{

printk(KERN_INFO"release");
return 0;
}
