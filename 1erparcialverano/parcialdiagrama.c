#include<stdio.h>
#include<conio.h>
#include<locale.h>
void cargardatos(int[],char[][31],float[],float[],int[],int[],int[]);
void inicializarvec(int[],int);
int busqueda(int[],int,int);
int valida(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int vcod[500],dia[500],mes[500],eventxm[12],cod,pos,i;
    char det[500];
    float vadel[500],cost[500],adel;
    printf("\n Empresa de organización de eventos \n");
    printf("\n Tenemos confirmada la realización de 500 eventos. \n");
    printf("\n Cargue los datos de cada uno de ellos: \n\n");
    inicializarvec(eventxm,12);
    cargardatos(vcod,det,vadel,cost,dia,mes,eventxm);
    printf("\n Ahora ingrese un lote de datos con los adelantos recibidos: \n");
    printf("\n La carga de datos finalizará cuando ingrese código de evento 100:\n");
    printf("\n Ingrese el código del evento (entre 101 y 1000): \n\n\t\t");
    do
        {
        scanf("%d",&cod);
        }
    while(!valida(cod,100,1000));
    while(cod!=100)
        {
        pos=busqueda(vcod,500,cod);
        if(pos!=-1)
            {
            printf("\n Ingrese el adelanto recibido: \n\n\t\t");
            do
                {
                scanf("%f",&adel);
                }
            while(adel<=0);
            vadel[pos]+=adel;
            }
        else
            printf("\n El código ingresado NO corresponde a un evento \n Ingrese un nuevo código: \n");
         printf("\n Ingrese el código del evento (entre 101 y 1000): \n\n\t\t");
        do
            {
            scanf("%d",&cod);
            }
        while(!valida(cod,100,1000));
        }
    printf("\n Datos de los eventos cuyo costo fue cancelado: \n\n");
    for(i=0;i<500;i++)
        if(vadel[i]=cost[i])
            printf("\n Código:%d \t Detalles:%s \t Adelanto:%.2f \n Costo:%.2f \t Día:%d \t Mes:%d \n",vcod[i],det[i],vadel[i],cost[i],dia[i],mes[i]);
    printf("\n Cantidad de eventos mensuales: \n");
    printf("\n MES \t CANTIDAD \n");
    for(i=0;i<12;i++)
        printf("\n %d \t %d",i+1,eventxm);
    getch();
    }
void cargardatos(int A[],char B[][31],float C[],float D[],int E[],int F[],int G[])
    {
    int i;
    for(i=0;i<500;i++)
        {
        printf("\n Ingrese el código del evento (entre 101 y 1000):\n\n\t\t");
        do
            {
            scanf("%d",&A[i]);
            }
        while(!valida(A[i],101,1000));
        printf("\n Ingrese los detalles del evento (hasta 100 caracteres): \n\n\t\t");
        fflush(stdin);
        gets(B[i]);
        printf("\n Ingrese el adelanto recibido: \n\n\t\t");
        do
            {
            scanf("%f",&C[i]);
            }
        while(C[i]<=0);
        printf("\n Ingrese el costo del evento: \n\n\t\t");
        do
            {
            scanf("%f",&D[i]);
            }
        while(D[i]<=0);
        printf("\n Ingrese el día: \n\n\t\t");
        do
            {
            scanf("%d",&E[i]);
            }
        while(!valida(E[i],1,31));
        printf("\n Ingrese el mes: \n\n\t\t");
        do
            {
            scanf("%d",&F[i]);
            }
        while(!valida(F[i],1,12));
        G[F[i]-1]++;
        }
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int busqueda(int v[],int ce,int x)
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
int valida(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
