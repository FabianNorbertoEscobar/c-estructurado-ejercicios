#include<stdio.h>
#include<conio.h>
#include<locale.h>
void funcioncarga(int[],int[],int[],float[],char[][41]);
void inicializa(int[],int);
int valida(int,int);
int buscar(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int ca[100],cp[100],cd[100],coda,codp,casoc,contp[100],conta[100],band,i,may,mayact,pos,maypos;
    float pa[100],sum;
    char np[100][41],vnom[50][81];
    printf("\n\t CLUB DE DEPORTES \n\n");
    printf("\n Realice la carga de la base de datos del club \n");
    funcioncarga(ca,cp,cd,pa,np);
    inicializa(contp,100);
    inicializa(conta,50);
    band=0;
    sum=0;
    printf("\n A continuación, se realizará el control de las actividades deportivas \n");
    printf("\n Ingrese la información de las cuotas que abonaron los socios en el mes de Agosto\n");
    printf("\n Ingrese el código de actividad (entre 1 y 50) \n (Finalice la carga de datos con número de artículo)\n\n");
    coda=valida(0,50);
    while(coda!=0)
        {
        printf("\n Ingrese el código de profesor (entre 1 y 3000)\n\n");
        codp=valida(1,3000);
        printf("\n Ingrese el código de asociado (entre 1 y 5000) \n\n");
        casoc=valida(1,5000);
        pos=buscar(cp,100,codp);
        if(pos!=-1)
            {
            sum+=pa[pos];
            conta[coda-1]++;
            contp[pos]++;
            }
        printf("\n Ingrese el código de actividad (entre 1 y 50) \n (Finalice la carga de datos con número de artículo)\n\n");
        coda=valida(0,50);
        }
    printf("\n\n El monto total abonado por socios en Agosto es de %.2f \n",sum);
    for(i=0;i<50;i++)
        if(band==0||conta[i]>may)
            {
            band=1;
            may=conta[i];
            mayact=i+1;
            }
    printf("\n Actividad con mayor cantidad de asociados\n Código de actividad:%d \t Asociados:%d \n\n",mayact,may);
    band=0;
    for(i=0;i<50;i++)
        if(band==0||contp[i]>may)
            {
            band=1;
            may=contp[i];
            maypos=i;
            }
    printf("\n Datos del profesor que más asociados tuvo\n Código del profesor:%d \t Nombre del profesor:%s \n\n",cp[maypos],np[maypos]);
    getch();
    }
void funcioncarga(int A[],int B[],int C[],float D[],char E[][41])
    {
    int i;
    for(i=0;i<100;i++)
        {
        printf("\n Ingrese el código de actividad (entre 1 y 50)\n\n");
        A[i]=valida(1,50);
        printf("\n Ingrese el código de profesor (entre 1 y 3000)\n\n");
        B[i]=valida(1,3000);
        printf("\n Ingrese la cantidad de días que se dicta (entre 1 y 7)\n\n");
        C[i]=valida(1,7);
        do
            {
            printf("\n Ingrese el precio de la actividad: \n\n");
            scanf("%f",&D[i]);
            }
        while(D[i]<=0);
        printf("\n Ingrese el nombre del profesor: \n\n");
        fflush(stdin);
        gets(E[i]);
        }
    }
void inicializa(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int valida(int li,int ls)
    {
    int x;
    do
        {
        scanf("%d",&x);
        }
    while(!(x>=li&&x<=ls));
    return x;
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
