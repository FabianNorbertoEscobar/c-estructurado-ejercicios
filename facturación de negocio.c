#include<stdio.h>
#include<conio.h>
#include<locale.h>
int fechavalida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
void inicializar(int[],int);
void ponerencero1(float[],int);
void ponerencero2(int[],int);
void cargarvectores(float[],int[],int);
void ordenarmayor(float[],int[],int[],int);
void mostrar(float[],int[],int[],int);
float sumarvector1(float[],int);
int sumarvector2(int[],int);
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band,d,m,a,vendedor[12],facturas[12],totalfacturas;
    float importes[12],totalimportes;
    printf("\n\n Ingrese la fecha correspondiente al día de venta:\n\n");
    band=0;
    do
        {
        if(band!=0)
            printf("\n\n La fecha ingresada no existe. Ingrese una fecha válida.\n\n");
        printf("\n\n Ingrese el día (en números) de la fecha:\n\n\t");
        scanf("%d",&d);
        printf("\n\n Ingrese el mes (en números) de la fecha:\n\n\t");
        scanf("%d",&m);
        printf("\n\n Ingrese el año (en números) de la fecha:\n\n\t");
        scanf("%d",&a);
        band=1;
        }
    while(!fechavalida(d,m,a));
    printf("\n\n Ingrese los datos de facturación para sus vendedores, \n identificados con códigos que varían entre 1 y 12. \n");
    printf("Finalizar la carga de los datos con factura igual a cero.\n\n");
    inicializar(vendedor,12);
    ponerencero1(importes,12);
    ponerencero2(facturas,12);
    cargarvectores(importes,facturas,12);
    ordenarmayor(importes,facturas,vendedor,12);
    printf("\n\n N° DE VENDEDOR \t IMPORTE VENDIDO \t CANTIDAD DE FACTURAS EMITIDAS \n\n");
    mostrar(importes,vendedor,facturas,12);
    totalimportes=sumarvector1(importes,12);
    totalfacturas=sumarvector2(facturas,12);
    printf("\n\n TOTAL \t %f \t %d \n\n",totalimportes,totalfacturas);
    printf("\n\n Fin del día de facturación \n\n");
    getch();
    }
int fechavalida(int d,int m,int a)
    {
    int f;
    f=0;
    if(a>1600&&m>=1&&m<=12&&d>=1&&cantdiasmes(m,a))
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
void inicializar(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=i+1;
    }
void ponerencero1(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void ponerencero2(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void cargarvectores(float imp[],int fact[],int x)
    {
    int i,factu,vend;
    float impo;
    i=0;
    do
        {
        printf("\n\n Ingrese el número identificador de la factura num %d: \n\n\t",i+1);
        scanf("%d",&factu);
        printf("\n\n Ingrese el código del vendeder num %d: \n\n\t",i+1);
        scanf("%d",&vend);
        printf("\n\n Ingrese el importe de la venta num %d: \n\n\t",i+1);
        scanf("%f",&impo);
        }
    while(!validadato(vend,1,12)||fact<0||impo<=0);
    while(fact!=0)
        {
        fact[vend]++;
        imp[vend]+=impo;
        i++;
        do
        {
        printf("\n\n Ingrese el número identificador de la factura num %d: \n\n\t",i+1);
        scanf("%d",&factu);
        printf("\n\n Ingrese el código del vendeder num %d: \n\n\t",i+1);
        scanf("%d",&vend);
        printf("\n\n Ingrese el importe de la venta num %d: \n\n\t",i+1);
        scanf("%f",&impo);
        }
        while(!validadato(vend,1,12)||fact<0||impo<=0);
        }
    }
void ordenarmayor(float imp[],int fact[],int vend[],int ce)
    {
    int pm,i,j,aux2,aux3;
    float aux1;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(imp[i]>imp[pm])
                pm=i;
        aux1=imp[pm];
        imp[pm]=imp[j-1];
        imp[j-1]=aux1;
        aux2=fact[pm];
        fact[pm]=fact[j-1];
        fact[j-1]=aux2;
        aux3=vend[pm];
        vend[pm]=vend[j-1];
        vend[j-1]=aux3;
        }
    }
void mostrar(float imp[],int vend[],int fact[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %f \t %d",vend[i],imp[i],fact[i]);
    }
float sumarvector1(float v[],int ce)
    {
    int i;
    float acum;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum;
    }
int sumarvector2(int v[],int ce)
    {
    int i,acum;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum;
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
