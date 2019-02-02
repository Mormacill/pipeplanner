double Re (double v, double n, double d)
{
return ((v*d)/n);
}

double vis (double t)
{
return -1.16643853*pow(10,-13)*pow(t,5) + 3.60057235*pow(10,-10)*pow(t,4) + -5.304786536*pow(10,-7)*pow(t,3) + 0.001118914391*pow(t,2) + 0.891933997744*t + 135.2163195635;
}
