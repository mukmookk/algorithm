#include<iostream>
#include <stack>
using namespace std;
int main() {

	int T; 
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		stack<int> go; //당근 인덱스 저장

		int start = 0, end = 0;
		int len = 0, max = 0, maxx = 0; 

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'C') {
				go.push(i);
			}
			else if(s[i]=='T'){
				if (go.empty()) {
					len = 0;
				}else{ 
					if (go.size() == 1) {
						start = go.top();
						end = i;
						len+=(end-start) + 1;
					}
					if (max < len) {
						max =len;
					}
					go.pop();
				}
			}
		}

		len = 0;

		stack<int> back; //가시 인덱스 저장

		//역방향 재탐색 
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'T') {
				back.push(i);
			}
			else {
				if (!back.empty()) {
					if (back.size() == 1) {
						start = i; 
						end = back.top(); 
						len +=end-start + 1;
					}
					if (maxx < len) {
						maxx =len;
					}
					back.pop();
				}
				else {
					len = 0;
				}
			}
		}
		int result;
		if (max > maxx)
			result = max;
		else
			result = maxx;

		cout << result << endl;

		while (!go.empty()) {
			go.pop();
		}
		while (!back.empty()) {
			back.pop();
		}
	}
}