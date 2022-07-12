#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char arr[15];
    int n[4],i=0;
    char *num,ch;
    printf("Enter ip address\n");
    scanf("%s",arr);
    num=strtok(arr,".");
    while(num!=NULL)
    {
        n[i++]=atoi(num);
        num=strtok(NULL,".");
    }
    for(i=0;i<4;i++)
    {
        if(n[i]<0||n[i]>255)
        {
            printf("Invalid IP\n");
            return -1;
        }
    }
    if(n[0]>=0&&n[0]<128)
      ch=1;
    if(n[0]>=128&&n[0]<192)
      ch=2;
    if(n[0]>=192&&n[0]<224)
      ch=3;
    if(n[0]>=224&&n[0]<256)
      ch=4;
    
    switch(ch)
    {
        case 1: {printf(" Class A\n Network Id: %d.0.0.0\n Host ID: 0.%d.%d.%d",n[0],n[1],n[2],n[3]);
                 break;}
        case 2: {printf(" Class B\n Network Id: %d.%d.0.0\n Host ID: 0.0.%d.%d",n[0],n[1],n[2],n[3]);
                 break;}
        case 3: {printf(" Class A\n Network Id: %d.%d.%d.0\n Host ID: 0.0.0.%d",n[0],n[1],n[2],n[3]);
                 break;}
        case 4: {printf(" Not Apllicable\n");
                 break;}
    }
}