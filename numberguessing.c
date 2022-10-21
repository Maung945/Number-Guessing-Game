/*
*   Myo Aung- Number Guessing Game- CS-2600 System Programming
*   Frirst set Global variable as 10 and declare variables.
*   Prompt user to Choose options 1-3
*   Do-while loop to repeate till Optioni-3 is entered.
*   If User entered enry other than "Numbers" promopt user to enter a new number
*/

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int max_number = 10;                                                                                // Global variable
    int numberOfGuess, guess, option, max;
    int win = 0; 
    int randomNumber;
    char c[2];

    do
    {
        printf("        Enter 1 to Play a Game\n");
        printf("        Enter 2 to Change the Max Number\n");
        printf("        Enter 3 to Quit\n");
        scanf("%d", &option);
        
        switch (option)                                                                             // switch case
        {
        case 1:
            numberOfGuess = 0;
            
            randomNumber = rand() % max_number + 1;                                                 // Generate a random number from 0 to maximum number set by the user
            printf("Please enter a number \n");
            do
            {
                scanf("%s", c);

                if (c[0] == 'q')                                                                    // when user enters q it quits the game
                    break;
                else
                {
                    guess = atoi(c);
                    if (guess > randomNumber)                                                       // if the guessed number is greater than the random generated number
                        printf("Your guess is too high\n");

                    else if (guess < randomNumber)                                                   // if the guessed number is greater than the random generated number
                        printf("Your guess is too low\n");

                    else
                    {
                        win = 1;
                        printf("Your Guess is CORRECT!!\n\n");
                        break;
                    }
                    
                    numberOfGuess++;                                                                // count the total number of guess the user takes to find the correct number
                }
            } while (c[0] != 'q' || randomNumber == guess);
            break;
        case 2:
            char input;
            int incomingMax;
            

            printf("Enter the new maximum number:\n");
            do
            {
                FILE *out_file = fopen("MaxNumberSaveOutput.txt", "w"); // This lines open "MaxNumberSaveOutput.txt" to save Maximumb Nubmer
                if (out_file == NULL)
                {
                    printf("Error! File could  not open!\n");
                    exit(-1);
                }
                printf("Use previous Max-Number?(Y/N):");
                scanf("%s", &input);

                if (input == 'Y')
                {
                    FILE *fp = fopen("MaxNumberSaveOutput.txt", "r");
                    while(!feof(fp)) {
                        fscanf(fp, "%d", &max);
                        printf("Max Numberrrr: %d\n", max);
                    }
                    fclose(fp);
                    break;
                }
                else
                {
                    printf("Enter New Maximum Number: ");
                    scanf("%d", &max);
                    fprintf(out_file, "Last Saved Max Number: %d\n", max);
                }

                if (max <= 0 || max > 10)                                                           // if the new maximum number is not between 0 to 10
                    printf("Please enter a valid number \n");
                
                else                                                                                // if the new number is valid assign it to our global variable
                    max_number = max;
                
                

            } while (max <= 0 || max > 10);
            
            printf("The new maximum number generated will be between 0 to %d\n", max_number);
            break;
        case 3:
            
            printf("Thank you for playing the game\n");                                             // if user enters to quit the game print the results of the game they played
            
            break;
        }
    } while (option != 3);

    return EXIT_SUCCESS;
}