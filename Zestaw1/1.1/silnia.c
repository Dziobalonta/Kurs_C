/* Tomasz Dziób,  11.11.2022, tom.dziob@student.uj.edu.pl

Program obliczajacy silnie uzywajac typu zmiennej int 

-->Instrukcja kompilacji:

gcc silnia.c -o silnia 
./silnia 12

-->Spodziewany wynik:

// Dla wartosci w zakresie

12!=479001600

// Dla wartosci poza zakresem

Blad!   liczba przekroczyla zakres int

*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    int i,n,start;
    int silnia = 1;
  
    n=atoi(argv[1]);

    if(n%2)
        start = 1;
    else
        start = 2;

    for(i=start;i<=n;i++)
    {
        silnia*=i;
        if(i>12) // maksymalna wartosc jak zmiesci sie w typie int, 12!
             {
                printf("Blad!\tliczba przekroczyla zakres int\n");
                return 0; 
             }
    }
    printf("%d!=%d\n\n",n,silnia);
    return 0;
}
