# include <iostream>
# include <stdio.h>
# include <conio.h>
# include <math.h>
# include <stdlib.h>

using namespace std;

class Fractie
{
    private:
        int numarator;
        int numitor;
    
    public:
        Fractie(void) //Default Constructor
        {
            numarator = 0;
            numitor = 1;
        }
        
        Fractie(double Numarator , double Numitor) // Al doilea Constructor
        {
            numarator = Numarator;
            numitor = Numitor;
        }
        
        void Display()
        {
            cout << numarator << "/" << numitor << endl;
        }
        
        Fractie operator + (Fractie x)
        {
            cout << numarator << "/" << numitor << " + " << x.numarator << "/" << x.numitor << " = ";
            
            int gcdt = gcd(numarator * x.numitor + numitor * x.numarator, numitor * x.numitor);

            if(gcdt)
            {
                return * new Fractie((numarator * x.numitor + numitor * x.numarator) / gcdt, (numitor * x.numitor) / gcdt);
            }
            else
            {
                return * new Fractie(numarator * x.numitor + numitor * x.numarator, numitor * x.numitor);
            }
        }
        
        Fractie operator * (Fractie x)
        {
            cout << numarator << "/" << numitor << " * " << x.numarator << "/" << x.numitor << " = ";

            int gcdt = gcd(numarator * x.numarator, numitor * x.numitor);

            if(gcdt)
            {
                return * new Fractie((numarator * x.numarator) / gcdt, (numitor * x.numitor) / gcdt);
            }
            else
            {
                return * new Fractie(numarator * x.numarator, numitor * x.numitor);
            }
        }

        Fractie operator - (Fractie x)
        {
            cout << numarator << "/" << numitor << " - " << x.numarator << "/" << x.numitor << " = ";

            int gcdt = gcd(numarator * x.numitor - numitor * x.numarator, numitor * x.numitor);

            if(gcdt)
            {
                return * new Fractie((numarator * x.numitor - numitor * x.numarator) / gcdt, (numitor * x.numitor) / gcdt);
            }
            else
            {
                return * new Fractie(numarator * x.numitor - numitor * x.numarator, numitor * x.numitor);
            }
        }

        Fractie operator / (Fractie x)
        {
            cout << numarator << "/" << numitor << " / " << x.numarator << "/" << x.numitor << " = ";
            
            int gcdt = gcd(numarator * x.numitor, numitor * x.numarator);

            if(gcdt)
            {
                return * new Fractie((numarator * x.numitor) / gcdt, (numitor * x.numarator) / gcdt);
            }
            else
            {
                return * new Fractie(numarator * x.numitor, numitor * x.numarator);
            }
        }

        int gcd(int a, int b)
        {
            int gcd = 0;
            int temp;

            if(a > b)
            {   
                temp = b;
                b = a;
                a = temp;
            }
                
            for (int i = 1; i <= b; ++i)
            {
                if (a % i == 0 && b % i ==0)
                {
                    gcd = i;
                }
            }

            return gcd;
        }
};

int main(void)
{
    int numarator1, numitor1, numarator2, numitor2;
    
    cout << "numarator1 = ";
    cin >> numarator1;
    cout << "numitor1 = ";
    cin >> numitor1;

    cout << "numarator2 = ";
    cin >> numarator2;
    cout << "numitor2 = ";
    cin >> numitor2;

    Fractie x(numarator1, numitor1);
    Fractie y(numarator2, numitor2);   

    (x + y).Display();
    (x * y).Display();
    (x - y).Display();
    (x / y).Display();
}