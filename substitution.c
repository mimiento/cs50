#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2) //ensures user enters one argument as the key
    {
        printf("KEY\n");
        return 1;
    }

    string encipher(string, string);
    string key = argv[1];
    int keyLength = strlen(key);

    if (keyLength != 26) //checks if key is exactly 26 characters
    {
        printf("Error. Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < keyLength; i++) //checks if key is only alphabetical characters
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Error. Please enter only alphabetical characters into the key.\n");
            return 1;
        }
    }

    for (int i = 0; i < keyLength; i++) //nested loops check if a given letter appears more than once in key
    {
        for (int j = i + 1; j < keyLength; j++)
        {
            if (key[i] == key[j])
            {
                printf("Error. Please enter each alphabetical character only once with no repeats.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < 26; i++) //convert key to uppercase
    {
        key[i] = toupper(key[i]);
    }

    string plainText = get_string("plaintext: ");
    encipher(key, plainText);
    return 0;
}

string encipher(string key, string plainText)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int abcLen = 26;
    int plainLen = strlen(plainText);
    string cypherText = plainText;


    for (int i = 0; i < plainLen; i++) //loops through each character of plain text
    {
        for (int j = 0; j < abcLen; j++) //loops through alphabet for matching char, applies to cypher upon match
        {
            if (plainText[i] == abc[j])
            {
                cypherText[i] = toupper(key[j]);
                break;
            }
            else if (toupper(plainText[i]) == abc[j])
            {
                cypherText[i] = tolower(key[j]);
                break;
            }
            else if (plainText[i] > 31 && plainText[i] < 65) //if not an alpahetical char, applies punctuation to cypher upon match
            {
                cypherText[i] = plainText[i];
                break;
            }
        }

    }
    printf("ciphertext: %s\n", cypherText);
    return cypherText;
}