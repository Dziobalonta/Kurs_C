/* Tomasz Dziób,  11.11.2022, tom.dziob@student.uj.edu.pl

Program obliczajacy podwojna silnie

-->Instrukcja kompilacji:

gcc dua_silnia.c -o dua_silnia 
./dua_silnia 69

-->Spodziewany wynik:

69!=3.373825e+49

*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    int i,n,start;
    double silnia = 1.0;
    if(argc==1)
    {
        printf("nie podales n!\n");
        return 0;
    }

    n=atoi(argv[1]);

    if(n%2)
        start = 1;
    else
        start = 2;

    for(i=start;i<=n;i+=2)
    {
        silnia = silnia * i;
    }

    printf("\n%d!=%e\n\n",n,silnia);

    return 0;
}
