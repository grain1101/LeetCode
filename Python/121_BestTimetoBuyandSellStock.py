'''class Solution(object):
    def maxProfit(self, stock_prices_yesterday):
       if len(stock_prices_yesterday) < 2:
       		raise IndexError('Getting a error list')
       	min_price = stock_prices_yesterday[0]
       	ret = stock_prices_yesterday[1] - stock_prices_yesterday[0]
       	for index, current_price in enumerate(stock_prices_yesterday):
       		if (index == 0):
       			continue
       		tmp = current_price - min_price
       		ret = max(ret, tmp)
       		min_price = min(min_price, current_price)
       	return ret

'''

stock_prices_yesterday = [10, 7, 5, 8, 11, 9]
def maxProfit(self, stock_prices_yesterday):
    if len(stock_prices_yesterday) < 2:
   		raise IndexError('Getting a error list')
	for index, current_price in enumerate(stock_prices_yesterday):
   		min_price = min(min_price, current_price)
   		tmp = current_price - min_price
   		ret = max(ret, tmp)
   	return ret