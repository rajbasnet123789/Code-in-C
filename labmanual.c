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
 int t; 
    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t--) {  
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
    }
    return 0;
}*/







// question3 
/*#include<stdio.h>
int main()
{
 int t; 
    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t--) {
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
    }
   
}*/


//question 4
/*#include<stdio.h>

int main()
{
  
        int n;
        int c = 0;
        printf("Enter the size of matrix: ");
        scanf("%d", &n);
        int arr[n][n];
        printf("Enter the elements of the matrix:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        int target;
        printf("Enter the target value: ");
        scanf("%d", &target);
        int i = 0;
        int j = n - 1;
        while (i < n && j >= 0) {
            if (arr[i][j] < target) {
                i++;
            } else if (arr[i][j] > target) {
                j--;
            } else {
                c = 1;
                break;
            }
        }
        if (c == 0) {
            printf("Not present\n");
        } else {
            printf("Present\n");
        }
    

    return 0;
}*/








// question 5
/*#include<stdio.h>
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

}*/





 #include<stdio.h>
    
    void reverse(int *arr, int n) {
     for (int i = 0, j = n - 1; i < j; ++i, --j) {
         int temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
     }
 }

 int main()
 {
  int t; 
    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    while (t--) {
 int n;
    printf("enter the size of array");
   scanf("%d",&n);
   int arr[n];
   printf("enter the element of array:");
     for(int i=0;i<n;i++)
    {      
          scanf("%d",&arr[i]);
        }

    int d;
     printf("enter the time to rotate");
    scanf("%d",&d);
    d=d%n;
     reverse(arr, d);
     reverse(arr + d, n - d);
    reverse(arr, n);

     for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
        }
     }}
    




