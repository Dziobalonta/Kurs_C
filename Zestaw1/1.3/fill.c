/* Tomasz Dziób,  21.01.2023, tom.dziob@student.uj.edu.pl

Program wypisujacy wspolrzedne punktow w wybranej przez uzytkownika kolejnosci

-->Instrukcja kompilacji:

gcc -c fill_f.c
gcc fill.c -o fill fill_f.c
./fill 5

-->Spodziewany wynik:

Wybierz sposob wypelnienia:
1 - Poziomo
2 - Pionowo
3 - Na skos
4 - Spiralnie
4
{
{ 0.000000,     0.000000 },
{ 0.000000,     0.250000 },
{ 0.000000,     0.500000 },
{ 0.000000,     0.750000 },
{ 0.000000,     1.000000 },
{ 0.250000,     1.000000 },
{ 0.500000,     1.000000 },
{ 0.750000,     1.000000 },
{ 1.000000,     1.000000 },
{ 1.000000,     0.750000 },
{ 1.000000,     0.500000 },
{ 1.000000,     0.250000 },
{ 1.000000,     0.000000 },
{ 0.750000,     0.000000 },
{ 0.500000,     0.000000 },
{ 0.250000,     0.000000 },
{ 0.250000,     0.250000 },
{ 0.250000,     0.500000 },
{ 0.250000,     0.750000 },
{ 0.500000,     0.750000 },
{ 0.750000,     0.750000 },
{ 0.750000,     0.500000 },
{ 0.750000,     0.250000 },
{ 0.500000,     0.250000 },
{ 0.500000,     0.500000 },
};

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fill_f.h"

void WypiszZ(void (*funkcja)(int),int n)
{
    printf("{\n");
    (*funkcja)(n);
    printf("};\n");
}

int main(int argc,char *argv[])
{
    int n,wybor,i=0;
    bool loop = true;
    n = atoi(argv[1]);
    while(loop)
    {
        printf("Wybierz sposob wypelnienia:\n1 - Poziomo\n2 - Pionowo\n3 - Na skos\n4 - Spiralnie\n");
        scanf("%d", &wybor);
        loop = false;
        switch (wybor)
        {
        case 1:
            printf("{\n");
            Poziomo(n);
            printf("};\n");
            break;
        case 2:
            printf("{\n");
            Pionowo(n);
            printf("};\n");
            break;
        case 3:
            printf("{\n");
            Na_skos(n);
            printf("};\n");
            break;
        case 4:
            printf("{\n");
            Spiralnie(n);
            printf("};\n");
            break;
        
        default:
            printf("Podales niepoprawna liczbe! Sprobuj ponownie.\n");
            loop = true;
            i++;
            break;
        }
        if (i == 4)
        {
            printf("Za duzo prob wywolania programu na raz! Nastepuje zamkniecie programu.\n");
            return 0;
        }
        
    }
    return 0;
}