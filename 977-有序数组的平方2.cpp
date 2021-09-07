using namespace std;
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>//sort所需头文件
class Solution {//双指针法 :O(n） 
public://数组其实是有序的，即左右两边比中间的大,因此让两个指针分别由两边向中间移动
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int j = nums.size() -1;
        int k = nums.size() -1;
        vector<int> result(nums.size());//创建一个同等大小的vector数组
        while (i <= j){//这里必须要i<=j，为了最后一个元素放入数组中，否则无法处理中间元素，刚好等于的时候就是最后一个元素，
            if(nums[i] * nums[i] >= nums[j] * nums[j]){
                result[k]= nums[i] * nums[i];
                i++;
                k--;
            }
            else {
                result[k]=nums[j] * nums[j];
                j--;
                k--;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            cout<<result[i]<<" ";
        }
        return result;
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
