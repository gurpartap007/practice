#ifndef __header
#define __header
#include<linux/init.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/fs.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module for Character Driver\n");
MODULE_AUTHOR("KASHISH GARG");

#ifndef DEBUG
#define DEBUG
#endif
#ifndef DEVICE_NAME
#define DEVICE_NAME "KASHISHDEV"
#endif
struct ScullQset
{
void **data;
struct ScullQset *next;
};
struct ScullDev
{
struct ScullQset *scullqset;
struct cdev c_dev;
int quantum_size;
int qset_size;
int data_size;
int device_size;

}
;

#endif
