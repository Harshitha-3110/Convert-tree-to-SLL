#include<stdio.h>

int main()
{
    char str[50];
    printf("Enter string: ");
    scanf("%[^\n]",str);
    int i,j,k=1;
    for(i=0,j=i+1;str[i]!='\0';)
    {
        if(str[i]==str[j])
        {
        k=j;  //to track j position
        while(str[j+1]!='\0'){  //shift next index to previous when duplicate found
        str[j]=str[j+1];
        j++;
        }
        str[j]='\0';
        if(str[j]=='\0' && str[k] == '\0'){
        i++;
        j=i+1;
        }
        else if(str[j]=='\0' && str[k] != '\0')
        j=k;   
        }
        else{
        if(str[j]!='\0')
        j++;
        else{ 
        i++;
        j=i+1;
        }
        }
        }
    printf("%s\n",str);
    return 0;
}