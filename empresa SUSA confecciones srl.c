#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicializarm(int[][15],int,int);
void inicializarv(int[],int);
int valida(char[],int,int);
char validal(char[],char,char,char,char);
int funcioncarga(int[],int[],int[],char[]);
int buscar(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int nlp[4000],nd[4000],cp[4000],mes,lp,cup,cant,cudep[4000],pos,depn[15],mat[8][15],i,j;
    char tc[4000];
    printf("\n\t EMPRESA SUSA CONFECCIONES S.R.L \n\n");
    inicializarm(mat,8,15);
    inicializarv(cudep,4000);
    inicializarv(depn,15);
    printf("\n La empresa se dedica a la confección y venta de camisas \n para caballero, señora y niño \n");
    printf("\n Para controlar la producción se requiere que cargue la base de datos: \n");
    printf("\n (Recuerde que este lote finalizará al ingresar tipo de camisa F) \n\n");
    cant=funcioncarga(nlp,nd,cp,tc);
    printf("\n A continuación, cargue los datos de los pedidos realizados \n entre Enero y Agosto. Este lote termina con mes cero.\n\n");
    mes=valida("\n Ingrese el mes (entre 1 y 8): \n\n\t\t",0,8);
    while(mes!=0)
        {
        lp=valida("\n Ingrese el lote de producción (entre 3000 y 5000): \n\n\t\t",3000,5000);
        cup=valida("\n Ingrese la cantidad de unidades pedidas (entre 1 y 100): \n\n\t\t",1,100);
        pos=buscar(nlp,cant,lp);
        if(pos!=0)
            if(cup<=cp[pos])
                {
                cp[pos]-=cup;
                cudep[nd[pos]-1]+=cup;
                mat[mes-1][nd[pos]-1]+=cup;
                }
            else
                printf("\n El stock es insuficiente \n\n");
        else
            printf("\n El número de lote de producción no existe \n Reingrese los datos \n\n");
        mes=valida("\n Ingrese el mes (entre 1 y 8): \n\n\t\t",0,8);
        }
    printf("\n Cantidad de prendas depositadas, por depósito: \n\n");
    printf("\n N°de depósito \t Cantidad de unidades\n");
    for(i=0;i<15;i++)
        printf("\n %d \t\t %d",i+1,cudep[i]);
    printf("\n\n Cantidad de prendas de niño que quedan en stock en cada depósito: \n\n");
    for(i=0;i<cant;i++)
        if(tc[i]=='N')
            depn[nd[i]-1]+=cp[i];
    printf("\n N°de depósito \t Cantidad de prendas de niño \n");
    for(i=0;i<15;i++)
        printf("\n %d \t\t %d",i+1,depn[i]);
    printf("\n\n Stock que ha quedado de cada producto: \n\n");
    printf("\n N°lote de prod \t N°de depósito \t Prendas \t Tipo \n");
    for(i=0;i<cant;i++)
        printf("\n %d \t\t %d \t\t %d \t %c",nlp[i],nd[i],cp[i],tc[i]);
    printf("\n Cantidad de camisas que se han vendido en cada depósito por mes\n\n");
    printf("\nMes  d1   d2   d3  d4   d5   d6   d7   d8   d9   d10  d11  d12  d13  d14 d15\n\n");
    for(i=0;i<8;i++)
        {
        printf("\n%d",i+1);
        for(j=0;j<15;j++)
            printf("    %d",mat[i][j]);
        }
    printf("\n\n Fin del programa \n\n");
    getch();
    }
void inicializarm(int m[][15],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
void inicializarv(int v[],int ce)
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
char validal(char c[],char A,char B,char D,char E)
    {
    char x;
    do
        {
        printf("%s",c);
        scanf("%c",&x);
        }
    while(x!=A&&x!=B&&x!=D&&x!=E);
    return x;
    }
int funcioncarga(int A[],int B[],int C[],char D[])
    {
    int i;
    i=0;
    D[i]=validal("\n Ingrese el tipo de camisa (C,D o N) \n\n\t\t",'C','D','N','F');
    while(D[i]!='F'&&i<4000)
        {
        A[i]=valida("\n Ingrese el lote de producción (entre 3000 y 5000): \n\n\t\t",3000,5000);
        B[i]=valida("\n Ingrese el número de depósito (entre 1 y 15):\n\n\t\t",1,15);
        C[i]=valida("\n Ingrese la cantidad de prendas (entre 1 y 950):\n\n\t\t",1,950);
        i++;
        D[i]=validal("\n Ingrese el tipo de camisa (C,D o N) \n\n\t\t",'C','D','N','F');
        }
    return i;
    }
int buscar(int v[],int ce,int x)
    {
    int p,i;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        if(v[i]==x)
            p=i;
        else
            i++;
    return p;
    }
