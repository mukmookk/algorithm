#include <iostream>
#include <vector>

using namespace std;

void swap (int *num1, int *num2)
{
    int *temp;

    temp = num1;
    num1 = num2;
    num2 = temp;
}

int gcd(int num1, int num2)
{
    while (num2 > 0)
    {
        if (num2 > num1)
            swap(num1, num2);
        num1 = num1 % num2;
        swap(num1, num2);
    }
    return num1;
}

int multiple_gcd(vector<int> vals)
{
    int n_gcd;

    n_gcd = vals[0];

    for (int i = 1; i < vals.size(); i++)
        n_gcd = gcd(vals[i], n_gcd);
    return n_gcd;
}

void input_vec(vector<int> &v_inputs, int n_nums)
{
    int n_input;

    while (n_nums--)
    {
        cin >> n_input;
        v_inputs.push_back(n_input);   
    }
}

void number_war()
{
    int n_nums1, n_nums2, gcd1, gcd2, m_gcd;
    vector<int> v_inputs1, v_inputs2, output;

    cin >> n_nums1 >> n_nums2;
    input_vec(v_inputs1, n_nums1);
    input_vec(v_inputs2, n_nums2);
    gcd1 = multiple_gcd(v_inputs1);
    gcd2 = multiple_gcd(v_inputs2);
    
    m_gcd = gcd(gcd1, gcd2);
    if (gcd1 == 1 || gcd2 == 1)
    {
        if (gcd1 == 1 && gcd2 == 1)
        {
            output.push_back(-1);
            output.push_back(-1);
        }
        else if (gcd1 == 1)
        {
            output.push_back(gcd2);
            output.push_back(-1);
        }
        else if (gcd2 == 1)
        {
            output.push_back(-1);
            output.push_back(gcd1);
        }
    }
    else
    {
        if (m_gcd >= gcd2 && gcd1 >= gcd2)
        {
            output.push_back(-1);
            output.push_back(gcd1);
        }
        else if(m_gcd >= gcd1 && gcd2 > gcd1)
        {
            output.push_back(gcd2);
            output.push_back(-1);
        }
        else
        {
            output.push_back(gcd2);
            output.push_back(gcd1);
        }
    }
    cout << output[0] << " " << output[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n_cases;

    cin >> n_cases;
    while (n_cases--)
        number_war();
    return 0;
}