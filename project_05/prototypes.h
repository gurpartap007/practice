#ifndef __proto
#define __proto
#include"header.h"
int devopen(struct inode *,struct file *filep);
int devrelease(struct inode *,struct file *filep);
ssize_t devwrite(struct file *filep,const char __user *buffer,size_t size,loff_t *);
struct ScullQset * createqset(int);
int createquantum(int);

#endif
