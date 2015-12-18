#include <stdio.h>
#include <math.h>

const double cm1 = 3.15;
const double cm2 = 2.6;
const int N = 1000;
const int H = 5;
const int effi = 76;
const double G = 9.81;
const int Z = 8;
const int phi = 30;
const double pi = 3.14;

int main() {
    double d1, d2;
    printf("Enter D1 and D2\n");
    scanf("%lf %lf", &d1, &d2);
    printf("%lf  %lf", d1, d2);
    double u1 = (pi*d1*N)/60;
    double u2 = (pi*d2*N)/60;

    double ta1 = (u1/cm1);
    double a1 = atan(u1/cm1);

    double cb2 = (H*G)/effi*u2;

    double ta2 = (u2 - cb2)/cm2;
    double a2 = atan((u2 - cb2)/cm2);

    double vs = pi*u2*cos(a2)*sin(pi/6.0)/Z;

    double a21 = atan(ta2 - (vs/cm2));
    double am = atan((ta1 + ta2)/2);
    double s = pi*(d1+d2)/(2*Z);
    printf("Alpha2' =  %lf, Alpha1 = %lf, Alpham = %lf, S = %lf\n", (a21*180)/pi, (a1*180)/pi, (am*180)/pi, s);
    return 0;
}
