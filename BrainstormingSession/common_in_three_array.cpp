#include<iostream>
#include<vector>
using namespace std;

vector<int> processArray(int array1[],int array2[], int array3[], int arraySize1, int arraySize2, int arraySize3){
    vector<int>v;
    for(int i=0; i<arraySize1; ++i){
        for(int j=0; j<arraySize2; ++j){    
            for(int k=0; k<arraySize3; ++k){
                if(array1[i]==array2[j] && array2[j]==array3[k]){
                    v.emplace_back(array1[i]);
                }
            }
        }
    }
    return v;
    
}

int main(){

    int arraySize1,arraySize2,arraySize3;

    cout<<"Please enter the size of array1, array2, array3: "<<endl;
    cin>>arraySize1>>arraySize2>>arraySize3;

    int array1[100000] = {0};
    int array2[100000] = {0};
    int array3[100000] = {0};


    cout<<"enter array1 elements: "<<endl;
    for(int i=0; i<arraySize1; ++i){
        int temp;
        cin>>temp;
        array1[i] = temp;
    }

    cout<<"enter array2 elements: "<<endl;
    for(int i=0; i<arraySize2; ++i){
        int temp;
        cin>>temp;
        array2[i] = temp;
    }

    cout<<"enter array3 elements: "<<endl;
    for(int i=0; i<arraySize3; ++i){
        int temp;
        cin>>temp;
        array3[i] = temp;
    }


    vector<int> s1 = processArray(array1,array2,array3,arraySize1,arraySize2,arraySize3);

   for(auto x : s1){
       cout<<x<<" ,"<<endl;
   }

    return 0;
}