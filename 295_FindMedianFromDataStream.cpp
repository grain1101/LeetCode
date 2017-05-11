#include "leetcode.h"

class MedianFinder {
public:
    // 295. Find Median from Data Stream
    // use two priority_queue, small(half small), large(-half large)
    /** initialize your data structure here. */

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size() ?
                small.top() : (small.top() - large.top()) * 1.0 / 2;
    }
private:
    priority_queue<long long> small, large;
};

int main() {
    MedianFinder m;
    m.addNum(2);
    m.addNum(3);
    m.addNum(4);
    m.addNum(1);
    cout << m.findMedian() << endl;
    //showV(ans);
    //show(ans);
    //showV(ans);
}
