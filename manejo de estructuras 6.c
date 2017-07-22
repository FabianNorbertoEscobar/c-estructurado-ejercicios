#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct AyN {
    char ap[16],no[16];
    };
struct Fecha{
    int dia,mes,ann;
    };
struct persona3 {
    int nl;
    struct AyN apyno;
    float alt;
    char sexo;
    struct Fecha fnan;
    int cma[40];
    };
struct persona3 cargastruct3();
void mostrarper3(struct persona3);
int main()
{
    struct persona3 per3;
    setlocale(LC_CTYPE,"Spanish");
    printf("\n Cargue el array struct \n\n");
    per3=cargastruct3();
    printf("\n El array struct es: \n\n");
    mostrarper3(per3);
    getch();
    return 0;
}

struct persona3 cargastruct3()
{
    int i;
    struct persona3 p;
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
    for(i=0;i<40;i++)
    {
        printf("\n Ingrese código de materia aprobada \n\n\t\t");
        scanf("%d",&p.cma[i]);
    }
    return p;
}

void mostrarper3(struct persona3 per3)
{
    int j;
    printf("\n\n Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per3.nl,per3.apyno.no,per3.apyno.ap,per3.alt,per3.sexo,per3.fnan.dia,per3.fnan.mes,per3.fnan.ann);
    printf("\n Materias aprobadas \n\n");
    for(j=0;j<40;j++)
        printf("\n %d",per3.cma[j]);
}
