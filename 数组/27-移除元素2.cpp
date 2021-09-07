using namespace std;
#include<iostream>
#include <vector>
#include <string.h>
class Solution {//关于双指针法完成移除元素。即利用一个快指针和一个慢指针在一个for循环下
public:
    int removeElement(vector<int>& nums, int val) {
        int SlowIndex = 0;
        int FastIndex = 0;
        for(FastIndex; FastIndex < nums.size(); FastIndex++){
            if(val != nums[FastIndex]){
                nums[SlowIndex] = nums[FastIndex];
                SlowIndex++;
            }
        }
        return SlowIndex;
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