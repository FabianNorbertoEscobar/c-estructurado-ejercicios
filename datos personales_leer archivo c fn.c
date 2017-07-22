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
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    leerarchivo();
    getch();
    return 0;
}

void leerarchivo()
{
    FILE *nn;
    int i,j;
    struct persona per[1000];
    i=0;
    nn=fopen("DATOSPERSONAS.dat","rb");
    if(nn==NULL)
        {
            puts("Error, no existe el archivo");
            exit (0);
        }
    fread(&per[i],sizeof(struct persona),1,nn);
    while(!feof(nn))
    {
        i++;
        fread(&per[i],sizeof(struct persona),1,nn);
    }
    fclose(nn);
    printf("\n Legajo \t Apellido \t Nombre \t Altura \t Sexo \n\n");
    for(j=0;j<i;j++)
        {
            printf("\n %d \t\t %s \t\t %s \t %.2f \t\t %c \n",per[j].nl,per[j].ap,per[j].no,per[j].alt,per[j].sex);
        }
}
