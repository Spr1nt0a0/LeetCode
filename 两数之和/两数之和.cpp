//给定整数的一个数组，找出这样两个数，使它们之和为一个特定的目标数字
//hash解法
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//using namespace std;

class Solution
{
public:
std::vector<int> twosum(std::vector<int> &numbers,int target)
{
	std::map<int,int> mapping;
	std::vector<int> result;
	for(int i=0;i<numbers.size();i++)
	{
		mapping[numbers[i]]=i;
	}
	for(int j=0;j<numbers.size();j++)
	{
		int searched=target-numbers[i];
		if(mapping.find(searched)!=mapping.end()&&i!=mapping[searched])
		{
			result.push_back(i+1);
			result.push_back(mapping[searched]+1);
			break;
		}
	}
	return result;
}
};

int main()
{
	std::vector<int> a={2,7,11,15};
	int b=9;
    Solution solu = Solution();
    std::cout <<"[" <<solu.twosum(numbers, b)[0] <<", " <<solu.twosum(numbers, b)[1] <<"]" <<std::endl;;  
}