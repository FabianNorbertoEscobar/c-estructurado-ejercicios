#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct AUTOMOVIL
    {
    char marca[15];
    int aniof;
    char color[10];
    float precio;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct AUTOMOVIL autom[10],coche[10];
    int i;
    printf("\n ESTRUCTURAS CON DATOS DE COCHES \n\n");
    printf("\n Ingrese los datos de 10 automóviles: \n\n");
    for(i=0;i<10;i++)
        {
        printf("\n Ingrese la marca:\n\n\t");
        fflush(stdin);
        gets(autom[i].marca);
        printf("\n Ingrese el año de fabricación: \n\n\t");
        scanf("%d",&autom[i].aniof);
        printf("\n Ingrese el color: \n\n\t");
        fflush(stdin);
        gets(autom[i].color);
        printf("\n Ingrese el precio: \n\n\t");
        scanf("%f",&autom[i].precio);
        }
    for(i=0;i<10;i++)
        coche[i]=autom[i];
    printf("\n Datos de los automóviles cuyo precio es mayor a 90000:\n");
    printf("\n MARCA \t COLOR \t AÑO DE FABRICACIÓN \n\n");
    for(i<0;i<10;i++)
        if(coche[i].precio>90000)
            printf("\n %s \t %s \t %.2f",coche[i].marca,coche[i].color,coche[i].aniof);
    printf("\n Datos de todos los automóviles que fueron ingresados:\n\n");
    printf("\n MARCA \t AÑO DE FABRICACIÓN \t COLOR \t PRECIO \n\n");
    for(i=0;i<10;i++)
        printf("\n %s \t %d \t\t\t %s \t %.2f",autom[i].marca,autom[i].aniof,autom[i].color,autom[i].precio);
    printf("\n\n");
    getch();
    }
