Problem Statement: Given an array of N integers, write a 
program to add an array element at the beginning, end, 
and at a specific position.

//code
#include <iostream>

using namespace std;
void insertatbegin(int* arr,int n,int value)
{
    for(int i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=value;
}

void insertatEnd(int *arr, int n, int value)
{
    arr[n] = value;
}

void insertatposition(int *arr, int n, int value, int pos)
{
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
}