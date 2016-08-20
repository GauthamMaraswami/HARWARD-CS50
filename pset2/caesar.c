
/*this is my asssignment on pset 2 done by Gautham M in summer 2016   */#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc,string argv[]){
    
    
    string s;
    if(argc!=2)
       {printf("wrong input");
       return 1;}
    else
    { 
        int k = atoi(argv[1]);
        k%=26;
        s=GetString();
      
        for(int i=0;i<strlen(s);++i){
          
            if(isalpha(s[i])){
                if(islower(s[i])){
                    if(s[i]+k<=122)
                      printf("%c",s[i]+k);
                    else
                      printf("%c",96+((s[i]+k)%122));
                }
                else{
                    if(s[i]+k<=90)
                      printf("%c",s[i]+k);
                    else
                      printf("%c",64+((s[i]+k)%90));
                }
               }
               else
               printf("%c",s[i]); 
                
            }
             printf("\n");
        }
       
    }
