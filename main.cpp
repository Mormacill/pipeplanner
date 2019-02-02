#include <iostream>
#include <math.h>
#include "rrf.h"
using namespace std;

int main()
{

double v, d, T, nu, Rey = 0;

cout << "Rohrreibungsberechnung für ein gerades Rohr mit dem Medium Luft" << endl << endl << endl;

cout << "   ┌------------┐" << endl;
cout << "   └------------┘" << endl << endl << endl;

cout << "Beliebige Taste drücken zum fortsetzen" << endl;
cin.get();

cout << "Bestimmung der Reynolds-Zahl" << endl;

cout << "Re = (v * d) / ν(T)" << endl << endl;

cout << "Strömungsgeschwindigkeit v= ";
cin >> v;
cout << "charakteristische Länge d (Rohrdurchmesser)= ";
cin >> d;
cout << "Temperatur des Strömungsmediums T (Gültigkeit -40 - 1000°C)= ";
cin >> T;
nu = vis(T);
nu = nu*pow(10,-7);
cout << endl << "Viskosität ν: " << nu << endl;
Rey = Re(v,nu,d);

cout << "Die berechnete Reynolds-Zahl lautet: " << Rey << endl;






return 0;
}
