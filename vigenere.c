/*
* Edx-Harvardx CS50, Pset2, Vigenere.c
*
* By Khalid ATIF
*
*  
*
*   The purpose of this code is to encrypt a plain text, as seen in Caesar.c, but instead
* of shifting the text by a single key, it will encipher it using a key word,to which
* each letters will be attributed their alphabetical index value (for example; a = 0, c = 2). 
*
*
*                        _                                
*                 __   _(_) __ _  ___ _ __   ___ _ __ ___ 
*                 \ \ / / |/ _` |/ _ \ '_ \ / _ \ '__/ _ \
*                  \ V /| | (_| |  __/ | | |  __/ | |  __/
*                   \_/ |_|\__, |\___|_| |_|\___|_|  \___|
*                          |___/                          
*
*
*
*
*/


#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    
  // As in Caesar, the code below will return an error message if a key word isn't entered while declaring the code. 
    
  {
    if(argc != 2)
        {
            printf("Enter key word according to the following usage: ./vigenere word \n");
            return 1;
        }
       
    // Checking if the key is alphabetical. Each strings must be checked, hence the "for" loop. Thanks to the initiators of the following posts; http://redd.it/1vyb3m and http://redd.it/1vtaeo.
    
    
    for (int i = 0; i < strlen(argv[1]); i++)    
    {    
        if(!isalpha(argv[1][i]))
        {
            printf("Please input alphabetical characters only! \n");
            return 1;
        }
    
    }   
    
    
    
   
    
    
    string key = (argv[1]);
    

    
    string plain_text = GetString();
    
    
    
    if(plain_text != NULL)
    
   
    
    
   
    
/* 
*   The problem in this pset wasn't to figure out the calculus to be made (it was obvious
* that modulo was needed to wrap at the end of the key), but to implement it. 
*  
*
* I thought that it would be the same as for the plain text[i] and the same kind of for loop was needed for the key [j],
* but this wasn't that simple since "j" shouldn't loop outside the extrnal "else" statement (the one wich would let the 
* non alphabetical characters remaining untouched).
*
*
* I have also combined the "j" for loop into "i" for loop since the j < n value was another hick there.
* Thanks to Delpity (Brenda) on Reddit for this post, which elped me figure out what I did wrong (http://redd.it/1y78gs).
* 
* 
* 
*
*
*/

    for (int i = 0,j= 0,modk = 0; i < strlen(plain_text); i++)
    
    {
        
        if (isalpha(plain_text[i]))  
            {
             
            modk = j % strlen(key);
            
            if (islower(plain_text[i]) && isupper(key[modk]))
             
               {   
                   // The ASCII value ('a') to start with "a" as an alphabetical value (0). 
                   int upper_key = (((plain_text[i] - 'a') + (key[modk]  - 'A')) % 26) + 'a';
                   printf("%c", upper_key);
                   j++;
                  
               }
             
            else if (islower(plain_text[i]) && islower(key[modk]))
               {  
                   int lower_both = (((plain_text[i] - 'a') + (key[modk] - 'a')) % 26) + 'a';
                   printf("%c", lower_both);
                   j++;
               }
             
               
            else if (isupper(plain_text[i]) && islower(key[modk]))
              
               {   
                   int upper_plain = (((plain_text[i]- 'A') + (key[modk] - 'a'))  % 26) + 'A';
                   printf("%c", upper_plain); 
                   j++;
               }
            else if (isupper(plain_text[i]) && isupper(key[modk]))
               {  
                   int upper_both = (((plain_text[i] - 'A') + (key[modk] - 'A')) % 26) + 'A';
                   printf("%c", upper_both);
                   j++;
               }
            
            
            }
        // This statement will print all the non alphabeticals characters, such as spaces and punctuations.  
        else
            {
                printf("%c" , plain_text[i]);
                
            }
       
     } 
     
  }
   
    printf("\n");
}  
  
/*
*
*
* 
* 
*                            
*                             
*
*                   _ _     _                _                                    
*                  ( | )___| |_ __ _ _   _  | |__  _   _ _ __   __ _ _ __ _   _   
*                   V V/ __| __/ _` | | | | | '_ \| | | | '_ \ / _` | '__| | | |  
*                      \__ \ || (_| | |_| | | | | | |_| | | | | (_| | |  | |_| |_ 
*                      |___/\__\__,_|\__, | |_| |_|\__,_|_| |_|\__, |_|   \__, ( )
*                                    |___/                     |___/      |___/|/ 
*                       _                 __             _ _     _    _ _ 
*                   ___| |_ __ _ _   _   / _| ___   ___ | (_)___| |__( | )
*                  / __| __/ _` | | | | | |_ / _ \ / _ \| | / __| '_ \V V 
*                  \__ \ || (_| | |_| | |  _| (_) | (_) | | \__ \ | | |   
*                  |___/\__\__,_|\__, | |_|  \___/ \___/|_|_|___/_| |_|   
*                                |___/                                    
*
*
*
*
*
*
* Ascii art credit: http://www.network-science.de/ascii/
*
*
*/





