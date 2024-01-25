#include <iostream>
using namespace std;

void playerMoveX(char field[3][3]) {
    int playerSquare, currentSquare = 0;
    while (true) {
        cout << "Ход X" << endl;
        cout << "Введите номер клетки: ";
        cin >> playerSquare;
        currentSquare = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                currentSquare++;
                if (playerSquare == currentSquare){
                    if (field[i][j] == ' ') {
                        field[i][j] = 'X';
                        return;
                    }
                    else {
                        cout << endl << "Клетка занята" << endl;
                    }
                }
            }
        }

    }
}

void playerMoveO(char field[3][3]) {
    int playerSquare, currentSquare = 0;
    while (true) {
        cout << "Ход O" << endl;
        cout << "Введите номер клетки: ";
        cin >> playerSquare;
        currentSquare = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                currentSquare++;
                if (playerSquare == currentSquare){
                    if (field[i][j] == ' ') {
                        field[i][j] = 'O';
                        return;
                    } else {
                        cout << endl << "Клетка занята" << endl;
                    }
                }
            }
        }

    }
}

void fieldPrint(char field[3][3]) {
    int help[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numberOfSquare = 0;
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            numberOfSquare++;
            if (field[i][j] == ' '){
                cout << '[' << " " << numberOfSquare << " "<< ']';
            }
            else{
                cout << ' '<< '[' << field[i][j] <<']'<< " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void botMove(char field[3][3]) {
    for (int i = 0; i < 3; i++) {

        if (field[i][0] == 'O' && field[i][1] == 'O' && field[i][2] == ' ') {
            field[i][2] = 'O';
            return;
        } else if (field[i][0] == 'O' && field[i][2] == 'O' && field[i][1] == ' ') {
            field[i][1] = 'O';
            return;
        } else if (field[i][1] == 'O' && field[i][2] == 'O' && field[i][0] == ' ') {
            field[i][0] = 'O';
            return;
        }

        if (field[i][0] == 'X' && field[i][1] == 'X' && field[i][2] == ' ') {
            field[i][2] = 'O';
            return;
        } else if (field[i][0] == 'X' && field[i][2] == 'X' && field[i][1] == ' ') {
            field[i][1] = 'O';
            return;
        } else if (field[i][1] == 'X' && field[i][2] == 'X' && field[i][0] == ' ') {
            field[i][0] = 'O';
            return;
        }
    }

    if (field[1][1] == ' ') {
        field[1][1] = 'O';
        return;
    }

    if (field[0][0] == ' ' || field[0][2] == ' ' || field[2][0] == ' ' || field[2][2] == ' ') {
        if (field[0][0] == ' ') {
            field[0][0] = 'O';
        } else if (field[0][2] == ' ') {
            field[0][2] = 'O';
        } else if (field[2][0] == ' ') {
            field[2][0] = 'O';
        } else {
            field[2][2] = 'O';
        }
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (field[i][0] == ' ') {
            field[i][0] = 'O';
            return;
        } else if (field[i][1] == ' ') {
            field[i][1] = 'O';
            return;
        } else if (field[i][2] == ' ') {
            field[i][2] = 'O';
            return;
        }
    }


}

short winCheck(char field[3][3]){
    short feeled, win = 0;
    feeled = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (field[i][j] != ' ') {
                feeled++;
            }
        }
    }
    if (feeled == 9) {
        win = 3;
    }

    if (field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X') {
        win = 1;
    } else if (field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O') {
        win = 2;
    }

    if (field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X') {
        win = 1;
    } else if (field[0][2] == 'O' && field[1][1] == 'O' && field[2][0] == 'O') {
        win = 2;
    }

    for (int i = 0; i < 3; i++) {
        if (field[i][0] == 'X' && field[i][1] == 'X' && field[i][2] == 'X') {
            win = 1;
        }
        else if (field[i][0] == 'O' && field[i][1] == 'O' && field[i][2] == 'O') {
            win = 2;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (field[0][j] == 'X' && field[1][j] == 'X' && field[2][j] == 'X') {
            win = 1;
        }
        if (field[0][j] == 'O' && field[1][j] == 'O' && field[2][j] == 'O') {
            win = 2;
        }
    }

    return win;
}

int main() {
    system("chcp 65001");
    cout << "\033[2J\033[1;1H";
    short win;
    short players;
    string input;
    while(true) {
        char field[3][3] = {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}
        };
        while (true) {
            cout << "Сколько игроков? (1/2): ";
            cin >> players;
            if (players != 1 && players != 2) {
                cout << "Неверное количество игроков" << endl;
            } else {
                break;
            }
        }
        fieldPrint(field);

        if (players == 1) {
            while (true) {
                playerMoveX(field);
                fieldPrint(field);
                win = winCheck(field);
                if (win == 1 || win == 2 || win == 3) {
                    break;
                }

                botMove(field);
                fieldPrint(field);
                win = winCheck(field);
                if (win == 1 || win == 2 || win == 3) {
                    break;
                }
            }
            switch (win) {
                case 1:
                    cout << "Победа" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
                case 2:
                    cout << "Поражение" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
                case 3:
                    cout << "Ничья" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
            }
        }
        else {
            while (true) {
                playerMoveX(field);
                fieldPrint(field);
                win = winCheck(field);
                if (win == 1 || win == 2 || win == 3) {
                    break;
                }

                playerMoveO(field);
                fieldPrint(field);
                win = winCheck(field);
                if (win == 1 || win == 2 || win == 3) {
                    break;
                }
            }
            switch (win) {
                case 1:
                    cout << "Победа X" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
                case 2:
                    cout << "Победа O" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
                case 3:
                    cout << "Ничья" << endl;
                    cout << "Хотите сыграть ещё раз? (д/н): ";
                    while (true) {
                        cin >> input;
                        if (input == "д") {
                            break;
                        } else if (input == "н") {
                            return 1;
                        }
                    }
                    break;
            }
        }
    }
}