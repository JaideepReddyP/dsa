// time complexity worst : O(n*k)
//
// space complexity worst: O(n+b)
//
// k -> number of digits in max base 10 number
// b -> base of number system (in this case 10)
//
// ADVANTAGES:
// 1. good for large data sets with many digit keys
// 2. maintains relative order of equal elements
//
// DISADBANTAGES:
// 1. bad for small datasets
// 2. needs extra space
// 3. only for numerical data sets

#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int> &a, int n, int exp)
{
	int output[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++) count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++) a[i] = output[i];
}

void radix_sort(vector<int> &a, int n)
{
	int m = *max_element(a.begin(), a.end());
	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(a, n, exp);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++) cin >> a[i];

    radix_sort(a, n);

    for(int i : a) cout << i << ' ';

    return 0;
}
