#include<stdio.h>
#include <math.h>
int coff[5];
int power[5];
int d;
void fun()
{
     int x,y,i;
    for(i=0;i<=d;i++)
     {
         printf("enter coefficient and power of x%d:",i+1);
         scanf("%d%d",&x,&y);
         coff[i]=x;
         power[i]=y;
     }
}
float funv(float x)
{
    float sum=0.00;
   int i;
   for(i=0;i<=d;i++){
       sum=sum+(coff[i]*pow(x,power[i]));
   }
   return sum;
}

float bd(float x,float h)
{
    float xhp,xhm;
    xhp=funv(x+h);
    xhm=funv(x-h);
    return (xhp-xhm)/(2*h);
}
int main()
{
    float x,h;
     printf("enter degree of equation:");
     scanf("%d",&d);
     printf("enter the value of x and h:");
     scanf("%f%f",&x,&h);
     fun();
    printf("1 st derivative:%f\n",bd(x,h));
     return 0;
}