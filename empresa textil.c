#include<stdio.h>
#include<conio.h>
#include<locale.h>
void legajo(int[],int);
void inicmat(float[][24],int,int);
void inicvec(float[],int);
int validadato(int,int,int);
int validadato2(float,int,int);
void sumarxcolumna(float[][24],int,int,float[]);
int cargardatos(float[][24],int,int);
void listar(float[],int);
void sumarxfila(float[][24],int,int,float[]);
void obtenersueldo(float[],int,float[]);
void mostraralreves(int[],float[],int);
void ordenarmenor(float[],int,int[]);
float maximo(float[],int);
void mostrarmax(float[],int,float);
int contarsi(float[],int,float);
void mostrarsi(float[],int,float);
void main()
{
setlocale(LC_CTYPE,"Spanish");
int aux[50],ce,ceros;
float mat[50][24],dia[24],leg[50],sueld[50],max;
printf("\n EMPRESA TEXTIL \"LA MOROCHA\" \n\a\a");
printf("\n Se desea realizar un informe con los sueldos de cada empleado,");
printf("\n para lo que se solicitan sus datos.");
printf("\n Ingrese el legajo (identificado de 1 a 50),");
printf("\n el día laboral (de 1 a 24) y las horas trabajadas (menor a 12)");
printf("\n Finalice la carga de datos con legajo igual a cero \n");
legajo(aux,50);
inicmat(mat,50,24);
inicvec(dia,24);
inicvec(leg,50);
ce=cargardatos(mat,50,24);
if(ce!=0)
    {
    sumarxcolumna(mat,50,24,dia);
    printf("\n\n DÍA \t\t HORAS TRABAJADAS \n");
    listar(dia,50);
    sumarxfila(mat,50,24,leg);
    printf("\n\n LEGAJO \t HORAS TRABAJADAS \n");
    listar(leg,50);
    obtenersueldo(leg,50,sueld);
    ordenarmenor(sueld,50,aux);
    printf("\n\n LEGAJO \t SUELDO ABONADO \n");
    mostraralreves(aux,sueld,50);
    max=maximo(leg,50);
    printf("\n\n Empleado que mas ha trabajado: \n");
    printf("\n LEGAJO \t HORAS TRABAJADAS \n");
    mostrarmax(leg,50,max);
    ceros=contarsi(leg,50,0);
    if(ceros!=0)
        {
        printf("\n\n Empleados que no trabajaron: \n");
        printf("\n LEGAJO \n");
        mostrarsi(leg,50,0);
        printf("\n");
        }
    else
        printf("\n\n Todos los empleados han trabajado. \n\n");
    }
else
    printf("\n\n No se han ingresado datos \n\n");
getch();
}
void legajo(int v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    v[i]=i+1;
}
void inicmat(float m[][24],int f,int c)
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
int validadato(int x,int li,int ls)
{
if(x>=li&&x<=ls)
    return 1;
else
    return 0;
}
int validadato2(float x,int li,int ls)
{
if(x>=li&&x<ls)
    return 1;
else
    return 0;
}
void sumarxcolumna(float m[][24],int f,int c,float v[])
{
int i,j;
for(i=0;i<f;i++)
    for(j=0;j<c;j++)
        v[i]+=m[i][j];
}
int cargardatos(float m[][24],int f,int c)
{
int i,band,leg,d;
float hs;
i=0;
band=0;
do
    {
    if(band!=0)
        printf("\n Los datos ingresados son incorrectos. Ingréselos nuevamente.\n");
    printf("\n\t DATO NÚMERO %d \n",i+1);
    printf("\n Ingrese el legajo del empleado: \n\t");
    scanf("%d",&leg);
    printf("\n Ingrese el número de día laboral: \n\t");
    scanf("%d",&d);
    printf("\n Ingrese las horas trabajadas: \n\t");
    scanf("%f",&hs);
    band=1;
    }
while(!validadato(leg,0,50)||!validadato(d,1,24)||!validadato2(hs,0,12));
while(leg!=0)
    {
    m[leg-1][d-1]=hs;
    i++;
    band=0;
    do
        {
        if(band!=0)
            printf("\n Los datos ingresados son incorrectos. Ingréselos nuevamente.\n");
        printf("\n\t DATO NUMERO %d \n",i+1);
        printf("\n Ingrese el legajo del empleado: \n\t");
        scanf("%d",&leg);
        printf("\n Ingrese el número de día laboral: \n\t");
        scanf("%d",&d);
        printf("\n Ingrese las horas trabajadas: \n\t");
        scanf("%f",&hs);
        band=1;
        }
    while(!validadato(leg,0,50)||!validadato(d,1,24)||!validadato2(hs,0,12));
    }
return i;
}
void listar(float v[],int ce)
{
int i;
for(i=0;i<ce;i++)
    printf("\n %d \t\t %2.2f",i+1,v[i]);
}
void sumarxfila(float m[][24],int f,int c,float v[])
{
int i,j;
for(i=0;i<f;i++)
    for(j=0;j<c;j++)
        v[i]+=m[i][j];
}
void obtenersueldo(float l[],int ce,float s[])
{
int i;
for(i=0;i<ce;i++)
    s[i]=l[i]*15;
}
void mostraralreves(int a[],float s[],int ce)
{
int i;
for(i=0;i<ce;i++)
    printf("\n %d \t\t %4.2f",a[i],s[i]);
}
void ordenarmenor(float s[],int ce,int a[])
{
int i,j,pm,aux2;
float aux1;
for(j=1;j<ce;j++)
    {
    pm=j-1;
    for(i=j;i<ce;i++)
        if(s[i]<s[j-1])
            pm=i;
    aux1=s[pm];
    s[pm]=s[j-1];
    s[j-1]=aux1;
    aux2=a[pm];
    a[pm]=a[j-1];
    a[j-1]=aux2;
    }
}
float maximo(float v[],int ce)
{
int i;
float max;
for(i=0;i<ce;i++)
    if(i==0||v[i]>max)
        max=v[i];
return max;
}
void mostrarmax(float v[],int ce,float x)
{
int i;
for(i=0;i<ce;i++)
    printf("\n %d \t\t %2.2f",i+1,v[i]);
}
int contarsi(float v[],int ce,float x)
{
int cont,i;
cont=0;
for(i=0;i<ce;i++)
    if(v[i]==x)
        cont++;
return cont;
}
void mostrarsi(float v[],int ce,float x)
{
int i;
for(i=0;i<ce;i++)
    if(v[i]==x)
        printf("\n %d",i+1);
}
