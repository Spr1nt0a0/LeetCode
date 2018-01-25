//给定n个整数的一个数组S，S中是否有元素a，b，c满足和为0，若有则找出不同的三个数的组合
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
vector< vector<int> > threesum(vector<int> &num)
{
	std::sort(num.begin(),num.end());
	vector< vector<int> > result;
	int len=num.size();
	for(int i=0;i<len;i++)
	{
		int target=0-num[i];
		int start=i+1,end=len-i;
		while(start<end)
		{
			if(num[start]+num[end]==target)
			{
				vector<int> solution;
				solution.push_back(num[i]);
				solution.push_back(num[start]);
				solution.push_back(num[end]);
				result.push_back(solution);
				start++;end--;
				while(start<end && num[start] ==num[start-1])
					start++;
				while(start<end && num[end] ==num[end+1])
					end--;
			}
			else if(num[start]+num[end]<target)
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		if(i<len-1)
		{
			while(num[i]==num[i+1])
				i++;
		}
	}
	return result;
}
};

void main()
{
	//通过数组a的地址初始化，注意地址是从0到4（左闭右开区间）
	int a[5] = {2,7,11,-9};
    std::vector<int> b(a, a+4);
    Solution solu;
    std::cout<<"[" <<solu.threesum(b)[0] <<", " <<solu.threesum(b)[1] <<", " <<solu.threesum(b)[2]<<"]" <<std::endl;
}


