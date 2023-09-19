#include <bits/stdc++.h>
using namespace std;
#define point pair<int,int>
#define ls pair<point,point>

  int d(point p1, point p2, point p3){
		int ans = ( (p3.first - p1.first)*(p2.second - p1.second) -
		 (p2.first - p1.first)*(p3.second - p1.second));
		 
		 return ans;
	}

bool Onseg(point p1,point p2,point p3){
	
	if( min(p1.first, p2.first) <= p3.first and p3.first <= max(p1.first, p2.first) and
	   min(p1.second, p2.second) <= p3.second and p3. second<= max(p1.second, p2.second)
	   )return true;
	   
	   return false;
}

bool isIntersecting(ls pq, ls rs){
	int d1 = d(pq.first, pq.second, rs.first);
	int d2 = d(pq.first, pq.second, rs.second);
	int d3 = d(rs.first, rs.second, pq.first);
	int d4 = d(rs.first, rs.second, pq.second);
	
	if( d1*d2 < 0 and d3*d4  < 0)return true;
	else if(d1 == 0 && Onseg(pq.first, pq.second, rs.first))return true;
	else if(d2 == 0 && Onseg(pq.first, pq.second, rs.second))return true;
	else if(d3 == 0 && Onseg(rs.first, rs.second, pq.first))return true;
	else if(d4 == 0 && Onseg(rs.first, rs.second, pq.second))return true;
	else return false;
}

int main() {
    int x1,x2,x3,x4,y1,y2,y3,y4;
    
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    cin>>x4>>y4;
    point  p1({x1,y1}),p2({x2,y2}),p3({x3,y3}),p4({x4,y4}); 
    ls pq({p1,p2}),rs({p3,p4});
    
    cout<<isIntersecting(pq,rs);
    
    
	// your code goes here
	return 0;
}