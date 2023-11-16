/* Tomasz Dziób,  29.10.2022, tom.dziob@student.uj.edu.pl

-->Instrukcja kompilacji:
gcc echo.c -o echo
./echo "Echo!" 5

-->Spodziewany wynik:
Echo!
Echo!
Echo!
Echo!
Echo!
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
        for(int i=0;i<atoi(argv[2]);i++)
        {
                printf("%s\n",argv[1]);
        }
        return 0;
}
