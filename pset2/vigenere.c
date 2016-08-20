/*this is my asssignment on pset 2 done by Gautham M in summer 2016   */
#include<cs50.h>
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
        string s1=(argv[1]);
        int n2=strlen(s1),j=0;
        int flag=0;
        for(int i=0;i<n2;++i){
            if((isalpha(s1[i]))==0)
            flag=1;
        }
        if(flag==1){
            printf("wrong input");
       return 1;
        }
        
        s=GetString();
        int n=strlen(s);
        int a1[n];
        
        for(int i=0;i<n;++i){
            if(islower(s1[j]))
            a1[i]=s1[j]-97;
            else
              a1[i]=s1[j]-65;
            ++j;
            if(j>=n2)
            j%=n2;
            
        }
       /* for(int i=0;i<n;++i){
            printf("%d",a1[i]);
        }*/
      j=0;
        for(int i=0;i<strlen(s);++i){
          
            if(isalpha(s[i])){
                if(islower(s[i])){
                    if(s[i]+a1[j]<=122)
                      {printf("%c",s[i]+a1[j]);++j;}
                    else
                     { printf("%c",96+((s[i]+a1[j])%122));++j;}
                }
                else{
                    if(s[i]+a1[i]<=90)
                      {printf("%c",s[i]+a1[j]);++j;}
                    else
                      {printf("%c",64+((s[i]+a1[i])%90));++j;}
                }
               }
               else
               printf("%c",s[i]); 
                
            }
             printf("\n");
        }
       
    }
