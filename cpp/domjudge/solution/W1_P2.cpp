#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void cases() {
    string str;
    int start, end, length, max, maxx;
    stack<int> front;

    length = max = maxx = 0;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'C') {
            front.push(i);
        }
        else {
            if (front.empty()) {
                length = 0;
            }
            else if (str[i] == 'T') {
                if (front.size() == 1) {
                    start = front.top();
                    end = i;
                    length += (end - start) + 1;
                }
                if (length > max) {
                    max = length;
                }
                front.pop();
            }
        }
    }

    stack<int> back;
    length = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == 'T') {
            back.push(i);
        }
        else if (str[i] == 'C'){
            if (back.empty()) {
                length = 0;
            }
            else {
                if (back.size() == 1) {
                    start = i;
                    end = back.top();
                    length += (end - start) + 1;
                }
                if (length > maxx) {
                    maxx = length;
                }
                back.pop();
            }
        }
    }
    int ret = max > maxx ? max : maxx;
    cout << ret << "\n";
} 

int main() {
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}