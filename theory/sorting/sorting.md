# Sort

## Insertion sort
----
### Code 
```
int xLoc;
    if (vacant == 0)
        xLoc = vacant;
    else if (E[vacant-1].key ≤ x)
        xLoc = vacant; 
    else
        E[vacant] = E[vacant-1];
        xLoc = shiftVacRec(E, vacant-1, x); 
    return xLoc;
```
### Worst Case
sum(i) <- i=0...n-1
O(N^2)

### Average Case
탐색의 경우에는 탐색이 성공하는 경우와, 실패하는 경우, 두 가지를 분리해서 계산이 이뤄져야 했는데, 정렬의 경우는 성공의 사례만 존재한다.

```
list = [1, 2, 6, 3(cur), 7]
```

`3`이 현재 위치라고 하자. 그러면 3이 위치할 수 있는 인덱스는 현재 `1, 2, 6, 3`이 들어있는 `idx = 0, 1, 2, 3`이다. 만약 `3`이 `idx =2`의 위치에 들어가려면, 한 번의 비교(basic operation)가 이뤄진다. 

이런 식으로 `idx= 0, 1, 2, 3`의 경우에 들어가는 경우에는 각각 `3, 3, 2, 1` 번의 비교 연산이 이뤄진다.

이를 일반화 하면, i 번쨰의 인덱스에서 insertion sort의 정렬을 구현하기 위해서는, `idx = 0, 1, 2, ..., i` 에 따라 각각 `i, i, i-1, ..., 1`번의 연산이 이뤄진다.

`A(N) = sum(P(I) * t(I))`

이때, `sum(1, ... i+1)/(i+1) + i/(i+1) = i/2 + 1 - i/(i+1)`

*i/(i+1)은 인덱스 0*

여기까지는 단일 인덱스를 의미했으므로, 이를 모든 인덱스에 적용하면

`sum(i/2 + 1 - i/(i+1))`라는 식이 나오고, 이는 `pow(n, 2) / 4`에 근사한다.

### 참고) Loop imvariant
**알고리즘을 수행하면 정렬이 될텐데, 어떻게 정렬이 될 것이냐**를 증명

총 3가지 경우에 대해서, 특정 property를 만족하면 OK

1. Initailization -> 수행 이후 segment가 property가 충적해야 한다.
2. Maintainance -> 임의의 i에 대해서, 로직 수행 이전에 property가 만족했다면, 수행 이후에도 property가 수행되어야 함
3. Termination -> 수행 이후 entire segment가 property가 충적해야 한다.

귀납법으로 점화식을 증명하는 것과 유사

정렬의 경우에는, 오름차순으로 정렬이 되는지의 여부


### Optimality

Basic Problem이 인접한 element끼리만 비교가 가능하다면, 해당 알고리즘을 풀려면 최대 `N(N-1)^2/2` 비교가 이뤄져야 한다. 또한 Insertion Sort의 Average Case가 `n(n-1)/4` 이므로 해당 알고리즘이 Optimal이 된다.

이 경우에는 Insetion sort가 최적의 알고리즘이다.

## Quick Sort
----
Worst-Case: `O(N^2)`
Average-case: `O(N Log N)`

> heap sort와 merge sort가 Worst-Case에서 O(N Log N)이긴 하지만, Quick Sort가 Average Case에서 상당히 빠르기 떄문에, 많은 경우에서 Quick Sort가 더 빠른 결과가 나온다.

### Divide and Conquer
```
solve(I)
    n = size(I)
    if (n ≤ smallsize)
        solution = directlySolve(I); 
    else
        divide I into I1, ..., Ik. 
        for each i in {1, ..., k}
            Si = solve(Ii);
        solution = combine(S1, ..., Sk);
    return solution;
```
전체 문제를 쪼개서 여러 개의 sub-problem으로 만들어준다. 이때의 주의점은 전체 문제와 sub-problem의 매커니즘은 완전히 동일해야 한다. 

그렇게 Divide를 통해 원하는 지점까지 쪼개서, 쪼개진 sub-problem을 entire problem으로 다시 Combine 해준다.

### Implementation

Quick Sort는 바로 앞에서 설명했던 Divide and Conquer를 통해 구현되었다.

```
Algorithm partition(S, p)

    Input: sequence S, position p of pivot with randomization

    Output: subsequences L, E, G of the elements of S less than, equal to, or greater than the pivot, resp.

    L, E, G = []
    x = S.remove(p)
    while not S.isEmpty()
        y = S.remove(S.first()) 
        if y < x
            L.insertLast(y) 
        else if y = x
            E.insertLast(y) 
        else { y > x }
            G.insertLast(y) 
    return L, E, G
```
1. **Randomization 전략(랜덤하게 아무 원소나 선택)을 통해, 기준이 되는 pivot을 선택한다.**
2. **Pivot이 선택되었다면, Pivot을 기준으로 3가지로 정렬한다.**
   1. `L` (pivot보다 작은 원소들의 그룹)
   2. `E` (pivot과 값이 동일한 원소들의 그룹)
   3. `G` (pivot보다 값이 큰 원소들의 그룹)
3. **이를 Combine 한다. (사실 위치를 앞서서 정렬하며 바꿨기 때문에 별도의 연산은 이뤄지지 않는다.)** 

이렇게 되면, **E 그룹은 정렬이 완료되었음을 확인할 수 있다**. 이때 정렬이 수행되는 것을 `Conquer`라고 한다.

4. 이때 1, 2, 3의 한 사이클을 `Partition이라고` 명명하고, 이러한 Partition을 L과 G에서 다시 수행한다.

5. 재귀적으로 수행 후, 원소가 한 개 남을 때까지 수행한다.

그래서 각각의 Partition Step은 `O(N)`이 걸린다.

