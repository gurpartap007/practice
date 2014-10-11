#include"header.h"
#include"declaration.h"
void __exit cleanup(void)
{
int i;
#ifdef DEBUG
printk(KERN_INFO"This is exit function=%s\n",__func__);
#endif
for(i=0;i<nod;i++)
{

cdev_del(&(sculldev[i].c_dev));
#ifdef DEBUG
printk("value of minor%d",i);
#endif
}
kfree(sculldev);
unregister_chrdev_region(dev,nod);
#ifdef DEBUG
printk(KERN_INFO"bye kernel\n");
#endif
}
module_exit(cleanup);
