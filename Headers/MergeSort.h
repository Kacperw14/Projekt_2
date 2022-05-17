#include <iostream>

void Merge(int array[], int left, int mid, int right)
{
    int ArrayPartLeft = mid - left + 1;
    int ArrayPartRight = right - mid;

    //pomocnicze tablice dla lewego i prawego rozwiazania
    int* leftArray = new int[ArrayPartLeft];
    int* rightArray = new int[ArrayPartRight];

    //kopiowanie danych do zmiennych pomocniczych
    for (int i = 0; i < ArrayPartLeft; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < ArrayPartRight; j++)
        rightArray[j] = array[mid + 1 + j];

    //podstawowe zainicjowanie zmiennych
    int indexOfArrayPartLeft = 0; 
    int indexOfArrayPartRight = 0;
    int indexOfMergedArray = left; 

    //Laczenie pomocniczych tablic
    while (indexOfArrayPartLeft < ArrayPartLeft && indexOfArrayPartRight < ArrayPartRight) {
        if (leftArray[indexOfArrayPartLeft] <= rightArray[indexOfArrayPartRight]) {
            array[indexOfMergedArray] = leftArray[indexOfArrayPartLeft];
            indexOfArrayPartLeft++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfArrayPartRight];
            indexOfArrayPartRight++;
        }
        indexOfMergedArray++;
    }
    //Kopiowanie lewych elementow
    while (indexOfArrayPartLeft < ArrayPartLeft) {
        array[indexOfMergedArray] = leftArray[indexOfArrayPartLeft];
        indexOfArrayPartLeft++;
        indexOfMergedArray++;
    }
//Kopiowanie prawych elementow
    while (indexOfArrayPartRight < ArrayPartRight) {
        array[indexOfMergedArray] = rightArray[indexOfArrayPartRight];
        indexOfArrayPartRight++;
        indexOfMergedArray++;
    }
    delete[]leftArray;
    delete[]rightArray;
}

void MergeSort(int array[], int begin, int end)
{
    if (begin >= end) return; // rekursywny powrot

    int mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}

void PrintArray(int _tablica[], int size)
{
    for (int i = 0; i < size; i++) std::cout << _tablica[i] << " ";
}