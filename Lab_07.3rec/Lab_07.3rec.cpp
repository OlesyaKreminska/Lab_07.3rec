#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для підрахунку кількості однакових елементів у рядку
int CountSameElements(int* row, int colCount) {
    int maxCount = 1;
    for (int i = 0; i < colCount; ++i) {
        int count = 1;
        for (int j = i + 1; j < colCount; ++j) {
            if (row[i] == row[j])
                count++;
        }
        if (count > maxCount)
            maxCount = count;
    }
    return maxCount;
}

// Функція для сортування рядків за кількістю однакових елементів
void SortRowsBySameElements(int** a, int rowCount, int colCount) {
    // Масив для зберігання кількості однакових елементів у кожному рядку
    int* sameElementCounts = new int[rowCount];

    // Заповнюємо масив кількістю однакових елементів для кожного рядка
    for (int i = 0; i < rowCount; ++i) {
        sameElementCounts[i] = CountSameElements(a[i], colCount);
    }

    // Сортуємо рядки за кількістю однакових елементів за допомогою алгоритму "пузиркового сортування"
    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            if (sameElementCounts[j] > sameElementCounts[j + 1]) {
                // Обмінюємо місцями кількість однакових елементів
                int tempCount = sameElementCounts[j];
                sameElementCounts[j] = sameElementCounts[j + 1];
                sameElementCounts[j + 1] = tempCount;

                // Обмінюємо місцями рядки
                int* tempRow = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tempRow;
            }
        }
    }

    // Звільняємо пам'ять, виділену під масив
    delete[] sameElementCounts;
}

// Функція для пошуку першого стовпця без від'ємних елементів
int FindFirstColumnWithoutNegatives(int** a, int rowCount, int colCount) {
    for (int j = 0; j < colCount; ++j) {
        bool hasNegative = false;
        for (int i = 0; i < rowCount; ++i) {
            if (a[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative)
            return j; // Повертаємо номер стовпця
    }
    return -1; // Якщо немає жодного такого стовпця
}

// Допоміжні функції для виведення та введення матриці
void PrintRow(int* row, const int colCount) {
    for (int j = 0; j < colCount; ++j)
        cout << setw(4) << row[j];
    cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; ++i)
        PrintRow(a[i], colCount);
    cout << endl;
}

void InputRow(int* row, const int colCount) {
    for (int j = 0; j < colCount; ++j) {
        cout << "a[" << j << "] = ";
        cin >> row[j];
    }
}

void InputRows(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; ++i) {
        InputRow(a[i], colCount);
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // Динамічне створення матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    // Введення матриці
    InputRows(a, rowCount, colCount);

    // Виведення початкової матриці
    cout << "Initial Matrix:" << endl;
    PrintRows(a, rowCount, colCount);

    // Сортування рядків за кількістю однакових елементів
    SortRowsBySameElements(a, rowCount, colCount);

    // Виведення відсортованої матриці
    cout << "Sorted Matrix:" << endl;
    PrintRows(a, rowCount, colCount);

    // Пошук першого стовпця без від'ємних елементів
    int firstCol = FindFirstColumnWithoutNegatives(a, rowCount, colCount);
    if (firstCol != -1)
        cout << "First column without negative elements is: " << firstCol + 1 << endl;
    else
        cout << "There is no column without negative elements." << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; ++i)
        delete[] a[i];
    delete[] a;

    return 0;
}
