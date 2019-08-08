#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x, y; 
}; 
  
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
vector<pair<Point,int>> convexHull(vector<pair<Point,int>> points, int n) { 
    vector<pair<Point, int>> hull; 
  
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].first.x < points[l].first.x) 
            l = i; 
  
    int p = l, q; 
    do
    { 
        hull.push_back(points[p]); 
    
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           if (orientation(points[p].first, points[i].first, points[q].first) == 2) 
               q = i; 
        } 
  
        p = q; 
  
    } while (p != l);  // While we don't come to first point 

    return hull;
}
  
int main() 
{ 
    int cases; cin >> cases;
    for(int caso = 0; caso < cases; caso++){
        vector<pair<Point,int>> points;
        vector<Point> verify;
        vector<pair<Point,int>> hull_safe;

        int C,P; cin >> C >> P;

        for(int i=0; i<C; i++){
            int x,y;
            cin >> x >> y;
            Point p;
            p.x = x;
            p.y = y;
            points.push_back(make_pair(p,0));
        }

        hull_safe = convexHull(points, points.size());
        hull_safe.push_back(hull_safe[0]);

        for(int i=0; i<P; i++){
            int x,y;
            cin >> x >> y;
            Point p;
            p.x = x;
            p.y = y;
            verify.push_back(p);
        }


        cout << "Case " << caso+1 << endl;
        for(auto ph:hull_safe){
            cout << ph.first.x << " " << ph.first.y << endl;
        }

        for(auto ph:verify){
            vector<pair<Point,int>> hull_verification;
            points.push_back(make_pair(ph,1));
            hull_verification = convexHull(points, points.size());
            int achei = 0;
            bool flag2 = false;
            for(auto seek:hull_verification){
                if (seek.first.x == ph.x and seek.first.y == ph.y)
                    achei++;
            }
            // cout << flag << endl;
            if (achei==1){
                flag2 = false;
                // for(auto seek:hull_verification){
                //     bool flag2 = ((seek.second==1) ? 1 : 0);
                //     if (flag2) break;
                // }
            } else {
                flag2 = true;
            }
            points.pop_back();
            if (!flag2) cout << ph.x << " " << ph.y << " is safe!" << endl;
            else cout << ph.x << " " << ph.y << " is unsafe!" << endl;
        }
        if(caso != cases-1) cout << endl;
    }
    return 0; 
} 