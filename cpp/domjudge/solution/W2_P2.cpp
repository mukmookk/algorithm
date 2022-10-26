#include <iostream>
#include <set>
#include <string>

using namespace std;

void cases() {
    int M, N, problem;
    multiset<int> problems;

    string str;

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        cin >> problem;
        problems.insert(problem);
    }

    while (N--) {
        cin >> str;
        if (str == "Add") {
            cin >> problem;
            problems.insert(problem);
        }
        else if (str == "Delete") {
            cin >> str;
            if (str == "min") {
                problems.erase(problems.begin());
            }
            else if (str == "max") {
                problems.erase(prev(problems.end()));
            }
        }
    }

    cout << *(problems.begin()) << " " << *(prev(problems.end())) << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--)
        cases();
}