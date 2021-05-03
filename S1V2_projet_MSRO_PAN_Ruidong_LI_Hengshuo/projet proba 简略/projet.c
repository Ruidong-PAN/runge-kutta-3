#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
float gaussrand_NORMAL() {
 static float V1, V2, S;
 static int phase = 0;
 float X;


 if (phase == 0) {
  do {
   float U1 = (float) rand() / RAND_MAX;
   float U2 = (float) rand() / RAND_MAX;


   V1 = 2 * U1 - 1;
   V2 = 2 * U2 - 1;
   S = V1 * V1 + V2 * V2;
  } while (S >= 1 || S == 0);


  X = V1 * sqrt(-2 * log(S) / S);
 } else
  X = V2 * sqrt(-2 * log(S) / S);


 phase = 1 - phase;


 return X;
}


float gaussrand(float mean, float stdc) {
 return mean + gaussrand_NORMAL() * stdc;
}


int main() 
{
 float a,b, data = 0;
 printf("saisi esperance et variance:");
 scanf("%f%f",&a,&b);
 for(int i=0; i<100; ++i){
  data = gaussrand(a, b);
  if (i%10==0)
  {
  printf("\n");
  printf("%f  ", data);
 }
  else
  printf("%f  ", data);
 }
 return 0;
}
