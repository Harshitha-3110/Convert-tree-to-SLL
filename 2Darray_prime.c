/*Find 5th prime no from starting of corresponding array element*/
#include<stdio.h>

int fifth_prime(int num);
int is_prime(int n);

int main()
{
    int arr[2][3]={3,5,7,9,11,13};
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            arr[i][j]=fifth_prime(arr[i][j]);
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
return 0;
}
int fifth_prime(int num)
{
    num++;
    int count=0;
    while(count<5){
    if(is_prime(num))
        count++;
    if(count<5)
        num++;
    }
    return num;
}
int is_prime(int n)
{
    for(int i=2;(i*i)<=n;i++)
    {
        if(n%i == 0)
        return 0;
    }
    return 1;
}