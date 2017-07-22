#include<stdio.h>
#include<conio.h>
#include<locale.h>
int menor(int,int,int);
void par(int,int,int);
int factorial(int);
float promedio(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int a,b,c,i,men,fact;
    float prom;
    i=1;
    do
        {
        printf("\n\n Ingrese una terna de números enteros positivos, de a uno, \n confirmando cada uno con enter \n\n");
        do
            {
            scanf("%d%d%d",&a,&b,&c);
            }
        while(a<0||b<0||c<0);
        men=menor(a,b,c);
        printf("\n\n El menor de la terna %d es %d \n\n",i,men);
        par(a,b,c);
        fact=factorial(men);
        printf("\n\n El factorial del menor es %d \n\n",fact);
        if(i%2!=0)
            {
            prom=promedio(a,b,c);
            printf("\n\n El promedio de la terna %d es %8.2f \n\n",i,prom);
            }
        if(a==b&&b==c)
            i=30;
        else
            i++;
        }
    while(i<30);
    getch();
    }
int menor(int a,int b,int c)
    {
    int min;
    if(a<b)
        min=a;
    else
        min=b;
    if(c<min)
        min=c;
    return min;
    }
void par(int a,int b,int c)
    {
    if(a%2==0)
        printf("\n\n %d es par \n\n",a);
    if(b%2==0)
        printf("\n\n %d es par \n\n",b);
    if(c%2==0)
        printf("\n\n %d es par \n\n",c);
    }
int factorial(int x)
    {
    int f,j;
    f=1;
    for(j=1;j<=x;j++)
        f*=j;
    return f;
    }
float promedio(int x,int y,int z)
    {
    float pr;
    pr=(x+y+z)/3;
    return pr;
    }
