#include<iostream>
#include <vector>
using namespace std;
void subsequnce(int arr[],int index,int n,vector<vector<int>>&ans,vector<int>temp){
    
    if(index == n){
        ans.push_back(temp);
        return;
    }
    // no
    subsequnce(arr,index+1,n,ans,temp);

    // yes
    temp.push_back(arr[index]);
    subsequnce(arr,index+1,n,ans,temp);

}
int main(){
    int arr[3] = {1,2,3};
    vector<vector<int>>ans;
    vector<int>temp;
    subsequnce(arr,0,3,ans,temp);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
    

}