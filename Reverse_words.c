/* Reverse the words in a string*/
#include<stdio.h>
#include<string.h>

int top = 0;
void push(char *stack,char ch,int size);
void pop(char *stack, char *rev_str);

int main()
{
    char str[30]="hello world";
  /*  fgets(str, sizeof(str), stdin);
    
   if (str[size - 1] == '\n') { 
        str[size - 1] = '\0';  
        size--;
   }*/
   int size = strlen(str);
   // printf("%d\n",size);
    char stack[size];
    char rev_str[size];

   for (int i = 0; i <= (size); i++) {
    if(str[i]!=' ' && str[i]!='\0')
        push(stack, str[i], size);
    else
    pop(stack,rev_str);
    }
    
    rev_str[size]='\0';
    printf("%s\n",rev_str);
    
}
void push(char *stack,char ch,int size)
{
    if(top<size)
    stack[top++]=ch;
}
void pop(char *stack, char *rev_str)
{
    static int i = 0;
    while (top > 0) {
        rev_str[i++] = stack[--top];
    }
    rev_str[i++] = ' ';
    
}