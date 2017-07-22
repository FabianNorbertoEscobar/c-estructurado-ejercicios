#include<stdio.h>
#include<conio.h>
#include<locale.h>
int fechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int d,m,a,n,dif;
do
    {
    printf("\n Ingrese (en números) el día: \n\n\t\t");
    scanf("%d",&d);
    printf("\n\n Ingrese (en números) el mes: \n\n\t\t");
    scanf("%d",&m);
    printf("\n\n Ingrese (en números) el año: \n\n\t\t");
    scanf("%d",&a);
    }
while(!fechavalida(d,m,a));
printf("\n\n La fecha ingresada es: %d / %d / %d \n",d,m,a);
printf("\n Ingrese la cantidad de días a sumar: \n\n\t\t");
scanf("%d",&n);
d+=n;
while(d>cantdiasmes(m,a))
    {
    d-=cantdiasmes(m,a);
    m++;
    if(m>12)
        {
        m=1;
        a++;
        }
    }
printf("\n\n La fecha ingresada mas %d días es: %d / %d / %d \n",n,d,m,a);
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
