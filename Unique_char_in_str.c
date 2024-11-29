/* Determine if string has unique characters or not*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 26

struct hash
{
    int index;
    char value;
    struct hash *link;
};

void create_hash(struct hash *arr);
int insert_hash(struct hash *arr, char ch);

int main()
{
    struct hash arr[SIZE];
    create_hash(arr);

    char str[30];
    fgets(str,sizeof(str),stdin);
    int size=strlen(str);
    if(str[size-1]=='\n')
    {
        str[size-1] = '\0';
        size--;
    }
    
    for(int i=0;i<size;i++)
    {
        str[i]=tolower(str[i]);
        int ret = insert_hash(arr, str[i]);
        if(ret)
        {
            printf("False\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
    
}
void create_hash(struct hash *arr)
{
    for(int i=0;i<SIZE;i++)
    {
        arr[i].index=i;
        arr[i].value=-1;
        arr[i].link=NULL;
    }
}
int insert_hash(struct hash *arr, char ch)
{
    int index = ch%97;
    if(arr[index].value == -1){
        arr[index].value=ch;
    return 0;
    }
    return 1;
}