#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Before Sorting: ";
    printArray(array, size);

    // Step 1: Finding Max
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // Step 2: Frequency Array
    int freq[max + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        freq[array[i]]++;
    }

    cout << "Freq Array: ";
    printArray(freq, max + 1);

    // Step 3: Cumulative Sum
    for (int i = 1; i <= max; i++)
    {
        freq[i] += freq[i - 1];
    }

    cout << "After Sum of cumulative: ";
    printArray(freq, max + 1);

    // Stet 4: Backword Traversal
    int final[size];
    for (int i = size - 1; i >= 0; i--)
    {
        freq[array[i]]--;
        int k = freq[array[i]];
        final[k] = array[i];
    }

    cout << "After Sorting: ";
    printArray(final, size);
    return 0;
}