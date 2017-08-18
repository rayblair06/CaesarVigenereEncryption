#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        // Error Handling
        printf("Error!\n");
        return 1;
        
    } else {

        // Initiate key and Input String
        int k = atoi(argv[1]);
        string plaintext = GetString();

        // Iterate through plaintext 
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {   
            // Iterates through each letter and tests it between the alphabet, otherwise it rotates back to A or breaks
            for (int j = 0; k > j; j++)
            {
                if ((plaintext[i] >= 'a' && plaintext[i] < 'z') || (plaintext[i] >= 'A' && plaintext[i] < 'Z'))
                {
                    plaintext[i] = plaintext[i] + 1;
                } else if (plaintext[i] == 'z' || plaintext[i] == 'Z') { 
                    plaintext[i]  = plaintext[i] - 25;
                } else { 
                    break;
                }
            }
            //plaintext[i] = plaintext[i] + (k % 26);
            printf("%c", plaintext[i]);
        }
        
        printf("\n");
        
    } 
}