root에서는 모든 원소를 훝으므로 `n`만큼이 필요

|depth|time|
|-|-|
|0|n|
|1|n-1|
|...|...|
|n-1|1|

그래서 time을 전부 더하면 `n(n+1)/2`

### Average Case (Informal)

만약, pivot이 최소값 혹은 최대값인 경우 Worst Case에 가까워지고,

pivot이 중간에 위치하여, **L 그룹과 G 그룹의 크기가 동일하다면,** depth가 최소가 되어 **Best Case**에 가까워질 것이다.

Average Case는 Worst와 Best의 사이를 의미할 것이고

**[?(Worst), ?, ?(AVG1), ?, ?(Best), ?, ?(AVG2), ?, ?(Worst)]** 정도가 될 것이다.

이때 AVG1의 위치를 가정하고 Average Time을 구해보면,

|depth|Time||||
|-|-|-|-|-|
|0|n||||
|1|n/4|3n/4||
|2|n/16|3n/16|3n/16|9n/16|
|...|...|...|...|...|

이때 가장 Depth가 긴 맨 오른쪽을 보면 된다.

그러면 모든 Depth의 Time을 곱해주면 될 것이고, 이를 모두 곱하면 

n * (3/4)^k = 1이고

n = (4/3)^k 이며

k = log (sub=4/3) n 이 된다.

k = log(2) n / log (2) 4/3 이 되고, 이때, 1 / log (2) 4/3 라고 하면 <= C Log(n)이 되고

최종적으로 O(log 2 n)에 수행이 가능하다.

## In-Place Quick-Sorkt

*In-place: 추가적으로 사용하는 메모리의 크기가 O(1)인 경우*
> 단, 재귀를 사용했을 경우에는 log(n)의 메모리 사용도 in-place라고 한다.

Quick Sort의 경우, Average 분석에서 `log(n)` 만큼을 사용하는 것을 확인하였다.

```
Algorithm inPlaceQuickSort(S, l, r)

// S: sequence
// l: 가장 왼쪽
// r: 가장 오른쪽
```

```c
Algorithm inPlaceQuickSort(S, l, r)
    Input sequence S, ranks l and r
    Output sequence S with the elements of rank between l and r rearranged in increasing order

    // 재귀 탈출
    if l >= r 
        return

    // 랜덤하게 pivot 선택
    i = a random integer between l and r
    // 해당 pivot의 인덱스를 저장
    x = S.elemAtRank(i)
    // E그룹의 양 끝을 h와 k로 표시
    // E그룹의 경우 h~K까지의 인덱스를 갖는다
    (h, k) = inPlacePartition(x)
    // l부터 h-1까지 정렬
    inPlaceQuickSort(S, l, h - 1)
    // k-1부터 r까지 정렬
    inPlaceQuickSort(S, k - 1, r)
```

> 본인이 먼저 값을 얻고 (inPlacePartition), QuickSort하는 것을 보면 Pre-order traversal 방식으로 볼 수 있다.

## Merge Sort
----
> 앞서, Quick-sort에서 Parition 하는 것이 핵심이였다면, Merge sort에서는 Merge하는 것이 핵심이다.

```c
Merge(A, B, C)
    if (A is empty)
        rest of C = rest of B 
    else if (B is empty)
        rest of C = rest of A
    else if (first of A ≤ first of B)
        first of C = first of A
        merge (rest of A, B, rest of C) 
    else
        first of C = first of B
        merge (A, rest of B, rest of C) 
return
```
**두 시퀀스의 길이가 동일하고 번갈아 가며, 비교 연산을 수행할 때 Worst-Case**

### 전략

- 시퀀스를 길이를 기반으로 절반으로 쪼갠다
- 재귀적으로 길이가 1이 될 때까지 쪼개준다.

- Divide and conquer
  - 길이가 1이되는 경우 해당 경우에 대해서는 Conquer
  - 이것을 Merge
- 전체적으로 놓고 보면, Complete Binary Tree의 모양을 갖게 된다.
  - 마지막에 쪼개온 과정을 역추적하며 leaf node
  - leaf 노드의 개수가 n개
  - 이를 log n번 수행 (Depth = log (n), 2로 계속 쪼갰으므로)

```
void mergeSort(Element[] E, int first, int last) 
    # 원소가 최소 2개
    if (first < last)
        int mid = (first+last)/2; 
        mergeSort(E, first, mid);   // Divide1
        mergeSort(E, mid+1, last);  // Divide2
        merge(E, first, mid, last); // Conquer
    return;
```

> 이를, Graph의 순회로 비유하자면 Post-order traversal로 볼 수 있다.


### Complexity

- **W(n) = W(n/2) + W(n/2) + Wmerge(n) => O(nlogn)**
  - Wmerge(n) = n-1

## Heapsort

### Heap

다음 두 가지 조건을 맞춰줘야 한다.
1. 구조 조건: (left) Compelete Binary Tree
   1. T는 h-1까지 Complete 해야한다.
   2. 모든 leaf는 h 혹은 h-1에 위치해야 한다.
   3. h에 위치한 leaf는 (left)에 몰려있어야 한다.
2. 순서 조건: Max heap을 기준으로, v.key >= v.parent.key (=Partial Order tree property, 전체의 순서와는 상관이 없다)

루트에서 lst.append(heap_.getMax()) 하고 heap_deleteMax()하면 된다.

그리고 저장된 리스트를 뒤에서부터 출력하면 큰 순서대로 출력이된다.

## Array based heap implementation

```
heapSort(E, n) // Outline
    construct H from E, the set of n elements to be sorted 
    for (i = n; i ≥ 1; i--)
        curMax = getMax(H) 
        deleteMax(H);
        E[i] = curMax;
```