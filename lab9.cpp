// Implement constant time algorithm to check if line segments P1P2 intersect with the line segment P3P4 or not.
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
    
    
	
	return 0;
}
//Grahams Convex Hull Algorithm

#include <bits/stdc++.h>

#define pointType pair<int, int>
#define pointWithSin pair<double, pointType>
using namespace std;

pointType basePoint;
static vector<pointWithSin> points;
class GrahamConvexHull
{
public:
    void findSin(pointWithSin &point)
    {
        if (point.second == basePoint)
            return;
        int y = point.second.second - basePoint.second;
        double d = sqrt(pow(point.second.first - basePoint.first, 2) + pow(y, 2));
        double sin = y / d;
        double value;
        if (point.second.first < basePoint.first)
            value = 2 - sin;
        else
            value = sin;
        point.first = value;
    }

    void generateSin()
    {
        for (pointWithSin &point : points)
        {
            findSin(point);
        }
    }

    void findBasePoint()
    {
        int minY = INT_MAX, minX = INT_MAX;
        for (pointWithSin point : points)
        {
            if (point.second.second < minY)
            {
                minY = point.second.second;
                minX = point.second.first;
            }
            else if (point.second.second == minY)
                minX = min(minX, point.second.first);
        }
        basePoint = {minX, minY};
    }

    GrahamConvexHull(vector<pointType> points1)
    {
        for (pointType point : points1)
        {
            points.push_back({-1.0, point});
        }
    }

    int direction(pointType p1, pointType p2, pointType p3)
    {
        return (p2.first - p1.first) * (p3.second - p1.second) -
               (p2.second - p1.second) * (p3.first - p1.first);
    }

    vector<pointWithSin> getConvexHull()
    {
        findBasePoint();
        generateSin();
        sort(points.begin(), points.end());
        vector<pointWithSin> convexHull;
        if (3 > points.size())
            return points;

        convexHull.push_back(points[0]);
        convexHull.push_back(points[1]);
        convexHull.push_back(points[2]);

        for (int i = 3; i < points.size(); i++)
        {
            while (convexHull.size() > 1)
            {
                pointWithSin p1 = convexHull[convexHull.size() - 2];
                pointWithSin p2 = convexHull[convexHull.size() - 1];
                if (direction(p1.second, p2.second, points[i].second) < 0)
                    convexHull.pop_back();
                else
                    break;
            }
            convexHull.push_back(points[i]);
        }
        return convexHull;
    }
};

int main()
{
    vector<pointType> pointsInput = {{1, 1}, {1, 3}, {3, 1}, {1, 2}, {2, 1}, {0, 0}, {0, 3}, {-1, 3}, {-1, 1}, {-3, 1}};
    GrahamConvexHull grahamHull(pointsInput);
    vector<pointWithSin> convexHull = grahamHull.getConvexHull();
    for (pointWithSin point : convexHull)
        cout << "(" << point.second.first << ", " << point.second.second << ")\n";
    return 0;
}
