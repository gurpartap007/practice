#include"prototypes.h"
#include"declaration.h"
int createquantum(int noqr)
{



		#ifdef DEBUG
		printk(KERN_INFO"IN-->%s\n",__func__);
		#endif
		return 0;
}

struct ScullQset * createqset(int nosqr)
{

		#ifdef DEBUG
		printk(KERN_INFO"IN-->%s\n",__func__);
		#endif
struct ScullQset *lscullqset;
lscullqset=NULL;
	lscullqset=(struct ScullQset *)kmalloc(sizeof(struct ScullQset),GFP_KERNEL);

	if(!lscullqset)
	{	
		#ifdef DEBUG
		printk(KERN_ERR"error no scullqset found\n");
		#endif
		goto OUT;
	}

	return lscullqset;

OUT:
	#ifdef DEBUG
	printk(KERN_ERR"error cannot create scullqset\n");
	#endif
	return lscullqset;
	
		
}
ssize_t devwrite(struct file *filep,const char __user *buffer,size_t size,loff_t *loff_t)
{  	int quantum_size=8,qset_size=8, data_size=100,device_size=100;
	struct ScullDev *lsculldev;
	struct ScullQset *lscullqset;
	int nosqr;
	#ifdef DEBUG
	printk(KERN_INFO"write function%s\n",__func__);
	#endif


lsculldev=filep->private_data;
	lscullqset=NULL;
	if(!lsculldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR"error no sculldev found\n");
		#endif
		goto OUT;
	}
	lsculldev->quantum_size=quantum_size;
	lsculldev->qset_size=qset_size;
	lsculldev->data_size=data_size;
	lsculldev->device_size=device_size;

	if(lsculldev->scullqset)
{	nosqr = size/(quantum_size*qset_size);

	if(size%(quantum_size*qset_size))
	nosqr++;
		#ifdef DEBUG
		printk(KERN_ERR"no of scullqset require =%d\n",nosqr);
		#endif
	lscullqset=createqset(nosqr);
}
	if(!lscullqset)
	{	
		#ifdef DEBUG
		printk(KERN_ERR"error no scullqset found\n");
		#endif
		goto OUT;
	}
	if(lscullqset->data)
	{
	int noqr;
	//char *quantum;
	noqr=size/quantum_size;
	createquantum(noqr);
	
	
	}
OUT: 
	#ifdef DEBUG
	printk(KERN_ERR"error \n");
	#endif
	return -1;

return 0;
}
