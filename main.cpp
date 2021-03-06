#include <iostream>
#include <math.h>
#include "rrf.h"
using namespace std;

int main()
{
double v;      //Strömungsgeschwindigkeit
double d;      //char. Länge -> Durchmesser
double l;      //Rohrlänge
double T;      //Temperatur des Mediums
double nu;     //kinematische Viskosität
double Rey;    //Reynolds-Zahl
double rho;    //Dichte
double lambda; //Rohrreibungszahl
double dp;     //Druckverlust

cout << "Rohrreibungsberechnung für ein gerades Rohr mit dem Medium Luft" << endl << endl << endl;

cout << "   ┌------------┐" << endl;
cout << "   └------------┘" << endl << endl << endl;

cout << "Beliebige Taste drücken zum Fortsetzen" << endl;
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
cout << endl << endl << "--> Viskosität ν: " << nu << endl << endl;
Rey = Re(v,nu,d);

cout << "--> Die berechnete Reynolds-Zahl lautet: " << Rey << endl <<endl;

	if (Rey < 2300)
	{
	cout << "INFO: Es liegt eine laminare Strömung vor!" << endl << endl;
	}
	else
	{
	cout << "INFO: Es liegt eine turbulente Strömung vor!" << endl << endl;
	}


if (Rey < 2300)
{
lambda = 64 / Rey;
cout << "Der Rohrreibungsbeiwert lautet: " << lambda << endl;
}
else
{
//SOLVER FÜR LAMBDA IM TURBULENTEN BEREICH NACH PRANDTL/KARMAN
double y_ceil = 1;
double y_floor = 0;
double eq = 1;
double y = 0;
double epsilon = 1e-10;

cout << "Der Rohrreibungsbeiwert wird nun iterativ durch die Prandtl - Karman Formel ermittelt." << endl << endl;
cin.get();

while (fabs(eq) > epsilon)
	{
	y = y_floor + (y_ceil - y_floor) / 2;
	cout << y << endl;
	eq = Karman_r (Rey,y);
		if (eq < 0)
		{
		y_ceil = y;
		}
		else
		{
		y_floor = y;
		}
	}
lambda = y;
}



rho = Dichte(T);
dp = ((rho * pow(v,2)) / 2) * lambda * (l / d);

cout << endl << "Der berechnete Druckverlust lautet: " << dp << " Pascal" << endl;
return 0;
}
