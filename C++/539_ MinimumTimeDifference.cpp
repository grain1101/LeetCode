class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int ret = INT_MAX;
        for(int i = 0; i < n; i++) {
            int diff = timeDiff(timePoints[(i - 1 + n) % n], timePoints[i]);
            diff = min(diff, 1440 - diff); // 1440 = 24 * 60;
            ret = min(ret, diff);
        }
        return ret;
    }
    int timeDiff(string& s1, string& s2) {
        int h1 = stoi(s1.substr(0, 2));
        int m1 = stoi(s1.substr(3, 2));
        int h2 = stoi(s2.substr(0, 2));
        int m2 = stoi(s2.substr(3, 2));
        return abs((h2 - h1) * 60 + (m2 - m1));
        
    }
};