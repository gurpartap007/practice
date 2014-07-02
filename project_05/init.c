#include"header.h"
#include"declaration.h"
#include"fops.h"
struct ScullDev *sculldev;
struct cdev *my_chrdev;
dev_t dev,newdev;
int nod=5,quantum_size=8,qset_size=8, data_size=100,device_size=100;
module_param(nod,int,S_IRUGO);
module_param(quantum_size,int,S_IRUGO);
module_param(qset_size,int,S_IRUGO);
module_param(data_size,int,S_IRUGO);
module_param(device_size,int,S_IRUGO);
	int i,major_no,minor_no;
	static int  initial(void)
{
	#ifdef DEBUG
	printk(KERN_INFO"This is initialisation function=%s\n",__func__);
	printk(KERN_INFO"hello kernel\n");
	#endif
	alloc_chrdev_region(&dev,0,nod,DEVICE_NAME);
	major_no=MAJOR(dev);
sculldev=(struct ScullDev *)kmalloc(sizeof(struct ScullDev)*nod,GFP_KERNEL);
	printk(KERN_INFO"memmory succesfull allocated %p",sculldev);
	if(!sculldev)
{
	#ifdef DEBUG
	printk(KERN_ERR"memory allocation for sculldev failed\n");
	goto OUT;
	#endif
}
for(i=0;i<nod;i++)
{
newdev=MKDEV(major_no,i);
printk("for scull[%d]major no is%d\n and minor no %d\n and dev is%d",i,major_no,i,newdev);
cdev_init(&sculldev[i].c_dev,&fops);
cdev_add(&sculldev[i].c_dev,newdev,1);
cdev_add(&sculldev[i].c_dev,newdev,quantum_size);
cdev_add(&sculldev[i].c_dev,newdev,qset_size);
cdev_add(&sculldev[i].c_dev,newdev,data_size);
cdev_add(&sculldev[i].c_dev,newdev,device_size);
}
return 0;
OUT:
	return -1;
}
module_init(initial);
