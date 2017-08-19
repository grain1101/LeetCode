#include "leetcode.h"

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    typedef Iterator super;
    // 284. Peeking Iterator
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    top = 0;
	    flag = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (!flag){
            top = super::next();
            flag = true;
	    }
        return top;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (!flag) return super::next();
        flag = false;
        return top;
	}

	bool hasNext() const {
        if (!flag) return super::hasNext();
        return true;
	}
private:
    int top;
    bool flag;
};

int main() {
    Solution s1;
    string nums = "00";
    int target = 0;
    auto ans = s1.addOperators(nums, target);
    showV(ans);
    //show(ans);
    //showV(ans);
}
