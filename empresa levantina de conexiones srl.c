#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
void inicializarvec(int[],int);
void inicializarmat(int[][31],int,int);
int valida(char[],int,int);
int funcioncarga(int[],int[],int[],char[][31]);
int buscar(int[],int,int);
void funcionpuntob(int[],char[],int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int np[8000],st[8000],pr[8000],cant,prod,dia,cuv,vec[8000],sum[8000],may,i,mat[1200][31],band,j,m,pos;
    char des[8000];
    printf("\n\t EMPRESA LEVANTINA DE CONEXIONES SRL \n\n");
    printf("\n La empresa se dedica a la fabricación, montaje y venta por mayor y menor \n");
    printf(" de cables,conexiones eléctricas y electrónicas, y componetes: \n");
    printf("\n Para realizar los controles pertinentes necesitamos que cargue la base de datos\n (Ingrese la descripción FINAL para finalizar) \n\n");
    cant=funcioncarga(np,st,pr,des);
    inicializarvec(vec,cant);
    inicializarvec(sum,cant);
    inicializarmat(mat,1200,31);
    printf("\n A continuación, ingresar los datos de las ventas de Agosto: \n (finalizar con número de producto inexistente: \n");
    prod=valida("\n Ingrese el número de producto (entre 1 y 1200): \n\n\t\t",1,1200);
    pos=buscar(np,cant,prod);
    while(pos!=-1)
        {
        dia=valida("\n Ingrese el día del mes (1 a 31): \n\n\t\t",1,31);
        cuv=valida("\n Ingrese la cantidad de unidades vendidas (entre 1 y 100):\n\n\t\t",1,100);
        if(cuv<=st[pos])
            {
            st[pos]-=cuv;
            vec[pos]++;
            sum[pos]+=cuv;
            mat[prod-1][dia-1]+=cuv;
            }
        else
            printf("\n\n Stock insuficiente \n\n");
        i++;
        prod=valida("\n Ingrese el número de producto (entre 1 y 1200): \n\n\t\t",1,1200);
        pos=buscar(np,cant,prod);
        }
    printf("\n Productos que han quedado por debajo del punto de reposición: \n\n");
    printf("\n N° DE PRODUCTO \t DESCRIPCIÓN \n");
    for(i=0;i<cant;i++)
        if(st[i]<pr[i])
            printf("\n %d \t\t %s",np[i],des[i]);
    printf("\n\n Cantidad de pedidos realizados por cada producto :\n");
    printf("\n N° DE PRODUCTO \t DESCRIPCIÓN \t CANTIDAD \n");
    funcionpuntob(np,des,vec,cant);
    band=0;
    for(i=0;i<cant;i++)
        if(band==0||sum[i]>may)
            {
            band=1;
            may=sum[i];
            }
    printf("\n La mayor cantidad de unidades pedida fue: %d \n y se trató del siguiente producto: \n",may);
    for(i=0;i<cant;i++)
        if(may==sum[i])
            printf("\n Número de producto: %d \t Descripción: %s \n",np[i],des[i]);
    printf("\n Cantidad de unidades solicitadas por dia y número de producto: \n");
    for(i=0;i<31;i++)
        for(j=0;j<1200;j++)
            if(mat[i][j]!=0)
                printf("\t %d",mat[i][j]);
    printf("\n\n Fin del programa ... \n\n");
    getch();
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void inicializarmat(int m[][31],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
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
int funcioncarga(int A[],int B[],int C[],char D[][31])
    {
    int i=0,prod,st,pr;
    char des[31];
    fflush(stdin);
    printf("\n Ingrese la descripción del producto (hasta 30 caracteres): \n\n\t\t");
    gets(des);
    while(strcmp(des,"FINAL")!=0&&i<8000)
        {
        strcpy(D[i],des);
        prod=valida("\n Ingrese el número de producto (entre 1 y 1200): \n\n\t\t",1,1200);
        A[i]=prod;
        st=valida("\n Ingrese el número de stock (entre 1 y 10000): \n\n\t\t",1,10000);
        B[i]=st;
        pr=valida("\n Ingrese el punto de reposición (entre 3000 a 6000):\n\n\t\t",3000,6000);
        C[i]=pr;
        i++;
        fflush(stdin);
        printf("\n Ingrese la descripción del producto (hasta 30 caracteres): \n\n\t\t");
        gets(des);
        }
    return i;
    }
int buscar(int v[],int ce,int x)
    {
    int p,i;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        {
        if(v[i]==x)
            p=i;
        else
            i++;
        }
    return p;
    }
void funcionpuntob(int A[],char B[],int C[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t\t %s \t %d",A[i],B[i],C[i]);
    }
