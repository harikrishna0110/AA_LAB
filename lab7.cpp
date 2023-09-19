//Rabin-Karp ALgorithm
#include<bits/stdc++.h>
using namespace std;


void rabin_karp(string t,string p,int d,int q){
	int n = t.length();
	int m = p.length();
	
	
	int pq=0,t0=0;
	// int a=0;
	
	for(int i=0;i<m;i++){
		t0 = (d*t0 + (t[i] -'0'))%q;
		pq = (d*pq + (p[i]-'0'))%q;
	}
	// cout<<pq<<" "<<t0<<endl;
	
	int h = pow(d,m-1);
	int f1=0;
	for(int i=0;i<=n-m;i++){
		if(pq == t0){
			int f=0;
			for(int j=0;j<m;j++){
				if(p[j] != t[i+j]){
				    f=1;
				}
			}
				if(!f){
					cout<<"matching found at shift :"<<i<<endl;
					f1 = 1;
				}
		}
		if(i < n-m){
		  t0 = (d*(t0 - ((t[i]-'0')*h) )+ t[i+m]-'0' )%q;
		  
		}
		if(t0< 0 ){
			t0 += q;
		}
	}
	if(!f1)
	cout<<"string match not found\n";
}

int main() {
	
	
	int q=13;
	string t="2359178604";
	string p="591";
    int d=10;
    
    rabin_karp(t,p,d,q);
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



