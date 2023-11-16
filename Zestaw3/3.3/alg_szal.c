/* Tomasz Dziób,  31.12.2022, tom.dziob@student.uj.edu.pl

Program podstawiajacy wszystkie liczby mozliwe do zapisania w typie float do podanego w zadaniu
równania E^x=x^2.Wypisywana jest liczba ktora najdokladniej spelnia to rownanie tzn. jest najblizsza faktycznej
liczbie spelniajacej rownanie.

-->Instrukcja kompilacji:
gcc alg_szal.c -o alg_szal -lm
time ./alg_szal

-->Spodziewany wynik:

Najblizsza wartosc: -7.0346742868e-01
real    0m42.596s
user    0m42.584s
sys     0m0.000s

*/
#include <stdio.h>
#include <math.h> //next after
#include <float.h> //min max

int main()
{
    register float b=-FLT_MAX, difference=0, min_difference=FLT_MAX, min_val;
    while(b!=FLT_MAX)
    {
        difference = fabsf(expf(b)-b*b);
        if(difference < min_difference) 
        {
            min_difference = difference;
            min_val = b;
        }
        b = nextafterf(b,FLT_MAX); 
    }
    printf("\nNajblizsza wartosc: %0.10e\n",min_val);
    return 0;
}