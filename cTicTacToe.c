#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // For Sleep function
#include <conio.h>   // For getch function

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Tic-Tac-Toe board
int checkwin();                                                       // Function to check for a win
void drawBoard();                                                     // Function to draw the Tic-Tac-Toe board

int main()
{
    system("color 0A"); // Set console color to green text on black background
    int player = 1;     // Player 1 starts
    int choice;         // User's choice of square
    int i;              // Loop variable
    char mark;          // 'X' or 'O'

    do
    {
        drawBoard();
        player = (player % 2) ? 1 : 2; // Switch player
        printf("Player %d, Your Turn: ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O'; // Assign mark based on player

        // Check if the choice is valid
        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
        {
            square[choice] = mark; // Place the mark on the board
        }
        else
        {
            printf("Invalid move! Try again.\n");
            player--; // Decrement player to retry
            _getch(); // Wait for user input
            continue; // Skip the rest of the loop
        }

        i = checkwin(); // Check for a win
        player++;       // Switch to the next player
    } while (i == -1);

    drawBoard(); // Draw the final board

    if (i == 1)
    {
        printf("==> Player %d wins!\n", --player);
    }
    else
    {
        printf("==> It's a draw!\n");
    }
    getch(); // Wait for user input before exiting
    return 0;
}

int checkwin()
{
    // Check for winning combinations
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' &&
             square[3] != '3' && square[4] != '4' &&
             square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' &&
             square[9] != '9')
        return 0; // Draw
    else
        return -1; // Game continues
}

void drawBoard()
{
    system("cls"); // Clear the console
    printf("\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
