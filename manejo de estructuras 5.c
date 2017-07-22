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
struct persona3 {
    struct persona2 per2;
    int cma[40];
    };

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    struct persona3 per3;
    int i,j,h;
    printf("\n Cargue el struct \n\n");
    printf("\n Ingrese el número de legajo:\n\n\t\t");
    scanf("%d",&per3.per2.nl);
    printf("\n Ingrese nombre \n\n\t\t");
    fflush(stdin);
    scanf("%s",per3.per2.apyno.no);
    printf("\n Ingrese apellido \n\n\t\t");
    fflush(stdin);
    scanf("%s",per3.per2.apyno.ap);
    printf("\n Ingrese altura \n\n\t\t");
    scanf("%f",&per3.per2.alt);
    printf("\n Ingrese sexo \n\n\t\t");
    fflush(stdin);
    scanf("%c",&per3.per2.sexo);
    printf("\n Ingrese día de nacimiento \n\n\t\t");
    scanf("%d",&per3.per2.fnan.dia);
    printf("\n Ingrese mes de nacimiento \n\n\t\t");
    scanf("%d",&per3.per2.fnan.mes);
    printf("\n Ingrese año de nacimiento \n\n\t\t");
    scanf("%d",&per3.per2.fnan.ann);
    i=0;
    printf("\n Ingrese código de materia aprobada(termina con 0)\n\n\t\t");
    scanf("%d",&per3.cma[i]);
    while(i<40 && per3.cma[i]!=0)
        {
            i++;
            printf("\n Ingrese código de materia aprobada(termina con 0)\n\n\t\t");
            scanf("%d",&per3.cma[i]);
        }
    printf("\n El array struct es: \n\n");
    printf("\n\n Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per3.per2.nl,per3.per2.apyno.no,per3.per2.apyno.ap,per3.per2.alt,per3.per2.sexo,per3.per2.fnan.dia,per3.per2.fnan.mes,per3.per2.fnan.ann);
    printf("\n Materias aprobadas \n\n");
        for(j=0;j<i;j++)
            printf("\n %d",per3.cma[j]);
    getch();
    return 0;
}
