//C++ Program to play Tic-Tac-Toe against computer.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int SIZE = 3;

// display table
void display_table(char board[SIZE][SIZE]) {
    cout << "The current state of the game is:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '\0') {
                cout << "_ ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}
//clear table
void clear_table(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = '\0';
        }
    }
}
//check table
bool check_table_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '\0') {
                return false;
            }
        }
    }
    return true;
}
//checl legal option
bool check_legal_option(char board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    return board[row][col] == '\0';
}
//generate player2 move
void generate_player2_move(char board[SIZE][SIZE]) {
    srand(time(0));

    while (true) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        if (check_legal_option(board, row, col)) {
            board[row][col] = 'X';
            cout << "Player 2 has entered [row, col]: " << row + 1 << "," << col + 1 << endl;
            display_table(board);
            break;
        }
    }
}
//check 3 in a row
int check_three_in_a_row(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '\0') {
            return (board[i][0] == 'O') ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '\0') {
            return (board[0][i] == 'O') ? 1 : 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '\0') {
        return (board[0][0] == 'O') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '\0') {
        return (board[0][2] == 'O') ? 1 : 2;
    }

    return 0;
}
//check end of game
bool check_end_of_game(char board[SIZE][SIZE]) {
    return check_table_full(board) || check_three_in_a_row(board) != 0;
}
//get player 1 move

void get_player1_move(char board[SIZE][SIZE]) {
    int row, col;

    do {
        cout << "Player 1 enter your selection [row col]: ";
        cin >> row >> col;

        // Adjust the input to userbased index
        --row;
        --col;

        if (!check_legal_option(board, row, col)) {
            cout << "Invalid move. Try again.\n";
        }
    } while (!check_legal_option(board, row, col));

    // Update the board with the valid move
    board[row][col] = 'O';

    // Print out the current state of the board
    display_table(board);
}
//printing
void print_winner(char board[SIZE][SIZE]) {
    int winner = check_three_in_a_row(board);

    if (winner == 1) {
        cout << "Congratulations, Player 1 wins!" << endl;
    } else if (winner == 2) {
        cout << "Player 2 wins! Better luck next time, Player 1." << endl;
    } else {
        cout << "Game over, no player wins." << endl;
    }
}
//main function
int main() {
    char board[SIZE][SIZE];
    clear_table(board);
    display_table(board);

    do {
        get_player1_move(board);

        if (check_end_of_game(board)) {
            break;  // Exit the loop if the game ends after Player 1's move
        }

        generate_player2_move(board);

    } while (!check_end_of_game(board));

    print_winner(board);

    return 0;
}
