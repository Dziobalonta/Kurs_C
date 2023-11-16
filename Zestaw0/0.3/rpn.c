/* Tomasz Dziób,  29.10.2022, tom.dziob@student.uj.edu.pl

-->Instrukcja kompilacji:
gcc rpn.c -o rpn
./rpn 5 7 + 7 / 0 x -

-->Spodziewany wynik:
5
7
Plus
7
Divide
0
Times
Subtract

*/
#include <stdio.h>
#include <string.h>

int main (int argc, char * argv[])
{
    for(int i=1;i<argc;i++)
    {
        switch(argv[i][0])
        {
            case '+':
                printf("Plus\n");
                break;
            case '-':
                printf("Substract\n");
                break;
            case '/':
                printf("Divide\n");
                break;
            case 'x':
                printf("Times\n");
                break;
            case ' ':
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            printf("%c\n",argv[i][0]);
            break;
        }
    }
    return 0;
}
