#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicializarmat(int[][15],int,int);
int valida(char[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[120][15],mod,est,cu,sum,i,j,band,may,maymod;
    float prom;
    inicializarmat(mat,120,15);
    sum=0;
    printf("\n Fábrica de remeras para hombre \n\n");
    printf("\n Para realizar el control de los pedidos, se solicitará \n que ingrese los modelos, los estampados, y la cantidad \n de unidades pedidas \n");
    printf("\n Para finalizar la carga de los datos y realizar el informe, ingrese modelo cero \n\n");
    mod=valida("\n Ingrese el modelo (entre 1 y 120) \n\n",0,120);
    while(mod!=0)
        {
        est=valida("\n Ingrese el estampado (entre 1 y 15) \n\n",1,15);
        do
            {
            printf("\n Ingrese la cantidad de unidades pedidas: \n\n");
            scanf("%d",&cu);
            }
        while(cu<=0);
        sum+=cu;
        mat[mod-1][est-1]+=cu;
        mod=valida("\n Ingrese el modelo (entre 1 y 120) \n\n",0,120);
        }
    prom=(float)sum/120*5;
    printf("\n\n El promedio total de la cantidad de unidades pedidas es %.2f \n\n",prom);
    sum=0;
    for(i=0;i<120;i++)
        sum+=mat[i][4];
    printf("\n La cantidad total de pedidos del estampado 5 es %d \n\n",sum);
    for(i=0;i<120;i++)
        {
        sum=0;
        for(j=0;j<15;j++)
            sum+=mat[i][j];
        if(band==0||sum>may)
            {
            band=1;
            may=sum;
            maymod=i+1;
            }
        }
    printf("\n El número de modelo que tiene la mayor cantidad de unidades pedidas es \n el modelo %d con %d unidades pedidas \n\n",maymod,may);
    getch();
    }
void inicializarmat(int mat[][15],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            mat[i][j]=0;
    }
int valida(char A[],int li,int ls)
    {
    int d;
    do
        {
        printf("%s",A);
        scanf("%d",&d);
        }
    while(!(d>=li&&d<=ls));
    return d;
    }
