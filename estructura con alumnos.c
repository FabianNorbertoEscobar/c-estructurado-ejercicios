#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#define tope 50
struct ALUMNOS
    {
    char dni[11];
    char apeynom[30];
    char sexo[7];
    int nota1;
    int nota2;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int acum,i;
    float prom;
    struct ALUMNOS alu[50];
    acum=0;
    printf("\n\a\a Ingrese los datos de los alumnos: \n (No ingrese datos incorrectos ya que no se está validando) \n\n");
    for(i=0;i<tope;i++)
        {
        printf("\n Alumno número %d \n",i+1);
        printf("\n Ingrese el dni: \t\t");
        fflush(stdin);
        gets(alu[i].dni);
        printf("\n Ingrese el apellido y nombre: \t\t");
        fflush(stdin);
        gets(alu[i].apeynom);
        printf("\n Ingrese el sexo (VARON o MUJER): \t\t");
        fflush(stdin);
        gets(alu[i].sexo);
        printf("\n Ingrese la nota del primer parcial: \t\t");
        scanf("%d",&alu[i].nota1);
        printf("\n Ingrese la nota del segundo parcial: \t\t");
        scanf("%d",&alu[i].nota2);
        acum+=alu[i].nota1;
        acum+=alu[i].nota2;
        }
    printf("\n\n DNI de los alumnos que promocionaron la materia \n\n");
    for(i=0;i<tope;i++)
        if(alu[i].nota1>=7&&alu[i].nota2>=7)
            printf("\n %s",alu[i].dni);
    printf("\n\n DNI de los alumnos que obtuvieron la condición de cursada \n\n");
    for(i=0;i<tope;i++)
        if(strcmp(alu[i].sexo,"VARON")==0&&alu[i].nota1>=4&&alu[i].nota2>=4)
            if(alu[i].nota1<7||alu[i].nota2<7)
                printf("\n %s",alu[i].dni);
    prom=(float)acum/(tope*2);
    printf("\n\n DNI de los alumnos que sacaron nota superior al promedio \n\n");
    for(i=0;i<tope;i++)
        if((float)(alu[i].nota1+alu[i].nota2)/2>prom)
            printf("\n %s",alu[i].dni);
    printf("\n\n Fin del programa \n\n\a\a");
    getch();
    }
