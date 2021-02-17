

#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>


#define msize 500



int  M1[msize][msize], M2[msize][msize], M3[msize][msize];


int satir, sutun1, sutun2;

int deger;

void *thread_matris_carpim(void *);


int main()
{
 
   int r; 
  
   pthread_t  threadID;
     

    
    printf("1. matris satir sayisini giriniz: ");
    scanf("%d", &satir);
    printf("1. matris sutun sayisini giriniz: ");
    scanf("%d", &sutun1);
    printf("2. matris sutun sayisini giriniz: ");
    scanf("%d", &sutun2);

    
   for(int i=0; i<satir; i++){
      
        for(int j=0; j<sutun1; j++){

        FILE *dosya=fopen("Rndmdeger.txt","w");
        r = 1 + rand()%10; 
		    fprintf(dosya, "%d\n", r);	
        fclose(dosya);
        
        dosya = fopen("Rndmdeger.txt","r");
        fscanf(dosya, "%d", &deger) ;
         
        int c = deger;
         
        M1[i][j] = c;
        fclose(dosya);
           
        }
    }
    printf("\n");


    for(int i=0; i<sutun1; i++){

        for(int j=0; j<sutun2; j++){

         FILE *dosya=fopen("Rndmdeger.txt","w"); 
         r =1 + rand()%10; 
         fprintf(dosya, "%d\n", r);	
         fclose(dosya);

         dosya = fopen("Rndmdeger.txt","r");
         fscanf(dosya, "%d", &deger) ;

         int c = deger;

         M2[i][j] = c;
        fclose(dosya);
           
        }
    }
  
for(int z = 0; z<satir; z++)
{
 pthread_create(&threadID, NULL,thread_matris_carpim,NULL );

 pthread_join(threadID,NULL);
 }





 printf("1.Matris\n");
    for(int deg1=0; deg1<satir; deg1++)
    {
      for(int deg2=0; deg2<sutun1; deg2++)
      {
        printf("%2d\t",M1[deg1][deg2]);
      }
      printf("\n");
    }




 printf("\n2.Matris\n");
    for(int deg1=0; deg1<sutun1; deg1++)
    {
      for(int deg2=0; deg2<sutun2; deg2++)
      {
        printf("%2d\t", M2[deg1][deg2]);
      }
      printf("\n");
    }
     

    
    
    

printf("\n 3.Matris \n");
    for(int deg3 = 0; deg3 < satir; deg3++)
    {
      for(int deg4 = 0; deg4 < sutun2; deg4++)
      {
        printf("%2d\t", M3[deg3][deg4]);
      }
      printf("\n");
    }
  

   return 0;
}


void *thread_matris_carpim(void *sonuc)
{
    for(int c = 0; c < satir; c++)
    {

      for(int d = 0; d < sutun2; d++)
      {
        M3[c][d] = 0;

        for(int e = 0; e < sutun1;e++)
        {
          M3[c][d] +=M1[c][e] * M2[e][d]; 
        }

      }

    }

pthread_exit(NULL);

}