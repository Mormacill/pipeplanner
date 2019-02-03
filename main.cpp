#include <iostream>
#include <math.h>
#include "rrf.h"
using namespace std;

int main()
{
double v,      //Strömungsgeschwindigkeit
double d,      //char. Länge -> Durchmesser
double l,      //Rohrlänge
double T,      //Temperatur des Mediums
double nu,     //kinematische Viskosität
double Rey,    //Reynolds-Zahl
double rho,    //Dichte
double lambda, //Rohrreibungszahl
double dp;     //Druckverlust

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
cout << "Rohrlänge l= ";
cin >> l;
cout << "Temperatur des Strömungsmediums T (Gültigkeit -40 - 500°C)= ";
cin >> T;
nu = vis(T);
nu = nu*pow(10,-7);
cout << endl << "Viskosität ν: " << nu << endl;
Rey = Re(v,nu,d);

cout << "Die berechnete Reynolds-Zahl lautet: " << Rey << endl;

	if (Rey < 2300)
	{
	cout << "INFO: Es liegt eine laminare Strömung vor!" << endl;
	}
	else
	{
	cout << "INFO: Es liegt eine turbulente Strömung vor!" << endl;
	}



// BERECHNUNG
// VON
// LAMBDA

lambda = 0.02;

rho = Dichte(T);
dp = ((rho * pow(v,2)) / 2) * lambda * (l / d);

cout << "Der berechnete Druckverlust lautet: " << dp << " Pascal" << endl;
return 0;
}
