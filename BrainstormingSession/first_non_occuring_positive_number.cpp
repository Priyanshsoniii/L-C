#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int array[], int arraySize){

    for(int i=0; i<arraySize; ++i){
        cout<<array[i]<<",";
    }
}

int processArray(int array[], int arraySize){

    for(int i=0; i<arraySize; ++i){
        if(array[i]>0){
            for(int j=1; ; ++j){
                if(array[i]==j){
                   // cout<<j<<",";
                    i++;
                }
                else return j++;
            }
        }
    }
    return 1;
    
}

int main(){
    int arraySize;
    cout<<"Please enter the size of array: "<<endl;
    cin>>arraySize;

    cout<<"enter array elements: "<<endl;
    int array[100000] = {0};

    for(int i=0; i<arraySize; ++i){
        int temp;
        cin>>temp;
        array[i] = temp;
    }

    sort(array, array + arraySize);

    cout<<processArray(array,arraySize)<<endl;

    return 0;
}