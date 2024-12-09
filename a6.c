#include<stdio.h>
#include<stdbool.h>
int code(char s)
{
if(s=='(')
{
return 1;
}
if(s=='{')
{
return 2;
}
if(s=='[')
{
return 3;
}
if(s==')')
{
return -1;
}
if(s=='}')
{
return -2;
}
if(s==']')
{
return -3;
}
}
void push(int arr[],int *top,int n,int value)
{
if((*top)==n)
{
printf("stack is full");
return;
}
else 
{
(*top)++;
arr[(*top)]=value;
}
}
char pop(int arr[],int *top)
{
if((*top)==-1)
{
printf("stack is empty");
}
else 
{
char x=arr[(*top)];
(*top)--;
return x;
}}
bool isempty(int top)
{
if(top==-1)
{
return true;
}
else 
{
return false;
}}
int main()
{
    int t;
    printf("enter no of testcase:");
    scanf("%d",&t);
    while(t--)
    {
int n;
printf("enter size of string");
scanf("%d",&n);

int flag=0;
int st[n];
char s[n];
scanf("%s",s);



int top=-1;
for(int i=0;i<n;i++)
{
if(code(s[i])>0)
{
push(st,&top,n,code(s[i]));
}
else if(!isempty(top) && st[top]+code(s[i])==0)
{
char a=pop(st,&top);
}
else
{
printf("not balanced");
flag=1;
break;
}
}
if(flag==0)
{
if(isempty(top))
{
printf("balanced\n");
}
else 
{
printf("unbalanced\n");
}
}
}
}



