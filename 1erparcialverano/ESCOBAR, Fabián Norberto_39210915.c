//ESCOBAR,FABIÁN NORBERTO       DNI 39210915
/*
La Empresa NUMERO 10 cuenta con casi 500 inmuebles a la venta hasta el momento,
para ello se cuenta con los siguientes datos de cada Inmueble (estos datos se ingresan
por teclado y finalizan cuando se ingresa el Nro de Inmueble igual a cero):
• Número de Inmueble (int, entre 101 y 2.000).
• Ubicación geográfica(char, 30 caracteres)
• Características de inmueble (int, entre 1 y 6). El Número 1 significa “Fabrica”, el
Número 2 significa “Terreno”, el Número 3 significa “Departamento”, el Número 4
significa “Local”, el Número 5 significa “Casa” y el Número 6 significa “Dúplex”.
• Cantidad de ambientes (int, entre 1 y 10).
• Precio de Venta del inmueble (float, mayor a cero).
Se pide determinar e informar:
a) Informar los datos de todos los inmuebles cuyo Precio de Venta es el menor de los
inmuebles que posee la empresa.
b) Informar Cantidad de inmuebles que se posee a la venta por Características de
Inmueble pero separada por Cantidad de Ambientes.
FUNCIONES:
1. Para cargar en memoria todos los datos de los productos que tiene la empresa.
2. Para Validar los datos ingresados por teclado
3. Para Inicializar los vectores y/o matrices auxiliares.
*/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<ctype.h>
int validaint(int,int,int);
void inicializarmat(int[][10],int,int);
int cargardatos(int[],char[][31],int[],int[],float[],int[][10]);
float minimo(float[],int);
void listarsi(int[],char[][31],int[],int[],float[],int,float);
void mostrarmatriz(int[][10],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int inm[500],carac[500],amb[500],mat[6][10],ce;
    float prec[500],min;
    char ubic[500][31];
    inicializarmat(mat,6,10);
    printf("\a\a\n\t *****  EMPRESA DE VENTA DE INMUEBLES  ***** \n");
    printf("\n La empresa cuenta con casi 500 inmuebles a la venta \n");
    printf("\n Los inmuebles se clasifican según: \n");
    printf("\n\t %c Característica 1: \t Fábrica",16);
    printf("\n\t %c Característica 2: \t Terreno",16);
    printf("\n\t %c Característica 3: \t Departamento",16);
    printf("\n\t %c Característica 4: \t Local",16);
    printf("\n\t %c Característica 5: \t Casa",16);
    printf("\n\t %c Característica 6: \t Dúplex",16);
    printf("\n\n A continuación se pide que cargue los datos de la base de datos: \n\n");
    ce=cargardatos(inm,ubic,carac,amb,prec,mat);
    if(ce==0)
        printf("\n\t\t NO SE HA CARGADO NINGÚN DATO \n\n\t\t El informe podría arrojar datos falsos \n\n \a\a\a\a");
    min=minimo(prec,ce);
    printf("\n El menor precio de venta es: %.2f \n\n",min);
    printf("\n Los datos de los inmuebles con menor precio de venta son: \n\n");
    printf("\n N°Inmueble \t Ubicación \t Caract \t Ambientes \t Precio \n\n");
    listarsi(inm,ubic,carac,amb,prec,ce,min);
    printf("\n\n\nCantidad de inmuebles discriminados por características y cantidad de ambientes:\n\n");
    printf("\nCar    1am    2am    3am    4am    5am    6am    7am    8am   9am    10am\n\n");
    mostrarmatriz(mat,6,10);
    printf("\n\n\t\t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    }
int validaint(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void inicializarmat(int mat[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            mat[i][j]=0;
    }
int cargardatos(int A[],char B[][31],int C[],int D[],float E[],int F[][10])
    {
    int inm,i;
    i=0;
    do
        {
        printf("\n Ingrese el número de inmueble (entre 101 y 2000): \n (La carga de datos finalizará cuando ingrese número de inmueble cero)\n\n\t\t");
        scanf("%d",&inm);
        }
    while(!(validaint(inm,101,2000)||inm==0));
    while(inm!=0&&i<500)
        {
        A[i]=inm;
        fflush(stdin);
        printf("\n Ingrese la ubicación geográfica del inmueble (máximo 30 caracteres):\n\n\t\t");
        gets(B[i]);
        do
            {
            printf("\n Ingrese la característica del inmueble (entre 1 y 6):\n\n\t\t");
            scanf("%d",&C[i]);
            }
        while(!validaint(C[i],1,6));
        do
            {
            printf("\n Ingrese la cantidad de ambientes que posee el inmueble (entre 1 y 10):\n\n\t\t");
            scanf("%d",&D[i]);
            }
        while(!validaint(D[i],1,10));
        do
            {
            printf("\n Ingrese el precio de venta del inmueble: \n\n\t\t");
            scanf("%f",&E[i]);
            }
        while(E[i]<=0);
        F[C[i]-1][D[i]-1]++;
        i++;
        do
            {
            printf("\n Ingrese el número de inmueble (entre 101 y 2000): \n (La carga de datos finalizará cuando ingrese número de inmueble cero\n\n\t\t");
            scanf("%d",&inm);
            }
        while(!(validaint(inm,101,2000)||inm==0));
            }
        return i;
    }
float minimo(float v[],int ce)
    {
    int i,band;
    float min;
    band=0;
        for(i=0;i<ce;i++)
            {
             if(band==0||v[i]<min)
                {
                band=1;
                min=v[i];
                }
            }
    return min;
    }
void listarsi(int A[],char B[][31],int C[],int D[],float E[],int ce,float x)
    {
    int i;
    for(i=0;i<ce;i++)
        if(E[i]==x)
            printf("\n %d \t\t %s \t\t %d \t\t %d \t\t %.2f",A[i],B[i],C[i],D[i],E[i]);
    }
void mostrarmatriz(int m[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n%d",i+1);
        for(j=0;j<c;j++)
            printf("      %d",m[i][j]);
        }
    }
