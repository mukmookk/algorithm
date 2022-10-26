#include <string>
#include <map>
#include <iostream>

using namespace std;

void cases() {
    int M, N;
    string bitstream;

    cin >> M >> N;
    map<int, string> bits_alpha;
    for (int i = 0; i < M; i++) {
        cin >> bitstream;
        bits_alpha.insert({i, string(bitstream)});
    }

    int L, diff, min_diff, min_diff_i;
    string file_bits;
    cin >> L >> file_bits;

    min_diff = min_diff_i = INT8_MAX;
    diff = 0;
    for (int i = 0; i < L / N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                if (bits_alpha.find(j)->second[k] != file_bits[i * N + k])
                    diff = diff + 1;
            }
            if (min_diff > diff) {
                min_diff = diff;
                min_diff_i = j;
            }
            diff = 0;
        }
        cout << char('A' + min_diff_i);
        min_diff = min_diff_i = INT8_MAX;
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cases();
    }
}