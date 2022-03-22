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
return (x-y)/x;
}
float root(float x1,float x2)
{
    float xl=x1,xu=x2,xm,err;
    float vxl,vxu,dif;
    printf("xl\t\txu\t\txm\t\t\terror\n");
    do {
        vxl=func(xl);
        vxu=func(xu);
         dif=xu-xl;
         xm=xu-((vxu*dif)/(vxu-vxl));
        printf("%f\t%f\t%f\t%f\n",xl,xu,xm,err);
        xl=xu;
        xu=xm;
         err=abs(error(xu,xl));
       // printf("%f\n")     
    }while(err>0.00001);
return xm;
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