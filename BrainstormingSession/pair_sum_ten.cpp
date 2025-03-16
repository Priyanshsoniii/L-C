#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
 
void findPairs(vector<int>& nums, int target) {

    multiset<pair<int, int>> result;
    unordered_map<int, int> freq;

    for (int num : nums) {
        int complement = target - num;
        if (freq[complement] > 0) {
            result.insert({min(num, complement), max(num, complement)});
            freq[complement]--;
        } else {
            freq[num]++;
        }
    }

    for (auto& p : result) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}
 
int main() {

    vector<int> nums;
    int Size,target;

    cout<<"input size of array: "<<endl;
    cin>>Size;

    cout<<"input target sum: "<<endl;
    cin>>target;

    nums.resize(Size,0);

    cout<<"input array elements : "<<endl;

    for(int i=0;i<Size;++i){
        int temp; 
        cin>>temp;
        nums[i]=temp;
    }

    findPairs(nums,target);

    return 0;

}

 