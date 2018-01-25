//����n��������һ������S��S���Ƿ���Ԫ��a��b��c�����Ϊ0���������ҳ���ͬ�������������
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
	//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��4������ҿ����䣩
	int a[5] = {2,7,11,-9};
    std::vector<int> b(a, a+4);
    Solution solu;
    std::cout<<"[" <<solu.threesum(b)[0] <<", " <<solu.threesum(b)[1] <<", " <<solu.threesum(b)[2]<<"]" <<std::endl;
}


