#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//path存放排列，nums存放排序后n个数，used标记nums是否已用
void FullP(vector<int>&path,const vector<int>&nums, vector <bool>&used,const int &n)
{
	//path存放排列，排列好了就输出
	if (path.size() == n)
	{
		for (const auto& i : path)
		{

			cout << i << " ";

		}
		cout << endl;
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (used[i])
		{
			continue;
		}
		//改变
		//产生组合，标记已用
		path.push_back(nums[i]);
		used[i] = true;
		//递归
		FullP(path, nums, used, n);
		//恢复
		path.pop_back();
		used[i] = false;
	}
	
}
void test01()
{
	int n;
	cin >> n;
	vector<int>nums;
	vector<int>path;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(),nums.end());
	vector<bool >used;
	used.assign(n, false);
	FullP(path,nums, used, n);
}
int main()
{

	test01();
	return 0;
}
//\b(?!if|for|return)(\w+)\s*\(