#include <iostream>
#include <map>
#include <stack>

using namespace std;

stack<int> stack1;
stack<int> stack2;
stack<int> stack3;

int ext, N, K, cnt;

void TowerOfHanoi(int num, stack<int> *from, stack<int> *by, stack<int> *to) {
    if (ext == 1)
        return ;
    if (num == 1) {
        int init = from->top();
        while (!from->empty() && from->top() == init) {
            cnt++;
            to->push(from->top());
            to->pop();
            if (cnt == K) {
                ext = 1;
                if (stack2.size() == 0) {
                    printf("0\n");
                    return ;
                }
                else {
                    while (stack2.size() != 0){
                        printf("%d ", stack2.top());
                        stack2.pop();
                    }
                    printf("\n");
                    return 1;
                }
            }
        }
        return 1;
    }
    TowerOfHanoi(num - 1, from, to, by);
    int init = from->top();
    while (!from->empty() && from->top() == init) {
        cnt++;
        to->push(from.top());
        from.pop();
    }
    if (cnt == K) {
        int init = from->top();
        while (!from->empty() && from->top() == init) {
            cnt++;
            to->push(from->top());
            to->pop();
            if (cnt == K) {
                ext = 1;
                if (stack2.size() == 0) {
                    printf("0\n");
                    return ;
                }
                else {
                    while (stack2.size() != 0){
                        printf("%d ", stack2.top());
                        stack2.pop();
                    }
                    printf("\n");
                    return 1;
                }
            }
        }
        return 1;
    }
    TowerOfHanoi(num - 1, by, from, to);
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        cnt = 0;
        ext = 0;
        cin >> N;
        map<int, int> m;
        int num;

        for (int i = 1; i <= N; i++) {
            cin >> num;
            m.insert({i, num});
        }

        cin >> K;

        for (int i = N; i >= 1; i--) {
            int count = m.at(i);
            for (int i = 0; i < count; i++) {
                stack1.push(i);
            }
        }

        TowerOfHanoi(N, &stack1, &stack2, &stack3);
    }
}