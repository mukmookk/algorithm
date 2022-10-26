#include <iostream>
#include <string>
#include <map>

using namespace std;

void execute_case()
{
    // 알파벳을 구성하는 문자 개수: M
    // 문자에 대한 비트 수 N
    int M, N, L;
    string bitstream, file_bits;
    
    // bits and alpha
    map<int, string> bits_alpha;
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        cin >> bitstream;
        bits_alpha.insert({i, string(bitstream)});
    }

    cin >> L >> file_bits;

    int diff = 0;
    int min_diff = INT8_MAX;
    int min_idx = -1;

    for (int i = 0; i < L/N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (file_bits[i * N + k] != bits_alpha.find(j)->second[k])
                    diff = diff + 1;
            }

            if (min_diff > diff)
            {
                min_diff = diff;
                min_idx = j;
            }
            diff = 0;
        }
        cout << char('A' + min_idx);
        min_diff = INT8_MAX;
        min_idx = -1;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;

    cin >> test_case;

    while (test_case--) 
        execute_case();
}