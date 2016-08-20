/*this is my asssignment on pset 1 done by Gautham M in summer 2016   */
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int n,i,j,k,ctr,valid;
    
    do{
        printf("height: ");
        char s[30];

fgets(s, sizeof(s), stdin);
valid = 1;
n=0;
for (i = 0; i <strlen(s)-1; ++i)
{//printf("%c",s[i]);
    if (!isdigit(s[i]))
    {
        valid = 0;
        break;
    }
   
    n=n*10+s[i]-48;
}
if(s[0]=='\n')
valid=0;
 
        
    }while(valid==0||n<0||n>23);
   // printf("%d",n);
    ctr=n-1;
    for( i=2;i<=n+1;++i){
        for( j=0;j<ctr;++j)
         printf(" ");
        for( k=0;k<i;++k)
           printf("#");
         printf("\n");
        --ctr;
    }
    
}