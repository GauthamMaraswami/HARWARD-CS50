/*this is my asssignment on pset 1 done by Gautham M in summer 2016   */
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    int n,c,valid;
    do{
        
        char s[30];
 printf("minutes: ");
fgets(s, sizeof(s), stdin);
valid = 1;
n=0;
for (int i = 0; i <strlen(s)-1; ++i)
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
 
        
    }while(valid==0);
    
   
   // scanf("%d",&n);
    c=12*n;
    printf("bottles: %d",c);
}
    
