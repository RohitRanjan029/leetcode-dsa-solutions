#include<iostream>
#include <vector>
using namespace std;
void subsequnce(string s,int index,int n,vector<string>&ans,string temp){
    
    if(index == n){
        ans.push_back(temp);
        return;
    }
    // no
    subsequnce(s,index+1,n,ans,temp);

    // yes
    temp.push_back(s[index]);
    subsequnce(s,index+1,n,ans,temp);

}
int main(){
    string s = "abc";
    vector<string>ans;
    string temp;
    subsequnce(s,0,s.size(),ans,temp);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" "<<endl;
        
    }
    return 0;
}