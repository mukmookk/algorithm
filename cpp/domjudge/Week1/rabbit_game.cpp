#include <iostream>
#include <vector>
#include <string> 
using namespace std;

void insert_vector(vector<int> *vec, string str)
{
    int s_size = str.size();

    for (int i = 0; i < s_size; i++)
    {
        vec.push_back(0);
        if (i == 0)
        {
            if (str[i] == 'C')
                vec[i] = 1;
            else if (str[i] == 'T')
                vec[i] = -1;
        }
        else
        {
            if (str[i] == 'C')
                vec[i] = vec[i] + 1;
            else if (str[i] == 'T')
                vec[i] = vec[i] + -1;
        }
    }
}

int main() {
    
    vector <int> m
    ap_info;
    vector <int> prefix_max;
    string s_map;

    cin >> s_map;
    insert_vector(prefix_max, s_map);

    for (auto n : prefix_max)
        cout << n << "\n";
    cout << "\n" << endl;
}