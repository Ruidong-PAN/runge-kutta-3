# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>
# define PI  3.14159265
# define SCOPE 4.0
# define N 101
# define max 100000
typedef struct coordinate{
        float x;
        float y;
}coord;
float rm(){


        float c= rand()/(double)(RAND_MAX + 1.0);
        return c;
}
void gaussienne(float U[max] ,float V[max],float m,float n,float t,coord C[max]){
       n=sqrt(n);
       float tmp1, tmp2;
       for (int j=0; j< t; j++){
                tmp1 = -2*log(U[j]);
                tmp2 = 2*PI*V[j];
                C[j].x=m+n* sqrt(tmp1)*sin(tmp2);
                C[j].y=m+n* sqrt(tmp1)*cos(tmp2);     }

}
int contain(float a ,float INF, float SUF){
	int k = 0;
        if ( a >= INF && a< SUF) k = 1;
        else k = 0;
	return k;
}
void hist1(int t ,int nb,float m,float n,coord C[max] ){
       float xb[N]; int a[N];
       float da;
       da = 2.0 * SCOPE * sqrt(n) / nb;
       for (int i=0; i<=nb;i++) {
               xb[i]=m-SCOPE * sqrt((double)n)+ i * da;
       }
       for (int i=0; i<nb; i++) a[i]=0;
       for (int i =0; i< t;i++ ){
               for (int j=0;j<nb; j++){
               if (contain(C[i].x,xb[j],xb[j+1])==1) {
               a[j]+=1;
               break;
               }
               }

       }
       float mean, proba;
       for(int i=0 ; i<nb;i++){
               mean=0.5* ( xb[i] + xb[i+1]);
	       proba=a[i]/(da*t);
	       printf(" %f %f\n",mean,proba);
       }

}
void hist2(int t ,int nb , float U[max] ){
       float xbb[N] ;  int aa[N] ;
       float da = 1.0 / nb;
       for (int i=0;  i<=nb;i++)  xbb[i] = i*da;
       for (int i=0; i<nb; i++) aa[i]=0;

       for (int i =0; i< t;i++ ){
	       
               for (int j=0;j<nb;j ++){
		       if (contain(U[i],xbb[j],xbb[j+1])== 0) continue; 
		       aa[j]+=1;
		       break;
		       
               }
       }

       float mean, proba;
       for(int i=0 ; i<nb;i++){
	       mean=0.5* (xbb[i] + xbb[i+1]);
	       proba=aa[i]/(t*da);
	       printf(" %f %f\n", mean,proba);
       }



}
void hist3(int t ,int nb,float m,float n,coord C[max]  ){
       coord xc[N][N]; int ac[N][N];
       float da  =2 * SCOPE * sqrt((double)n)/nb;
       for (int i=0; i<=nb; i++) {
              for (int j=0;j<=nb;j++){
                      xc[i][j].x=m-SCOPE * sqrt(n)+i*da;
                      xc[i][j].y=m-SCOPE * sqrt(n)+j*da;
              }
       }
       for (int i=0 ; i<nb ; i++)
	       for (int j =0; j< nb ; j++)
		       ac[i][j]=0;

       for (int i =0; i< t ;i++ ){
               for (int j=0;j<nb; j++){
		       if (contain(C[i].x,xc[j][0].x,xc[j+1][0].x)==1){
                          for (int k=0; k<nb; k++){
                              if (contain(C[i].y , xc[j][k].y , xc[j][k+1].y)==1) {
				      ac[j][k]+=1;
				      break;
			      }
			  }
			  break;
                       }

               }
       }

       float meanx,meany,proba;

       for(int i=0 ; i<nb;i++ ){
               for (int j=0;j<nb;j++){
                      meanx=0.5*(xc[i][j].x + xc[i+1][j].x);
		      meany=0.5*(xc[i][j].y+xc[i][j+1].y);
		      proba=ac[i][j]/(da*da*t);
                      printf(" %f %f %f\n", meanx, meany, proba);}
       }
       

}
int main()
{       srand(time(NULL));
        float U[max],V[max],X[max]; coord C[max];
        float m,n;
        int t,nb;
        int cho; 	
        scanf("%f %f %d %d %d",&m,&n,&t,&nb,&cho);
        for (int i=0; i < t; i++){
        U[i]=rm();
        V[i]=rm();}
	gaussienne(U,V,m,n,t,C);
	switch(cho){
		case 1 :
	        hist1(t,nb,m,n,C);
		break;
		case 2 :
	        hist2(t,nb,U);
		break;
		case 3 :
	        hist3(t,nb,m,n,C);
		break;
	}
        return 0;
}
