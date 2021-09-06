using namespace std;
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>//sort所需头文件
class Solution {//暴力解法  :O(n) + O(log(n)) 
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] <<" ";
        }
        return nums;
    }
};
int main()
{
    vector<int> obj;
    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        obj.push_back(temp);
    }
    Solution s;
    obj=s.sortedSquares(obj);

}
