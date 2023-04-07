Amortized analysis is a method used to estimate the average time complexity of an algorithm over a sequence of operations, rather than just a single operation. It is often used when the worst-case time complexity of individual operations is significantly different from the overall time complexity of a sequence of operations.

There are several techniques for performing an amortized analysis, including aggregate analysis, accounting method, and potential method. Each technique involves a different approach to assigning costs to operations and distributing them over the entire sequence of operations.

Amortized analysis is commonly used in the analysis of data structures such as dynamic arrays, hash tables, and binary heaps, where the worst-case time complexity of individual operations can be significantly higher than the average time complexity over a sequence of operations.

Yes, the accounting method is one of the primary techniques used in amortized analysis. The accounting method involves assigning a "charge" or "cost" to each operation in a sequence of operations, and then analyzing the total cost of all operations to determine the average cost per operation.

In the accounting method, the charge assigned to each operation can be more than its actual cost, in order to account for the cost of other operations in the sequence. The extra charge assigned to each operation is known as "credit", and this credit can be used to pay for the actual cost of other operations.

The accounting method is often used in the analysis of data structures such as dynamic arrays, where the cost of an individual operation can depend on the current state of the data structure. By assigning a charge to each operation and using the credit to pay for the actual cost of other operations, we can estimate the average cost per operation over a sequence of operations.

The accounting method is just one of several techniques used in amortized analysis. Other techniques include the aggregate method and the potential method, each of which involves a different approach to analyzing the cost of a sequence of operations.
----

### Array doubeling
```
cost t*n/2 + t*n/4 + t*n/8 + ... for previous array- doubling, i.e. cost less than t*n

the total cost cannot exceed (2t)*n
```