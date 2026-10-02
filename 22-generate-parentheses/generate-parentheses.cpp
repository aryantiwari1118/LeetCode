class Solution {
public:

    void count(vector<string> &ans , string temp , int n, int l, int r){
        if(l==n && r==n) {
            ans.push_back(temp);
            return ;
        }
        if(l<n){
            temp.push_back('(');
            count(ans , temp ,n,l+1,r);
            temp.pop_back();
        }
        if(r<l){
            temp.push_back(')');
            count(ans , temp ,n,l,r+1);
            temp.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        int l=0,r=0;
        vector<string> ans;
        string temp;
        count(ans , temp ,n,l,r);
        return ans;

    }
};