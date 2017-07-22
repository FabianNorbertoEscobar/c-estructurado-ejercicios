#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct info1
    {
    int cp;
    char des[36];
    int car;
    int modp;
    int st;
    };
struct info2
    {
    int cp;
    char des[36];
    int st;
    };
int fcarga(struct info1[], int [][8]);
void inicializar_mat(int [][8], int, int);
void funcionb(struct info1 [], int);
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[2000];
    int cant,i, mat[25][8],j,t;
    inicializar_mat(mat,25,8);
    t=2;
    while(t--)
        {
        printf("\n\t\t ****** EMPRESA 6 - MUEBLES PARA OFICINA ****** \n");
        Sleep(100);
        system("cls");
        Sleep(100);
        }
    printf("\n\t\t ****** EMPRESA 6 - MUEBLES PARA OFICINA ****** \n");
    cant=fcarga(vec,mat);
    printf("\n Unidades en stock separadas por característica y modelo \n");
    printf("\n Nºcar \t mod1 \t mod2 \t mod3 \t mod4 \t mod5 \t mod6 \t mod7 \t mod8 \n");
    for(i=0;i<25;i++)
        {
            printf("\n %d", i+1);
            for(j=0;j<8;j++)
                printf("\t %d",mat[i][j]);
        }
    funcionb(vec,cant);
    printf("\n\n Fin del programa... \n\n");
    getch();
    return 0;
}
void inicializar_mat(int m[][8], int f, int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
}
int fcarga(struct info1 v[], int m[][8])
{
    int i;
    FILE *pf;
    i=0;
    pf=fopen("empresa6.dat","rb");
    if(pf==NULL)
        {
            printf("\n No existe el archivo \n\n");
            exit (1);
        }
    fread(&v[i],sizeof(struct info1),1,pf);
    while(!feof(pf))
        {
            m[v[i].car-1][v[i].modp-1]+=v[i].st;
            i++;
            fread(&v[i],sizeof(struct info1),1,pf);
        }
    fclose(pf);
    return i;
}

void funcionb(struct info1 v[], int ce)
{
    struct info2 aux;
    FILE *pf;
    int i, acum;
    float prom;
    acum=0;
    pf=fopen("mayoralpromedio.dat","wb");
    for(i=0;i<ce;i++)
        {
        acum+=v[i].st;
        }
    prom=(float)acum/ce;
    for(i=0;i<ce;i++)
        if(v[i].st>prom)
        {
            aux.cp=v[i].cp;
            strcpy(aux.des,v[i].des);
            aux.st=v[i].st;
            fwrite(&aux,sizeof(struct info2),1,pf);
        }
    fclose(pf);
    printf("\n\n\n Promedio de stocks: %.2f \n",prom);
    printf("\n\n Productos con stock mayor al promedio total de stocks \n");
    printf("\n CÓDIGO DE PRODUCTO \t DESCRIPCIÓN \t\t\t STOCK \n");
    pf=fopen("mayoralpromedio.dat","rb");
    if(pf==NULL)
    {
        printf("\n No existe el archivo \n\n");
        exit (1);
    }
    fread(&aux,sizeof(struct info2),1,pf);
    while(!feof(pf))
        {
            printf("\n %d \t\t\t %s \t\t %d",aux.cp,aux.des,aux.st);
            fread(&aux,sizeof(struct info2),1,pf);
        }
    fclose(pf);
}
