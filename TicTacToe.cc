#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

void drawBoard() { // Draws the board
	cout << "——————————————" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "| ";
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j] << " | ";
		}
	cout << endl << "——————————————" << endl;
	}
}

bool checkWin() { // Check if a player has won
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkTie() { // Check if there is a tie
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(int position) { // Check if player's move is valid
    if (position < 1 || position > 9) {
        return false;
    }
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    return true;
}

void makeMove(int position) { // Make player's move
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = currentPlayer;
}

void switchPlayer() { // Switch to next player
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int minimax(char currentPlayer) { // Psuedo enemy AI
    // Check if AI wins
    if (checkWin() && currentPlayer == 'X') {
        return 10;
    } else if (checkWin() && currentPlayer == 'O') {
        return -10;
    } else if (checkTie()) {
        return 0;
    }

    vector<int> scores;
    vector<int> moves;

    // Simulate each possible move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j];
                board[i][j] = currentPlayer;
                if (currentPlayer == 'X') {
                    scores.push_back(minimax('O'));
                } else {
                    scores.push_back(minimax('X'));
                }
                moves.push_back(i * 3 + j + 1);
                board[i][j] = temp;
            }
        }
    }

    // Find the best move
    if (currentPlayer == 'X') {
        int maxScoreIndex = distance(scores.begin(), max_element(scores.begin(), scores.end()));
        return scores[maxScoreIndex];
    } else {
        int minScoreIndex = distance(scores.begin(), min_element(scores.begin(), scores.end()));
        return scores[minScoreIndex];
    }
}

int findBestMove() {
    vector<int> scores;
    vector<int> moves;

    // Simulate each possible move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char temp = board[i][j];
                board[i][j] = currentPlayer;
                scores.push_back(minimax('O'));
                moves.push_back(i * 3 + j + 1);
                board[i][j] = temp;
            }
        }
    }

    // Find the best move
    int bestMoveIndex;
    if (currentPlayer == 'X') {
        bestMoveIndex = distance(scores.begin(), max_element(scores.begin(), scores.end()));
    } else {
        bestMoveIndex = distance(scores.begin(), min_element(scores.begin(), scores.end()));
    }
    return moves[bestMoveIndex];
}

int main() {
    int move;
    cout << "Welcome to Tic Tac Toe!" << endl;
    drawBoard();

    while (!checkWin() && !checkTie()) {
        if (currentPlayer == 'X') {
            cout << "Player X's turn. Enter a position (1-9): ";
            while (!(cin >> move) || !isValidMove(move)) {
                cout << "Invalid move. Please try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            cout << "Player O's turn." << endl;
            move = findBestMove();
        }
        makeMove(move);
        drawBoard();
        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
        }
        switchPlayer();
    }

    return 0;
}



