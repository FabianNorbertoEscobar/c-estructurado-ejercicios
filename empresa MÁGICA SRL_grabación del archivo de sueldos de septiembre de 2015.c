#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info2
    {
    int ce;
    float suel;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info2 aux;
    int ce,i;
    float suel;
    i=0;
    FILE *pf;
    pf=fopen("sueldos09.dat","ab");
    printf("\n Cargue los sueldos del mes de septiembre de 2015 de sus empleados. \n Usted puede tener hasta 3000 empleados \n\n");
    printf("\t EMPLEADO N°%d\n\n",i+1);
    printf("\n Ingrese el código de empleado (entre 1 y 15000)(finalice con cero): \n\n\t\t");
    do
        {
        scanf("%d",&ce);
        }
    while(!validadato(ce,0,15000));
    while(ce!=0&&i<3000)
        {
        aux.ce=ce;
        printf("\n Sueldo: \t\t");
        do
            {
            scanf("%f",&suel);
            }
        while(suel<=0);
        aux.suel=suel;
        fwrite(&aux,sizeof(struct info2),1,pf);
        i++;
        printf("\n\n\t EMPLEADO N°%d\n\n",i+1);
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
