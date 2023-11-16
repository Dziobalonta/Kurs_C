/* Tomasz Dziób,  21.01.2022, tom.dziob@student.uj.edu.pl

Program wyswietlajacy 1024 coraz dokladniejszych przyblizen wymiernych liczby niewymiernej PI,
przy uzyciu algorytmu Sterna-Brocota.

-->Instrukcja kompilacji:

gcc acc_values.c -o acc_values -lm
./acc_values

-->Spodziewany wynik:

Liczba niewymierna - PI ~ 3.14159265358979323846
Lista przyblizen:
1/1
2/1
3/1
4/1
7/2
10/3
13/4
16/5
19/6
22/7
25/8
47/15
69/22
91/29
113/36
135/43
157/50
179/57
201/64
223/71

*/
#include <stdio.h>
#include <math.h>
#include <stdint.h>
//#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385

typedef struct 
{
    long double licznik;
    long double mianownik;

}liczba_wymierna;

int main() 
{
    long double a = 0, b = 1, c = 1, d = 0;
    long double q = M_PI;
    liczba_wymierna ulamek;
    printf("Liczba niewymierna - PI ~ 3.14159265358979323846\n");
    printf("Lista przyblizen:\n");
    for (int i = 0; i < 20; i++) 
    {
        ulamek.licznik = a + c;
        ulamek.mianownik = b + d;

        if (q < ulamek.licznik / ulamek.mianownik) 
        {
            printf("%.0Lf/%.0Lf\n", ulamek.licznik, ulamek.mianownik);
            c = ulamek.licznik;
            d = ulamek.mianownik;
        } 
        else 
        {
            printf("%.0Lf/%.0Lf\n", ulamek.licznik, ulamek.mianownik);
            a = ulamek.licznik;
            b = ulamek.mianownik;
        }
    }
    return 0;
}