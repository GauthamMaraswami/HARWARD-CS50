#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


// size of hashtable
#define SIZE 1000000

// create nodes for linked list
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[SIZE] = {NULL};

// create hash function
int hash (const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;
        
        // comma case
        else
            n = 27;
            
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;    
}

// create global variable to count size
int dictionarySize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    // opens dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    
    // create an array for word to be stored in
    char word[LENGTH+1];
    
    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        // increment dictionary size
        dictionarySize++;
        
        // allocate memory for new word 
        node* newWord = malloc(sizeof(node));
        
        // put word in the new node
        strcpy(newWord->word, word);
        
        // find what index of the array the word should go in
        int index = hash(word);
        
        // if hashtable is empty at index, insert
        if (hashtable[index] == NULL)
        {
            hashtable[index] = newWord;
            newWord->next = NULL;
        }
        
        // if hashtable is not empty at index, append
        else
        {
            newWord->next = hashtable[index];
            hashtable[index] = newWord;
        }      
    }
    
    // close file
    fclose(file);
    
    // return true if successful 
    return true;
}

     


bool check(const char* word)
{
   char temp[LENGTH+1];
   int len=strlen(word);
   for(int i=0;i<len;++i){
       temp[i]=tolower(word[i]);
       
   }
   temp[len]='\0';
    int index = hash(temp);
    if(hashtable[index]==NULL){
       return false;
    }
     node* cursor = hashtable[index];
    while(cursor!=NULL){
        if(strcmp(cursor->word,temp)==0){
            return true;
        }
        cursor=cursor->next;
    }
    return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
     if (dictionarySize > 0)
    {
        return dictionarySize;
    }
     
    // if dictionary hasn't been loaded, return 0
    else
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   int index=0;
   while (index < SIZE)
    {
       
        if (hashtable[index] == NULL)
        {
            index++;
        }
        else{
            while(hashtable[index]!=NULL){
                node* cursor=hashtable[index];
                hashtable[index]=cursor->next;
                free(cursor);
            }
             index++;
              
        }
        
    }
   return true;
}
