#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
int main(int argc, char *argv[])
    {
    int i=10;
    while(--i)
        {
        printf("\n Texto intermitente \n");
        Sleep(1000);
        system("cls");
        Sleep(1000);
        }
    return 0;
    }
