#include <iostream>
#include <vector>
using namespace std;

int main()
{
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

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			std::cout << pole[i][j] << " ";
		}
		cout << endl;
	}



	return EXIT_SUCCESS;
}
