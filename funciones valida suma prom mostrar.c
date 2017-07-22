#include<stdio.h>
#include<conio.h>
#define n 50
int valida(int,int);
int fsuma(int,int);
float fpromedio(int,int);
void fmostrar(float);
void main()
    {
    int sum,cont,i,dato;
    float prom;
    sum=cont=0;
    for(i=0;i<n;i++)
        {
        dato=valida(-15,45);
        if(dato>0)
            {
            sum=fsuma(dato,sum);
            cont++;
            }
        }
    prom=fpromedio(sum,cont);
    fmostrar(prom);
    getch();
    }
int valida(int li,int ls)
    {
    int d;
    do
        {
        printf("\n Ingrese un dato: \n\t");
        scanf("%d",&d);
        }
    while(!(d>=li&&d<=ls));
    return d;
    }
int fsuma(int a,int b)
    {
    int s;
    s=a+b;
    return s;
    }
float fpromedio(int a,int b)
    {
    float p;
    if(b!=0)
        p=(float)a/b;
    else
        p=0;
    return p;
    }
void fmostrar(float a)
    {
    printf("\n Promedio: %.2f \n\n",a);
    }
