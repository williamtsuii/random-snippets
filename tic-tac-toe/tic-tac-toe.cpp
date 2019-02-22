#include <iostream>

char EMPTY='-';
char CROSS='X';
char CIRCLE='O';
char CURRENT_PLAYER=CROSS;
char board[3][3];

void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j]=EMPTY;
        }
    }
}

bool checkFinished(char array[3][3]) {
    bool status=true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == EMPTY) { status = false; }
        }
    }

    return status;
}

void updateBoard(char array[3][3], int x, int y) {
    array[x][y]=CURRENT_PLAYER;
}

bool checkWinner(char array[3][3]) {
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

void printBoard(char array[3][3]) {
    for (int i = 0; i<3; i++) {
        std::cout << board[0][i] << "|" << board[1][i] << "|" << board[2][i] << "\n";
    }
}

int main() {
    initBoard();


    while (checkFinished(board) != true) {
        std::cout << "Current player: " << CURRENT_PLAYER << "\n";

        int x,y;
        char comma;
        std::cout << "Please enter coordinates x,y: ";
        std::cin >> x >> comma >> y;
        x--,y--;

        if (board[x][y] != EMPTY) {
            std::cout << "This spot is already occupied. Please select another.\n";
            continue;
        }
        updateBoard(board, x, y);
        printBoard(board);

        if (checkWinner(board)==true) {
            std::cout << "Player " << CURRENT_PLAYER << " is the winner!\n";
            break;
        }

        nextPlayer();
    }
    
    if (checkFinished(board) == true && checkWinner(board) == false) {
        std::cout << "It's a draw!\n";
    }
    
    char exitAnswer;
    std::cout << "Do you want to play again? y/n: ";
    while (std::cin >> exitAnswer) {

//        std::cin >> exitAnswer;
        
        if (exitAnswer == 'y') {
            main();
        } else if (exitAnswer == 'n') {
            std::cout << "Goodbye.\n";
            return 0;
        } else {
            std::cout << "I didn't get that, please input your answer again: ";
            continue;
        }
        
    }
    
}
