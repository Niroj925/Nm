#include<stdio.h>
float up[10];
float lw[10];
float dp[10];
float funv[10];
float term[10];
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
        scanf("%f",&funv[i]);
        up[i]=1;
        lw[i]=1;
    }
  printf("enter interpolate value: ");
  scanf("%f",&x);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
        if(i!=j){
        up[i]=up[i]*(x-dp[j]);
        lw[i]=lw[i]*(dp[i]-dp[j]);
        }
        }
        term[i]=funv[i]*(up[i]/lw[i]);
        res=res+term[i];
    }
    printf("\nres=%f,\n",res);
}