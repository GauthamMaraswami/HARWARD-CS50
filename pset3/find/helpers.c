/*this is my asssignment on pset 4 bmp done by Gautham M in summer 2016 
the sotrt and search functions are implemented by me  */
/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include<stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{ 
if(n<0){
    return false;
}
else{
    int flag=0;
  int beg=0,las=n-1,mid;
  while(beg<=las){
      
      mid=(beg+las)/2;
      printf("%d\n",mid);
      if(values[mid]==value){
          flag=1;
          break;
      }
      else if(values[mid]<value){
          beg=mid+1;  
      }
      else if(values[mid]>value){
       las=mid-1;
  }
     
}
  if(flag==1){
         return true;
              }
    else
        return false;
      
}
    
}
bool search1(int value, int values[], int n)
{ 
if(n<0){
    return false;
}
else{  int flag=0;
   for(int i=0;i<n;++i)
     {
         if(values[i]==value){
             flag=1;
             
         }
     }
     if(flag==1){
         return true;
              }
    else
        return false;
      
}
  
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{ 
     int te;
    for(int i=0;i<n;++i){
       int small=values[i];
        for(int j=i;j<n;++j){
            if(small>values[j]){
                te=values[j];
                values[j]=small;
                small=te;
                
            }
        }
    }
    
    return;
}