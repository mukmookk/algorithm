#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> stack1;
stack<int> stack2;
stack<int> stack3;

int N, K, cnt, ext;

void TowerOfHanoi(int num, stack<int> *from, stack<int> *by, stack<int> *to) {
    int ret;

    if (ext == 1)
        return ;
    if (num == 1) {
        to->push(from->top());
        from->pop();
        cnt++;
        if (cnt == K) {
            ext = 1;
            if (stack2.size() == 0) {
                printf("0\n");
                return ;
            }
            while (stack2.size() != 0) {
                printf("%d ", stack2.top());
                stack2.pop();
            }
            printf("\n");
            return ;
        }
    }
    TowerOfHanoi(num - 1, from, to, by);
    if (ext == 1)
        return ;
    
    to->push(from->top());
    from->pop();
    cnt++;
    if (cnt == K) {
        to->push(from->top());
        from->pop();
        cnt++;
        if (cnt == K) {
            ext = 1;
            if (stack2.size() == 0) {
                printf("0\n");
                return ;
            }
            while (stack2.size() != 0) {
                printf("%d ", stack2.top());
                stack2.pop();
            }
            printf("\n");
            return ;
        }
    }
    TowerOfHanoi(num - 1, by, from, to);
}

int main() {
    int T, temp;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        stack1 = stack<int>();
        stack2 = stack<int>();
        stack3 = stack<int>();

        cnt = 0;
        ext = 0;
        temp = N;
        while (temp) {
            stack1.push(temp);
            temp--;
        }
        TowerOfHanoi(N, &stack1, &stack2, &stack3);
    }
}
