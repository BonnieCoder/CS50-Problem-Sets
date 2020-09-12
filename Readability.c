#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{
    string text = get_string("Text: ");
    int words = 1;
    int sentences = 0;
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //sentence counter
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        //word counter
        else if (text[i] == ' ')
        {
            words++;
        }
        //letter counter
        else if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    float l = 100 * letters / words; //average number of letters per 100 words
    float s = 100 * sentences / words; //average number of sentences per 100 words
    //grade calculator
    float index = 0.0588 * l - 0.296 * s - 15.8;
    if (index >= 1 && index <= 16)
    {
        printf("Grade %.f\n", round(index));
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
