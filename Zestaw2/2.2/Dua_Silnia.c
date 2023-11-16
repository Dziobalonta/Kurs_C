double Dua_Silnia_f(int n)
{
    return (n>0) ? n*Dua_Silnia_f(n-2) : 1.0;
}

int Dua_Silnia_i(int n)
{
    return (n>0) ? n*Dua_Silnia_i(n-2) : 1;
}