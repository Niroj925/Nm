#include<stdio.h>
float f[10];
float df[10];
float dfs[10];
float dfq[10];
float dp[10];
int main()
{
    int i,j,n;
    float res=0.00,x;
    printf("enter the no. of data point:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter data point:");
        scanf("%f",&dp[i]);
           printf("enter data point value:");
        scanf("%f",&f[i]);
    }
  printf("enter interpolate value: ");
  scanf("%f",&x);
  for(i=0; i<n-1; i++)
  {
      df[i]=(f[i+1]-f[i])/(dp[i+1]-dp[i]);
  }
   for(i=0; i<n-2; i++)
  {
      dfs[i]=(df[i+1]-df[i])/(dp[i+2]-dp[i]);
  }
     for(i=0; i<n-3; i++)
  {
      dfq[i]=(dfs[i+1]-dfs[i])/(dp[i+3]-dp[i]);
  }
  res=f[0]+((x-dp[0])*df[0])+((x-dp[0])*(x-dp[1])*dfs[0])+((x-dp[0])*(x-dp[1])*(x-dp[2])*dfq[0]);
  printf("output:%f\n",res);
  return 0;
}