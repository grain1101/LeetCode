#include "leetcode.h"
/*
我们使用大小堆来解决问题，其中大堆保存右半段较大的数字，小堆保存左半段较小的数组。
这样整个数组就被中间分为两段了，由于堆的保存方式是由大到小，我们希望大堆里面的数据是从小到大，这样取第一个来计算中位数方便。
我们用到一个小技巧，就是存到大堆里的数先取反再存，这样由大到小存下来的顺序就是实际上我们想要的从小到大的顺序。
当大堆和小堆中的数字一样多时，我们取出大堆小堆的首元素求平均值，当小堆元素多时，取小堆首元素为中位数
getting the median takes O(1) time. And adding a number takes O(log n) time.
*/
class MedianFinder {
public:
    // 295. Find Median from Data Stream
    // use two priority_queue, small(half small), large(-half large)
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
                small.top() : (small.top() - large.top()) * 0.5;
    }
private:
    // To prevent a bug with -2^31 (which negated is itself, when using 32-bit ints), so use long long type.
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
