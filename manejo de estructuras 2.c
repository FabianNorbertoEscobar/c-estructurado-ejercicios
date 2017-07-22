#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct AyN {
    char ap[16],no[16];
    };
struct Fecha{
    int dia,mes,ann;
    };
struct persona2{
    int nl;
    struct AyN apyno;
    float alt;
    char sexo;
    struct Fecha fnan;
    };
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n Cargue las estructuras: \n\n");
    struct persona2 per2[10];
    int i;
    for(i=0;i<10;i++)
    {
        printf("\n Ingrese el número de legajo:\n\n\t\t");
        scanf("%d",&per2[i].nl);
        printf("\n Ingrese nombre \n\n\t\t");
        fflush(stdin);
        scanf("%s",per2[i].apyno.no);
        printf("\n Ingrese apellido \n\n\t\t");
        fflush(stdin);
        scanf("%s",per2[i].apyno.ap);
        printf("\n Ingrese altura \n\n\t\t");
        scanf("%f",&per2[i].alt);
        printf("\n Ingrese sexo \n\n\t\t");
        fflush(stdin);
        scanf("%c",&per2[i].sexo);
        printf("\n Ingrese día de nacimiento \n\n\t\t");
        scanf("%d",&per2[i].fnan.dia);
        printf("\n Ingrese mes de nacimiento \n\n\t\t");
        scanf("%d",&per2[i].fnan.mes);
        printf("\n Ingres año de nacimiento \n\n\t\t");
        scanf("%d",&per2[i].fnan.ann);
    }
    printf("\n Las estructuras son: \n\n");
    for(i=0;i<10;i++)
         printf("\n\n Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per2[i].nl,per2[i].apyno.no,per2[i].apyno.ap,per2[i].alt,per2[i].sexo,per2[i].fnan.dia,per2[i].fnan.mes,per2[i].fnan.ann);
    getch();
    return 0;
}
