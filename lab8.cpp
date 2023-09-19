// implement KMP String Matching algorithm.
 #include<bits/stdc++.h>
using namespace std;


int main() {

    //pi table
    cout << "Enter Pattern: " << endl;
    string pattern;
    cin >> pattern;
    cout << "Enter Text" << endl;
    string text;
    cin >> text;
    int n = text.length();

    int m = pattern.length();
    int cnt = 0;
    int arr[m+1] = {0};
    arr[1] = 0;
    int k = 0;
    for(int q = 2; q<=m; q++){
        while(k > 0 && ++cnt && pattern[k] != pattern[q-1]){
            k = arr[k];
        }
        if(pattern[k] == pattern[q-1]){
            k += 1;
        }
        cnt++;
        arr[q] = k;
    } 
    cout << "Printing pi table" << endl;
    for(int i = 1; i <= m; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    //kmp matcher
    int q = 0;
    int i;
    for(i = 0 ; i < n; i++){
        while(q > 0 and pattern[q] != text[i]){
            q = arr[q];
        }
        if(pattern[q] == text[i]){
            q = q + 1;
        }
        if(q == m){
            cout << "Pattern occrs with shift: " << (i - m + 1) << endl;
            q = arr[q];
        }
    }
    cout << "number of comparisions " << cnt << endl; 
    // cout << cnt << endl;
    return 0;
}

//Find the closest pair of points from a given set of n points using Brute-force approach.

#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class CPP
{
    vector<Point> points;

    int dist(int i, int j)
    {
        return sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
    }

public:
    pair<Point, Point> run()
    {
        int n = points.size();

        int minIndex1 = 0, minIndex2 = 1, minDist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int a = dist(i, j);
                if (a < minDist)
                {
                    minIndex1 = i;
                    minIndex2 = j;
                    minDist = a;
                }
            }
        }
        return {points[minIndex1], points[minIndex2]};
    }

    void takeInput()
    {
        cout << "enter number of point" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points.push_back(Point(x, y));
        }
    }
};

int main()
{

    CPP p;
    p.takeInput();
    auto ans = p.run();
    cout << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;

    return 0;
}