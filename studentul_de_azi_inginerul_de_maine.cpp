#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class zi_din_an
{
    public:
        int zi_azi, luna_azi, an_azi, zi_maine, luna_maine, an_maine;

        void citire()
        {
            cout << "ziua de azi: "; cin >> zi_azi;
            cout << "luna de azi: "; cin >> luna_azi;
            cout << "an de azi: "; cin >> an_azi;
        }

        void calcul()
        {
            zi_maine = zi_azi;
            luna_maine = luna_azi;
            an_maine = an_azi;

            if(luna_azi == 2)
            {
                if(zi_azi == 28)
                {
                    if(an_azi % 4 == 0)
                    {
                        luna_maine = 3;
                        zi_maine = 1;
                    }
                    else
                    {
                        zi_maine = zi_azi + 1;
                    }
                }
                else if(zi_azi == 29)
                {
                    luna_maine = 3;
                    zi_maine = 1;
                }
                else
                {
                    zi_maine = zi_azi + 1;
                }
            }
            else if((luna_azi <= 7) && (luna_azi % 2 == 0))
            {
                if(zi_azi == 30)
                {
                    luna_maine = luna_azi + 1;
                    zi_maine = 1;
                }
                else
                {
                    zi_maine = zi_azi + 1;
                }
            }
            else if((luna_azi <= 7) && (luna_azi % 2 == 1))
            {
                if(zi_azi == 31)
                {
                    luna_maine = luna_azi + 1;
                    zi_maine = 1;
                }
                else
                {
                    zi_maine = zi_azi + 1;
                }
            }
            else if((luna_azi < 12) && (luna_azi % 2 == 0))
            {
                if(zi_azi == 31)
                {
                    luna_maine = luna_azi + 1;
                    zi_maine = 1;
                }
                else
                {
                    zi_maine = zi_azi + 1;
                }
            }
            else if((luna_azi < 12) && (luna_azi % 2 == 1))
            {
                if(zi_azi == 30)
                {
                    luna_maine = luna_azi + 1;
                    zi_maine = 1;
                }
                else
                {
                    zi_maine = zi_azi + 1;
                }
            }
            else if(zi_azi == 31)
            {
                luna_maine = 1;
                zi_maine = 1;
                an_maine = an_azi + 1;
            }
            else
            {
                zi_maine = zi_azi + 1;
            }
        }

        void afisare()
        {
            cout << "ziua de maine: " << zi_maine << endl;
            cout << "luna de maine: " << luna_maine << endl;
            cout << "anul de maine: " << an_maine << endl;
        };
};

int main()
{
    zi_din_an data;

    data.citire();
    data.calcul();
    data.afisare();
}