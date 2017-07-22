#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct fecha
    {
    int dia;
    char mes[12];
    int anio;
    };
void lee_ayer(struct fecha *);
struct fecha lee_hoy();
void mostrar_fecha(struct fecha);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct fecha ayer,hoy;
    printf("\n Ingrese la fecha de ayer: \n\t");
    lee_ayer(&ayer);
    printf("\n Ingrese la fecha de hoy: \n\t");
    hoy=lee_hoy();
    printf("\n\n Ayer fue:\n");
    mostrar_fecha(ayer);
    printf("\n Hoy es:\n");
    mostrar_fecha(hoy);
    getch();
    }
void lee_ayer(struct fecha *ay)
    {
    printf("\n Día: \n\t");
    scanf("%d",&ay->dia);
    fflush(stdin);
    printf("\n Mes: \n\t");
    gets(ay->mes);
    printf("\n Año: \n\t");
    scanf("%d",&ay->anio);
    fflush(stdin);
    }
struct fecha lee_hoy()
    {
    struct fecha aux;
    printf("\n Día: \n\t");
    scanf("%d",&aux.dia);
    fflush(stdin);
    printf("\n Mes: \n\t");
    gets(aux.mes);
    printf("\n Año: \n\t");
    scanf("%d",&aux.anio);
    fflush(stdin);
    return aux;
    }
void mostrar_fecha(struct fecha most)
    {
    printf("\n\t %02d-%-s-%4d \n",most.dia,most.mes,most.anio);
    }
