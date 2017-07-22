#include<stdio.h>
#include<conio.h>
#include<locale.h>
int validadato(int,int,int);
int esfechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
int calculaedad(int,int,int,int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int da,ma,aa,dn,mn,an,i,n,leg,edad;
    do
        {
        printf("\n Ingrese la cantidad de alumnos: \t\t");
        scanf("%d",&n);
        }
    while(n<0);
    do
        {
        printf("\n Ingrese la fecha actual:\n");
        printf("\n Día: \t\t");
        scanf("%d",&da);
        printf("\n Mes: \t\t");
        scanf("%d",&ma);
        printf("\n Año: \t\t");
        scanf("%d",&aa);
        }
    while(!esfechavalida(da,ma,aa));
    for(i=0;i<n;i++)
        {
        do
            {
            printf("\n Ingrese el número de legajo del alumno:(entre 1000 y 9999):\t\t");
            scanf("%d",&leg);
            }
        while(!validadato(leg,1000,9999));
        do
            {
            printf("\n Ingrese la fecha de nacimiento:\n");
            printf("\n Día: \t\t");
            scanf("%d",&dn);
            printf("\n Mes: \t\t");
            scanf("%d",&mn);
            printf("\n Año: \t\t");
            scanf("%d",&an);
            }
        while(!esfechavalida(dn,mn,an));
        if(bisiesto(an)==1)
            printf("\n El alumno nació en año bisiesto \n\n");
        else
            printf("\n El alumno no nació en año bisiesto \n\n");
        edad=calculaedad(dn,mn,an,da,ma,aa);
        printf("\n La edad del alumno es: %d \n\n",edad);
        }
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
int esfechavalida(int d,int m,int a)
    {
    if(a>1600&&m>=1&&m<=12&&d>=1&&d<=cantdiasmes(m,a))
        return 1;
    else
        return 0;
    }
int cantdiasmes(int m,int a)
    {
    int cd;
    if(m==4||m==6||m==9||m==11)
        cd=30;
    else
        if(m==2)
            cd=28+bisiesto(a);
        else
            cd=31;
    return cd;
    }
int bisiesto(int a)
    {
    if((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
    }
int calculaedad(int d1,int m1,int a1,int d2,int m2,int a2)
    {
    int edad;
    edad=a2-a1;
    if(m2<m1||(m1==m2&&d2<d1))
        edad--;
    return edad;
    }
