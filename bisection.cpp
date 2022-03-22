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
float func(float x)
{
    float sum=0.00;
   int i;
   for(i=0;i<=d;i++){
       sum=sum+(coff[i]*pow(x,power[i]));
   }
   return sum;
}
float error(float x,float y){
return (y-x)/x;
}
float root(float x1,float x2)
{
    if(func(x1)*func(x2)<0)
    {
    float xl=x1,xu=x2,xm,err,vxm;
    printf("xl\t\txu\t\txm\t\tf(xm)\t\terror\n");
    do {
         xm=(xl+xu)/2;
        vxm=func(xm);
        err=error(xl,xu);
       // printf("%f\n")
       printf("%f\t%f\t%f\t%f\t%f\n",xl,xu,xm,vxm,err);
       vxm>0?xu=xm:xl=xm;
    }while(err>0.00001);
return xm;
    }
    else
    {
        printf("root is not possibe.\n");
        return 0;
    }
}
int main()
{
    float x1,x2;
     printf("enter degree of equation:");
     scanf("%d",&d);
     printf("enter intial guess(x1,x2):");
     scanf("%f%f",&x1,&x2);
     fun();
      //printf("%f\n",pow(coff[1],power[1]));
     printf("%f\n",func(2.00));
    printf("root:%f\n",root(x1,x2));
     return 0;
}