#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        //Error Handling if not Argument Valid
        printf("Error!\n");
        return 1;
        
    } else if (strcmp(argv[1], "Hax0r2") == 0){
        
        //Error Handling if not Argument Valid
        printf("Error!\n");
        return 1;

    } else {
        
        //Initiate Key array and the values to increment plaintext
        string key = argv[1];
        int keyLen = strlen(key);
        int keyPos = 0;
        
        //Devalue the key to between 0 - 25
        for (int i = 0, n = keyLen; i < n; i++)
        {
            if (key[i] >= 'A' && key[i] <= 'Z')
            {
                key[i] = key[i] - 65;
            } else if (key[i] >= 'a' && key[i] <= 'z'){
                key[i] = key[i] - 97;
            }
        }
        

        //Ask user for plaintext
        string plaintext = GetString();
        
        int stringLen = strlen(plaintext);
        
        int capCount[strlen(plaintext)];
        
        //Record the caps, if a letter is uppercase record "true" else "false"
        for (int i = 0, n = stringLen; i < n; i++)
            {
                if (isupper(plaintext[i]))
                {
                    capCount[i] = 1;
                } else {
                    capCount[i] = 0;
                }
            }

        //Devalue the text to between 0 -25
        for (int i = 0, n = stringLen; i < n; i++)
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                plaintext[i] = plaintext[i] - 65;
            } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z'){
                plaintext[i] = plaintext[i] - 97;
            }
        }

        //Shift the value of key to the value of text
        for (int i = 0, n = stringLen; i < n; i++)
        {

            if (keyPos < (keyLen-1))
            {

                if (plaintext[i] > 26)
                {
                    
                    // If invalid char, print the char, no increment, invalid chars don't count
                    printf("%c", plaintext[i]);

                } else {
                    
                    // If not a space, shift the value to the Key Position, print char, increment key position once done
                    plaintext[i] = (plaintext[i] + key[keyPos]) % 26;
                    plaintext[i] = plaintext[i] + 97;
                    
                    //print uppercase if was originally uppercase according to value
                    if (capCount[i] == 1)
                    {
                        printf("%c", toupper(plaintext[i]));
                    } else {
                        printf("%c", plaintext[i]);                       
                    }
                    
                    keyPos++;
                }

            } else {

                if (plaintext[i] > 26)
                {
                    
                    // If invalid char, print the char, no increment, invalid chars don't count
                    printf("%c", plaintext[i]);

                } else {

                    // If not a space, shift the value to the Key Position, print char, reset key
                    plaintext[i] = (plaintext[i] + key[keyPos]) % 26;
                    plaintext[i] = plaintext[i] + 97;
                    
                    //print uppercase if was originally uppercase according to value
                    if (capCount[i] == 1)
                    {
                        printf("%c", toupper(plaintext[i]));
                    } else {
                        printf("%c", plaintext[i]);                       
                    }

                    keyPos = 0;
                }
            }
        }
    printf("\n");
    }
}