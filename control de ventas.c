#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#define tope 100
int fechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
int validadato(int,int,int);
void inicmat(float[][35],int,int);
void inicvec(float[],int);
int cargardatos(float[][35],int,int,int,char[][31]);
void sumarxcolumna(float[][35],int,int,float[]);
void mostrarvec(float[],int);
float sumar(float[],int);
void sumarxfila(float[][35],int,int,float[]);
int maximo(float[],int);
int contarsi(float[],int,int);
float percent(int,int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int band,d,m,a,ce,cl,ceros;
float tot,p,mat[tope][35],vend[35],client[tope];
char codclient[tope][31];
printf("\n CONTROL DE VENTAS \n");
printf("\n Ingrese la fecha del proceso:\n");
band=0;
do
    {
    if(band==1)
        printf("\n Fecha incorrecta. Ingrese una fecha que exista \n");
    printf("\n Ingrese el día (en números) de la fecha: \n\t");
    scanf("%d",&d);
    printf("\n Ingrese el mes (en números) de la fecha \n\t");
    scanf("%d",&m);
    printf("n Ingrese el año (en números) de la fecha \n\t");
    scanf("\%d",&a);
    band=1;
    }
while(!fechavalida(d,m,a));
printf("\n Ingrese los datos de las ventas. Se pide la fecha de venta");
printf("\n (debe ser del mismo año que la fecha de proceso),");
printf("\n el número de vendedor (identificado entre 1 y 35),");
printf("\n el código del cliente (cadena de hasta 30 caracteres),");
printf("\n y el importe de la compra. \n");
printf("\n\n Finalizar la carga de los datos con vendedor igual a cero \n");
inicmat(mat,tope,35);
inicvec(vend,35);
inicvec(client,tope);
ce=cargardatos(mat,tope,35,a,codclient);
if(ce!=0)
    {
    sumarxcolumna(mat,ce,35,vend);
    printf("\n VENDEDOR \t TOTAL DE VENTAS \n");
    mostrarvec(vend,35);
    tot=sumar(vend,35);
    printf("\n El total de ventas en importe es: $ %f \n",tot);
    sumarxfila(mat,ce,35,client);
    cl=maximo(client,ce);
    printf("\n El código del cliente que realizó la compra más grande es: %s \n",codclient[cl+1]);
    ceros=contarsi(vend,35,0);
    p=percent(ceros,35);
    printf("\n El porcentaje de vendedores que no vendieron nada es de: %f \n\n",p);
    }
else
    printf("\n No se ingresaron datos \n\n");
getch();
}
int fechavalida(int d,int m,int a)
{
int f;
f=0;
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
if((a%4==0&&a%100!=0)||a%400==0)
    return 1;
else
    return 0;
}
int validadato(int x,int li,int ls)
{
if(x>=li&&x<=ls)
    return 1;
else
    return 0;
}
void inicmat(float m[][35],int f,int c)
{
int i,j;
for(i=0;i<f;i++)
    for(j=0;j<c;j++)
        m[i][j]=0;
}
void inicvec(float v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    v[i]=0;
}
int cargardatos(float m[][35],int f,int c,int x,char n[][31])
{
int i,band,d,m1,a,vend;
float imp;
char chara[31];
do
    {
    printf("\n Venta número %d \n",i+1);
    if(band==1)
        printf("\n Datos incorrectos. Ingréselos nuevamente: \n");
    printf("\n Ingrese la fecha de venta: \n");
    printf("\n Ingrese el día (en números) de la fecha de venta: \n\t");
    scanf("%d",&d);
    printf("\n Ingrese el mes (en números) de la fecha de venta: \n\t");
    scanf("&d",&m1);
    printf("\n Ingrese el año (en números) de la fecha de venta: \n\t");
    scanf("%d",&a);
    printf("\n Ingrese el numero de vendedor: \n\t");
    scanf("%d",&vend);
    printf("\n Ingrese el código de cliente: \n\t");
    fflush(stdin);
    gets(chara);
    strcpy(chara,toupper(chara));
    printf("\n Ingrese el importe: \n\t");
    scanf("&f",&imp);
    band=1;
    }
while((!fechavalida(d,m1,a)&&a==x)||!validadato(vend,0,35)||strlen(chara)==0||imp<=0);
while(vend!=0)
    {
    m[i][vend-1]=imp;
    strcpy(n[i],chara);
    i++;
    band=0;
    do
        {
        printf("\n Venta número %d \n",i+1);
        if(band==1)
            printf("\n Datos incorrectos. Ingréselos nuevamente: \n");
        printf("\n Ingrese la fecha de venta: \n");
        printf("\n Ingrese el día (en números) de la fecha de venta: \n\t");
        scanf("%d",&d);
        printf("\n Ingrese el mes (en números) de la fecha de venta: \n\t");
        scanf("&d",&m1);
        printf("\n Ingrese el año (en números) de la fecha de venta: \n\t");
        scanf("%d",&a);
        printf("\n Ingrese el número de vendedor: \n\t");
        scanf("%d",&vend);
        printf("\n Ingrese el código de cliente: \n\t");
        fflush(stdin);
        gets(chara);
        strcpy(chara,toupper(chara));
        printf("\n Ingrese el importe: \n\t");
        scanf("&f",&imp);
        band=1;
        }
    while((!fechavalida(d,m1,a)&&a==x)||!validadato(vend,0,35)||strlen(chara)==0||imp<=0);
    }
return i;
}
void sumarxcolumna(float m[][35],int f,int c,float v[])
{
int i,j;
for(j=0;j<c;j++)
    for(i=0;i<f;i++)
        v[j]+=m[i][j];
}
void mostrarvec(float v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    printf("\n %d \t %f",i+1,v[i]);
}
float sumar(float v[],int ce)
{
int i;
float acum;
acum=0;
for(i=0;i<ce;i++)
    acum+=v[i];
return acum;
}
void sumarxfila(float m[][35],int f,int c,float v[])
{
int i,j;
for(i=0;i<f;i++)
    for(j=0;j<c;j++)
        v[i]+=m[i][j];
}
int maximo(float v[],int ce)
{
int i,pm;
float max;
for(i=0;i<ce;i++)
    if(i==0||v[i]>=max)
        {
        max=v[i];
        pm=i;
        }
return pm;
}
int contarsi(float v[],int ce,int x)
{
int i,cont;
cont=0;
for(i=0;i<ce;i++)
    if(v[i]==x)
        cont++;
return cont;
}
float percent(int i,int s)
{
float p;
p=i*100/s;
return p;
}
