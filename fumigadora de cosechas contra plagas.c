#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicializarmat(int[][12],int,int);
void inicializarveci(int[],int);
void inicializarvecf(float[],int);
int fechavalida(int,int,int);
int bisiesto(int);
int cantdiasmes(int,int);
void fecha(void);
int valida(int,int,int);
float funcionpuntoc(int,int);
void funcionpuntob(int[][12],int,int);
int funcionpuntoe(float[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[50][12],vgus[12],nrog,contl,contgral,tipof,cantm2,mes,valor,i,posnya;
    float vimp[50],imp,porc;
    char nya[50][40];
    inicializarmat(mat,50,12);
    inicializarvecf(vimp,50);
    inicializarveci(vgus,12);
    contl=contgral=0;
    printf("\n Compañía fumigadora de cosechas contra plagas \n\n\a\a");
    printf("\n Se solicitará que se ingresen los datos de las fumigaciones \n para realizar los informes correspondientes \n");
    printf("\n Los tipos de fumigaciones son: \n");
    printf("\n TIPO 1:\t fumigación contra malas hierbas \t\t a $18 el m2");
    printf("\n TIPO 2:\t fumigación contra langostas \t\t\t a $20 el m2");
    printf("\n TIPO 3:\t fumigación contra gusanos \t\t\t a $22 el m2");
    printf("\n TIPO 4:\t fumigación contra todo lo anterior \t\t a $30 el m2 \n\n");
    fecha();
    printf("\n\t\t DATOS \n\n (la carga de los datos finalizará al ingresar número de granjero cero)\n\n");
    do
        {
        printf("\n Ingrese el número de granjero (entre 1 y 50): \n\n");
        scanf("%d",&nrog);
        }
    while(!valida(nrog,0,50));
    while(nrog!=0)
        {
        fflush(stdin);
        printf("\n Ingrese el nombre y apellido del granjero: \n\n");
        gets(nya[nrog-1]);
        contgral++;
        do
            {
            printf("\n Ingrese el tipo de fumigación (entre 1 y 4): \n\n");
            scanf("%d",&tipof);
            }
        while(!valida(tipof,1,4));
        do
            {
            printf("\n Ingrese la cantidad de metros cuadrados a fumigar (mínimo 1 m2):\n\n");
            scanf("%d",&cantm2);
            }
        while(cantm2<1);
        do
            {
            printf("\n Ingrese el mes en que se desea fumigar: \n\n");
            scanf("%d",&mes);
            }
        while(!valida(mes,1,12));
        switch(tipof)
            {
            case 1: valor=18;
                    break;
            case 2: valor=20;
                    contl++;
                    break;
            case 3: valor=22;
                    vgus[mes-1]++;
                    break;
            case 4: valor=30;
                    break;
            }
        imp=cantm2*valor;
        if(cantm2>10000)
            {
            printf("\n Este granjero goza de un descuento del 7% \n\n");
            imp*=0.93;
            }
        vimp[nrog-1]+=imp;
        mat[nrog-1][mes-1]=1;
        printf("\n Factura del pedido ingresado:\n");
        printf("\n N°de granjero:%d \t Importe:%.2f \t Mes:%d \n\n",nrog,imp,mes);
        do
            {
            printf("\n Ingrese el número de granjero (entre 1 y 50): \n\n");
            scanf("%d",&nrog);
            }
        while(!valida(nrog,0,50));
        }
    printf("\a\a\n Números de granjeros que hicieron fumigaciones en más de 3 meses: \n\n");
    funcionpuntob(mat,50,12);
    porc=funcionpuntoc(contgral,contl);
    printf("\n El porcentaje total de fumigaciones contra langostas es de %.2f \n\n",porc);
    printf("\n Mes \t\t Cantidad de fumigaciones contra gusanos \n");
    for(i=0;i<12;i++)
        printf("\n %d \t\t %d",i+1,vgus[i]);
    posnya=funcionpuntoe(vimp,50);
    printf("\n\n El nombre y apellido del granjero que facturó más dinero en el año es:\n\n\t");
    puts(nya[posnya]);
    printf("\n\n Fin del programa \n\n");
    getch();
    }
void inicializarmat(int mat[][12],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            mat[i][j]=0;
    }
void inicializarveci(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void inicializarvecf(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int fechavalida(int d,int m,int a)
    {
    if(a>1600&&m>=1&&m<=12&&d>=1&&d<=cantdiasmes(m,a))
        return 1;
    else
        return 0;
    }
int bisiesto(int a)
    {
    if((a%4==0&&a%100!=0)||a%400==0)
        return 1;
    else
        return 0;
    }
int cantdiasmes(int m,int a)
    {
    int cd;
    if(m==4||m==6||m==9||m==11)
        cd=30;
    else
        if(m==2)
            cd=28+bisiesto(a);
        else
            cd=31;
    return cd;
    }
void fecha(void)
    {
    int d,m,a;
    do
        {
        printf("\n Ingrese la fecha del proceso: \n\n");
        printf("\n Día: \t\t");
        scanf("%d",&d);
        printf("\n Mes: \t\t");
        scanf("%d",&m);
        printf("\n Año: \t\t");
        scanf("%d",&a);
        }
    while(!fechavalida(d,m,a));
    printf("\n\t FECHA DEL PROCESO: %d/%d/%d \n\n",d,m,a);
    }
int valida(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
float funcionpuntoc(int g,int l)
    {
    if(g>0)
        return (float)l*100/g;
    else
        return 0;
    }
void funcionpuntob(int mat[][12],int f,int c)
    {
    int sum,x,p;
    for(x=0;x<f;x++)
        {
        sum=0;
        for(p=0;p<c;p++)
            sum+=mat[x][p];
        if(sum>3)
            printf("\n %d",x+1);
        }
    }
int funcionpuntoe(float v[],int ce)
    {
    int i,band,maypos;
    float mayimp;
    band=0;
    for(i=0;i<ce;i++)
        if(band==0||v[i]>mayimp)
            {
            band=1;
            mayimp=v[i];
            maypos=i;
            }
    return maypos;
    }
