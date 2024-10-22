#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

// Counting Sort

// Counting Sort
void countingSort(vector<int>& arr) {
    // Find the maximum value in the input array
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Create a count array to store the frequency of each value
    vector<int> count(maxVal + 1, 0);
    vector<int> output(arr.size());

    // Count the occurrences of each value
    for (int i = 0; i < arr.size(); ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the position of each value in the sorted order
    for (int i = 1; i <= maxVal; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted values back to the original array
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}



// Radix Sort
int getMax(vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
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

    vector<int> arr;
    int n = 20; // Change the array size as needed

    cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        arr.push_back(rand() % 100); // Fill the array with random numbers between 0 and 99
        cout << arr[i] << " ";
    }
    cout << endl;

    // Create copies of the original array for each sorting algorithm
    vector<int> arrBubble = arr;
    vector<int> arrSelection = arr;
    vector<int> arrInsertion = arr;
    vector<int> arrMerge = arr;
    vector<int> arrCounting = arr;
    vector<int> arrRadix = arr;
    vector<int> arrQuick = arr;

    // Sort and print using Bubble Sort
    cout << "\nBubble Sort:" << endl;
    bubbleSort(arrBubble);
    printArray(arrBubble);

    // Sort and print using Selection Sort
    cout << "\nSelection Sort:" << endl;
    selectionSort(arrSelection);
    printArray(arrSelection);

    // Sort and print using Insertion Sort
    cout << "\nInsertion Sort:" << endl;
    insertionSort(arrInsertion);
    printArray(arrInsertion);

    // Sort and print using Merge Sort
    cout << "\nMerge Sort:" << endl;
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    printArray(arrMerge);

    // Sort and print using Counting Sort
    cout << "\nCounting Sort:" << endl;
    countingSort(arrCounting);
    printArray(arrCounting);

    // Sort and print using Radix Sort
    cout << "\nRadix Sort:" << endl;
    radixSort(arrRadix);
    printArray(arrRadix);

    // Sort and print using Quick Sort
    cout << "\nQuick Sort:" << endl;
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    printArray(arrQuick);

    return 0;
}


