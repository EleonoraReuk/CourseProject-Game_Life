#include <iostream>
#include <vector>

using namespace std;

int countLiveCell(const vector<vector<char>>& pole, int row, int col) {
    int liveCount = 0;
    int rows = pole.size();
    int columns = pole[0].size();


    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns) {
                if (pole[newRow][newCol] == '*') {
                    ++liveCount;
                }
            }
        }
    }
    return liveCount;
}

void printPole(const vector<vector<char>>& pole) {
    for (const auto& row : pole) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, columns;
    std::cin >> rows >> columns;

    vector<vector<char>> pole(rows, vector<char>(columns, '-'));

    cout << "Введите 10 клеток с жизнью:" << endl;
    for (int k = 0; k < 10; k++) {
        int row, col;
        cout << "Клетка " << k + 1 << ": ";
        cin >> row >> col;
        if (row >= 0 && row < rows && col >= 0 && col < columns) {
            pole[row][col] = '*';
        }
        else {
            cout << "Ошибка! Координаты вне поля. Попробуйте снова." << endl;
            k--;
        }
    }

    while (true) {
        printPole(pole);
        vector<vector<char>> newPole = pole;
        bool Change = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int liveCell = countLiveCell(pole, i, j);

                if (pole[i][j] == '*') {
                    if (liveCell < 2 || liveCell > 3) {
                        newPole[i][j] = '-';
                        Change = true;
                    }
                }
                else {
                    if (liveCell == 3) {
                        newPole[i][j] = '*';
                        Change = true;
                    }
                }
            }
        }

        if (!Change) {
            cout << "Игра закончена. Стабильная конфигурация." << endl;
            break;
        }

        pole = newPole;

        bool hasLiveCells = false;
        for (const auto& row : pole) {
            for (char cell : row) {
                if (cell == '*') {
                    hasLiveCells = true;
                    break;
                }
            }
            if (hasLiveCells) break;
        }
        if (!hasLiveCells) {
            cout << "Игра закончена." <<  "Нет живых клеток." << endl;
            break;
        }


        cout << "Нажмите Enter для продолжения...";
        cin.ignore();
        cin.get();
    }

    return EXIT_SUCCESS;
}
