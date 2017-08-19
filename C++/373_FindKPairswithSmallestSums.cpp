vector<int> nums1;
vector<int> nums2;
typedef pair<int, int> PII;
class Solution {
public:
    // 373. Find K Pairs with Smallest Sums
    // priority_queue
    vector<pair<int, int>> kSmallestPairs(vector<int>& _nums1, vector<int>& _nums2, int k) {
        if (k <= 0 || _nums1.empty() || _nums2.empty()) return {};
        nums1 = _nums1;
        nums2 = _nums2;
        vector<PII> ret;
        set<PII> used;
        priority_queue<PII, vector<PII>, cmp> pq;
        pq.push({0,0});
        while(!pq.empty() && k-- > 0) {
            PII top = pq.top(); pq.pop();
            //cout << top.first << " " << top.second << endl;
            ret.push_back({nums1[top.first], nums2[top.second]});
            PII next1(top.first + 1, top.second);
            PII next2(top.first, top.second + 1);
            if (next1.first < nums1.size() && used.find(next1)== used.end()) {
                    pq.push(next1);
                    used.insert(next1);
            }
            if (next2.second < nums2.size() && used.find(next2)== used.end()) {
                    pq.push(next2);
                    used.insert(next2);
            }
        }
        return ret;
    }
private:
    int sumPII(const PII& p) {return nums1[p.first] + nums2[p.second];}
    struct cmp {
        bool operator() (const PII& a, const PII& b)  {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        }
    };
};
