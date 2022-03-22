#include<stdio.h>
#include <math.h>
int coff[5];
int power[5];
float fun_v[10];
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
void find_funv(int n,float h)
{
    int i;
   float  hh=0;
    for(i=0;i<=n;i++){
        hh=hh+h;
    fun_v[i]=funv(hh);
    }
}
float simpson(int n,float h)
{
    int i;
    float os=0,es=0;
  for(i=1;i<n;i++){
      if(i%2==0)
      {
          es=es+fun_v[i];
      }
      else
      {
      os=os+fun_v[i];
      }
  }
  return (h/3)*(fun_v[0]+(2*es)+(2*os)+fun_v[n]);
}
int main()
{
    float a,b,n,h;
     printf("enter degree of equation:");
     scanf("%d",&d);
     printf("enter the value of a and b:");
     scanf("%f%f",&a,&b);
     printf("enter the value of n:");
     scanf("%f",&n);
     h=(b-a)/n;
     fun();
     find_funv(n,h);
    printf("required output:%f\n",simpson(n,h));
     return 0;
}