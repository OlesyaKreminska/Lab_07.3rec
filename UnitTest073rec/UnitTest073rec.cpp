#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3rec/Lab_07.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest073rec
{
	TEST_CLASS(UnitTest073rec)
	{
	public:

		// ���� ��� ������� ���������� ����� �� ������� ��������� ��������
		TEST_METHOD(TestSortRowsBySameElements)
		{
			// ��������� ������� 3x3
			int rowCount = 3, colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
				a[i] = new int[colCount];

			// ������� ��� ����������
			a[0][0] = 1; a[0][1] = 1; a[0][2] = 1;
			a[1][0] = 2; a[1][1] = 2; a[1][2] = 3;
			a[2][0] = 4; a[2][1] = 5; a[2][2] = 6;

			// ���������� ��������� ���� ���������� (�������� ��������� �������� � ����� 0)
			int expected[3][3] = {
				{4, 5, 6},
				{2, 2, 3},
				{1, 1, 1}
			};

			// ������ ������� ����������
			SortRowsBySameElements(a, rowCount, colCount);

			// �������� ����������
			for (int i = 0; i < rowCount; ++i) {
				for (int j = 0; j < colCount; ++j) {
					Assert::AreEqual(expected[i][j], a[i][j], L"������� ����������� �����������");
				}
			}

			// ��������� ���'��
			for (int i = 0; i < rowCount; ++i)
				delete[] a[i];
			delete[] a;
		}
	};
}