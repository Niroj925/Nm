#include<stdio.h>
float up[10];
float lw[10];
float dp[10];
float funv[10];
float term[10];
int main()
{
    int i,j;
    float res=0.00,x;
    for(i=0;i<4;i++){
        printf("enter data point:");
        scanf("%f",&dp[i]);
           printf("enter data point value:");
        scanf("%f",&funv[i]);
        up[i]=1;
        lw[i]=1;
    }
  printf("enter interpolate vlaue: ");
  scanf("%f",&x);
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        {
        if(i!=j){
        up[i]=up[i]*(x-dp[j]);
        lw[i]=lw[i]*(dp[i]-dp[j]);
        }
        }
        term[i]=funv[i]*(up[i]/lw[i]);
        res=res+term[i];
    }
    printf("\n");
      for(i=0;i<4;i++){
        printf("%f",dp[i]);
        printf("=>%f\t\n",funv[i]);
    }
    printf("\n");
    for(i=0;i<4;i++)
    {
        printf("up:%f,lw:%f\n",up[i],lw[i]);
    }
    printf("\nres=%f,\n",res);
}