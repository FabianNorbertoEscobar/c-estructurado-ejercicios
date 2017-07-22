#include<stdio.h>
#include<conio.h>
#include<locale.h>
int fechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
int julianos(int,int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int d1,d2,d3,m1,m2,m3,a1,a2,a3,dif,i;
printf("\n DIFERENCIA DE DÍAS ENTRE DOS FECHAS \n");
do
    {
    printf("\n Ingrese (en números) el día de la primera fecha: \n\n\t\t");
    scanf("%d",&d1);
    printf("\n\n Ingrese (en números) el mes de la primera fecha: \n\n\t\t");
    scanf("%d",&m1);
    printf("\n\n Ingrese (en números) el año de la primera fecha: \n\n\t\t");
    scanf("%d",&a1);
    }
while(!fechavalida(d1,m1,a1));
do
    {
    printf("\n Ingrese (en números) el día de la segunda fecha: \n\n\t\t");
    scanf("%d",&d2);
    printf("\n\n Ingrese (en números) el mes de la segunda fecha: \n\n\t\t");
    scanf("%d",&m2);
    printf("\n\n Ingrese (en números) el año de la segunda fecha: \n\n\t\t");
    scanf("%d",&a2);
    }
while(!fechavalida(d2,m2,a2));
if((a2<a1)||((a2==a1)&&((m2<m1)||((m2==m1)&&(d2<d1)))))
    {
    if(d2<d1)
        d3=d1-d2;
    else
        {
        dif=d2-d1;
        if(m1>1)
            {
            m1--;
            d3=cantdiasmes(m1,a1);
            }
        else
            {
            m1=12;
            a1--;
            d3=cantdiasmes(m1,a1)-dif;
            }
        }
    if(m2<m1)
        m3=m1-m2;
    else
        {
        dif=m2-1;
        m3=12-dif;
        a1--;
        }
    a3=a1-a2;
    dif=(a3-1)*365+julianos(d3,m3,a3);
    for(i=1;i<a3;i++)
        dif+=bisiesto(i);
    printf("\n\n Hay una diferencia de %d días entre las dos fechas ingresadas \n\n",dif);
    }
else
    printf("\n\n No se pueden restar las dos fechas ingresadas \n\n");
getch();
}
int fechavalida(int d,int m,int a)
{
int f=0;
if(a>1600&&m>=1&&m<=12&&d>=1&&d<=cantdiasmes(m,a))
    f=1;
return f;
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
if(a%4==0&&a%100!=0||a%400==0)
    return 1;
else
    return 0;
}
int julianos(int d,int m,int a)
{
int jul,i;
jul=d;
for(i=1;i<m;i++)
    jul+=cantdiasmes(i,a);
return jul;
}
