/* Tomasz Dziób,  25.12.2022, tom.dziob@student.uj.edu.pl

Program wykonujacy podstawowe operacje arytmetyczne na (pseudo)losowo wybranych ulamkach zwyklych.
Uzywa do tego shared libraries zawieracjacych dane operacje arytmetyczne tworzone z pliku liczby_wymierne.c

-->Instrukcja kompilacji:

chmod +x compile.sh
./compile.sh

-->Spodziewany wynik:

11/15 + 6/44 = 287/330
11/15 - 6/44 = 197/330
11/15 * 6/44 = 1/10
11/15 % 6/44 = 242/45
(11/15)^-1 = 15/11
11/15 * -1 = -11/15
(11/15)^2 = 121/225
Licznik z liczby 11/15 to: 11
Mianownik z liczby 11/15 to: 15

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "liczby_wymierne.h"
#define randnum (rand() % 100 + 1)

int main()
{
    liczba_wymierna a,b,c;
    int d;
    srand(time(NULL));
    a.licznik = randnum; a.mianownik = randnum;
    b.licznik = randnum; b.mianownik = randnum;

    c = Dodawanie(a,b);
    printf("%d/%d + %d/%d = %d/%d\n",a.licznik,a.mianownik,b.licznik,b.mianownik,c.licznik,c.mianownik);

    c = Odejmowanie(a,b);
    printf("%d/%d - %d/%d = %d/%d\n",a.licznik,a.mianownik,b.licznik,b.mianownik,c.licznik,c.mianownik);
    
    c = Mnozenie(a,b);
    printf("%d/%d * %d/%d = %d/%d\n",a.licznik,a.mianownik,b.licznik,b.mianownik,c.licznik,c.mianownik);

    c = Dzielenie(a,b);
    printf("%d/%d %% %d/%d = %d/%d\n",a.licznik,a.mianownik,b.licznik,b.mianownik,c.licznik,c.mianownik);

    c = Odwrocenie(a);
    printf("(%d/%d)^-1 = %d/%d\n",a.licznik,a.mianownik,c.licznik,c.mianownik);

    c = Negacja(a);
    printf("%d/%d * -1 = %d/%d\n",a.licznik,a.mianownik,c.licznik,c.mianownik);

    c = Kwadrat(a);
    printf("(%d/%d)^2 = %d/%d\n",a.licznik,a.mianownik,c.licznik,c.mianownik);

    d = Licznik(a);
    printf("Licznik z liczby %d/%d to: %d\n",a.licznik,a.mianownik,d);

    d = Mianownik(a);
    printf("Mianownik z liczby %d/%d to: %d\n",a.licznik,a.mianownik,d);

    return 0;
}