#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct DATOS
    {
    int cods;
    int nroa;
    int stock;
    };
int valida(int,int,int);
void inicializarmat(int[][100],int,int);
void inicializarvec(int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,mat[15][100],vaux[15],codsup,stock,codart,codop,cant,f,c;
    struct DATOS dis[1500];
    printf("\n\t DISTRIBUIDORA \n\n");
    printf("\n Una distribuidora se encarga de repartir 100 productos \n a 15 supermercados. Cargue la base de datos de los productos:\n\n");
    inicializarmat(mat,15,100);
    inicializarvec(vaux,15);
    for(i=0;i<1500;i++)
        {
        do
            {
            printf("\n Ingrese el código de supermercado (entre 1 y 15):\n\n\t\t");
            scanf("%d",&codsup);
            }
        while(!valida(codsup,1,15));
        do
            {
            printf("\n Ingrese el código de artículo (entre 1 y 100):\n\n\t\t");
            scanf("%d",&codart);
            }
        while(!valida(codart,1,100));
        do
            {
            printf("\n Ingrese el stock:\n\n\t\t");
            scanf("%d",&stock);
            }
        while(stock<0);
        mat[codsup-1][codart-1]=stock;
        }
    printf("\n A continuación, cargue los movimientos de ingreso y egreso \n de los artículos para dichos supermercados.\n(El lote finaliza con supermercado cero)\n\n\t\t");
    do
        {
        printf("\n Ingrese el código de supermercados (entre 1 y 15)\n\n\t\t");
        scanf("%d",&codsup);
        }
    while(!valida(codsup,0,15));
    while(codsup!=0)
        {
        do
            {
            printf("\n Ingrese el código de artículo (entre 1 y 100):\n\n\t\t");
            scanf("%d",&codart);
            }
        while(!valida(codart,1,100));
        do
            {
            printf("\n Ingrese el código de operación ( 1:ingreso  2:egreso ): \n\n\t\t");
            scanf("%d",&codop);
            }
        while(!valida(codop,1,2));
        do
            {
            printf("\n Ingrese la cantidad ingresada/pedida: \n\n\t\t");
            scanf("%d",&cant);
            }
        while(stock<0);
        if(codop==1)
            {
            mat[codsup-1][codart-1]+=cant;
            vaux[codsup-1]++;
            }
        else
            if(mat[codsup-1][codart-1]>=cant)
                {
                mat[codsup-1][codart-1]-=cant;
                vaux[codsup-1]++;
                }
            else
                printf("\n Operación rechazada. \t Motivo: Stock insuficiente \n\n");
        do
            {
            printf("\n Ingrese el código de supermercados (entre 1 y 15)\n\n\t\t");
            scanf("%d",&codsup);
            }
        while(!valida(codsup,0,15));
        }
    printf("\n Total de movimientos por supermercado: \n");
    printf("\n N° de supermercado \t Cantidad de movimientos \n\n");
    for(i=0;i<15;i++)
        printf("\n %d \t\t %d",i+1,vaux[i]);
    printf("\n Base de datos actualizada ordenada por código de supermercado\n\n");
    i=0;
    for(f=0;f<15;f++)
        for(c=0;c<100;c++)
            {
            dis[i].cods=f+1;
            dis[i].nroa=c+1;
            dis[i].stock=mat[f][c];
            i++;
            }
    printf("\n Supermercado \t Producto \t Stock \n\n");
    for(i=0;i<1500;i++)
        printf("\n %d \t\t %d \t\t %d",dis[i].cods,dis[i].nroa,dis[i].stock);
    printf("\n\n");
    getch();
    }
int valida(int x,int li,int ls)
    {
    int i;
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void inicializarmat(int m[][100],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
