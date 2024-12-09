#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int *arr;
    int size;
    int top;
}stack;
stack* create_stack(int n)
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->size=n;
    s->top=-1;
    s->arr=(int*)malloc(sizeof(int)*n);
}
void push(stack* s,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow");
        return;
    }
    st->arr[++(st->top)];
}
int pop(stack*s)
{
    if(s->top==-1)
    {
        return -1;
    }
    return st->arr[(st->top)--];
}
char peek(stack *s)
{
    return s->arr[st->top];
}
bool is_empty(stack *s){
    return st->top==-1;
}
bool valid_paranthesis(char *s)
{
    int n=strlen(s);
      stack *st=create_stack(n)
    for(int i=0;i<n;i++)
    {
         if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(st,s[i]);
         }
         else if(!is_empty(s) && ((peek(st)=='(' && s[i]==')' ) || (peek(st)=='{' && s[i]=='}')||(peek(st)=='[' && s[i]==']')))
         {
             pop(st);
         }
         else
         {
            return false;   
         }

    }
    return is_empty(st);
}