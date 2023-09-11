//Rabin-Karp ALgorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter Text" << endl;
    cin >> text;
    cout << "Enter pattern" << endl;
    cin >> pattern;
    cout << text << pattern << endl;
    int n = text.length();
    int m = pattern.length();
    int d = 10;
    int q = 13;
    int h = pow(d, m - 1);
    h = h % q;
    int p = 0;
    int t = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= (n - m); i++)
    {
        if (p = t && pattern == text.substr(i, m))
        {
            cout << "Pattern occurs with shift " << i << endl;
        }
        if (i < (n - m))
        {
            t = (d * (t - text[i + 1] * h) + text[i + m + 1]) % q;
        }
        if (t < 0)
        {
            t = t + q;
        }
    }

    return 0;
}

// Finite Automata Pattern searching

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

int getNextState(string pat, int M, int state, int x)
{
	
	if (state < M && x == pat[state])
		return state+1;

	
	int ns, i;

	
	for (ns = state; ns > 0; ns--)
	{
		if (pat[ns-1] == x)
		{
			for (i = 0; i < ns-1; i++)
				if (pat[i] != pat[state-ns+1+i])
					break;
			if (i == ns-1)
				return ns;
		}
	}

	return 0;
}


void computeTF(string pat, int M, int TF[][NO_OF_CHARS])
{
	int state, x;
	for (state = 0; state <= M; ++state)
		for (x = 0; x < NO_OF_CHARS; ++x)
			TF[state][x] = getNextState(pat, M, state, x);
}

/* Prints all occurrences of pat in txt */
void search(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();

	int TF[M+1][NO_OF_CHARS];

	computeTF(pat, M, TF);

	// Process txt over FA.
	int i, state=0;
	for (i = 0; i < N; i++)
	{
		state = TF[state][txt[i]];
		if (state == M)
			cout<<" Pattern found at index "<< i-M+1<<endl;
	}
}


int main()
{
	string txt = "AABAACAADAABAAABAA";
	string pat = "AABA";
	search(pat, txt);
	return 0;
}



