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
void ordenar(struct persona[], int);
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    FILE *nn;
    int i,j;
    struct persona per[1000];
    i=0;
    nn=fopen("DATOSPERSONAS.dat","rb");
    if(nn==NULL)
        {
            puts("Error, no existe el archivo");
            exit(0);
        }
    fread(&per[i],sizeof(struct persona),1,nn);
    while(!feof(nn))
    {
        i++;
        fread(&per[i],sizeof(struct persona),1,nn);
    }
    fclose(nn);
    ordenar(per,i);
    printf("\n Legajo \t Apellido \t Nombre \t Altura \t Sexo \n\n");
    for(j=0;j<i;j++)
        {
            printf("\n %d \t\t %s \t\t %s \t %.2f \t\t %c \n",per[j].nl,per[j].ap,per[j].no,per[j].alt,per[j].sex);
        }
    getch();
    return 0;
}

void ordenar(struct persona v[],int ce)
    {
    int i,j,pm;
    struct persona aux;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(v[i].nl<v[pm].nl)
                pm=i;;
        aux.nl=v[pm].nl;
        v[pm].nl=v[j-1].nl;
        v[j-1].nl=aux.nl;
        strcpy(aux.ap,v[pm].ap);
        strcpy(v[pm].ap,v[j-1].ap);
        strcpy(v[j-1].ap,aux.ap);
        strcpy(aux.no,v[pm].no);
        strcpy(v[pm].no,v[j-1].no);
        strcpy(v[j-1].no,aux.no);
        aux.alt=v[pm].alt;
        v[pm].alt=v[j-1].alt;
        v[j-1].alt=aux.alt;
        aux.sex=v[pm].sex;
        v[pm].sex=v[j-1].sex;
        v[j-1].sex=aux.sex;
        }
    }
