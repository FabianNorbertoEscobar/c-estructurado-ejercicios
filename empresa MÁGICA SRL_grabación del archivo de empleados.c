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
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 aux;
    int i,ce,ai,nl,j;
    char ne[41];
    char le[36];
    float sueldo[14];
    j=0;
    FILE *pf;
    pf=fopen("empleados.dat","ab");
    printf("\n Cargue los datos de los empleados. Usted puede tener hasta 3000 empleados \n\n");
    printf("\t EMPLEADO N°%d\n\n",j+1);
    printf("\n Ingrese el código de empleado (entre 1 y 15000)(finalice con cero): \n\n\t\t");
    do
        {
        scanf("%d",&ce);
        }
    while(!validadato(ce,0,15000));
    while(ce!=0&&j<3000)
        {
        aux.ce=ce;
        printf("\n Ingrese el nombre del empleado (hasta 40 caracteres):\n\n\t\t");
        fflush(stdin);
        gets(ne);
        strcpy(aux.ne,ne);
        printf("\n Ingrese la localidad donde vive el empleado (hasta 35 caracteres):\n\n\t\t");
        fflush(stdin);
        gets(le);
        strcpy(aux.le,le);
        printf("\n Ingrese el año de ingreso a la empresa (entre 1950 y 2015):\n\n\t\t");
        do
            {
            scanf("%d",&ai);
            }
        while(!validadato(ai,1950,2015));
        aux.ai=ai;
        printf("\n A continuación ingrese los sueldos y aguinaldos del empleado en el año 2015:\n");
        for(i=0;i<12;i++)
            {
            printf("\n Mes %d: \t\t",i+1);
            do
                {
                scanf("%f",&sueldo[i]);
                }
            while(sueldo[i]<=0);
            }
        printf("\n Primer aguinaldo: \t\t");
        do
            {
            scanf("%f",&sueldo[12]);
            }
        while(sueldo[12]<=0);
        printf("\n Segundo aguinaldo: \t\t");
        do
            {
            scanf("%f",&sueldo[13]);
            }
        while(sueldo[13]<=0);
        for(i=0;i<14;i++)
            aux.sueldo[i]=sueldo[i];
        printf("\n\n Ingrese el número de local en que trabaja (entre 1 y 20): \n\n\t\t");
        do
            {
            scanf("%d",&nl);
            }
        while(!validadato(nl,1,20));
        aux.nl=nl;
        fwrite(&aux,sizeof(struct info1),1,pf);
        j++;
        printf("\t EMPLEADO N°%d\n\n",j+1);
        printf("\n Ingrese el código de empleado (entre 1 y 15000)(finalice con cero): \n\n\t\t");
        do
            {
            scanf("%d",&ce);
            }
        while(!validadato(ce,0,15000));
        }
    fclose(pf);
    printf("\n Archivo creado/actualizado... \n\n");
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
