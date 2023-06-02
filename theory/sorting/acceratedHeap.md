void bubbleUpHead(E [], root, K, vacant) {
    if vacant == root {
        E[vacant] = K
    }
    else {
        int parent = vacant / 2;
        if (K.key <= E[parant].key) {
            E[vacant] = K
        }
        else {
            E[vacant] = E[parent].key;
            bubbleUpHeap(E, root, K, parent)
        }
    }
}
----

void fixHeapSort() {
    if h <= 1:
        process heap of 0 or 1
    else {
        int hStop = h // 2
        int vacStop = promote(E, hStop, vacant, h);

        int vacParent = vacStop / 2;

        if (E[vacParent].key <= K.key) {
            E[vacStop] = E[vacParent];
            bubbleUpHeap(E, vacant, K, vacParent)
        } 
        else {
            fixHeapfast
        }
    }
}

h + log(h)