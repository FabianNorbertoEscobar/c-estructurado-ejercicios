#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 30
int control(int,int,int);
int menor(int,int,int);
void par(int,int,int);
int factorial(int);
float promedio(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,band,a,b,c,men,fact;
    float prom;
    i=1;
    band=0;
    do
        {
        if(band==1)
            printf("\n La terna ingresada es incorrecta. Reingrésela \n");
        printf("\n Ingrese los tres valores de la terna, de a uno, \n y confirmando cada uno con enter: \n\n");
        scanf("%d%d%d",&a,&b,&c);
        band=1;
        }
    while(!control(a,b,c));
    while((a!=b&&b!=c&&a!=c)&&i<=tope)
        {
        men=menor(a,b,c);
        band=0;
        printf("\n El menor valor de la terna es %d \n\n",men);
        printf("\n Pares \n");
        par(a,b,c);
        fact=factorial(men);
        printf("\n El factorial del menor valor de la terna es %d \n\n",fact);
        if(i%2!=0)
            {
            prom=promedio(a,b,c);
            printf("\n\n El promedio de la terna %d es %.2f \n\n",i,prom);
            }
        do
            {
            if(band==1)
                printf("\n La terna ingresada es incorrecta. Reingrésela \n");
            printf("\n Ingrese los tres valores de la terna, de a uno, \n y confirmando cada uno con enter: \n\n");
            scanf("%d%d%d",&a,&b,&c);
            band=1;
            }
        while(!control(a,b,c));
        i++;
        }
    getch();
    }
int control(int x,int y,int z)
    {
    if(x>0&&y>0&&z>0)
        return 1;
    else
        return 0;
    }
int menor(int x,int y,int z)
    {
    int men;
    if(x>y)
        men=y;
    else
        men=x;
    if(z<men)
        men=z;
    return men;
    }
void par(int x,int y,int z)
    {
    int cont;
    cont=0;
    if(x%2==0)
        {
        printf("\n %d",x);
        cont++;
        }
    if(y%2==0)
        {
        printf("\n %d",y);
        cont++;
        }
    if(z%2==0)
        {
        printf("\n %d",z);
        cont++;
        }
    if(cont==0)
        printf("\n No hubo números pares \n\n");
    }
int factorial(int x)
    {
    int fact,i;
    fact=1;
    for(i=0;i<=x;i++)
        fact*=i;
    return fact;
    }
float promedio(int x,int y,int z)
    {
    float pr;
    pr=(float)(x+y+z)/3;
    return pr;
    }
