#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct persona1
    {
    int nl;
    char ap[16];
    char no[16];
    float alt;
    char sexo;
    int dn,mn,an;
    };
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
    printf("\n Cargue una estructura: \n\n");
    struct persona1 per;
    struct persona2 per2;
    printf("\n Ingrese el número de legajo:\n\n\t\t");
    scanf("%d",&per.nl);
    printf("\n Ingrese nombre \n\n\t\t");
    fflush(stdin);
    scanf("%s",per.no);
    printf("\n Ingrese apellido \n\n\t\t");
    fflush(stdin);
    scanf("%s",per.ap);
    printf("\n Ingrese altura \n\n\t\t");
    scanf("%f",&per.alt);
    printf("\n Ingrese sexo \n\n\t\t");
    fflush(stdin);
    scanf("%c",&per.sexo);
    printf("\n Ingrese día de nacimiento \n\n\t\t");
    scanf("%d",&per.dn);
    printf("\n Ingrese mes de nacimiento \n\n\t\t");
    scanf("%d",&per.mn);
    printf("\n Ingres año de nacimiento \n\n\t\t");
    scanf("%d",&per.an);
    printf("Legajo %d \t Apellido %s \t Nombre %s \t Altura %.2f \t\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per.nl,per.ap,per.no,per.alt,per.sexo,per.dn,per.mn,per.an);
    printf("\n Ingrese el número de legajo:\n\n\t\t");
    scanf("%d",&per2.nl);
    printf("\n Ingrese nombre \n\n\t\t");
    fflush(stdin);
    scanf("%s",per2.apyno.no);
    printf("\n Ingrese apellido \n\n\t\t");
    fflush(stdin);
    scanf("%s",per2.apyno.ap);
    printf("\n Ingrese altura \n\n\t\t");
    scanf("%f",&per2.alt);
    printf("\n Ingrese sexo \n\n\t\t");
    fflush(stdin);
    scanf("%c",&per2.sexo);
    printf("\n Ingrese día de nacimiento \n\n\t\t");
    scanf("%d",&per2.fnan.dia);
    printf("\n Ingrese mes de nacimiento \n\n\t\t");
    scanf("%d",&per2.fnan.mes);
    printf("\n Ingres año de nacimiento \n\n\t\t");
    scanf("%d",&per2.fnan.ann);
    printf("\n La estructura es: \n\n");
    printf("Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per2.nl,per2.apyno.no,per2.apyno.ap,per2.alt,per2.sexo,per2.fnan.dia,per2.fnan.mes,per2.fnan.ann);
    getch();
    return 0;
    }
