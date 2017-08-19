class BestTimetoBuyandSellStock {
public:
	int 1_oneTransaction(vector<int>& prices) {
		int ret = 0, minV = INT_MAX;
		for(auto p : prices) {
			minV = min(minV, p);
			ret = max(ret, p - minV);
			// if (ret == 0 && minV == p) ret = -p;  // only if the prices is [5,4,3,2,1] and we need to return a negtive number 
		}
		return ret;
	}
    int 2_manyTransactions(vector<int>& prices) {
    	int ret = 0;
    	for(int i = 0; i < prices.size(); i++) {
    		if (i > 0 && prices[i] > prices[i - 1]) ret += prices[i] - prices[i - 1];
    	}
    	return ret;     
    }
    int 3_atMostTwoTransactions(vector<int>& prices) {
		/*定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
		  定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：
		local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
		global[i][j] = max(local[i][j], global[i - 1][j])*/
 		if (prices.empty()) return 0;
        vector<vector<int>> local(prices.size(), vector<int>(3,0));
        vector<vector<int>> global(prices.size(), vector<int>(3,0));
        for(int i = 1; i < prices.size(); i++) {
        	int diff = prices[i] - prices[i - 1];
        	for(int j = 0; j < 3; j++) {
        		local[i][j] = max(global[i - 1][j - 1] + max(0, diff), local[i - 1][j] + diff);
        		global[i][j] = max(global[i - 1][j], local[i][j]);
        	}
        }
        return global[prices.size() - 1][2];
    }
    int 4_atMostKTransactions(int k, vector<int>& prices) {
    	if (prices.empty()) return 0;
        vector<vector<int>> local(prices.size(), vector<int>(k,0));
        vector<vector<int>> global(prices.size(), vector<int>(k,0));
        for(int i = 1; i < prices.size(); i++) {
        	int diff = prices[i] - prices[i - 1];
        	for(int i = 1; i <= k; i++) {
        		local[i][j] = max(global[i - 1][j - 1] + max(0, diff), local[i - 1][j] + diff);
        		global[i][j] = max(global[i - 1][j], local[i][j]);
        	}
        }
        return global[prices.size() - 1][k];
    }
};