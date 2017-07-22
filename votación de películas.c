#include<stdio.h>
#include<conio.h>
#include<locale.h>
void inicmat(int[][10],int,int);
void inicvec(int[],int);
int cargarvotos(int[][10],int,int);
void mostrarxfila(int[][10],int,int);
void sumarxfila(int[][10],int,int,int[]);
int contarsi(int[],int,int);
void mostrarsi(int[],int,int);
void maximoxsemana(int[][10],int,int,int[]);
void mostrarmax(int[][10],int,int,int[]);
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[100][10],vpel[100],ce,ceros,vsem[10];
    printf("\n\n Ingrese los votos que se han recaudado por teléfono. Se pide: \n");
    printf(" el código de la película (de 1 a 100) y el número de semana \n en que fue votada (de 1 a 10) \n");
    printf(" Finalice la carga de datos ingresando una semana negativa. \n\n");
    inicmat(mat,100,10);
    inicvec(vpel,100);
    ce=cargarvotos(mat,100,10);
    if(ce!=0)
        {
        printf("\n Película S1\tS2\tS3\tS4\tS5\tS6\tS7\tS8\tS9\tS10 \n\n");
        mostrarxfila(mat,100,10);
        sumarxfila(mat,100,10,vpel);
        ceros=contarsi(vpel,100,0);
        if(ceros!=0)
            {
            printf("\n\n Códigos de películas que no han tenido votos \n");
            mostrarsi(vpel,100,0);
            }
        else
            printf("\n\n Todas las películas recibieron votos \n\n");
        maximoxsemana(mat,100,10,vsem);
        printf("\n\n Vehículos más votados por semana: \n\n");
        printf(" Semana \t Más votada \n\n");
        mostrarmax(mat,100,10,vsem);
        }
    else
        printf("\n\n No se ingresaron votos. \n\n");
    getch();
    }
void inicmat(int m[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
void inicvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int cargarvotos(int m[][10],int f,int c)
    {
    int i,band,cod,sem;
    i=0;
    band=0;
    do
        {
        if(band==1)
            {
            if(!validadato(cod,1,100))
                printf("\n\n Código erróneo: %d \n\n",cod);
            if(!validadato(sem,1,10)&&sem>=0)
                printf("\n\n Semana errónea: %d \n\n",sem);
            printf("\n\n Ingrese nuevamente los datos: \n\n");
            }
        printf("\n\n Voto %d",i+1);
        printf("\n\n Ingrese el código de la película que fue votada: \n\n\t");
        scanf("%d",&cod);
        printf("\n\n Ingrese la semana en que fue votada esta película: \n\n\t");
        scanf("%d",&sem);
        band=1;
        }
    while(!validadato(cod,1,100)||(!validadato(sem,1,10)&&sem>=0));
    while(sem>=0)
        {
        m[cod-1][sem-1]++;
        i++;
        band=0;
        do
            {
            if(band==1)
                {
                if(!validadato(cod,1,100))
                    printf("\n\n Código erróneo: %d \n\n",cod);
                if(!validadato(sem,1,10)&&sem>=0)
                    printf("\n\n Semana errónea: %d \n\n",sem);
                printf("\n\n Ingrese nuevamente los datos: \n\n");
                }
            printf("\n\n Voto %d",i+1);
            printf("\n\n Ingrese el código de la película que fue votada: \n\n\t");
            scanf("%d",&cod);
            printf("\n\n Ingrese la semana en que fue votada esta película: \n\n\t");
            scanf("%d",&sem);
            band=1;
            }
        while(!validadato(cod,1,100)||(!validadato(sem,1,10)&&sem>=0));
        }
    return i;
    }
void mostrarxfila(int m[][10],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n %d",i+1);
        for(j=0;j<c;j++)
            printf("\t %d",m[i][j]);
        }
    }
void sumarxfila(int m[][10],int f,int c,int v[])
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            v[i]+=m[i][j];
    }
int contarsi(int v[],int ce,int x)
    {
    int i,cont;
    cont=0;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            cont++;
    return cont;
    }
void mostrarsi(int v[],int ce,int x)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            printf("\n %d",i+1);
    }
void maximoxsemana(int m[][10],int f,int c,int v[])
    {
    int i,j,max;
    for(j=0;j<c;j++)
        {
        for(i=0;i<f;i++)
            if(i==0||m[i][j]>max)
                max=m[i][j];
        v[j]=max;
        }
    }
void mostrarmax(int m[][10],int f,int c,int v[])
    {
    int i,j;
    for(j=0;j<c;j++)
        {
        printf("\n %d",j+1);
        for(i=0;i<f;i++)
            if(m[i][j]==v[j])
                printf("\t %d \n",i+1);
        }
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
