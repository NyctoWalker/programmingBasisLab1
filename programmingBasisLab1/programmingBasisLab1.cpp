#include <iostream>
using namespace std;
#include <ctime>

int main()
{
    /*Дана целочисленная квадратная матрица порядка 6. Найти матрицу, получающуюся из данной перестановкой
    строк - первой с последней, второй - с предпоследней и т.д.Перестановка осуществляется при условии, что 
    элемент главной диагонали обоих строк не равен нулю.Вывести исходную и преобразованную матрицы.
    По условию задачи, должно быть 3 посделовательных блока: чтение и запись, обработка, вывод.*/
    //Блок записи
    setlocale(LC_ALL, "ru");
    int const SIZE = 6;
    int arr[SIZE][SIZE];
    srand(time(NULL));
    //Для данной матрицы используем генератор случайных чисел(так как псевдослучайные могут не дать 0 на диагонали) и заполним массив через цикл
    cout << "Изначальная матрица: \n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    //===================================
    //Блок обработки данных
    int arrChanged[SIZE][SIZE], noZeroes[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i][i] != 0)
        {
            noZeroes[i] = true;
            cout << "\nЧлен главной диагонали " << i << ", " << i << " не равен нулю.";
        }
        else
        {
            noZeroes[i] = false;
            cout << endl << i << ", " << i << " - член главной диагонали, равный нулю!";
        }
    }

    for (int i = 0; i < (SIZE/2); i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (noZeroes[i] == true && noZeroes[SIZE - 1 - i] == true)
            {
                arrChanged[i][j] = arr[SIZE - 1 - i][j];
                arrChanged[SIZE - 1 - i][j] = arr[i][j];
            }
            else
            {
                arrChanged[i][j] = arr[i][j];
                arrChanged[SIZE - 1 - i][j] = arr[SIZE - 1 - i][j];
            }
        }
    }

    //============================================
    //Блок вывода
    cout << "\nИзменённая матрица:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << arrChanged[i][j] << "\t";
        }
        cout << endl;
    }
}