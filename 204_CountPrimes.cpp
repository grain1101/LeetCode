#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <set>
#include <string>
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
        cout << r << " ";
    cout << endl;
}
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    // 204. Count Primes
    // primes number: 2,3,5,7,11,13..
    int countPrimes(int n) {
        int p = 0;
        vector<bool> isPrime(n+1, true);
        for(int i = 2; i < n; i++){ // less than n;
            if (isPrime[i]){
                p++;
                for(int j = 2 * i; j <= n; j += i) isPrime[j] = false;
            }
        }
        return p;
    }
};

int main() {
    Solution s1;
    auto ans = s1.countPrimes(5);
    cout << ans << endl;
}
