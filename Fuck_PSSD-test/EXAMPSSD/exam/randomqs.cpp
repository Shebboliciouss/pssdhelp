#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to partition the array into two parts and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    // Randomly select a pivot element
    int randomIdx = low + rand() % (high - low + 1);
    swap(arr[randomIdx], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Find the pivot index
        int pivotIdx = partition(arr, low, high);

        // Recursively sort the two sub-arrays
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed for random numbers

    vector<int> arr = {4, 2, 9, 6, 5, 3, 8, 7, 1};
    
    cout << "Original Array: ";
    printArray(arr);

    cout << "Sorted Array (Randomized Quick Sort): ";
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);

    return 0;
}
