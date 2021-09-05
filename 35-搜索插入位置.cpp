using namespace std;
#include<iostream>
#include <vector>
#include <string.h>

class Solution {// 这是查找搜索位置算法，如果是Log(n)则使用二分查找
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();//这是左闭右开的的二分查找
        while (left < right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle; //此时目标在左区间，注意一直是左闭又开因此不用middle-1
            else if (nums[middle] < target)
                left = middle + 1; //此时目标在右区间
            else
                return middle;
        }
        return right;

    }
};
int main()
{
    vector<int> obj;
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        obj.push_back(temp);
    }
    Solution s;
    int target;
    cin >> target;
    cout << s.searchInsert(obj,target) << endl;
}
