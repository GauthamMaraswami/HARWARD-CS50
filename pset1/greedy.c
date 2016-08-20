/*this is my asssignment on pset 1 done by Gautham M in summer 2016   */
#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main(){
    float b;
    int a,ctr;
    ctr=0;
    
   // printf("O hai! How much change is owed?");
    do{
         printf("O hai! How much change is owed?");
     b=GetFloat();
    }while(b<0);
    a=(int) round(b*100);
    while(a>0){
        if(a>=25){
            ctr+=a/25;
            a%=25;
        }
        else if(a>=10)
        {
            ctr+=a/10;
            a%=10;
        }
        else if(a>=5){
            ctr+=a/5;
            a%=5;}
        else{
            ctr+=a;
            a=0;
        }
        }
        printf("%d\n",ctr);
        
   
        
}