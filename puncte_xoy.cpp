#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

class Punct
{
    public:
        Punct(char P)
        {
            cout << "unghi " << P << ":" << endl;

            cout << "f[" << P << "] = ";
            cin >> f;

            cout << "o[" << P << "] = ";
            cin >> o;

            cout << "p[" << P << "] = ";
            cin >> p;

            calcul();
        }

        ~Punct()
        {

        }

        float X()
        {
            return x;
        }

        float Y()
        {
            return y;
        }

        void calcul();

        void afisare();

    private:
        float f, o, p;
        float x, y, z;
};

void Punct::calcul()
{
    x = p * cos(o) * cos(f);
    y = p * cos(o) * sin(o);
    z = p * sin(o);
}

void Punct::afisare()
{
    cout << setprecision(4);
    cout << "x = " << x << " ";
    cout << "y = " << y << " ";
    cout << "z = " << z << " ";
    cout << "f = " << f << " ";
    cout << "o = " << o << " ";
    cout << "p = " << p << endl;
}

class Segment
{
    public:
        Segment(Punct, Punct)
        {
            float Distanta(Punct, Punct);

            void afisare(Punct, Punct);
        }

        ~Segment()
        {
            
        }

        float Distanta(Punct X, Punct Y)
        {
            d = sqrt((X.X() - Y.X()) * (X.X() - Y.X()) + (X.Y() - Y.Y()) * (X.Y() - Y.Y()));
            
            return d;
        }

        void afisare(Punct X, Punct Y)
        {

            X.afisare();
            Y.afisare();
            cout << endl;
        }

        float d;
};

int main()
{
    Punct A('A');
    Punct B('B');

    Segment a(A, B);

    Punct C('C');
    Punct D('D');

    Segment b(C, D);

    cout << "Distanta puncte A B: " << a.Distanta(A, B) << endl;

    cout << "Coordonate puncte A B:" << endl;
    a.afisare(A, B);

    cout << "Distanta puncte C D: " << b.Distanta(C, D) << endl;

    cout << "Coordonate Puncte C D:" << endl;
    b.afisare(C, D);
}