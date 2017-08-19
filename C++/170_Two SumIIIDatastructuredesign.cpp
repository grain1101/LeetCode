/****************************************************************************
4. Two Sum III
store- O(1)
test - O(n)
*/
class TwoSum {
public:
    void store(int input) {
        numbers[input]++;
    }
    bool test(int input) {
        if (numbers.size() == 0) return false;
        for(auto p : numbers){
            int second = input - p.first;
            if (second == p.first) return p.second >= 2;
            if (numbers.find(second) != numbers.end()) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> numbers;   
};
/****************************************************************************
5. Two Sum III
store O(n)
test O(1)
*/
class TwoSum {
public:  
    void store(int input) {
        for(auto n : numbers) {
            sum.insert(input + n);
        }
        numbers.push_back(input);
    }
    bool test(int input) {
        if (sum.empty()) return false;
        return sum.find(input) != sum.end();
    }
private:
    unordered_set<int> sum;
    vetor<int> numbers;
}; 
/****************************************************************************
6. Multi Sum
same number can be used repeatedly.
*/
class MultiSum {
public:
    void store(int input) {
        numbers[input]++;
    }
    bool test(int input, int k) {
        if (numbers.size() == 0 || numbers.size() < k || k <= 0) return false;
        if (k == 1) return numbers.find(input) != numbers.end();
        unordered_set<int> kSum = generate(k);
        return kSum.find(input) != kSum.end();
    }
private:
    unordered_map<int, int> numbers;
    unordered_set<int> kSum;
    unordered_set<int> generate(int k) {
        unordered_set<int> ret;
        if (k == 0) return ret;
        if (k == 1) {
            for(auto p : numbers) {
                ret.insert(p.first);
            }
            return ret;
        }
        auto half = generate(k / 2);
        for(auto p : half) {
            for(auto q : half) {
                ret.insert(p + q);
            }
        }
        if (k % 2){
            unordered_set<int> tmp;
            for(auto& r : ret){
                for(auto n : numbers) {
                    tmp.insert(r + n.first);
                }
            }
            ret = tmp;put) {
        numbers[input]++;
    }
};