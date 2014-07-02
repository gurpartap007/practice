#include<stdio.h>
#include<fcntl.h>
int main()
{
int fd,ret;
char buff[]="hi write";
fd=open("emblogic",O_WRONLY);
ret=write(fd,buff,8);
printf("fd value is %d",fd);
printf("write this much%d",ret);return 0;
}
