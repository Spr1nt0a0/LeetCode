//假设有一个数组，其第i个元素是一支给定的股票在某一天i的价格，如果最多只允许你完成一次交易，找出最大赢利点
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int maxprofit(vector<int> &prices)
{
	int minV=INT_MAX;
	int max=0;
	int diff=0;
	for(int i=0;i<prices.size();i++)
	{
		if(prices[i]<minV)
			minV=prices[i];
		diff=prices[i]-minV;
		if(max<diff)
			max=diff;
	}
	return max;
}
void main()
{
	int a[7]={24,56,21,15,67,20,81};
	std:vector<int> b(a,a+7);
	int c=maxprofit(b);
	cout<<"maxprofit:"<<c<<endl;
}