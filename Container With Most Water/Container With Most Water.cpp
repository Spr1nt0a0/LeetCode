// Container With Most Water.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <math.h>


class Solution 
{
public: 
	int maxArea(vector<int> &height)
	{
		if (height.length < 2) return 0;
		int ans = 0;
		int l = 0;
		int r = height.length - 1;
		while (l < r) 
		{
			int v = (r - l) * Math.min(height[l], height[r]);
			if (v > ans) ans = v;
			if (height[l] < height[r]) l++;
			else r--;
		}
		return ans;
	}
};

