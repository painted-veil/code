using namespace std;
#include<iostream>
#include <vector>
#include <string.h>

class Solution {// 这是一个升序数组的二分查找
public:
    int search(vector<int>& nums, int target)
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
        return -1;

    }
};
int main()
{
    vector<int> obj;
    for (int i = 0; i < 6; i++)
    {
        int temp;
        cin >> temp;
        obj.push_back(temp);
    }
    Solution s;
    int target;
    cin >> target;
    cout << s.search(obj, target) << endl;
}
