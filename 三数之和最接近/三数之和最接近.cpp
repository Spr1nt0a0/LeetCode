//给定n个整数的一个数组S，从S中找出3个数，其加和最接近一个给定数，返回这3个数的和
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int threesumclosest(vector<int> &num,int target)
{
	std::sort(num.begin(),num.end());
	int len=num.size();
	int minv=INT_MAX,record;
	for(int i=0;i<len;i++)
	{
		int start=i+1,end=len-1;
		while(start<end)
		{
			int sum=num[i]+num[start]+num[end];
			if(sum==target)
			{
				minv=0;
				record=sum;
				break;
			}
			if(sum<target)
			{
				if(target-sum<minv)
				{
					minv=target-sum;
					record=sum;
				}
				start++;
			}
			else
			{
				if(sum-target<minv)
				{
					minv=target-sum;
					record=sum;
				}
				end--;
			}
		}
		if(record==target)
			break;
		while(i<len-1&&num[i]==num[i+1])
			i++;
	}
	return record;
}

void main()
{
	//通过数组a的地址初始化，注意地址是从0到4（左闭右开区间）
	int a[5] = {-1,2,1,-4};
	int t=1;
    std::vector<int> b(a, a+4);
    int solu;
	solu=threesumclosest(b,t);
	cout<<"threesumclosest:"<<solu<<endl;
}