#include <set>
#include <iostream>
#include <string>

using namespace std;

void handle_text_input(multiset<int> *probs, int N) {
    string text;
    int problem;

    while (N--) {
        cin >> text;
        if (text == "Add") {
            cin >> problem;
            probs->insert(problem);
        }
        else if (text == "Delete") {
            cin >> text;
            if (text == "min") {
                probs->erase(probs->begin()++);
            }
            else if (text == "max") {
                probs->erase(prev(probs->end()));
            }
        }
    }
}

void cases() {
    int M, N, problem;
    multiset<int> problems;

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> problem;
        problems.insert(problem);
    }

    handle_text_input(&problems, N);
    cout << *(problems.begin()) << " " << *(prev(problems.end())) << "\n";
}

int main() {
    int T;

    cin >> T;
    while (T--) {
        cases();
    }
}
