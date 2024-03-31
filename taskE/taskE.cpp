#include <bits/stdc++.h>
using namespace std;

bool isPlaced(int n, int a[], int minDist, int k) {
	int last = 0;
	int placed = 1;

	for (int i = 1; i < n; i++) {
		if (a[i] - a[last] >= minDist) {
			last = i;
			placed++;
			if (placed >= k) {
				break;
			}
		}
	}

	return placed >= k;
}

int main() {

	int n, k;
	cin >> n >> k;
	//input so chuong
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int l = 1;
	int r = a[n - 1] - a[0];
	//r khoang cach lon nhat
	//vong lap chi dung lai khi min va max gan nhau
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (isPlaced(n, a, m, k)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout<<l<<" co the sai "<<r<< " dung: ";
	if (isPlaced(n, a, r, k)) {
		cout << r;
	} else {
		cout << l;
	}
	return 0;
}
