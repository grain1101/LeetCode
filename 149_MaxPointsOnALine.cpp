#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
using namespace std;

void show(auto& result){
    for(auto r : result){
        for(auto t : r){
            cout << t << " ";
        }
        cout << endl;
    }
}
void showV(auto& result){
    for(auto r : result)
        cout << r;
    cout << endl;
}
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

typedef pair<int, int> PII;
namespace std {
template <>
struct hash<PII> {
    std::size_t operator()(const PII& p) const {
        return p.first * p.second;
    }
};

};
class Solution {
public:
    // 149. Max Points on a Line
    int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
    Point calc_pair(Point& p1, Point& p2) {
        Point ret(p1.x - p2.x, p1.y - p2.y);
        if (ret.x == 0) ret.y = 0;
        else {
            int d = gcd(ret.x, ret.y);
            ret.x /= d;
            ret.y /= d;
        }
        return ret;
    }
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<PII, int> slope;
            int same = 1;
            for(int j = i + 1; j < points.size(); j++){
                if (points[j].x == points[i].x && points[j].y == points[i].y) same ++;
                else {
                    Point p = calc_pair(points[j], points[i]);
                    slope[PII(p.x, p.y)]++;
                }
            }
            int localMax = 0;
            for(auto it = slope.begin();it!=slope.end();it++){
                localMax = max(localMax, it->second);
            }
            ans = max(ans, localMax + same);
        }
        return ans;
    }
};
int main() {
    Solution s1;

}
