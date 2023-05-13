#include <iostream>
#include <stdlib.h>

using namespace std;

void afiseaza(int zz, int ll, int aaaa)
{
    char *lun[12] = {"ianuarie", "februarie", "martie", "aprilie", "mai", "iunie", "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"};

    cout << zz << ' ' << *(lun + ll - 1) << ' ' << aaaa;
}

int main()
{
    int zz, ll, aaaa;

    cin >> zz >> ll >> aaaa;

    afiseaza(zz, ll, aaaa);
}