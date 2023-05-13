#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Patrulater
{
    public :
        class Punct
        {
            public :
                float x, y, z;
              
                Punct(void)
                {
                    x = y = z = 0;
                }

                Punct(char P)
                {
                    cout << "x[" << P << "] = ";
                    cin >> x;

                    cout << "Y[" << P << "] = ";
                    cin >> y;

                    cout << "Z[" << P << "] = ";
                    cin >> z;
                }

                Punct(float X, float Y, float Z)
                {
                    x = X;
                    y = Y;
                    z = Z;
                }

                ~Punct()
                {
                    
                }
                
                void Afisare_Punct()
                {
                    cout << endl <<"Coordonatele Punctului sunt : x = " << x << " y = " << y << " z = " << z;
                }
        };

    private :
        Punct p1;
        Punct p2;
        Punct p3;
        Punct p4;
      
        float laturi[6];
        
    public :
        Patrulater(Punct P1, Punct P2, Punct P3, Punct P4)
        {
            p1 = *new Punct (P1.x, P1.y, P1.z);
            p2 = *new Punct (P2.x, P2.y, P2.z);
            p3 = *new Punct (P3.x, P3.y, P3.z);
            p4 = *new Punct (P4.x, P4.y, P4.z);
            Calculeaza_Laturi();
        }
        
        void Calculeaza_Laturi()
        {
            laturi[0] = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
            laturi[1] = sqrt(pow(p2.x - p3.x, 2) + pow(p2.y - p3.y, 2) + pow(p2.z - p3.z, 2));
            laturi[2] = sqrt(pow(p3.x - p4.x, 2) + pow(p3.y - p4.y, 2) + pow(p3.z - p4.z, 2));
            laturi[3] = sqrt(pow(p1.x - p4.x, 2) + pow(p1.y - p4.y, 2) + pow(p1.z - p4.z, 2));
            laturi[4] = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2) + pow(p1.z - p3.z, 2));
            laturi[5] = sqrt(pow(p2.x - p4.x, 2) + pow(p2.y - p4.y, 2) + pow(p2.z - p4.z, 2));
        }
        
        float Perimetru(void)
        {
            float perimetru = laturi[0] + laturi [1] + laturi[2] + laturi[3];
            return perimetru;
        }
        
        int Tip_Patrulater()
        {
            if(laturi[0] >= laturi[1] + laturi[2] + laturi[3]) return -1;
            if(laturi[1] >= laturi[0] + laturi[2] + laturi[3]) return -1;
            if(laturi[2] >= laturi[0] + laturi[1] + laturi[3]) return -1;
            if(laturi[3] >= laturi[0] + laturi[1] + laturi[2]) return -1;

            if(laturi[0] == laturi[1] && laturi[1] == laturi[2] && laturi[2] == laturi[3] && laturi[4] == laturi[5]) return 2;
            //2 inseamna ca e patrat
            else
            {
                if(laturi[0] == laturi[1] && laturi[1] == laturi[2] && laturi[2] == laturi[3]) return 1;
                //1 inseamna ca e romb;
                if(laturi[0] == laturi[2] && laturi[1] == laturi[3] && laturi[4] == laturi[5]) return 3;
                //dreptunghi
                if(laturi[0] == laturi[2] && laturi[1] == laturi[3]) return 4;
                //paralelogram
                if((p1.y - p2.y) / (p1.x - p2.x) == (p3.y - p4.y) / (p3.x - p4.x) || (p2.y - p3.y) / (p2.x - p3.x) == (p1.y - p4.y) / (p1.x - p4.x)) return 5;
                //trapez
            }
            //daca am ajuns aici , adica nu s-a intalnit nici un RETURN inseamna
            //ca patrulaterul e Oarecare
            return 0; // 0 inseamna ca patrulateru e oarecare;
        }

        void Afisare_Patrulater(void)
        {
            p1.Afisare_Punct();
            p2.Afisare_Punct();
            p3.Afisare_Punct();
            p4.Afisare_Punct();

            for (int i = 0; i < 4; i++)
                cout << endl << "Latura " << (i+1) << " = " << laturi[i];

            cout << endl << "Perimetrul patrulater este = " << Perimetru();
        }
};

int main (void)
{
    Patrulater::Punct p1('A');
    Patrulater::Punct p2('B');
    Patrulater::Punct p3('C');
    Patrulater::Punct p4('D');

    //patrat - (0, 1, 0) - (1, 1, 0) - (1, 0, 0) - (0, 0, 0)
    //paralelogram - (0, 2, 0) - (1, 3, 0) - (1, 1, 0) - (0, 0, 0)
    //dreptunghi - (0, 2, 0) - (1, 2, 0) - (0, 1, 0) - (0, 0, 0)
    //trapez - (4, 0, 0) - (2, 1, 0) - (1, 1, 0) - (0, 0, 0)
    //romb - (-1, 1, 0) - (4, 1, 0) - (0, -2, 0) - (-5, -2, 0)

    Patrulater Patrulater(p1, p2, p3, p4);

    switch (Patrulater.Tip_Patrulater())
    {
        case -1: cout << endl << "Patrulaterul este OARECARE !!!";
            Patrulater.Afisare_Patrulater();
            break;
        
        case 1: cout << endl << "Patrulaterul este ROMB !!!";
            Patrulater.Afisare_Patrulater();
            break;
        
        case 2: cout << endl << "Patrulaterul este PATRAT !!!";
            Patrulater.Afisare_Patrulater();
            break;

        case 3: cout << endl << "Patrulaterul este DREPTUNGHI !!!";
            Patrulater.Afisare_Patrulater();
            break;

        case 4: cout << endl << "Patrulaterul este PARALELOGRAM !!!";
            Patrulater.Afisare_Patrulater();
            break;

        case 5: cout << endl << "Patrulaterul este Trapez !!!";
            Patrulater.Afisare_Patrulater();
            break;
    }
}