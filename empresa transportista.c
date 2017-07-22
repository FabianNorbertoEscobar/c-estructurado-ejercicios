#include<stdio.h>
#include<conio.h>
#include<locale.h>
int valida(float,int,int);
void inicializarvec(float[],int);
float funcionprecio(float,float);
int busqueda(int,int[],int);
void funcionpuntoc(float[],int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int vnroc[200],i,nroc,pos,kgs;
    float vrecaudxc[200],vkgsxc[200],valorkm,kms,precio;
    inicializarvec(vrecaudxc,200);
    inicializarvec(vkgsxc,200);
    printf("\n Empresa transportista \n\n");
    printf("\n Realice la carga de los números de camiones \n con los que cuenta la empresa \n\n");
    for(i=0;i<200;i++)
        {
        do
            {
            printf("\n Ingrese el número de un camión: (entre 100 y 999): \n\n\t\t");
            scanf("%d",&vnroc[i]);
            }
        while(!valida(vnroc[i],100,999));
        }
    do
        {
        printf("\n Ingrese el valor del importe que se cobrará \n por kilómetro en el mes de Abril: \n\n\t\t");
        scanf("%f",&valorkm);
        }
    while(valorkm<=0);
    printf("\n\n A continuación, ingrese los datos de cada viaje: \n\n");
    do
        {
        printf("\n Ingrese el número de un camión: (entre 100 y 999): \n\n\t\t");
        scanf("%d",&nroc);
        }
    while(!(valida(nroc,100,999)||nroc==0));
    while(nroc!=0)
        {
        pos=busqueda(nroc,vnroc,200);
        if(pos!=-1)
            {
            do
                {
                printf("\n Ingrese la cantidad de kilogramos transportados (entre 1000 y 10000): \n\n\t\t");
                scanf("%d",&kgs);
                }
            while(!valida(kgs,1000,10000));
            do
                {
                printf("\n Ingrese la cantidad de kilómetros recorridos:\n\n\t\t");
                scanf("%f",&kms);
                }
            while(kms<=0);
            precio=funcionprecio(valorkm,kms);
            printf("\n El camión %d deberá cobrar un importe de %.2f \n\n",precio);
            vrecaudxc[pos]+=precio;
            vkgsxc[pos]+=kgs;
            }
        else
            printf("\n No existe el número de camión %d \n\t Reingrese un dato correcto: \n",nroc);
        do
            {
            printf("\n Ingrese el número de un camión: (entre 100 y 999): \n\n\t\t");
            scanf("%d",&nroc);
            }
        while(!(valida(nroc,100,999)||nroc==0));
        }
    printf("\n El número de camión que más recaudó en el mes de Abril fue: \n\n");
    funcionpuntoc(vrecaudxc,vnroc,200);
    printf("\n Informe final de viajes del mes \n\n");
    printf("\n N°Camión \t Kgs transportados \t Importe recaudado\n\n");
    for(i=0;i<200;i++)
        printf("\n %d \t %d \t %.2f",vnroc[i],vkgsxc[i],vrecaudxc[i]);
    getch();
    }
int valida(float x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void inicializarvec(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
float funcionprecio(float valor,float k)
    {
    float r;
    r=valor*k;
    return r;
    }
int busqueda(int n,int v[],int ce)
    {
    int p,i;
    p=-1;
    i=0;
    while(i<ce&&p==-1)
        if(v[i]==n)
            p=i;
        else
            i++;
    return p;
    }
void funcionpuntoc(float r[],int c[],int ce)
    {
    int i;
    float may;
    for(i=0;i<ce;i++)
        if(i==0||r[i]>may)
            may=r[i];
    for(i=0;i<ce;i++)
        if(r[i]==may)
            printf("\n %d",c[i]);
    }
