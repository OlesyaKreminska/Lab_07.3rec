#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// ������� ��� ��������� ������� ��������� �������� � �����
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

// ������� ��� ���������� ����� �� ������� ��������� ��������
void SortRowsBySameElements(int** a, int rowCount, int colCount) {
    // ����� ��� ��������� ������� ��������� �������� � ������� �����
    int* sameElementCounts = new int[rowCount];

    // ���������� ����� ������� ��������� �������� ��� ������� �����
    for (int i = 0; i < rowCount; ++i) {
        sameElementCounts[i] = CountSameElements(a[i], colCount);
    }

    // ������� ����� �� ������� ��������� �������� �� ��������� ��������� "����������� ����������"
    for (int i = 0; i < rowCount - 1; ++i) {
        for (int j = 0; j < rowCount - i - 1; ++j) {
            if (sameElementCounts[j] > sameElementCounts[j + 1]) {
                // �������� ������ ������� ��������� ��������
                int tempCount = sameElementCounts[j];
                sameElementCounts[j] = sameElementCounts[j + 1];
                sameElementCounts[j + 1] = tempCount;

                // �������� ������ �����
                int* tempRow = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tempRow;
            }
        }
    }

    // ��������� ���'���, ������� �� �����
    delete[] sameElementCounts;
}

// ������� ��� ������ ������� ������� ��� ��'����� ��������
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
            return j; // ��������� ����� �������
    }
    return -1; // ���� ���� ������� ������ �������
}

// ������� ������� ��� ��������� �� �������� �������
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

    // �������� ��������� �������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];

    // �������� �������
    InputRows(a, rowCount, colCount);

    // ��������� ��������� �������
    cout << "Initial Matrix:" << endl;
    PrintRows(a, rowCount, colCount);

    // ���������� ����� �� ������� ��������� ��������
    SortRowsBySameElements(a, rowCount, colCount);

    // ��������� ����������� �������
    cout << "Sorted Matrix:" << endl;
    PrintRows(a, rowCount, colCount);

    // ����� ������� ������� ��� ��'����� ��������
    int firstCol = FindFirstColumnWithoutNegatives(a, rowCount, colCount);
    if (firstCol != -1)
        cout << "First column without negative elements is: " << firstCol + 1 << endl;
    else
        cout << "There is no column without negative elements." << endl;

    // ��������� ���'��
    for (int i = 0; i < rowCount; ++i)
        delete[] a[i];
    delete[] a;

    return 0;
}
