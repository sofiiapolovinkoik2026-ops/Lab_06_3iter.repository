// Lab_06_3_iter.cpp
// Половінко Софія 
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (Ітераційний спосіб).
// Варіант 13

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Звичайна функція створення масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Шаблонна функція створення масиву
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + static_cast<T>(rand()) / RAND_MAX * (High - Low);
}

// Звичайна функція виведення масиву
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// Шаблонна функція виведення масиву
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << setprecision(2) << fixed << a[i];
    cout << endl;
}

// Звичайна ітераційна функція перевірки впорядкованості за незростанням
bool IsNonIncreasing(const int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] < a[i + 1])
            return false;
    }
    return true;
}

// Шаблонна ітераційна функція перевірки впорядкованості за незростанням
template <typename T>
bool IsNonIncreasing(const T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] < a[i + 1])
            return false;
    }
    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 5;

    // 1. Тест зі звичайною функцією (int)
    int a[n] = { 10, 8, 8, 3, 1 }; // Впорядкований за незростанням
    cout << "Masiv int a:" << endl;
    Print(a, n);
    if (IsNonIncreasing(a, n))
        cout << "Masiv 'a' vporyadkovanyi za nezrostannyam (YES)" << endl;
    else
        cout << "Masiv 'a' NE vporyadkovanyi za nezrostannyam (NO)" << endl;

    cout << endl;

    // 2. Тест із шаблонною функцією (double)
    double b[n] = { 15.5, 12.1, 12.1, 4.0, 4.2 }; // Не впорядкований (4.0 < 4.2)
    cout << "Masiv double b:" << endl;
    Print(b, n);
    if (IsNonIncreasing<double>(b, n))
        cout << "Masiv 'b' vporyadkovanyi za nezrostannyam (YES)" << endl;
    else
        cout << "Masiv 'b' NE vporyadkovanyi za nezrostannyam (NO)" << endl;

    return 0;
}