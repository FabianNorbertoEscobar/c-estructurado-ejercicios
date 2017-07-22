#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
int funcioncarga(int[],int[],char[],int[],int[],char[]);
void inicializarmat(int[][15],int,int);
void funcion1(int,int,int[],int[]);
int valida(char[],int,int,int);
char valida2(char[],char,char,char);
int busqueda(int,int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int np[9000],nc[9000],cmm[9000],cup[9000],cant,i,j,viejo,ped,mat[5000][15],pos,t;
    char mm[9000],ep[9000];
    printf("\n\t EMPRESA OFUSO S.R.L. \n\n");
    inicializarmat(mat,5000,15);
    printf("\n La empresa de comercialización de artesanía del punto y venta, \n y alquiler de maquinería para confección de \n");
    printf(" géneros de punto, desea controlar los pedidos, y para ello, \n necesita que se cargue la base de datos de sus casi 9000 pedidos \n\n");
    printf("\n La carga de la base de datos finaliza con pedido 0 \n\n");
    cant=funcioncarga(np,nc,mm,cmm,cup,ep);
    viejo=cant;
    printf("\n A continuación, debe ingresar los números de pedido de aquellos que \n han sido cumplidos. El lote finaliza con 0. \n");
    printf("\n También puede ingresar un nuevo número de pedido: en ese caso, \n el sistema le solicitará los datos faltantes. \n\n");
    ped=valida("\n Ingrese el número de pedido (entre 1000 y 1500): \n\n\t\t",1000,1500,0);
    while(ped!=0)
        {
        pos=busqueda(ped,np,cant);
        if(pos!=-1)
            ep[pos]='S';
        else
            if(cant<9000)
                {
                printf("\n Se ha ingresado un nuevo pedido. Ingrese el resto de los datos: \n\n");
                np[cant]=ped;
                nc[cant]=valida("\n Ingrese el número de cliente (entre 1 y 5000):\n\n\t\t",1,5000,5000);
                mm[cant]=valida2("\n Ingrese el modelo de máquina (A, B o C):\n\n\t\t",'A','B','C');
                cmm[cant]=valida("\n Ingrese la característica (entre 1 y 15):\n\n\t\t",1,15,15);
                cup[cant]=valida("\n Ingrese la cantidad de unidades pedidas (entre 50 y 600):\n\n\t\t",50,600,600);
                ep[cant]='N';
                cant++;
                }
            else
                printf("\n No se pueden agregar más pedidos (ya se encargaron 9000 pedidos)\n\n");
            ped=valida("\n Ingrese el número de pedido (entre 1000 y 1500): \n\n\t\t",1000,1500,0);
        }
    printf("\n\n Datos de los pedidos que han sido cumplidos \n\n");
    printf(" N° de pedido \t N° de cliente \n");
    for(i=0;i<cant;i++)
        if(ep[i]='S')
            printf("\n %d \t\t %d",np[i],nc[i]);
    printf("\n\n Datos de los pedidos no cumplidos de modelo C y característica 2:\n\n");
    printf(" N° de pedido \t N° de cliente \n");
    for(i=0;i<cant;i++)
        if(ep[i]=='N'&&mm[i]=='C'&&cmm[i]==2)
            printf("\n %d \t\t %d",np[i],nc[i]);
    printf("\n\n Datos de los nuevos pedidos ingresados:\n\n");
    printf(" N° de pedido \t N° de cliente \n");
    funcion1(viejo,cant,np,nc);
    printf("\n Para continuar, presione una tecla cualquiera.\n\n");
    getch();
    printf("\n\n Cantidad de unidades pedidas discriminadas por \n número de cliente y característica: \n\n");
    printf("\nClien  c1  c2  c3  c4  c5  c6  c7  c8  c9  c10 c11 c12 c13 c14 c15\n\n");
    for(i=0;i<cant;i++)
        mat[nc[i]-1][cmm[i]-1]+=cup[i];
    for(i=0;i<5000;i++)
        {
        printf("\n%d,",i+1);
        for(j=0;j<15;j++)
            printf("   %d",mat[i][j]);
        t=10;
        while(--t)
            {
            Sleep(10);
            }
        }
    printf("\n\n Fin del programa \n\n");
    getch();
    }
int funcioncarga(int A[],int B[],char C[],int D[],int E[],char F[])
    {
    int i,ped,nc,cup,cmm;
    char mm,ep;
    i=0;
    ped=valida("\n Ingrese el número de pedido (entre 1000 y 1500): \n\n\t\t",1000,1500,0);
    while(ped!=0&&i<9000)
        {
        A[i]=ped;
        nc=valida("\n Ingrese el número de cliente (entre 1 y 5000):\n\n\t\t",1,5000,5000);
        B[i]=nc;
        mm=valida2("\n Ingrese el modelo de máquina (A, B o C):\n\n\t\t",'A','B','C');
        C[i]=mm;
        cmm=valida("\n Ingrese la característica (entre 1 y 15):\n\n\t\t",1,15,15);
        D[i]=cmm;
        cup=valida("\n Ingrese la cantidad de unidades pedidas (entre 50 y 600):\n\n\t\t",50,600,600);
        E[i]=cup;
        ep=valida2("\n Ingrese el estado del pedido (S:Sí  N:No):\n\n\t\t",'S','N','N');
        F[i]=ep;
        i++;
        ped=valida("\n Ingrese el número de pedido (entre 1000 y 1500): \n\n\t\t",1000,1500,0);
        }
    return i;
    }
void inicializarmat(int m[][15],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
void funcion1(int a,int b,int c[],int d[])
    {
    int i;
    for(i=a;i<b;i++)
        printf("\n %d \t\t %d",c[i],d[i]);
    }
int valida(char c[],int li,int ls,int x)
    {
    int f;
    do
        {
        printf("%s",c);
        scanf("%d",&f);
        }
    while(!((f>=li&&f<=ls)||f==x));
    return f;
    }
char valida2(char c[],char A,char B,char C)
    {
    char x;
    do
        {
        fflush(stdin);
        printf("%s",c);
        scanf("%c",&x);
        }
    while(!(x==A||x==B||x==C));
    return x;
    }
int busqueda(int n,int v[],int ce)
    {
    int p,i;
    p=-1;
    i=0;
    while(i<ce&&p==-1)
        {
        if(v[i]==n)
            p=i;
        else
            i++;
        }
    return p;
    }
