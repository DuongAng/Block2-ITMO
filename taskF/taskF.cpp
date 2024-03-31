#include <bits/stdc++.h>
using namespace std;
bool check(string s1, string s2) {
	return s2 + s1 < s1 + s2;
}
/*
Có thể hiểu việc kiểm tra này về mặt toán học khá giống với toán bình thường. Ví dụ  s1 là 20, s2 là 004 thì ta sẽ có chuỗi answer là 20004(s1+s2)
và 00420 (s2+s1). Về mặt toán học 20004>00420 (tức là s1+s2 > s2+s1) nên kết quả sẽ trả về true.
Ngược lại nếu s2=20, s1=004 kết quả sẽ là false và sẽ không làm gì thêm nếu trước đó trong vector còn có giá trị.
Nếu đã không còn giá trị nào thì ta chèn s2 vào ngay trước s1 (004)
*/
int main() {
    #ifndef ONLINE_JUDGE
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    #endif
	vector<string> out;

	while (true) {
		string a;
		cin >> a;
		if (cin.eof()) {
			break;
		}

		if (out.size() == 0) {
			out.push_back(a);
			continue;
		}

		for (int i = out.size() - 1; i >= 0; i--) {
			if (check(out[i], a)) {
				out.insert(out.begin() + i + 1, a);
				break;
			}
			if (i == 0) {
				out.insert(out.begin(), a);
			}
		}
	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i];
	}
	return 0;
}
