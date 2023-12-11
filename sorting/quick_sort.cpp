// time complexity avg :  O(n*log(n))
//                 worst: O(n^2)
//
// space complexity worst: O(log(n))
//
// ADVANTAGES:
// 1. space constraint
// 2. smaller lists
// 3. easy to implement
//
// DISADBANTAGES:
// 1. unstable(sensitive to pivot choice)
// 2. vulnerable to worst case (if already sorted, have to iterate through all elements as pivots)

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int r) {
	int i = l;
	for(int j = l; j < r; j++) {
		if(a[j] < a[r]) {
			swap(a[j], a[i]);
			i++;
		}
	}
    swap(a[i], a[r]);
	return i;
}

void quick_sort(vector<int> &a, int l, int r) {
	if(l < r) {
		int p = partition(a, l, r);
		quick_sort(a, l, p-1);
		quick_sort(a, p+1, r);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n,0);
	for(int i = 0; i < n; i++) cin >> a[i];

	quick_sort(a, 0, n-1);

	for(int i : a) cout << i << ' ';

	return 0;
}
