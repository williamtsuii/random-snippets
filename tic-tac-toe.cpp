#include <iostream>

int EMPTY=0;
int CROSS=1;
int CIRCLE=2;
int CURRENT_PLAYER=CROSS;
int board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j]=EMPTY;
        }
    }
}

bool checkFinished(int array[3][3]) {
    bool status=true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == EMPTY) { status = false; }
        }
    }

    return status;
}

void updateBoard(int array[3][3], int x, int y) {
    array[x][y]=CURRENT_PLAYER;
}

bool checkWinner(int array[3][3]) {
    bool won=false;

    for (int i = 0 ; i < 3; i++) {
        if (CURRENT_PLAYER==array[i][0] && CURRENT_PLAYER==array[i][1] && CURRENT_PLAYER==array[i][2]) {
            won=true;
        }
        if (CURRENT_PLAYER==array[0][i] && CURRENT_PLAYER==array[1][i] && CURRENT_PLAYER==array[2][i]) {
            won=true;
        }
    }
    if ((CURRENT_PLAYER==array[0][0] && CURRENT_PLAYER==array[1][1] && CURRENT_PLAYER==array[2][2]) ||
        (CURRENT_PLAYER==array[2][0] && CURRENT_PLAYER==array[1][1] && CURRENT_PLAYER==array[0][2])) {
            won=true;
    }

    return won;
}

void nextPlayer() {
    if (CURRENT_PLAYER == CROSS) {
        CURRENT_PLAYER = CIRCLE;
    } else {
        CURRENT_PLAYER = CROSS;
    }
}

void printBoard(int array[3][3]) {
    for (int i = 0; i<3; i++) {
        std::cout << board[0][i] << "|" << board[1][i] << "|" << board[2][i] << "\n";
    }
}

int main() {
    initBoard();


    while (checkFinished(board) != true) {
        std::cout << "Current player: " << CURRENT_PLAYER << "\n";

        int x,y;
        char open,comma,close;
        std::cout << "Please enter coordinates (x,y): ";
        std::cin >> open >> x >> comma >> y >> close;
        x--,y--;

        if (board[x][y] != EMPTY) {
            std::cout << "This spot is already occupied. Please select another.\n";
            continue;
        }
        updateBoard(board, x, y);
        printBoard(board);

        if (checkWinner(board)==true) {
            std::cout << "Player " << CURRENT_PLAYER << " is the winner!";
            break;
        }

        nextPlayer();
    }
}
