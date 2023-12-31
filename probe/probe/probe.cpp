﻿// probe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>  // 3 ЛАБА

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    const int N = 12;
    int vec_nosort[N] = { 22,999,1,5,250,115,777,-5,333,620,0,123 };
    int vec_sort[N] = { -5,0,1,5,22,115,123,250,333,620,777,999 };
    int number;
    cout << "Введите число для поиска: ";
    cin >> number;
    // линейный поиск 
    int i = 0;
    int found_index = -1; // порядковый номер найденного элемента

    for (; i < N; i++)
        if (vec_nosort[i] == number)
        {
            found_index = i;
            cout << "Число найдено в неупорядоченном массиве. Порядковый номер: " << found_index << endl;
            break;
        }
    if (i == N)
        cout << "Число не найдено в неупорядоченном массиве." << endl;

    // бинарный поиск

    bool found = false;  // вначале полагаем, что такого числа нет
    int low = 0, high = N - 1, mid;
    int found_index2 = -1; // порядковый номер найденного элемента

    while (!found and low <= high)
    {
        mid = (low + high) / 2;
        if (vec_sort[mid] > number)
            high = mid - 1;
        else if (vec_sort[mid] < number)
            low = mid + 1;
        else
        {
            found = true;
            found_index2 = mid;
        }
    }

    if (found)
        cout << "Число найдено в упорядоченном массиве. Порядковый номер: " << found_index2 << endl;
    else
        cout << "Число не найдено в упорядоченном массиве." << endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
