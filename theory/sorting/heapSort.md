def heapSort(E, n) {
    n개만 큼 뽑음 -> H
    for (i = n; i >= 1; i--) {
        curMax = getMax(H)
        deleteMax(H)
        E[i] = curMax;
    } 
}

deleteMax(H) {
    1. 가장 낮은 레벨의 오른쪽 원소 = K
    2. 가장 낮은 레벨의 오른쪽 원소 제거
    fixHeap(H, K)
}

fixHeap(H, K) {
    if (H is Leaf)
        insert K in Root(H) // 리프면 루트에 넣음
    else {
        H의 SubTree 중에서 값이 더 큰 것을 LargerSubTree로 설정.

        If (K.key >= root(largerSubHeap.key)) {
            insert K in root(H)
        }
        else {
            insert root(largerSubHeap) in root(H)
            fixHeap(largerSubHeap, K);
        }

    }
}



Construct Heap {
    if (H is not leaf) {
        constructHeap(leftsub subtree)
        constructHeap(right subtree)
        Element K = root(H)
        fixHeap(H, K)
    }
}