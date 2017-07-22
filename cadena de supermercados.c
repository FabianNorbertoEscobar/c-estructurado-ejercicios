#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicmat(int[][12],int,int);
void inicvec(int[],int);
int cargarmat(int[][12],int,int);
int validadato(int,int,int);
void sumarxfila(int[][12],int,int,int[]);
void sumarxcolumna(int[][12],int,int,int[]);
void mostrarxfila(int[][12],int,int);
void mostrarvector(int[],int);
int minimo(int[],int);
int posmax(int[],int);
void listarcolumna(int[][12],int,int);
int contar(int[],int,int);
void mostrarminimos(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[2][12],vsuc[5],vrub[12],ce,posimax,min,ceros;
    printf("\n\n \t\t CADENA DE SUPERMERCADOS \n\n");
    printf("Ingrese los pedidos de mercadería. Se pide el número de sucursal \n (identificados de 1 a 12) y la cantidad pedida. \n");
    printf("Finalice la carga de datos con sucursal igual a cero. \n\n");
    inicmat(mat,5,12);
    inicvec(vsuc,5);
    inicvec(vrub,12);
    ce=cargarmat(mat,5,12);
    if(ce!=0)
        {
        sumarxfila(mat,5,12,vsuc);
        sumarxcolumna(mat,5,12,vrub);
        printf("\n\n Sucursal\tR1\tR2\tR3\tR4\tR5\tR6\tR7\tR8\tR9\tR10\tR11\tR12");
        mostrarxfila(mat,5,12);
        printf("\n\n Sucursal \t Cantidad Pedida \n\n");
        mostrarvector(vsuc,5);
        printf("\n\n Rubro \t Cantidad Pedida \n\n");
        mostrarvector(vrub,5);
        posimax=posmax(vrub,12);
        printf("\n\n El rubro de mayor cantidad pedida es:%d \n\n",posimax+1);
        printf("\n Cantidades pedidas del rubro 7 para todas las sucursales: \n");
        printf("\n Sucursal \t Cantidad pedida \n\n");
        listarcolumna(mat,5,6);
        min=minimo(vsuc,5);
        printf("\n\n La sucursal que pidió la menor cantidad de mercadería es: \n\n");
        mostrarminimos(vsuc,5,min);
        ceros=contar(vrub,12,0);
        printf("\n\n La cantidad de rubros no pedidos por ninguna sucursal:%d \n\n",ceros);
        }
    else
        printf("\n\n No se ingresó ningún pedido de mercadería \n\n");
    getch();
    }
void inicmat(int m[][12],int f,int c)
    {
    int i,j;
    for(j=0;j<c;j++)
        for(i=0;i<f;i++)
            m[i][j]=0;
    }
void inicvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int cargarmat(int m[][12],int f,int c)
    {
    int i,suc,rub,cant;
    i=0;
    do
        {
        printf("\n\n Ingrese el número de sucursal del pedido %d: \n\n",i+1);
        scanf("%d",&suc);
        printf("\n\n Ingrese el código de rubro del pedido %d: \n\n",i+1);
        scanf("%d",&rub);
        printf("\n\n Ingrese la cantidad solicitada del pedido %d: \n\n",i+1);
        scanf("%d",&cant);
        }
    while(!validadato(suc,0,5)||!validadato(rub,1,12)||cant<=0);
    while(suc!=0)
        {
        m[suc-1][rub-1]+=cant;
        i++;
        do
            {
            printf("\n\n Ingrese el número de sucursal del pedido %d: \n\n",i+1);
            scanf("%d",&suc);
            printf("\n\n Ingrese el código de rubro del pedido %d: \n\n",i+1);
            scanf("%d",&rub);
            printf("\n\n Ingrese la cantidad solicitada del pedido %d: \n\n",i+1);
            scanf("%d",&cant);
            }
        while(!validadato(suc,0,5)||!validadato(rub,1,12)||cant<=0);
        }
    return i;
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void sumarxfila(int m[][12],int f,int c,int v[])
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            v[i]+=m[i][j];
    }
void sumarxcolumna(int m[][12],int f,int c,int v[])
    {
    int i,j;
    for(j=0;j<c;j++)
        for(i=0;i<f;i++)
            v[j]+=m[i][j];
    }
void mostrarxfila(int m[][12],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n %d",i+1);
        for(j=0;j<c;j++)
            printf("\t %d",m[i][j]);
        }
    }
void mostrarvector(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
       printf("\n %d \t %d",i+1,v[i]);
    }
int minimo(int v[],int ce)
    {
    int i,min;
    for(i=0;i<ce;i++)
        if(i==0||v[i]<min)
            min=v[i];
    return min;
    }
int posmax(int v[],int ce)
    {
    int i,pmax;
    for(i=0;i<ce;i++)
        if(i==0||v[i]>pmax)
            pmax=i;
    return pmax;
    }
void listarcolumna(int m[][12],int f,int x)
    {
    int i,j;
    for(i=0;i<f;i++)
        printf("\n %d \t %d",i+1,m[i][j]);
    }
int contar(int v[],int ce,int x)
    {
    int i,cont;
    cont=0;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            cont++;
    return cont;
    }
void mostrarminimos(int v[],int ce,int min)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]==min);
            printf("\n %d",i+1);
    }
