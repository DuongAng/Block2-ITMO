#include <bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    return a>b;
}
int main()
{

	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum=0;
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++){
        if((i+1)%k==0)
            continue;
        sum += a[i];
	}

	cout<<sum;
	return 0;
}
