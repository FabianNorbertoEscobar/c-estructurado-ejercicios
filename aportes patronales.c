#include<stdio.h>
#include<conio.h>
#include<locale.h>
int cargarmat(float[][12],int,int);
void ordinarios(int[],int);
void inicmat(float[][12],int,int);
void inicvec(float[],int);
void sumarxfila(float[][12],int,int,float[]);
void sumarxcolumna(float[][12],int,int,float[]);
void mostrarvector(float[],int);
int validadato(int,int,int);
void minimo(float[][12],int,int,float[]);
void mostrarminimo(float[][12],int,int,float[]);
float maximo(float[],int);
void mostrarmaximos(float[],int,float);
void ordenarmayor(float[],int[],int);
float sumar(float[],int);
void mostrar(int[],float[],int);
void porcentaje(float[],int,float,float[]);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int meses[12],ce;
    float mat[45][12],vos[45],apmin[45],per[45],vmes[12],max,totap;
    printf("\n\n APORTES PATRONALES \n\n");
    printf("\n Ingrese los aportes del último año en concepto  \n de pagos efectuados por las empresas. \n");
    printf("Se pide: código de obra social (entre 1 y 45), el mes y el monto aportado. \n");
    printf("Finalice la carga de datos con obra social igual a cero. \n\n");
    inicmat(mat,45,12);
    inicvec(vos,45);
    inicvec(vmes,12);
    ce=cargarmat(mat,45,12);
    ordinarios(meses,45);
    if(ce!=0)
        {
        sumarxfila(mat,45,12,vos);
        sumarxcolumna(mat,45,12,vmes);
        printf("\n OBRA SOCIAL \t APORTE ANUAL \n");
        mostrarvector(vos,45);
        minimo(mat,45,12,apmin);
        max=maximo(vos,45);
        printf("\n\n Las obras sociales que recibieron más aportes son: \n");
        mostrarmaximos(vos,45,max);
        ordenarmayor(vmes,meses,12);
        printf("\n MES \t TOTAL APORTADO \n");
        mostrar(meses,vmes,12);
        totap=sumar(vos,45);
        porcentaje(vos,45,totap,per);
        printf("\n OBRA SOCIAL \t PORCENTAJE DEL APORTE TOTAL \n");
        mostrarvector(per,45);
        }
    else
        printf("\n\n No se efectuaron aportes patronales. \n\n");
    getch();
    }
int cargarmat(float m[][12],int f,int c)
    {
    int i,os,me;
    float ap;
    i=0;
    do
        {
        printf("\n\n Ingrese el código de obra social del aporte %d: \n\n\t",i+1);
        scanf("%d",&os);
        printf("\n\n Ingrese el mes (en números) del aporte %d: \n\n\t",i+1);
        scanf("%d",&me);
        printf("\n\n Ingrese el monto aportado por la empresa del aporte %d: \n\n\t",i+1);
        scanf("%f",&ap);
        }
    while(!validadato(os,0,45)||!validadato(me,1,12)||ap<0);
    while(os!=0)
        {
        m[os-1][me-1]+=ap;
        i++;
        do
            {
            printf("\n\n Ingrese el código de obra social del aporte %d: \n\n\t",i+1);
            scanf("%d",&os);
            printf("\n\n Ingrese el mes (en números) del aporte %d: \n\n\t",i+1);
            scanf("%d",&me);
            printf("\n\n Ingrese el monto aportado por la empresa del aporte %d: \n\n\t",i+1);
            scanf("%f",&ap);
            }
        while(!validadato(os,0,45)||!validadato(me,1,12)||ap<0);
        }
    return i;
    }
void ordinarios(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=i+1;
    }
void inicmat(float m[][12],int f,int c)
    {
    int j,i;
    for(j=0;j<c;j++)
        for(i=0;i<f;i++)
            m[i][j]=0;
    }
void inicvec(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void sumarxfila(float m[][12],int f,int c,float v[])
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            v[i]+=m[i][j];
    }
void sumarxcolumna(float m[][12],int f,int c,float v[])
    {
    int i,j;
    for(j=0;j<c;j++)
        for(i=0;i<f;i++)
            v[j]+=m[i][j];
    }
void mostrarvector(float p[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %f",i+1,p[i]);
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void minimo(float m[][12],int f,int c,float v[])
    {
    int i,j;
    float min;
    for(i=0;i<f;i++)
        {
        for(j=0;j<c;j++)
            if(j==0||m[i][j]<min)
                min=m[i][j];
        v[i]=min;
        }
    }
void mostrarminimo(float m[][12],int f,int c,float v[])
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n %d",i+1);
        for(j=0;j<c;j++)
            if(m[i][j]==v[i])
                printf("\t %d \n",j+1);
        }
    }
float maximo(float v[],int ce)
    {
    int i;
    float max;
    for(i=0;i<ce;i++)
        if(i==0||v[i]>max)
            max=v[i];
    return max;
    }
void mostrarmaximos(float v[],int ce,float x)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            printf("\n %d",i+1);
    }
void ordenarmayor(float vm[],int m[],int ce)
    {
    int i,j,pm,aux2;
    float aux1;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(vm[i]>vm[j-1])
                pm=i;
        aux1=vm[pm];
        vm[pm]=vm[j-1];
        vm[j-1]=aux1;
        aux2=m[pm];
        m[pm]=m[j-1];
        m[j-1]=aux2;
        }
    }
float sumar(float v[],int ce)
    {
    int i;
    float acum;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum;
    }
void mostrar(int m[],float vm[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("\n %d \t %f",m[i],vm[i]);
    }
void porcentaje(float os[],int ce,float tot,float p[])
    {
    int i;
    for(i=0;i<ce;i++)
        p[i]=os[i]*100/tot;
    }
