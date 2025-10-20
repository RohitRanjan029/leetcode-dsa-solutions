class Solution {
public:
    void parentheses(int n, int L, int R,vector<string>&ans, string &temp){
        if(L+R == 2*n){
            ans.push_back(temp);
            return;
        }


        if(L<n){
            temp.push_back('(');
            parentheses(n,L+1,R,ans,temp); 
            temp.pop_back();
        }
        if(R<L){
            temp.push_back(')');
            parentheses(n,L,R+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string temp;
       int L = 0;
       int R = 0;
       parentheses(n,L,R,ans,temp);

       return ans;
    }
};