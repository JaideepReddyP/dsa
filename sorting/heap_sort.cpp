// time complexity worst : O(n*log(n))
//
// space complexity worst: O(1)
//
// ADVANTAGES:
// 1. stable time complexity
// 2. very good space complexity
// 3. simple
//
// DISADBANTAGES:
// 1. well implemented quick sort is faster
// 2. a bit slower than merge sort ( more reads and writes required ) ( equal items are rearranged )

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heap_sort(vector<int> &a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++) cin >> a[i];

    heap_sort(a, n);

    for(int i : a) cout << i << ' ';

    return 0;
}



