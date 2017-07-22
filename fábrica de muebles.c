#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicializar(int[],int);
void ponerencero(int[],int);
void mostrar(int[],int);
int maximo(int[],int);
void cargarvectores(int[],int[],int[]);
void mostrarmaximos(int[],int,int);
void ordenarmenor(int[],int[],int);
void listar(int[],int[],int);
int contar(int[],int,int);
int validadato(int,int,int);
void diasencero(int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int aux[25],operarios[25],muebles[14],diahabil[22],max,ceros;
    printf("\n\n Ingrese la fabricación del mes para realizar un resumen mensual.\n");
    printf("Hay 22 días hábiles,14 tipos de muebles y 25 operarios. \n");
    printf("Ingrese un día hábil negativo para finalizar la carga de datos. \n");
    printf("Ingrese día, tipo y operario para cada fabricación \n\n");
    inicializar(aux,25);
    ponerencero(operarios,25);
    ponerencero(muebles,14);
    ponerencero(diahabil,22);
    cargarvectores(operarios,muebles,diahabil);
    printf("\n\n TIPO DE MUEBLE \t CANTIDAD FABRICADA \n\n");
    mostrar(muebles,14);
    max=maximo(muebles,14);
    printf("\n Tipo de mueble más fabricado: \n\n");
    mostrarmaximos(muebles,14,max);
    ordenarmenor(operarios,aux,25);
    printf("\n CÓDIGO DE OPERARIO \t CANTIDAD DE MUEBLES FABRICADA \n\n");
    listar(aux,operarios,25);
    ceros=contar(diahabil,22,0);
    if(ceros!=0)
        {
        printf("\n\n Los días en que no hubo producción son: \n\n");
        diasencero(diahabil,22);
        }
    else
        printf("\n\n Todos los días hubo producción \n\n");
    getch();
    }
void inicializar(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=i+1;
    }
void ponerencero(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void mostrar(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %d",i+1,v[i]);
    }
int maximo(int v[],int ce)
    {
    int i,max;
    for(i=0;i<ce;i++)
        if(i==0||v[i]>max)
            max=v[i];
    return max;
    }
void cargarvectores(int op[],int tm[],int dh[])
    {
    int i,dh1,tm1,op1;
    i=0;
    do
        {
        printf("\n\n Fabricación número %d \n",i+1);
        printf("\n\n Ingrese el día hábil (1 a 22): \n\n\t");
        scanf("%d",&dh1);
        printf("\n\n Ingrese el tipo de mueble (1 a 14): \n\n\t");
        scanf("%d",&tm1);
        printf("\n\n Ingrese el código de operario encargado (1 a 25): \n\n\t");
        scanf("%d",&op1);
        }
    while((dh1>=0&&!validadato(dh1,1,22))||!validadato(tm1,1,14)||!validadato(op1,1,25));
    while(dh1>=0)
        {
        dh[dh1-1]=1;
        tm[tm1-1]++;
        i++;
        op[op1-1]++;
        do
            {
            printf("\n\n Fabricación número %d \n",i+1);
            printf("\n\n Ingrese el día hábil (1 a 22): \n\n\t");
            scanf("%d",&dh1);
            printf("\n\n Ingrese el tipo de mueble (1 a 14): \n\n\t");
            scanf("%d",&tm1);
            printf("\n\n Ingrese el código de operario encargado (1 a 25): \n\n\t");
            scanf("%d",&op1);
            }
        while((dh1>=0&&!validadato(dh1,1,22))||!validadato(tm1,1,14)||!validadato(op1,1,25));
        }
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void mostrarmaximos(int v[],int ce,int max)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]==max)
            printf(" \n %d",i+1);
    }
void ordenarmenor(int op[],int aux[],int ce)
    {
    int i,j,pm,aux1,aux2;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(op[i]<op[pm])
                pm=i;
        aux1=op[pm];
        op[pm]=op[j-1];
        op[j-1]=aux1;
        aux2=aux[pm];
        aux[pm]=aux[j-1];
        aux[j-1]=aux2;
        }
    }
void listar(int a[],int o[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %d",a[i],o[i]);
    }
int contar(int v[],int ce,int x)
    {
    int i,cont;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            cont++;
    return cont;
    }
void diasencero(int d[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        if(d[i]==0)
            printf("%d \n",d[i]);
    }
