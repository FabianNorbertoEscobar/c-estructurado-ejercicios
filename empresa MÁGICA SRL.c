#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    int ce;
    char ne[41];
    char le[36];
    int ai;
    float sueldo[14];
    int nl;
    };
struct info2
    {
    int ce;
    float suel;
    };
struct info3
    {
    int ce;
    char ne[41];
    char le[36];
    int ai;
    float sueldo[14];
    };
int validadato(int,int,int);
void inicializarvec(int[],int);
void inicializarmat(float[][9],int,int);
int fcarga(struct info1[]);
int buscar(struct info1[],int,int);
void funcionb(struct info1[],int);
void funciond(struct info1[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[3000];
    struct info2 aux;
    int cant,i,pos,j,vl[20],band,mayloc,viejo,ai,nl;
    float mat[20][9],sum,may;
    char ne[41];
    char le[36];
    FILE *pf;
    inicializarvec(vl,20);
    inicializarmat(mat,20,9);
    printf("\n\n\t\t\a\a ***** EMPRESA MÁGICA SRL ***** \n\n");
    cant=fcarga(vec);
    printf("\n Tenemos a la venta todo tipo de artículos y accesorios del calzado \n");
    printf("\n Contamos con 20 locales propios donde realizamos la venta de nuestros productos \n");
    printf("\n Contamos con casi 3000 empleados hasta el momento. Somos un ejemplo de empresa. \n");
    printf("\n Y aquí controlamos y actualizamos los sueldos de los empleados de cada local \n\n");
    viejo=cant;
    pf=fopen("sueldos09.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info2),1,pf);
    while(!feof(pf))
        {
        pos=buscar(vec,cant,aux.ce);
        if(pos!=-1)
            vec[pos].sueldo[8]=aux.suel;
        else
            {
            printf("\n Tenemos un nuevo empleado: \n\t\t Su código es %d \n\n",aux.ce);
            vec[cant].ce=aux.ce;
            printf("\n Necesitamos que complete su registro en la base de datos: \n\n");
            printf("\n Ingrese el nombre del empleado (hasta 40 caracteres):\n\n\t\t");
            fflush(stdin);
            gets(ne);
            strcpy(vec[cant].ne,ne);
            printf("\n Ingrese la localidad donde vive el empleado (hasta 35 caracteres):\n\n\t\t");
            fflush(stdin);
            gets(le);
            strcpy(vec[cant].le,le);
            printf("\n\n Su año de ingreso a la empresa es 2015");
            vec[cant].ai=2015;
            printf("\n\n Primer sueldo del empleado \n\n\t Sueldo de septiembre del 2015: %.2f \n\n",aux.suel);
            vec[cant].sueldo[8]=aux.suel;
            printf("\n\n Ingrese el número de local en que trabaja (entre 1 y 20): \n\n\t\t");
            do
                {
                scanf("%d",&nl);
                }
            while(!validadato(nl,1,20));
            vec[cant].nl=nl;
            cant++;
            }
        fread(&aux,sizeof(struct info2),1,pf);
        }
    fclose(pf);
    printf("\n\n Montos de los sueldos acumulados en el año de cada uno de los empleados \n");
    for(i=0;i<8;i++)
        {
        sum=0;
        printf("\n\n CÓDIGO DE EMPLEADO: %d \n",vec[i].ce);
        printf("\t\t Nombre: %s",vec[i].ne);
        printf("\n\t\t Localidad: %s",vec[i].le);
        for(j=0;j<8;j++)
            sum+=vec[i].sueldo[j];
        printf("\n\t\t Sueldo acumulado en el año: %.2f",sum);
        }
    funcionb(vec,cant);
    printf("\n Sueldos acumulados hasta el momento discriminados por locale y mes \n\n");
    printf("\n LOCAL    m1    m2    m3    m4    m5    m6    m7    m8    m9\n");
    for(i=0;i<viejo;i++)
        for(j=0;j<9;j++)
            mat[vec[i].nl-1][j]+=vec[i].sueldo[j];
    for(i=viejo;i<cant;i++)
        mat[vec[i].nl-1][8]+=vec[i].sueldo[8];
    for(i=0;i<20;i++)
        {
        printf("\n %d",i+1);
        for(j=0;j<9;j++)
            printf("  %.2f",mat[i][j]);
        }
    funciond(vec,cant);
    printf("\n\n Cantidad de empleados de cada local \n\n");
    printf("\n N° de LOCAL \t CANTIDAD DE EMPLEADOS \n");
    for(i=0;i<cant;i++)
        vl[vec[i].nl-1]++;
    band=0;
    for(i=0;i<cant;i++)
        {
        printf("\n %d \t\t %d",i+1,vl[i]);
        if(band==0||vl[i]>may)
            {
            band=1;
            may=vl[i];
            mayloc=i+1;
            }
        }
    printf("\n\n Datos del local con mayor cantidad de empleados \n");
    printf("\n N° de local: %d \t Empleados: %.2f \n\n",mayloc,may);
    printf("\n Fin del programa \n\n");
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void inicializarmat(float m[][9],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
int fcarga(struct info1 v[])
    {
    int i;
    FILE *pf;
    i=0;
    pf=fopen("empleados.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&v[i],sizeof(struct info1),1,pf);
    while(!feof(pf))
        {
        i++;
        fread(&v[i],sizeof(struct info1),1,pf);
        }
    fclose(pf);
    return i;
    }
int buscar(struct info1 v[],int ce,int cod)
    {
    int p,i;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        {
         if(v[i].ce==cod)
            p=i;
        else
            i++;
        }
    return p;
    }
void funcionb(struct info1 v[],int c)
    {
    int i,j;
    struct info3 aux;
    FILE *pf;
    pf=fopen("Local15.dat","ab");
    for(i=0;i<c;i++)
        {
        if(v[i].nl==15)
            {
            aux.ce=v[i].ce;
            aux.ai=v[i].ai;
            strcpy(aux.ne,v[i].ne);
            strcpy(aux.le,v[i].le);
            for(j=0;j<8;j++)
                aux.sueldo[j]=v[i].sueldo[j];
            fwrite(&aux,sizeof(struct info3),1,pf);
            }
        }
    fclose(pf);
    }
void funciond(struct info1 v[],int c)
    {
    int i;
    FILE *pf;
    pf=fopen("empleados.dat","wb");
    for(i=0;i<c;i++)
        fwrite(&v[i],sizeof(struct info1),1,pf);
    fclose(pf);
    }
