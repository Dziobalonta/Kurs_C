/* Tomasz Dziób,  02.11.2022, tom.dziob@student.uj.edu.pl

Program obliczający funkcyjnie silnię, podwójną silnię oraz n-tą liczbę Ciągu Fibbonaciego na dwa sposoby: 
- zwracając typ int 
- zwracając typ double

-->Instrukcja kompilacji:

gcc dua_silnia_fib.c -o dua_silnia_fib
./dua_silnia_fib 5

-->Spodziewany wynik:

5 !     =       120
        =       1.200000000000000e+02
5 !!    =       15
        =       1.50000000e+01
Fib(5)  =       5
        =       5.000000000000000e+00

*/
#include <stdio.h>
#include <stdlib.h>

double Silnia_f(int n)
{
    return (n>0) ? n*Silnia_f(n-1) : 1.0;
}

long long Silnia_i(int n)
{
    return (n>0) ? n*Silnia_i(n-1) : 1;
}

double Dua_Silnia_f(int n)
{
    return (n>0) ? n*Dua_Silnia_f(n-2) : 1.0;
}

int Dua_Silnia_i(int n)
{
    return (n>0) ? n*Dua_Silnia_i(n-2) : 1;
}

int Fib_i(int n)
{
    if(n == 0) return n;
    if(n == 1) return n;
    if(n>1) return Fib_i(n-1) + Fib_i(n-2);
}

double Fib_f(int n)
{
    if(n == 0) return 0.0;
    if(n == 1) return 1.0;
    if(n>1) return Fib_f(n-1) + Fib_f(n-2);
}

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