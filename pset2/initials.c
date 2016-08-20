/*this is my asssignment on pset 2 done by Gautham M in summer 2016   */
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    string s;
    s=GetString();
    int i=0;
    if(islower(s[0]))
    {
        printf("%c",toupper(s[0]));
    }
    else
       printf("%c",s[0]);
    while(i<=strlen(s)){
        if(s[i]==' '){
            if(islower(s[i+1]))
              printf("%c",toupper(s[i+1]));
            else
              printf("%c",s[i+1]);
             }
    ++i;}
    printf("\n");
}