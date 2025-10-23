class Solution {
public:
    void subsequnce(vector<int>& nums,int index,int n, set<vector<int>>&ans, vector<int>&temp){
        if(index == n){
            ans.insert(temp);
            return;
        }

        //NO
        subsequnce(nums,index+1,n,ans,temp);
        //yes
        temp.push_back(nums[index]);
        subsequnce(nums,index+1,n,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<int>temp;
        subsequnce(nums,0,n,ans,temp);

        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};