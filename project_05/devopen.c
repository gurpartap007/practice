#include"prototypes.h"
/*
 int sculltrim(struct ScullDev *);
int sculltrim(struct ScullDev *fsculldev)
{
struct ScullQset *lscullqset,*bptrscullqset;
lscullqset=bptrscullqset=NULL;
if(!fsculldev)
{
	printk(KERN_ERR"error in fsculldev pointer\n");
	return -1;
}
if(!fsculldev->scullqset)
{
	printk(KERN_INFO"no scullqset\n");
}
while(bptrscullqset->next)
bptrscullqset=bptrscullqset->next;
return 0;
}*/
int devopen(struct inode *inodep,struct file *filep)
{
struct ScullDev *lsculldev;
//int ret;
#ifdef DEBUG
printk(KERN_INFO"hi i am open %s\n",__func__);
#endif
lsculldev=NULL;
lsculldev=container_of(inodep->i_cdev,struct ScullDev,c_dev);
if(!lsculldev)
{

#ifdef DEBUG
printk(KERN_ERR"\n");
#endif
}
filep->private_data=lsculldev;
if((filep->f_flags & O_ACCMODE)==O_WRONLY)
{
#ifdef DEBUG
printk(KERN_INFO"module open for write only\n");
#endif
/*ret=sculltrim(lsculldev);
if(ret<0)
{
	printk(KERN_ERR"error in sculltrim\n");
	goto OUT;
}*/
}


//OUT:
//	return -1;
return 0;
}
