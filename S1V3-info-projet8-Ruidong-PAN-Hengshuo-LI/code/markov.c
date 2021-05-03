#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define M 100

struct Terme {
       char gau[10];
       char dro[10] ;
       int aret ;//0 arête 1 continue 
       struct Terme * suiv;
};
typedef struct Terme terme;


void effacer( char  *donne, char *c , int lg){
       int i;
       for ( i = 0 ;i < strlen(donne); i++){
             if ((donne+i) == c ) {
		     int j;
		     for ( j = i ; j< strlen(donne)-lg; j++) donne[j] = donne [j +lg];
		     donne[j]='\0';
		     break;
	     }
       }
}



void inserer (char *donne, char *c ,char *regle){
        for (int i =0; i<= strlen(donne); i++){
                if ((donne+i) == c){
                        char *n= regle;
                        int j;
                        for ( j =strlen(donne); j>=i; j--)  donne[j+strlen(regle)]=donne[j];
			for (int k = 0; k< strlen(regle);k++)   donne[k+i]= regle[k];
                        break;
			}
        }

}



void cat(char *g, char i){
	int n=strlen(g);
	g[n]= i;
	g[n+1] ='\0';
}//concatener un caractere a une chaine de caractere
	
	      


terme * create_liste(){
	FILE *fp;
	terme *h , *s , *r;
	char str[20];
	int n= 20;

	h = (terme *) malloc (sizeof (terme));
        r=h;

        if ( ( fp = fopen("Soustra.dat", "r") ) == NULL )  //on change directement le nom du fichier dans le code
	{ printf ( "can't open the file! \n  "); exit(0) ;}

	fgets(str ,n, fp);
	str[strlen(str)-1]= '\0';
	while ( ! feof ( fp)) {

                s = (terme *) malloc (sizeof (terme));
	        int i =0;
	        s->gau[0] ='\0';
	        s->dro[0] ='\0';
	        while ( str[i] != '>' && i < strlen(str) ) {
                        cat(s->gau,str[i]); i++;
	        }
	        i++;
	        s->aret = 1;
	        while ( str[i] != '\0'){
		        if ( str [i] == '.' ) s->aret = 0;
		        else  cat(s->dro, str[i]);
		        i++;
	        }

		r->suiv = s;
		r = s;
		fgets(str ,n, fp);
	        str[strlen(str)-1]= '\0';
	        }
        r->suiv = NULL;
	fclose (fp);
	return h ;
}


terme * delete(terme * head)
{      terme *p=head->suiv;
	terme *q;
       while (p->suiv != NULL){
	       q= p;
	      p=p->suiv;} 
       q->suiv = NULL;
       free (p);
      return head;
}//effacer la derniere cellule de la liste chainee, parce que nous enregistrons des données redondantes une fois dans la liste chainee



void   result( char *donne, terme *h) {
        terme *r = h->suiv;	
     
        while ( r != NULL ) {
                 char  *c;
		 c = strstr( donne , r->gau);
			if ( c== NULL) r = r->suiv;
		        else{
			      effacer(donne, c,strlen(r->gau) );
		              if ( r->dro[0] != '\0' ) inserer( donne , c, r->dro );
			      if (r->aret == 0 ) break;
			      r =  h->suiv ;
			}
	}
}



int main(){
        char  donne[M];
	printf("veuillez saisir une donne\n");

	fgets(donne,M,stdin);
	donne[strlen(donne)-1]= '\0';
        terme * head;
        head = create_liste();
	head= delete(head);
        result(donne, head);
	printf("%s\n", donne);
	return 0;
}

             


