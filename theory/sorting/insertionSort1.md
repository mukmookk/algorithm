void InsertionSort(Element[] E, int n) {
    int xindex;
    for (xindex = 1; xindex < n; xindex++) {
        Element current = E[xindex];
        key x = current.key;
        int xLoc = shiftVacRec(E, xindex, x);
        E[xLoc] = current
    }
}

int shiftVacRec(Element E[], int vacant, Key x) {
    int xLoc;
    if (vacant == 0) {
        xLoc = vacant;
    }
    else if (E[vacant] - 1 <= x) {
        xLoc = vacant;
    }
    else if (E[vacant]- 1 > x) {
        E[vacant] = E[Vacant - 1]
        xLoc = shiftVacRec(E, vacant-1, x)
    }
    return xLoc
}