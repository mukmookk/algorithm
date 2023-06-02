radixSort(L, int radix, int numFields) {
    List[] bucket = new List[radix];
    int field;
    
    List newL;
    newL = L;
    
    For (field = 0; field < numFileds; field++) {
        // bucket array 초기화
        Distribute(newL, buckets, radix, field);
        newL = combine(buckets, radix)
    }
    return newL;
}
---

distribute(L, buckets, radix, field) {
    List remL;
    remL = L;
    
    while (remL != nil) {
        Element K = first(remL);
        int b = maskShift(field, radix, K.key);
        bucket[b] = cons(K, buckets[k])
        remL = rest(remL)
    }    
}

List Combine(List [] buckets, int radix) {
    int b;
    List L, remBucket;
    L = nil
    
    for (b = radix - 1; b >= 0; b--) {
        remBucket = buckets[b];
        while (remBucket != nil) {
            K = first(rembucekt)
            L = cons(K, L);
            remBuckey = rest(remBucket)
        }
    }
}