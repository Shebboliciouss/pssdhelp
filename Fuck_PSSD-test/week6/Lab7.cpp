
#include <stdio.h>

// Time Complexity of O(n^2)

// int findSplit( int a[], int aSize) {
//     int x, y;
//     for (int i=0; i < aSize; i++) {
//         x = 0;
//         y = 0;
//         for (int j=0; j <= i; j++)
//              x += a[j];
//         for (int k=i+1; k < aSize; k++)
//              y += a[k];
//         if (x == y) 
//             return i;
//     }
//     return -1;
// }



// Time Complexity of O(n)

int findSplit(int a[], int aSize){
    int first_sum = 0;
    int second_sum = 0;
    
    // this sums all the elements in the array 
    for (int i = 0; i < aSize; i++){
        first_sum += a[i];
    }

    // then add the elements one by one into the second sum but minus from the first sum 
    // which will give the sum from 2 subarrays: first_sum and second_sum
    for (int i = 0; i < aSize; i++){
        first_sum -= a[i];
        second_sum += a[i];
        // if 2 of the sum from the subarrays are the same return the index
        if(first_sum==second_sum){
            return i;
        }
    }

    // not possible 
    return -1;
} 




/*
Time Complexity:
Old code : O(n^2) 
New code : O(n)

Reason: 

I made separate for loop for adding and subtracting the elements from the sum, in order to
break the nested for loop from the previous code which will reduce the time complexity 
of the code. Furthermore, I made seperate for loop instead of a nested for loop 
as it would be more easier to have a for loop that iterate through the array 
and have a variable that sum up all the elements in the array.
Then, using another for loop outside the previous loop to loop through the array 
again and add one element at a time to another variable while subtracting 
the same element from the preivous variable that add up all the elements in the array.

*/
    
int main() {
    int numbers[] = {12, 2,5, 3,8,2,6};
    int index = findSplit(numbers, 7);

    if (index == -1)
         printf("not possible");
    else 
        printf("Split at index %2i", index);

    return 0;
}
