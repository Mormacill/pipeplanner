#include <math.h>

double Re (double v, double n, double d)
{
return ((v*d)/n);
}

double vis (double T)
{
//* * * Muss noch mit 10^-7 multipliziert werden! * * *
return -1.16643853*pow(10,-13)*pow(T,5) + 3.60057235*pow(10,-10)*pow(T,4) + -5.304786536*pow(10,-7)*pow(T,3) + 0.001118914391*pow(T,2) + 0.891933997744*T + 135.2163195635;
}

double Dichte (double T)
{
return 9.1756*pow(10,-17)*pow(T,6) + -1.6489*pow(10,-13)*pow(T,5) + 1.2461*pow(10,-10)*pow(T,4) + -5.45353*pow(10,-8)*pow(T,3) + 1.70866*pow(10,-5)*pow(T,2) + -0.00469795*T + 1.2755;
}
