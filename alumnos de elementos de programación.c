#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,cont,band,leg,ing,mayleg,maying;
    char sex,maysex;
    i=cont=band=0;
    printf("\n Alumnos de Elementos de Programación \n");
    printf("\n Ingrese el sexo del alumno (H para hombre, M para mujer)");
    printf("\n (Ingrese F para finalizar)\n\n");
    do
        {
        fflush(stdin);
        scanf("%c",&sex);
        sex=toupper(sex);
        }
    while(sex!='M'&&sex!='H'&&sex!='F');
    while(sex!='F')
        {
        i++;
        printf("\n Ingrese el número de legajo del alumno (entre 5000 y 15000)\n\n");
        do
            {
            scanf("%d",&leg);
            }
        while(!(leg>=5000&&leg<=15000));
        printf("\n Ingrese el año de ingreso del alumno (entre 1990 y 2013)\n\n");
        do
            {
            scanf("%d",&ing);
            }
        while(!(ing>=1990&&ing<=2013));
        if(ing==2010&&sex=='H')
            cont++;
        if(band==0||leg>mayleg)
            {
            band=1;
            mayleg=leg;
            maysex=sex;
            maying=ing;
            }
        printf("\n Ingrese el sexo del alumno (H para hombre, M para mujer)");
        printf("\n (Ingrese F para finalizar)\n\n");
        do
            {
            fflush(stdin);
            scanf("%c",&sex);
            sex=toupper(sex);
            }
        while(sex!='M'&&sex!='H'&&sex!='F');
        }
    if(i!=0)
        {
        printf("\n El porcentaje de alumnos masculinos que ingresaron a la facultad \n en el año 2010 es de %.2f \n\n",(float)cont*100/i);
        printf("\n Datos del alumno con mayor número de legajo:\n");
        printf("\n Legajo: %d \t Sexo: %c \t Año de ingreso: %d \n\n",mayleg,maysex,maying);
        }
    else
        printf("\n No se ingresaron datos de alumnos \n");
    getch();
    }
