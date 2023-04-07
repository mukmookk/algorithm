Bubble sort, heap sort, and radix sort are not considered in-place sorting algorithms because they require additional memory to store temporary data during the sorting process.

Bubble sort swaps adjacent elements in the input array during the sorting process, which means that it is not an in-place sorting algorithm. It requires a temporary variable to perform the swaps.

Heap sort builds a heap data structure by rearranging the elements in the input array, which means that it is not an in-place sorting algorithm. It requires additional memory to store the heap structure during the sorting process.

Radix sort sorts the numbers based on their digits, starting with the least significant digit, and maintains the relative order of equal elements as they are sorted based on each digit. However, it requires additional memory to store the buckets and temporary arrays used during the sorting process.

Merge sort is a stable sorting algorithm that is generally considered to be an in-place sorting algorithm when implemented using an iterative approach called "bottom-up merge sort". This approach sorts small subarrays of the input data and merges them into larger sorted subarrays until the entire input array is sorted. It requires only a constant amount of additional memory to store temporary data during the sorting process.

In general, in-place sorting algorithms are preferred over non-in-place sorting algorithms when memory usage is a concern, such as when sorting large datasets or on memory-constrained systems.