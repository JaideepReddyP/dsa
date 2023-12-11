// time complexity worst : O(n*log(n))
//
// space complexity worst: O(n)
//
// ADVANTAGES:
// 1. stable time complexity
// 2. good for large data sets
// 3. equal items are not moved
//
// DISADBANTAGES:
// 1. high space complexity
// 2. not good for smaller / already sorted lists.

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int m, int r) {
    int n1 = m-l+1;
	int n2 = r-m;
	vector<int> temp1(n1), temp2(n2);

    for(int i = 0; i < n1; i++) temp1[i] = a[l+i];
    for(int i = 0; i < n2; i++) temp2[i] = a[m+1+i];

	int p = l, p1 = 0, p2 = 0;
	while(p1 < n1 && p2 < n2) {
		if(temp1[p1] < temp2[p2]) {
			a[p] = temp1[p1];
			p1++;
		} else {
			a[p] = temp2[p2];
			p2++;
		}
		p++;
    }
    while(p1 < n1) {
        a[p] = temp1[p1];
        p1++; 
        p++;
    }
    while(p2 < n2) {
        a[p] = temp2[p2];
        p2++; 
        p++;
    }
}

void merge_sort(vector<int> &a, int l, int r) {
	if(l >= r) return;
	int m = (r+l)/2;
	merge_sort(a, l, m);
	merge_sort(a, m+1, r);
	merge(a, l, m, r);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n,0);
	for(int i = 0; i < n; i++) cin >> a[i];

	merge_sort(a, 0, n-1);

	for(int i : a) cout << i << ' ';

	return 0;
}