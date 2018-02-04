//假设有一个数组，其第i个元素是一支给定的股票在某一天i的价格
//设计一个算法找出最大赢利点，你可以最多可以进行两次交易，然而不能同时进行交易，在再次购买之前必须先销售该股票
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//动态规划，max（0，n）=max（0，i）+max（i+1，n）
int maxprofit(vector<int>&prices)
{
	if(prices.size()<=1)
		return 0;
	vector<int> maxfromleft(prices.size(),0);
	vector<int> maxfromright(prices.size(),0);
	int minV=INT_MAX,maxP=INT_MIN;
	for(int i=0;i<prices.size();i++)
	{
		if(minV>prices[i])
			minV=prices[i];
		int temp=prices[i]-minV;
		if(temp>maxP)
			maxP=temp;
		maxfromleft[i]=maxP;
	}
	int maxV=INT_MIN;
	maxP=INT_MIN;
	for(int j=prices.size()-1;i>=0;i--)
	{
		if(maxV<prices[j])
			maxV=prices[j];
		int qwe=maxV-prices[j];
		if(qwe>maxP)
			maxP=qwe;
		maxfromright[i]=maxP;
	}
	int maxprofit=INT_MIN;
	for(int k=0;k<prices.size();k++)
	{
		int sum=maxfromleft[k]+maxfromright[k+1];
		if(sum>maxprofit)
			maxprofit=sum;
	}
	if(maxprofit<maxfromright[0])
		maxprofit=maxfromright[0];
	return maxprofit;
}
void main()
{
	int a[7]={24,56,21,15,67,20,81};
	std:vector<int> b(a,a+7);
	int c=maxprofit(b);
	cout<<"maxprofit:"<<c<<endl;
}
