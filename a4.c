//question 6
#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int arr[n][n];
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
scanf("%d",&arr[i][j]);
}
}

int startingrow=0;
int startingcol=0;
int endingrow=n-1;
int endingcol=n-1;
int k=0;
while(k<=(n*n)-4)
{

int prev=arr[startingrow][startingcol];
int prev1,prev2,prev3;
prev1=arr[startingrow][endingcol];
prev2=arr[endingrow][endingcol];
prev3=arr[endingrow][startingcol];
for(int j=startingcol+1;j<=endingcol;j++)
{
int temp=arr[startingrow][j];
arr[startingrow][j]=prev;
prev=temp;
k++;

}

for(int i=startingrow+1;i<=endingrow;i++)
{
int temp=arr[i][endingcol];
arr[i][endingcol]=prev1;
prev1=temp;
k++;
}

for(int j=endingcol-1;j>=startingcol;j--)
{
int temp=arr[endingrow][j];
arr[endingrow][j]=prev2;
prev2=temp;
k++;
}

for(int i=endingrow-1;i>=startingrow;i--)
{
int temp=arr[i][startingcol];
arr[i][startingcol]=prev3;
prev3=temp;
k++;
}
startingrow++;
endingrow--;
startingcol++;
endingcol--;
}


for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
printf("%d ",arr[i][j]);
}
printf("\n");
}

return 0;
}

// question 5
/*#include <stdio.h>
#include <limits.h>



int main() {
    int m, n;
    printf("Enter the size of the matrix (rows and columns): ");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int max_row_index = -1;
    int j = n - 1;

    for (int i = 0; i < m; i++) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            max_row_index = i; 
        }
    }
   
    if (max_row_index != -1) {
        printf("Row with the maximum number of 1s is: %d\n", max_row_index + 1);
    } else {
        printf("No 1s found in the matrix.\n");
    }
    return 0;
}*/
