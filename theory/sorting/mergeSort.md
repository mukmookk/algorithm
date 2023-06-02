Algorithm partition(S, p) {
    x <- S.remove(p)
    while not S.isEmpty() {
        y <-S.remove(S.first())
        if y < x {
            L.insertLast(y)
        }
        elif x == y {
            E.insertLast(y)
        }
        else {
            G.insertLast(y)
        }
    }
    return L, E, G
}

def InplaceSort(S, l, r) {
    if l >= r {
        return
    }
    i <- a ramdom integer betwwen l and r
    x <- S.eleAtRank(i)
    (h, k) <- inPlacePartition(x)
    inPlaceQuickSort(S, l, h - 1)
    inPlaceQuickSOrt(S, k - 1, h)
}


------


def Partition(S, p) {
    L, E, G

    x <- S.remove(p)
    while not S.isEmpty() {
        y <- S.remove(S.first())

        if y <= x {
            L.insertLast(y)
        }
        elif y == x {
            E.insertLast(y)
        }
        else {
            G.insertLast(y)
        }

    }
    retturn L, E, G
}