//lab 5 
#include <bits/stdc++.h>
using namespace std;

//Naive String Matching
int main()
{
    string text = "MY NAME IS MAHARSHI";
    string pattern = "IS";
    int n = text.length();
    int m = pattern.length();
    int s = 0;
    for (; s <= n - m; s++)
    {
        int i = 0, j = 0;
        while (j < m && text[s + i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern matched at index " << s << endl;
        }
    }
    if(s == 0){
        cout << "Pattern not matched" << endl;
    }
    return 0;
}




// Horsepool String Matching
int main()
{
    string text = "my name is maharshi";
    string pattern = "maharshi";
    int n = text.length();
    int m = pattern.length();
    // shift table
    map<char, int> shift = {};
    for (char c = 'a'; c <= 'z'; c++)
    {
        shift[c] = m;
    }
    shift[' '] = m;
    for (int i = 0; i <= (m - 2); i++)
    {
        shift[pattern[i]] = m - i - 1;
    }

    for (auto i : shift)
    {
        cout << i.first << " " << i.second << endl;
    }

    int j = 0;
    while (j + m <= n)
    {
        if (pattern[m - 1] == text[j + m - 1])
        {
            int i = m - 2;
            while (i >= 0 && pattern[i] == text[j + i])
            {
                i = i - 1;
            }
            if (i == -1)
            {
                cout << "String matched at index " << j << endl;
            }
        }
        j = j + shift[text[j + m - 1]];
    }
    return 0;
}