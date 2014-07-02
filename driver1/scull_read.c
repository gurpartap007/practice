#include"header.h"
ssize_t scull_read(struct file *filep,char __user *buffer1,size_t count,loff_t *lseek)
{
struct sculldev *lsculldev;
struct scullqset *lscullqset;
int i,j=0,size=0;
lsculldev=filep->private_data;
lscullqset=lsculldev->scullqset;
printk(KERN_INFO"Address = %p\n",lscullqset);
   for(i=0;i<8;i++)
   {
  copy_to_user(buffer1+size,(char *)lscullqset->data[i],8);
  size=size+8;
   }
lscullqset=lscullqset->next;
printk(KERN_INFO"Address = %p\n",lscullqset);
{
   for(i=0;i<8;i++)
   {
  pr_info("I AM IN LOOP SECOND and value of size is %d\n",size);
  copy_to_user(buffer1+size,(char *)lscullqset->data[i],8);
  pr_info("data is %s\n",(char*)lscullqset->data[i]);
  size=size+8;
   }
j++;
}
lscullqset=lscullqset->next;
printk(KERN_INFO"Address = %p\n",lscullqset);
   for(i=0;i<8;i++)
   {
  copy_to_user(buffer1+size,(char *)lscullqset->data[i],8);
  size=size+8;
   }
printk(KERN_INFO"Characters read = %s\n",buffer1);
printk(KERN_INFO"size= = %d\n",size);
return 0;
}

