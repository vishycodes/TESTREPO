/*==================================================================
 *
 *               University College Dublin
 *          EEEN20010 - Computer Engineering I
 *
 * File Name	:	hangman.c
 *
 * Description	:	Game of Hangman
 *
 * Author		:	Vishnu Peteti
 *
 * Student No.  :   18387313
 *
 * Date         :   12-11-19
 *
 * Lab Group    :   Friday 11am-12:50pm
 *==================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define readonly = r


int main(void)

{
    char reply;

    do
    {

    int num_lives = 10;
    char user_choice;
    char guess_word[100];
    int character_ref;
    char letter;
    char output[100]; /* Temporary Variable to hide the word */
    char word[100];
    char file_import[100];
    printf("Give the filename with the unknown word: ");
    scanf("%s/n",file_import);


    FILE *fp;

         if((fp = fopen(file_import, "r"))== NULL) /* Opening the file from file path */
        {
            printf("Cannot open file"); /* If the file is not founf in the system please exit the program */
            exit(EXIT_FAILURE);
        }

    fscanf(fp,"%s",word); /* Read the file until the first character space */
    fclose(fp); /* Closing the file */

        for(character_ref=0;character_ref<=strlen(word)-1;character_ref++)
        {
            output[character_ref] = '*'; /* Make all the characters in the string asteriks*/
        }

    bool match; /* Use of the Bool function to guess the word */


    printf("\nReady to Start!\n");

    while(num_lives != 0)
    {

        printf("The word is: %s ",output);
        printf("\nNumber of Lives remaining:%d\n",num_lives);
        match = false; /* Initialise the boolean function to be false initially */
        printf("Would you like to guess the word [w] or guess a letter [l]: ");
        scanf(" %c",&user_choice); /* User input- whether the user wants to guess the word or guess a letter */

        if(user_choice == 'l') /* If user input is l please scan the letter and see it matches if it does not please cover the letter */
        {
            printf("\nWhat letter have you chosen?: ");
            scanf(" %c",&letter);
            printf("\n***********************************************");
            for(character_ref=0;character_ref<strlen(word);character_ref++)
            {

                if(word[character_ref] != letter && output[character_ref] == '*') /*If the letter is not a letter in the string please keep the asterik and dont reveal the word*/
                {

                    output[character_ref] = '*';
                }
                else if(word[character_ref] == letter) /*If the word is a letter in the string please reveal the letter */
                {
                    output[character_ref]=letter;
                    match = true; /* Boolean Logic - The letter is correct */
                }
            }

            if(match == true)
            {
                printf("\nGood Choice! ");
            }
            else if(num_lives) /* If the match is not true print "Bad choice and subtract 1 from number of lives remaining*/
            {
                printf("\nBad Choice!");
                num_lives = num_lives-1;
            }

        }

        else if(user_choice =='w')
            /* If the user inputs 'w' we need the user to input the full guessed word and compare the strings using the strcmp function */
        {
            printf("What is your guessed word?: ");
            scanf(" %s",guess_word);
            if(strcmp(guess_word , word) == 0) /* If the guessed word is the same as the word in the string print "Congragulations"*/
            {
                printf("Congratulations!");
                break;
            }
            else /*If the word guessed is wrong print bad choice and subtract number of lives*/
            {
                printf("\n***********************************************");
                printf("\nBad Choice!\n");
                num_lives = num_lives -1 ;
            }

        }

    }
            if(num_lives==0)
            {
                printf("\nSorry you are out of lives!");
            }

        printf("\nDo you wish to play again[y/n]: ");
        while((getchar()) != '\n'); /* Deletes buffer formed by scanf inputs */
        reply = getchar();

    }
        while(reply == 'y');
        return 0;
}

