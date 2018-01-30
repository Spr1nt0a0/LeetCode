//给定一个字符串的数组，返回能够形成anagrams的所有字符串组合
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution 
{ 
public:  
	vector<vector<string> > anagrams(vector<string>& strs) 
		 {
			 if (strs.empty())    
				 return vector<vector<string> >();       
			 int len = strs.size();      //将字符串数组按照字典顺序排序   
			 sort(strs.begin(), strs.end());    //存储结果   
			 vector<vector<string> > ret;    //利用哈希思想构建map，将排序后相等的字符串存在相应的vector 
			 map<string, vector<string> > mv;    
			 for (int i = 0; i < len; i++)   
			 {    
				 string str = strs[i];    
				 sort(str.begin(), str.end());     
				 mv[str].push_back(strs[i]);   
			 }    
			 for (map<string, vector<string> >::iterator iter = mv.begin(); iter != mv.end(); iter++)    
				 ret.push_back(iter->second);    
			 return ret;  
		 } 
};  
int main() 
{
	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat" };  
	Solution s;   
	vector<vector<string> > ret = s.anagrams(v);   
	for (int i = 0; i < ret.size(); i++)  
	{
		for (int j = 0; j < ret[i].size(); j++)    
			cout << ret[i][j] << "\t";   
		cout << endl; 
	}
	system("pause");
	return 0; 
}












































