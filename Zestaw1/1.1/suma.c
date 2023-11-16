/* Tomasz Dziób,  11.11.2022, tom.dziob@student.uj.edu.pl

Program obliczajacy sume liczb do N podanego przy wywolywaniu programu

-->Instrukcja kompilacji:

gcc suma.c -o suma 
./suma 69

-->Spodziewany wynik:

suma:
2415

*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int suma=0,n=0;
    n=atoi(argv[1]);
    for(int i=1;i<=n;i++)
    {
        suma+=i;
    }

    printf("suma:\n%d\n",suma);

    return 0;
}
