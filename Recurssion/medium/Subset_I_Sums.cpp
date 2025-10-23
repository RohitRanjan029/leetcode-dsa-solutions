class Solution {
  public:
    void subsequnce(vector<int>& arr,int index,int n, vector<int>&ans, int &sum){
        if(index == n){
            ans.push_back(sum);
            return;
        }

        //NO
        subsequnce(arr,index+1,n,ans,sum);
        //yes
        sum += arr[index];
        subsequnce(arr,index+1,n,ans,sum);
        sum -= arr[index];
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int>ans;
        int sum = 0;
        subsequnce(arr,0,n,ans,sum);
        
        return ans;
    }
};