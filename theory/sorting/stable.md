In the context of sorting algorithms, "stable" refers to whether the algorithm preserves the relative order of equal elements in the input array after sorting.

A sorting algorithm is stable if, for any two elements with the same value in the input array, the algorithm maintains the order of these elements in the output array as they were in the input array. In other words, if two elements with the same value appear in the input array in a specific order, the stable sorting algorithm will keep them in the same order in the output array.

For example, if the input array is [2, 5, 2, 1, 3], and we want to sort it using a stable sorting algorithm, the output array should be [1, 2, 2, 3, 5], where the two 2s are in the same order as they were in the input array.

In contrast, an unstable sorting algorithm may change the relative order of equal elements in the input array during the sorting process. For example, if the input array is [2, 5, 2, 1, 3], an unstable sorting algorithm might output [1, 2, 2, 5, 3], where the two 2s have swapped positions.

----
The stability of a sorting algorithm is an important consideration when the input data contains multiple keys or fields, and we want to sort the data based on a specific key while maintaining the order of other keys. Stable sorting algorithms can be used to achieve this by sorting the data based on each key in turn, starting with the least significant key.

Radix sort is generally considered to be a stable sorting algorithm. This is because it sorts the numbers based on their digits, starting with the least significant digit, and maintains the relative order of equal elements as they are sorted based on each digit.

Bubble sort, on the other hand, is generally considered to be an unstable sorting algorithm. This is because it swaps adjacent elements if they are out of order, which may change the relative order of equal elements in the input array.

Heap sort is also an unstable sorting algorithm, because it repeatedly swaps elements in the input array to maintain the heap property, which may change the relative order of equal elements.

Merge sort is a stable sorting algorithm, as it uses a divide-and-conquer approach to divide the input array into smaller subarrays, sort them recursively, and then merge the sorted subarrays while maintaining the relative order of equal elements.

In general, stability is an important consideration when choosing a sorting algorithm, especially when the input data contains multiple keys or fields that need to be sorted in a specific order while maintaining the order of other keys.