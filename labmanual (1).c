//question 2

/*#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int minimumdistance(int arr[],int n,int a,int b)
{
    int distance=INT_MAX;
    int pos_a=-1;
    int pos_b=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a && pos_a<i)
        {
            pos_a=i;
        }
        if(arr[i]==b && pos_b<i)
        {
            pos_b=i;
        }
        if(pos_a!=-1 && pos_b!=-1 && distance>abs(pos_a-pos_b))
        {
            distance=abs(pos_a-pos_b);
        }

    }
    return distance;
}








int main()
{   
  int n;
   printf("enter the size of array");
  scanf("%d",&n);
  int arr[n];
  printf("enter the element of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
printf("enter the point a and b:");
int a,b;
scanf("%d",&a);
scanf("%d",&b);
int x=minimumdistance(arr,n,a,b);
printf("%d",x);
}*/







// question3 
/*#include<stdio.h>
int main()
{
     int n;
   printf("enter the size of array");
  scanf("%d",&n);
  int arr[n];
  printf("enter the element of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int dup=0;
      for(int i=0;i<n;i++)
    {
        dup=dup^arr[i];
    }
    printf("%d",dup);
   
}*/



//question 4
/*#include<stdio.h>
int main()
{
     int n;
     int c=0;
   printf("enter the size of array");
  scanf("%d",&n);
  int arr[n][n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);
    }
  }
  int target;
  scanf("%d",&target);
int i=0;
int j=n-1;
while(i<n)
{
    if(arr[i][j]<target)
    {
       i++;
    }
    else if(arr[i][j]>target)
    {
        j--;
    }
    else
    { if(arr[i][j]==target)
    {
     c=1;
     break;
    }
    }
}
if(c==0)
{
    printf("not present");
}
else 
{
    printf("present");
}


}*/







// question 5
#include<stdio.h>
#include<limits.h>
int main()
{
    
     int n,m;
   printf("enter the size of array");
  scanf("%d%d",&m,&n);
  int arr[m][n];
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);
    }
  }
  int maxi=INT_MIN;
int i=0;
int j=n-1;
int c;
int k;
while(i<n)
{
    if(arr[i][j]==1 && arr[i][j]>arr[i][j-1])
    {
        c++;
        i++;
    }
    else if(arr[i][j]==0)
    {
        c=0;
        i++;
    }
    else if(arr[i][j]==arr[i][j-1])
    {
        j--;
        c++;
    }
    
    if(maxi<c)
    {
        maxi=c;
        k=i;
    }
    
}
printf("%d%d",maxi,k);

}