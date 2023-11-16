/* Tomasz Dziób,  02.11.2022, tom.dziob@student.uj.edu.pl

Program obliczający funkcyjnie silnię, podwójną silnię oraz n-tą liczbę Ciągu Fibbonaciego na dwa sposoby: 
- zwracając typ int 
- zwracając typ double
Funkcje pogrupowane są w pilkach w zależności od tego co obliczają
np. w pliku Fib.c znajdują się dwie funkcje jedna zwracająca wynik typu int, a druga typu double

-->Instrukcja kompilacji:

chmod +x compile.sh
./compile.sh
./Main_file 15

-->Spodziewany wynik:

15 !    =       1307674368000
        =       1.307674368000000e+12
15 !!   =       2027025
        =       2.02702500e+06
Fib(15) =       610
        =       6.100000000000000e+02

*/
#include <stdio.h>
#include <stdlib.h>
#include "Fib.h"
#include "Dua_Silnia.h"
#include "Silnia.h"

int main (int argc, char * argv[])
{
    int n;
    if(argc==1)
    {
        printf("nie podales n!\n");
        return 0;
    }

    n=atoi(argv[1]);

    printf("%d !\t=\t%lld\n", n, Silnia_i(n));
    printf("\t=\t%.15e\n", Silnia_f(n));
    printf("%d !!\t=\t%d\n", n, Dua_Silnia_i(n));
    printf("\t=\t%.8e\n", Dua_Silnia_f(n));
    printf("Fib(%d)\t=\t%d\n", n, Fib_i(n));
    printf("\t=\t%.15e\n", Fib_f(n));

    return 0;
}