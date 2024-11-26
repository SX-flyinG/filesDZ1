#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Записываем текст в файл
    ofstream inFile("homework.txt");
    inFile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    inFile.close();

    // Читаем текст из файла
    string line;
    ifstream outFile("homework.txt");
    getline(outFile, line); // Читаем первую строку
    outFile.close();

    cout << "Original line: " << line << endl;

    // Копируем первые 100 символов в массив
    char* lineNew = new char[101]; // Дополнительный символ для '\0'
    for (int i = 0; i < 100; i++) {
        lineNew[i] = line[i];
    }
    lineNew[100] = '\0'; // Завершаем строку нулевым символом

    // Замена 'a' или 'A' на 'X'
    for (int i = 0; i < 100; i++) {
        if (lineNew[i] == 'a' || lineNew[i] == 'A') {
            lineNew[i] = 'X';
        }
    }

    // Вывод результата
    cout << "Modified line: " << lineNew << endl;

    // Освобождаем память
    delete[] lineNew;
    lineNew = nullptr;

    return 0;
}
