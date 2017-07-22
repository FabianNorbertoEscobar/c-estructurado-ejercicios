#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicializarmat(int[][10],int,int);
int maximo(int[],int);
void mostrarsi(int[],int[],int[],int[],int,int);
int cargardatos(int[],int[],int[],int[],int[][10]);
void mostrarmatriz(int[][10],int,int);
int valida(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cod[1000],dep[1000],clas[1000],cup[1000],mat[25][10],ce,max;
    inicializarmat(mat,25,10);
    printf("\n Para realizar el control de la producción, la empresa \n necesita que se ingresen los datos de cada producto: \n\n");
    printf("\n El lote finalizará cuando se ingrese código de producto igual a cero \n\n");
    ce=cargardatos(cod,dep,clas,cup,mat);
    if(ce>0)
        {
        max=maximo(cup,ce);
        printf("\n Productos que han quedado con la mayor cantidad de unidades producidas \n\n");
        printf("\n Código \t Depósito \t Clase \t Cant.unid.prod.\n\n");
        mostrarsi(cod,dep,clas,cup,ce,max);
        printf("\n\n Cantidad de unidades producidas por depósito discriminado por clase \n\n");
        printf("\nClase   dep1   dep2    dep3   dep4   dep5    dep6   dep7    dep8   dep9   dep10 \n\n");
        mostrarmatriz(mat,25,10);
        }
    else
        printf("\n No se han ingresado datos \n\n");
    printf("\n\n Fin del programa \n\n");
    getch();
    }
void inicializarmat(int m[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
int maximo(int v[],int ce)
    {
    int i,band,may;
    band=0;
    for(i=0;i<ce;i++)
        if(band==0||v[i]>may)
            {
            band=1;
            may=v[i];
            }
    return may;
    }
void mostrarsi(int A[],int B[],int C[],int D[],int ce,int max)
    {
    int i;
    for(i=0;i<ce;i++)
        if(D[i]==max)
            printf("\n %d \t %d \t %d \t %d",A[i],B[i],C[i],D[i]);
    }
int cargardatos(int A[],int B[],int C[],int D[],int M[][10])
    {
    int cod,dep,cl,cup,i;
    i=0;
    do
        {
        printf("\n Ingrese el código del producto (entre 1000 y 1500):\n\n\t\t");
        scanf("%d",&cod);
        }
    while(!(valida(cod,1000,1500)||cod==0));
    while(cod!=0&&i<1000)
        {
        A[i]=cod;
        do
            {
            printf("\n Ingrese el número de depósito (entre 1 y 10):\n\n\t\t");
            scanf("%d",&dep);
            }
        while(!valida(dep,1,10));
        B[i]=dep;
        do
            {
            printf("\n Ingrese la clase de producto (entre 1 y 10):\n\n\t\t");
            scanf("%d",&cl);
            }
        while(!valida(cl,1,25));
        C[i]=cl;
        do
            {
            printf("\n Ingrese la cantidad de unidades producidas (entre 0 y 10000):\n\n\t\t");
            scanf("%d",&cup);
            }
        while(!valida(cup,0,10000));
        D[i]=cup;
        M[cl-1][dep-1]+=cup;
        i++;
        do
            {
            printf("\n Ingrese el código del producto (entre 1000 y 1500):\n\n\t\t");
            scanf("%d",&cod);
            }
        while(!(valida(cod,1000,1500)||cod==0));
        }
    return i;
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
int valida(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
