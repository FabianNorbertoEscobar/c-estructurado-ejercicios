#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define n 2
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
void cargavectorstruct(struct persona2[]);
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int i;
    struct persona2 per2[n];
    printf("\n Cargue el array struct: \n\n");
    cargavectorstruct(per2);
    printf("\n El array struct es: \n\n");
    for(i=0;i<n;i++)
         printf("\n\n Legajo %d \t Nombre %s \t Apellido %s \t Altura %.2f \t\n\n Sexo %c \t Día de nacimiento %d \t Mes de nacimiento %d \t Año de nacimiento %d \n\n",per2[i].nl,per2[i].apyno.no,per2[i].apyno.ap,per2[i].alt,per2[i].sexo,per2[i].fnan.dia,per2[i].fnan.mes,per2[i].fnan.ann);
    getch();
    return 0;
}

void cargavectorstruct(struct persona2 per2[])
    {
    int i;
    for(i=0;i<n;i++)
        {
            per2[i]=cargastruct();
        }
    }

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
