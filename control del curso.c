#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define tope 90
int cargarvectores(int[],int[],int[],float[]);
void condicion(int[],int[],char[][12],int);
void listar(int[],char[][12],int);
void noasistentes(int[],float[],int);
void mostrarsi(int[],int[],int,int);
float minimo(float[],int);
void mostrarminimos(int[],float[],float,int);
float prom1(int[],int);
float prom2(float[],int);
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int ce,dni[tope],p1[tope],p2[tope];
    float percas[tope],min,promp1,promp2,promas;
    char cond[tope][12];
    printf("\n\n Materia: ELEMENTOS DE PROGRAMACIÓN \n");
    printf("\n Ingrese los datos de sus alumnos (máximo 90 alumnos) \n");
    printf(" Se pide DNI, las notas de los parciales (o si ausente) \n y el porcentaje de asistencia. Finaliza la carga de datos con DNI igual a cero \n\n");
    ce=cargarvectores(dni,p1,p2,percas);
    if(ce!=0)
        {
        condicion(p1,p2,cond,ce);
        printf("\n\n DNI \t CONDICIÓN \n\n");
        listar(dni,cond,ce);
        printf("\n\n DNIs de los alumnos que no cumplan con la asistencia: \n\n");
        noasistentes(dni,percas,ce);
        printf("\n\n DNIs de los alumnos que se sacaron un 10 en el 2do parcial: \n\n");
        mostrarsi(dni,p2,10,ce);
        printf("\n\n DNIs de los alumnos con menor asistencia: \n\n");
        min=minimo(percas,ce);
        mostrarminimos(dni,percas,min,ce);
        promp1=prom1(p1,ce);
        promp2=prom1(p2,ce);
        promas=prom2(percas,ce);
        printf("\n\n Nota promedio del 1er parcial: %8.2f \n",promp1);
        printf("\n Nota promedio del 2do parcial: %8.2f \n",promp2);
        printf("\n Asistencia promedio: %8.2f \n\n",promas);
        }
    else
        printf("\n\n No se registraron datos de los alumnos de este curso \n\n");
    getch();
    }
int cargarvectores(int dni[],int p1[],int p2[],float as[])
    {
    int i,dni1,p11,p21;
    float as1;
    i=0;
    do
        {
        printf("\n\n Ingrese el DNI del alumno %d: \n\n\t",i+1);
        scanf("%d",&dni1);
        printf("\n\n Ingrese la nota del primer parcial del alumno %d: \n\n\t",i+1);
        scanf("%d",&p11);
        printf("\n\n Ingrese la nota del segundo parcial del alumno %d: \n\n\t",i+1);
        scanf("%d",&p21);
        printf("\n\n Ingrese el porcentaje de asistencia del alumno %d: \n\n\t",i+1);
        scanf("%f",&as1);
        }
    while(!validadato(dni1,0,99999999)||as<0||!validadato(p11,0,10)||!validadato(p2,0,10));
    while(dni!=0)
        {
        dni[i]=dni1;
        p1[i]=p11;
        p2[i]=p21;
        as[i]=as1;
        i++;
        do
            {
            printf("\n\n Ingrese el DNI del alumno %d: \n\n\t",i+1);
            scanf("%d",&dni1);
            printf("\n\n Ingrese la nota del primer parcial del alumno %d: \n\n\t",i+1);
            scanf("%d",&p11);
            printf("\n\n Ingrese la nota del segundo parcial del alumno %d: \n\n\t",i+1);
            scanf("%d",&p21);
            printf("\n\n Ingrese el porcentaje de asistencia del alumno %d: \n\n\t",i+1);
            scanf("%f",&as1);
            }
        while(!validadato(dni1,0,99999999)||as<0||!validadato(p11,0,10)||!validadato(p2,0,10));
        }
    }
void condicion(int p1[],int p2[],char cond[][12],int ce)
    {
    int i;
    char c[12];
    for(i=0;i<ce;i++)
        {
        if(p1[i]==0||p2[i]==0)
            strcpy(c,"Ausente");
        else
            if(p1[i]<4||p2[i]<4)
                strcpy(c,"Reprobado");
            else
                if(p1[i]<7||p2[i]<7)
                    strcpy(c,"Aprobado");
                else
                    strcpy(c,"Promocionado");
        strcpy(cond[i][12],c);
        }
    }
void listar(int dni[],char cond[][12],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        printf("%d \t %s \n",dni[i],cond[i][12]);
    }
void noasistentes(int dni[],float as[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        if(as[i]<75)
            printf("\n %d",dni[i]);
    }
void mostrarsi(int dni[],int p2[],int x,int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        if(p2[i]==x)
            printf("\n %d",dni[i]);
    }
float minimo(float per[],int ce)
    {
    int i;
    float min;
    for(i=0;i<ce;i++)
        if(i==0||per[i]<min)
            min=per[i];
    return min;
    }
void mostrarminimos(int dni[],float per[],float min,int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        if(per[i]==min)
            printf("\n %d",dni[i]);
    }
float prom1(int p1[],int ce)
    {
    int i,acum;
    float pr;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=p1[i];
    pr=acum/ce;
    return pr;
    }
float prom2(float as[],int ce)
    {
    int i,acum;
    float pr;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=as[i];
    pr=acum/ce;
    return pr;
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
