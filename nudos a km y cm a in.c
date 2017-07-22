#include<stdio.h>
#include<conio.h>
#include<locale.h>
float leer1(void);
int leer2(void);
float nudosakmh(float);
float cmapulg(float);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cod;
    float m,res;
    m=leer1();
    cod=leer2();
    if(cod%2==0)
        {
        res=nudosakmh(m);
        printf("\n %.2f nudos es igual a %.2f km/h \n\n",m,res);
        }
    else
        {
        res=cmapulg(m);
        printf("\n %.2f cms es igual a %.2f pulgadas \n\n",m,res);
        }
    getch();
    }
float leer1(void)
    {
    float x;
    do
        {
        printf("\n Ingrese una medida de longitud: \t\t");
        scanf("%f",&x);
        }
    while(x<0);
    return x;
    }
int leer2(void)
    {
    int x;
    do
        {
        printf("\n Ingrese un código: \t\t");
        scanf("%d",&x);
        }
    while(x<0);
    return x;
    }
float nudosakmh(float x)
    {
    float y;
    y=1.6*x;
    return y;
    }
float cmapulg(float x)
    {
    float in;
    in=x/2.45;
    return in;
    }
