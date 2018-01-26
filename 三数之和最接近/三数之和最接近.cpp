//����n��������һ������S����S���ҳ�3��������Ӻ���ӽ�һ����������������3�����ĺ�
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
	//ͨ������a�ĵ�ַ��ʼ����ע���ַ�Ǵ�0��4������ҿ����䣩
	int a[5] = {-1,2,1,-4};
	int t=1;
    std::vector<int> b(a, a+4);
    int solu;
	solu=threesumclosest(b,t);
	cout<<"threesumclosest:"<<solu<<endl;
}