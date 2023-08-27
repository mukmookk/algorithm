#include <iostream>
#include <set>

using namespace std;

bool isAnagram1(string s, string t) {
    multiset<char> anagram1, anagram2;
    
    for (auto c : s)
        anagram1.insert(c);
    
    for (auto c : t)
        anagram2.insert(c);
        
    return (anagram1 == anagram2);
}

bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) return false;

    int n = s.length();
    unordered_map<char, int> counts;
    for (int i = 0; i < n; i++) {
        counts[s[i]]++;
        counts[t[i]]--;
    }

    for (auto count : counts)
        if (count.second) return false;
    return true;

}

int main()
{
    multiset<char> anagram1, anagram2;

    cout << boolalpha << isAnagram("string1", "string") << "\n";
}