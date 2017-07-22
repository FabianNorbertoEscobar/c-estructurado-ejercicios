#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
void cargarvendedores(int[],char[][31],int);
int esFechaValida(int,int,int);
int cantdiasmes(int,int);
int bisiesto(int);
void inicvecfloat(float[],int);
void cargardatos(int[],float[],int);
int busquedasecuencial(int[],int,int);
void ordenarmayor(int[],char[][31],float[],int);
void mostrar(int[],char[][31],float[],int);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int codvend[130],d,m,a;
float imp[130];
char nombvend[130][31];
printf("\n\t\t EMPRESA KALAF S.A. \n\n\a\a");
printf("\n Para analizar las ventas efectuadas se pide \n que se ingresen los datos de los 130 vendedores.");
printf("\n Se solicita el número de vendedor y su nombre (máximo 30 caracteres) \n");
cargarvendedores(codvend,nombvend,130);
printf("\n\n Ingrese la fecha del día de proceso: \n");
printf("\n Ingrese el día (en números) de la fecha:\n\t");
scanf("%d",&d);
printf("\n Ingrese el mes (en números) de la fecha:\n\t");
scanf("%d",&m);
printf("\n Ingrese el año (en números) de la fecha:\n\t");
scanf("%d",&a);
while(!esFechaValida(d,m,a))
    {
    printf("\n La fecha ingresada no es válida. Ingrese una fecha que exista:\n");
    printf("\n Ingrese el día (en números) de la fecha:\n\t");
    scanf("%d",&d);
    printf("\n Ingrese el mes (en números) de la fecha:\n\t");
    scanf("%d",&m);
    printf("\n Ingrese el año (en números) de la fecha:\n\t");
    scanf("%d",&a);
    }
inicvecfloat(imp,130);
printf("\n\n Ingrese los datos de las ventas del día. Se pide:");
printf("\n número de cliente,código de vendedor (alguno de los ya ingresados),");
printf("\n el código de artículo, la cantidad vendida y el precio unitario.");
printf("\n Finalice la carga de datos con número de cliente igual a cero.\n");
cargardatos(codvend,imp,130);
printf("\n VENTAS DEL DÍA %d/%d/%d\n",d,m,a);
printf("\n Código de vendedor \t Nombre del vendedor \t Importe vendido \n");
ordenarmayor(codvend,nombvend,imp,130);
mostrar(codvend,nombvend,imp,130);
printf("\n\n Fin del programa \n\n\a\a");
getch();
}
void cargarvendedores(int cod[],char nomb[][31],int ce)
{
int i,codv;
char nombv[31];
for(i=0;i<ce;i++)
    {
    printf("\n Ingrese el código del vendedor %d:\n\t",i+1);
    scanf("%d",&codv);
    printf("\n Ingrese el nombre del vendedor %d:\n\t",i+1);
    fflush(stdin);
    gets(nombv);
    cod[i]=codv;
    strcpy(nomb[i],nombv);
    }
}
int esFechaValida(int d,int m,int a)
{
if(a>=1600&&m>=1&&m<=12&&d>=1&&d<=cantdiasmes(m,a))
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
if((a%4==0&&a%100!=0)||(a%400==0))
    return 1;
else
    return 0;
}
void inicvecfloat(float v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    v[i]=0;
}
void cargardatos(int cod[],float imp[],int ce)
{
int i,numclient,codvend,codart,cantvend,pos;
float prun;
i=0;
printf("\n Ingrese el número del cliente %d:\n\t",i+1);
scanf("%d",&numclient);
printf("\n Ingrese el código del vendedor %d:\n\t",i+1);
scanf("%d",&codvend);
printf("\n Ingrese el código del artículo %d:\n\t",i+1);
scanf("%d",&codart);
printf("\n Ingrese la cantidad vendida del artículo %d:\n\t",i+1);
scanf("%d",&cantvend);
printf("\n Ingrese el precio unitario del artículo %d:\n\t",i+1);
scanf("%f",&prun);
while(numclient!=0)
    {
    pos=busquedasecuencial(cod,codvend,130);
    if(pos!=-1)
        {
        imp[pos]+=cantvend*prun;
        i++;
        }
    else
        printf("\n Código de vendedor erróneo. Ingrese los datos nuevamente.\n");
    printf("\n Ingrese el número del cliente %d:\n\t",i+1);
    scanf("%d",&numclient);
    printf("\n Ingrese el código del vendedor %d:\n\t",i+1);
    scanf("%d",&codvend);
    printf("\n Ingrese el código del artículo %d:\n\t",i+1);
    scanf("%d",&codart);
    printf("\n Ingrese la cantidad vendida del artículo %d:\n\t",i+1);
    scanf("%d",&cantvend);
    printf("\n Ingrese el precio unitario del artículo %d:\n\t",i+1);
    scanf("%f",&prun);
    }
}
int busquedasecuencial(int v[],int ce,int x)
{
int p,i;
p=-1;
i=0;
while(i<ce&&p==-1)
    {
    if(v[i]==x)
        p=i;
    i++;
    }
return p;
}
void ordenarmayor(int c[],char n[][31],float imp[],int ce)
{
int i,j,pm,aux1;
char aux2[31];
float aux3;
for(j=1;j<ce;j++)
    {
    pm=j-1;
    for(i=j;i<ce;i++)
        if(imp[i]>imp[pm])
            pm=i;
    aux1=c[pm];
    c[pm]=c[j-1];
    c[j-1]=aux1;
    strcpy(aux2,n[pm]);
    strcpy(n[pm],n[j-1]);
    strcpy(n[j-1],aux2);
    aux3=imp[pm];
    imp[pm]=imp[j-1];
    imp[j-1]=aux3;
    }
}
void mostrar(int c[],char n[][31],float i[],int ce)
{
int j;
for(j=0;j<ce;j++)
    printf("\n %d \t %s \t %f",c[j],n[j],i[j]);
}
