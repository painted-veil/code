#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bubblesort(vector<int> &vec) {
    for (int i = 0; i < vec.size()-1; i++) {
        bool exchange = false;
        for(int j = 0; j < vec.size() -1-i; j++) {
            if(vec[j]>vec[j+1]) {
                swap(vec[j],vec[j+1]);
                exchange = true;
        }
        if(!exchange)
        {
            break;
        }
        
    }
}
}
void print(vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] <<" ";
    }
    cout<<endl;
}
int main() {
    vector<int> vec = {9,8,7,6,5,4,3,2,1};
    bubblesort(vec);
    print(vec);
    vector<int> vec1(10,0);
    print(vec1);
    return 0;
}