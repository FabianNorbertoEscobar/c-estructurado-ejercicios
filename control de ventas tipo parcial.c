#include<stdio.h>
#include<conio.h>
#include<locale.h>
void cargardatos(int[],int[],float[],float[],int[],float[],int[][10]);
void inicializarmat(int[][10],int,int);
void inicializarvec(float[],int);
int valida(char[],int,int);
float valida2(char[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int prod[5000],vend[5000],cuv[5000],mat[5000][10],i,j;
    float prec[5000],imp[5000],com[10];
    inicializarmat(mat,5000,10);
    inicializarvec(com,10);
    printf("\n Cargue la base de daros de la empresa \n para que se puedan realizar los controles: \n\n");
    cargardatos(prod,vend,prec,imp,cuv,com,mat);
    printf("\n Comisiones cobradas por cada uno de los vendedores: \n");
    printf("\n VENDEDOR \t COMISIÓN \n");
    for(i=0;i<10;i++)
        printf("\n %d \t %d",i+1,com[i]);
    printf("\n Cantidad de unidades vendidas por vendedor y producto: \n");
    printf("\n Prod  v1   v2   v3   v4   v5   v6   v7   v8   v9   v10\n");
    for(i=0;i<5000;i++)
        for(j=0;j<10;j++)
            {
            printf("\n %d",i+1);
            for(j=0;j<10;j++)
                printf("   %d",mat[i][j]);
            }
    printf("\n\n Fin del programa \n\n");
    getch();
    }
void cargardatos(int A[],int B[],float C[],float D[],int E[],float F[],int m[][10])
    {
    int i,prod;
    prod=valida("\n Ingrese número de producto (entre 1 y 5000): \n\n\t\t",1,5000);
    A[prod-1]=prod;
    B[prod-1]=valida("\n Ingrese número de vendedor (entre 1 y 10): \n\n\t\t",1,10);
    C[prod-1]=valida2("\n Ingrese el precio (entre 5 y 50): \n\n\t\t",5,50);
    D[prod-1]=valida2("\n Ingrese el importe (entre 5 y 20): \n\n\t\t",5,20);
    E[prod-1]=valida("\n Ingrese la cantidad de unidades vendidas (entre 1 y 1000): \n\n\t\t",1,1000);
    F[B[prod-1]-1]+=E[prod-1]*C[prod-1]*D[prod-1];
    m[prod-1][B[prod-1]-1]+=E[prod-1];
    }
void inicializarmat(int m[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
void inicializarvec(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int valida(char c[],int li,int ls)
    {
    int x;
    do
        {
        printf("%s",c);
        scanf("%d",&x);
        }
    while(!(x>=li&&x<=ls));
    return x;
    }
float valida2(char c[],int li,int ls)
    {
    float x;
    do
        {
        printf("%s",c);
        scanf("%f",&x);
        }
    while(!(x>=li&&x<=ls));
    return x;
    }
