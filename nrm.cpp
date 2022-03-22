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
float dfunv(float x)
{
    float sum=0.00;
   int i;
   for(i=0;i<=d;i++){
       sum=sum+(coff[i]*power[i]*pow(x,power[i]-1));
   }
   return sum;
}
float error(float x,float y){
return (x-y)/y;
}
float root(float x1)
{
    float xl=x1,xu,err,vxl,dvxl;
    printf("xl\t\txu\t\terror\n");
    do {
        vxl=funv(xl);
        dvxl=dfunv(xl);
        xu=xl-(vxl/dvxl);
        err=abs(error(xu,xl));
        printf("%f\t%f\t%f\n",xl,xu,err);
        xl=xu;
    }while(err>0.00001);
return xu;
}
int main()
{
    float x1;
     printf("enter degree of equation:");
     scanf("%d",&d);
     printf("enter intial guess(x1):");
     scanf("%f",&x1);
     fun();
    printf("root:%f\n",root(x1));
     return 0;
}