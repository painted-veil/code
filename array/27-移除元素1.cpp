using namespace std;
#include<iostream>
#include <vector>
#include <string.h>
class Solution {//关于暴力解法移除元素
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] == val) {
                for(int j = i; j < size - 1; j++){
                    nums[j] = nums[j+1];
                }
            i--;
            size--;//i--和size--一定要放在if条件内
            }
        }
        return size;
    }
};
int main()
{
    vector<int> obj;
    for(int i = 0; i < 8; i++)
    {
        int temp;
        cin >> temp;
        obj.push_back(temp);
    }
    int val;
    cin >> val;
    Solution solve;
    cout<<solve.removeElement(obj,val)<<endl;

}