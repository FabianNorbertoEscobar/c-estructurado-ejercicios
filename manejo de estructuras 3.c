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
struct persona2 cargastruct();
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct persona2 per2;
    printf("\n Cargue una estructura:\n\n");
    per2=cargastruct();
    printf("\n La estructura es: \n\n");
    printf("Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per2.nl,per2.apyno.no,per2.apyno.ap,per2.alt,per2.sexo,per2.fnan.dia,per2.fnan.mes,per2.fnan.ann);
    getch();
    return 0;
    }

// ********* FUNCIONES *********

struct persona2 cargastruct()
{
    struct persona2 p;
    printf("\n Ingrese el número de legajo:\n\n\t\t");
    scanf("%d",&p.nl);
    printf("\n Ingrese nombre \n\n\t\t");
    fflush(stdin);
    scanf("%s",p.apyno.no);
    printf("\n Ingrese apellido \n\n\t\t");
    fflush(stdin);
    scanf("%s",p.apyno.ap);
    printf("\n Ingrese altura \n\n\t\t");
    scanf("%f",&p.alt);
    printf("\n Ingrese sexo \n\n\t\t");
    fflush(stdin);
    scanf("%c",&p.sexo);
    printf("\n Ingrese día de nacimiento \n\n\t\t");
    scanf("%d",&p.fnan.dia);
    printf("\n Ingrese mes de nacimiento \n\n\t\t");
    scanf("%d",&p.fnan.mes);
    printf("\n Ingres año de nacimiento \n\n\t\t");
    scanf("%d",&p.fnan.ann);
    return p;
}
