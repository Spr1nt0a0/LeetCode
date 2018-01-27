//给定n个整数的一个数组S，S中是否有4个元素a，b，c和d，满足其和为target，找出不同的四元组
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution 
{    
public:
vector< vector< vector<int> > > foursum(vector<int> &numbers, int target) 
	{  
       std::sort(numbers.begin(),numbers.end());  
        int len = 0;  
        if(target >= 0)  
        {  
            for(int i=0;i<numbers.size();i++)  
                if(numbers[i] >= target)  
                {  
                    len = i;  
                    break;  
                }  
        }  
        else 
		{  
            len = numbers.size()-1;  
        }  
        vector< vector< vector<int> > > list1; 
         for(int i=0;i<=len;i++)  
             for(int j=i+1;j<numbers.size();j++)  
                 for(int k=j+1;k<numbers.size();k++)  
                     for(int h=k+1;h<numbers.size();h++)  
                        {  
                             if(numbers[h]+numbers[i] + numbers[j] + numbers[k] == target)  
                             {  
                                 vector<int> list2;  
                                 int b[4]={numbers[i],numbers[j],numbers[k],numbers[h]}; 
								 vector<int> x(b,b+4); 
                                 std::sort(x.begin(),x.end());  
                                 list2.push_back(x[0]);  
                                 list2.push_back(x[1]);  
                                 list2.push_back(x[2]);  
                                 list2.push_back(x[3]); 
								 list1.push_back(list2);
                                 break;  
                             }  
                        }  
         return list1;  
    }  
};  

