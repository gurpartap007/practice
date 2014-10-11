#include<stdio.h>
#pragma pack(1)
struct data
{
double j;
long int k;
int a;
int jj;
char b,c,d,e;
char kk,ll,mm,nn,dd;
};
int main()
{
struct data item;
printf("size of structure is %d\n",sizeof(item));

return 0;
}
