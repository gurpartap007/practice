#ifndef __fileopr
#define __fileopr
#include"prototypes.h"
struct file_operations fops=
{

open:devopen,
release:devrelease,
write:devwrite

};
#endif
