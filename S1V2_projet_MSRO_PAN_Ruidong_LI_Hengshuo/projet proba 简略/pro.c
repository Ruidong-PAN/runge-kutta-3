#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
  double gaussrand_normal()
 {
   static double U,V;
   static int phase=0;
   double Z;
   if (phase==0)
   {
     U=rand()/(RAND_MAX+1.0);
     V=rand()/(RAND_MAX+1.0);
     Z=sqrt(-2*log(U))*sin(2*PI*V);
   }
   else
     Z=sqrt(-2*log(U))*cos(2*PI*V);
   phase = 1-phase;
   return Z ;
 }
     double  gaussrand(double mean, double stdc)
 {
 return mean + gaussrand_normal() * stdc;
 }

int main()
{
 double a,b, data = 0;
  printf("saisi esperance et variance:");
 scanf("%lf%lf",&a,&b);
 for(int i=0; i<100; i++)
 {
  data = gaussrand(a, b);
  if (i%10==0)
  {
  printf("\n");
  printf("%lf  ", data);
 }
  else
  printf("%lf  ", data);
 }
 return 0;
}
