#include<stdio.h>
#include<conio.h>
void main()
    {
    int a,b,c,s;
    printf("\n Ingrese valor a: \n\t");
    scanf("%d",&a);
    printf("\n Ingrese valor b: \n\t");
    scanf("%d",&b);
    printf("\n Ingrese valor c: \n\t");
    scanf("%d",&c);
    s=a+b+c;
    if(s>1000)
        printf("\n Mucho \n");
    else
        printf("\n Poco \n");
    getch();
    }
