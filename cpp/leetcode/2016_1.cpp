/**
** 2016. Maximum Difference Between Increasing Elements
* Given an array of integersm find the maximum difference between two elements such that the larger number
* appears after the smaller number. 
10000 2 3 10 6 4 8 1 -> (2, 8) => 8
7 9 5 6 3 2 -> (7, 9) => 2
2 5 15 6 4 -> (2, 15) => 13
**/
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
vector<int> split(string input, char delimiter)
{
    stringstream ss(input);
    string temp;
    vector<int> ret;

    while (getline(ss, input, delimiter))
        ret.push_back(stoi(input));
    return ret;
}

void print_vec(const vector<int> vec)
{
    for (auto elem : vec)
        cout << elem << ' ';
    cout << '\n';
}

int findMaxIdxAfter(vector<int> vec, int idx)
{
    int max_idx = idx;
    
    for (int i = idx; i < vec.size(); i++)
    {
        if (vec[max_idx] < vec[i])
            max_idx = i;
    }
    if (max_idx == idx)
        return -1;
    return max_idx;
}

/*
input string -> "10 20 30 40 50\n"
*/
int main()
{
    vector<int> inputs;
    string input;
    int max_diff;

    getline(cin, input, '\n');
    inputs = split(input, ' ');
    if (inputs.size() < 2)
        return -1;
    
    max_diff = inputs[1] - inputs[0];
    for (int idx = 0; idx < inputs.size() - 1; idx++)
    {
        int local_max = findMaxIdxAfter(inputs, idx);
        if (local_max != -1 && (inputs[local_max] - inputs[idx]) >= max_diff)
        {
            max_diff = inputs[local_max] - inputs[idx];
        }
    }
    cout << max_diff << "\n";
    return 0;
}

