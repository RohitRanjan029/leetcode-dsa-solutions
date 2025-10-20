class Solution {
public:
    void subsequnce(vector<int> nums,int index,int n, vector<vector<int>>&ans,vector<int>&temp){
        if(index == n){
        ans.push_back(temp);
        return;
        }
        // no
        subsequnce(nums,index+1,n,ans,temp);

        // yes
        temp.push_back(nums[index]);
        subsequnce(nums,index+1,n,ans,temp);
        temp.pop_back();
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        subsequnce(nums,0,n,ans,temp);

        return ans;

    }
};