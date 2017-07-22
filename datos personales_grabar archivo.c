#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
struct persona{
    int nl;
    char ap[16],no[16];
    float alt;
    char sex;
    };
int valida_int(int,int);
float valida_float(float);
char valida_char(char,char);
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int leg;
    float h;
    char ap[16],no[16],sx;
    FILE *nn;
    struct persona per;
    printf("\n Ingrese Número de Legajo entre 1 y 1000 (finaliza con 0) \n\n\t\t");
    leg=valida_int(0,1000);
    while(leg!=0)
    {
        per.nl=leg;
        printf("\n Ingrese Apellido: \n\n\t\t");
        scanf("%s",ap);
        strcpy(per.ap,ap);
        printf("\n Ingrese Nombre: \n\n\t\t");
        scanf("%s",no);
        strcpy(per.no,no);
        printf("\n Ingrese Altura:\n\n\t\t");
        h=valida_float(0);
        per.alt=h;
        printf("\n Ingrese Sexo: \n\n\t\t");
        fflush(stdin);
        sx=valida_char('F','M');
        per.sex=sx;
        nn=fopen("DATOSPERSONAS.dat","ab");
        fwrite(&per,sizeof(struct persona),1,nn);
        fclose(nn);
        printf("\n Ingrese Número de Legajo entre 1 y 1000 (finaliza con 0) \n\n\t\t");
        leg=valida_int(0,1000);
    }
    getch();
    return 0;
}

int valida_int(int LI, int LS)
{
int dat;
do{scanf("%d",&dat);
}while(!(dat>=LI&&dat<=LS));
return dat;
}

float valida_float(float F)
{
float dat;
do{scanf("%f",&dat);
}while(!(dat>=F));
return dat;
}

char valida_char(char a, char b)
{
char dat;
do{scanf("%c",&dat);
}while(!(dat==a||dat==b));
return dat;
}
