#include<iostream>
using namespace std;

void display(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getMax(int* arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max; //максимальный элемент массива
}

void countSort(int* arr, int n) {
    int* output = new int[n]; // выдел€ем пам€ть под временный массив
    int max = getMax(arr, n); // находим максимальный элемент массива
    int* count = new int[max + 1]; //выдел€ем пам€ть под массив частот

    for (int i = 0; i < max + 1; i++)
        count[i] = 0; //инициализируем массив частот нул€ми
    for (int i = 0; i < n; i++)
        count[arr[i]]++; // подсчитываем частоту повторени€ элементов
        display(count, max + 1);
    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1]; // вычисл€ем накопленные частоты
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i]; // устанавливаем элемент на корректное место во временный массив
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }
    // реализаци€ алгоритма без использовани€ накопленных частот 
    //int p = 0;
    // for (int j = 0; j <= max; ++j) {
    //    for (unsigned int i = 0; i < count[j]; ++i)
    //        output[p++] = j;
    //    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; // копируем отсортированный массив во входной 
    }

    delete[] count; // освобождаем пам€ть
    delete[] output;
}

int main() {
    int arr[] = { 1,3,1,1,3,4,3,4,3,4,10,12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before Sorting: ";
    display(arr, n);
    countSort(arr, n);
    cout << "Array after Sorting: ";
    display(arr, n);
}