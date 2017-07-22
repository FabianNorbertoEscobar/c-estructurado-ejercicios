#include<stdio.h>
#include<conio.h>
#include<locale.h>
struct datos
    {
    int np,ns,cantp;
    };
void inicializa_mat(int [][10],int,int);
void cargar(int [][10],int,int);
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    int mat[24][10],f,c,i,aux[24][10];
    struct datos dato;
    FILE *pf1,*pf2;
    inicializa_mat(mat,24,10);
    inicializa_mat(aux,24,10);
    printf("\n Cargue la cantidad de personas por povincia y sector: \n\n");
    cargar(mat,24,10);
    pf1=fopen("DATOS1.dat","ab");
    for(f=0;f<24;f++)
        for(c=0;c<10;c++)
            {
                dato.np=f+1;
                dato.ns=c+1;
                dato.cantp=mat[f][c];
                fwrite(&dato,sizeof(struct datos),1,pf1);
            }
    fclose(pf1);
    pf2=fopen("DATOS2.dat","ab");
    for(f=0;f<24;f++)
        for(c=0;c<10;c++)
            {
                if(mat[f][c]!=0)
                    {
                    dato.np=f+1;
                    dato.ns=c+1;
                    dato.cantp=mat[f][c];
                    fwrite(&dato,sizeof(struct datos),1,pf2);
                    }
            }
    fclose(pf2);
    i=0;
    pf1=fopen("DATOS1.dat","rb");
    if(pf1==NULL)
        {
            printf("\n Error al abrir el archivo \n\n");
            exit(0);
        }
    fread(&dato,sizeof(struct datos),1,pf1);
    while(!feof(pf1))
       {
            aux[dato.np-1][dato.ns-1]=dato.cantp;
            fread(&dato,sizeof(struct datos),1,pf1);
       }
    fclose(pf1);
    printf("\n\n PROV   S1   S2   S3   S4   S5   S6   S7   S8   S9   S10 \n");
    for(f=0;f<24;f++)
        {
            printf("\n %d",f+1);
            for(c=0;c<10;c++)
                printf("    %d",aux[f][c]);
        }
    pf2=fopen("DATOS2.dat","rb");
    if(pf2==NULL)
        {
            printf("\n Error al abrir el archivo \n\n");
            exit(0);
        }
    fread(&dato,sizeof(struct datos),1,pf2);
    while(!feof(pf2))
        {
            aux[dato.np-1][dato.ns-1]=dato.cantp;
            fread(&dato,sizeof(struct datos),1,pf2);
        }
    fclose(pf2);
    printf("\n\n PROV   S1   S2   S3   S4   S5   S6   S7   S8   S9   S10 \n");
    for(f=0;f<24;f++)
        {
            printf("\n %d",f+1);
            for(c=0;c<10;c++)
                printf("     %d",aux[f][c]);
        }
    getch();
    return 0;
}

void inicializa_mat(int m[][10],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
}

void cargar(int m[][10],int f,int c)
{
    int np,ns,cantp;
    printf("\n Ingrese el número de provincia (entre 1 y 24) (finaliza con cero): \n\n\t\t");
    np=valida(0,24);
    while(np!=0)
    {
        printf("\n Ingrese el número de sector (entre 1 y 10): \n\n\t\t");
        ns=valida(1,10);
        printf("\n Ingrese la cantidad de personas: \n\n\t\t");
        do
            {
                scanf("%d",&cantp);
            }
        while(cantp<=0);
        m[np-1][ns-1]+=cantp;
        printf("\n Ingrese el número de provincia (entre 0 y 24) (finaliza con cero): \n\n\t\t");
        np=valida(0,24);
    }
}

int valida(int LI,int LS)
{
    int dat;
    do
        {
            scanf("%d",&dat);
        }
    while(!(dat>=LI&&dat<=LS));
    return dat;
}
