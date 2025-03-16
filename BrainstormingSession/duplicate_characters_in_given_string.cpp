#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string inputString;
    cin>>inputString;
    unordered_map<char,int>mp;
    for(auto ch : inputString){
        mp[ch]++;
    }

    

    for(auto ch : mp){
        if(ch.second>1){
            cout<<ch.first<<" "<<ch.second<<endl;
        }
    }
    return 0;
}