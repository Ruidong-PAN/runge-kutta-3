#include<stdlib.h> 
#include<stdio.h> 
#include<math.h>

/*n désigne le nombre de intervales égales et n+1 désigne le nombre de points.*/ 

  //Méthode de Runge-Kutta d'ordre 3
  int rungeKutta(double y0,double a,double b,int n,double *x,double *y,double (*function)(double,double)){ 
      double h=(b-a)/n,k1,k2,k3; 
      int i; 
      // x=(double*)malloc((n+1)*sizeof(double)); 
      // y=(double*)malloc((n+1)*sizeof(double)); 
      x[0]=a; 
      y[0]=y0; 
      for(i=0;i<n;i++){ 
        x[i+1]=x[i]+h; 
        k1=function(x[i],y[i]); 
        k2=function(x[i]+h/2,y[i]+h*k1/2); 
        k3=function(x[i]+h,y[i]-h*k1+2*h*k2); 
        y[i+1]=y[i]+h*(k1+4*k2+k3)/6; 
      } 
      return 1;
   } 
      
      //exemple résoudre y'=2*y/(1+x);y0=1;
      double function(double x,double y){ 
         return y; 
      } 
      
      
      //solution exacte de équation différentielle y=(1+x)^2
      double f(double x){
        return exp(x);
      }

        int main(){
          int i,n; 
          double y0,a,b;
          printf("veuillez saisir respectivement le valeur initial y0, intervale à gauche a, intervale à droit b et le nombre de points intermédiaires n:\n");
          scanf("%lf%lf%lf%d",&y0,&a,&b,&n);
          double x[n+1],y[n+1]; 
          double h=(b-a)/n;
          
          printf(" \n");
          printf("Utiliser la méthode Ryuga-Kuta de troisième ordre:\n"); 
          printf(" \n");
          rungeKutta(y0,a,b,n,x,y,function); 
          printf("y0=%lf,a=%lf,b=%lf,le pas: h=%lf\n",y0,a,b,h); 
          printf(" \n");
          for(i=0;i<(n+1);i++) 
          //erreur entre les valeurs exactes et approximatives: %lf  f(x[i])-y[i]
          printf("x[%d]=%11.10f, y[%d]=%16.15f, y(%d)=%16.15lf, erreur:%16.15le\n",i,x[i],i,y[i],i,f(x[i]),f(x[i])-y[i]); 
          printf(" \n");
          //printf("Erreur de troncature locale: h^4=%le\n",h*h*h*h);
          //printf(" \n");
          //printf("précision maximale: h^3=%le\n",h*h*h);
          return 1; 
        }
