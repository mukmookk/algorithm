#include <iostream>
#include <stack>

using namespace std;

void cases() {
    string map;
    int len, max, maxx, start, end;

    len = max = maxx = 0;
    stack<int> carrots;
    cin >> map;
    for (int i = 0; i < map.size(); i++) {
        if (map[i] == 'C') {
            carrots.push(i);
        }
        else if (map[i] == 'T') {
            if (carrots.empty()) {
                len = 0;
            }
            else {
                if (carrots.size() == 1) {
                    start = carrots.top();
                    end = i;
                    len += (end - start) + 1;
                }
                if (max < len)
                    max = len;
                carrots.pop();
            }

        }
    }

    len = 0;
    stack<int> carrots2;
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i] == 'T') {
            carrots2.push(i);
        }
        else if (map[i] == 'C') {
            if (carrots2.empty()) {
                len = 0;
            }
            else {
                if (carrots.size() == 1) {
                    start = carrots2.top();
                    end = i;
                    len += (end - start) + 1;
                }
                if (maxx < len)
                    maxx = len;
                carrots2.pop();
            }
        }
    }
    int result = max > maxx ? max : maxx;
    cout << result << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--){
        cases();
    }
}