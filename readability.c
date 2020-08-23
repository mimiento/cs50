#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int countLetters(string, int);
int countWords(string, int);
int countSentences(string, int);
int calculateIndex(int, int, int);

int main(void)
{
    string text = get_string("Text: ");
    int textLength = strlen(text);
    int letters = countLetters(text, textLength);
    int words = countWords(text, textLength);
    int sentences = countSentences(text, textLength);
    int index = calculateIndex(letters, words, sentences);
}

int countLetters(string text, int textLength) //outputs total alphabetical characters within the text input
{
    int letters = 0;
    for (int i = 0; i < textLength; i++) //runs through each character in text
    {
        if (isalpha(text[i]) != 0) //function from ctype.h
        {
            letters++;
        }
    }
    return letters;
}

int countWords(string text, int textLength) //outputs total words within text input
{
    int words = 1;
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == ' ') //uses a space character to add to word count
        {
            words++;
        }
    }
    return words;
}

int countSentences(string text, int textLength) //outputs total sentences within text input by looking for . ! ? characters
{
    int sentences = 0;
    for (int i = 0; i < textLength; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

int calculateIndex(int letters, int words, int sentences) //outputs grade level of text input
{
    float L = (((float)letters / words) * 100);
    float S = (((float)sentences / words) * 100);
    int index = round(0.0588 * L - .296 * S - 15.8);
    if (index < 1)
    {
         printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return index;
}