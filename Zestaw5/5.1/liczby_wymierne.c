#include "liczby_wymierne.h"

int NWD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }   else 
        {
           return NWD(b,a % b); 
        }
    
}

void Skracanie(liczba_wymierna *a)
{
    int nwd;
    nwd = NWD(a->licznik,a->mianownik);
    a->licznik = a->licznik / nwd;
    a->mianownik = a->mianownik / nwd;
}

liczba_wymierna Dodawanie(liczba_wymierna a,liczba_wymierna b)
{
    liczba_wymierna wynik;
    wynik.licznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
    wynik.mianownik = a.mianownik * b.mianownik;
    Skracanie(&wynik);
    return wynik;
}

liczba_wymierna Odejmowanie(liczba_wymierna a,liczba_wymierna b)
{
    liczba_wymierna wynik;
    wynik.licznik = a.licznik * b.mianownik - b.licznik * a.mianownik;
    wynik.mianownik = a.mianownik * b.mianownik;
    Skracanie(&wynik);
    return wynik;
}

liczba_wymierna Mnozenie(liczba_wymierna a,liczba_wymierna b)
{
    liczba_wymierna wynik;
    wynik.licznik = a.licznik * b.licznik;
    wynik.mianownik = a.mianownik * b.mianownik;
    Skracanie(&wynik);
    return wynik;
}

liczba_wymierna Dzielenie(liczba_wymierna a,liczba_wymierna b)
{
    liczba_wymierna wynik;
    wynik.licznik = a.licznik * b.mianownik;
    wynik.mianownik = a.mianownik * b.licznik;
    Skracanie(&wynik);
    return wynik;
}

liczba_wymierna Odwrocenie(liczba_wymierna a)
{
    liczba_wymierna wynik;
    wynik.licznik = a.mianownik;
    wynik.mianownik = a.licznik;
    return wynik;
}

liczba_wymierna Negacja(liczba_wymierna a)
{
    liczba_wymierna wynik;
    wynik.licznik = -1 * a.licznik;
    wynik.mianownik = a.mianownik;
    return wynik;
}

liczba_wymierna Kwadrat(liczba_wymierna a)
{
    liczba_wymierna wynik;
    wynik.licznik = a.licznik * a.licznik;
    wynik.mianownik = a.mianownik * a.mianownik;
    return wynik;
}

int Licznik(liczba_wymierna a)
{
    int wynik;
    wynik = a.licznik;
    return wynik;
}

int Mianownik(liczba_wymierna a)
{
    int wynik;
    wynik = a.mianownik;
    return wynik;
}