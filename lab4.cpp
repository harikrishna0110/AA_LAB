//Implement Karger's Min-Cut algorithm.
#include <bits/stdc++.h>
using namespace std;

#define N 4
int G[N][N]={{0,1,1,1},{1,0,1,0},{1,0,0,1},{1,1,1,0}};

class edge {
	
	public :
	int x;
	int y;
	
	edge(int x,int y){
		this->x =x ;
		this->y=y;
		
	}
	
};




class mincut{
	
	public:
			int *parent;
		int *rank;
		
	mincut(){
		this->parent =  new int[N];
		this->rank  = new int[N];
		
		
		for(int i=0;i<N;i++){
		  parent[i] =i;
		  rank[i] = 1;
		}
		
		
	}
	
	int find(int v){
		if(parent[v] == v)return v;
		else return parent[v] = find(parent[v]);
	}
	
	void unionset(int u,int v){
		
		u = find(u);
		v = find(v);
		
		if(u != v){
			parent[u] = v;
		}
	}
	
	int kargers_mincut(int m,vector<edge> &edges){
		int n = N;
		while(n > 2 ){
		int i = random()%m;	
		int u= find(edges[i].x);
		int v= find(edges[i].y);
		
		
	if( u!= v){
		cout<<"contracting edge: "<<edges[i].x<<"---"<<edges[i].y<<"\n";
		unionset(u,v);
		n--;
	}
		}
		
	int cnt =0;
	for(int j=0;j<m;j++){
		
		int a = find(edges[j].x);
		int b= find(edges[j].y);
		
		if(a != b){
			cnt++;
		}
	}
		return cnt;
	}
	
};

int main() {
	// your code goes here
    int m=0;   //no of edges
    vector<edge> edges;
    for(int i=0;i<N;i++){
    	for(int j= i+1;j<N;j++){
    		if(G[i][j] == 1){m++;
    		 edges.push_back(*(new edge(i,j)));
    		}
    	}
    }
    
   //for(auto i : edges){
   //	cout<<i.x<<"--"<<i.y<<"\n";
   //}
    
    
    
   // cout<<m<<"\n";
   
   mincut *cut = new mincut();
   cout<<(*cut).kargers_mincut(m,edges);
	return 0;
}
