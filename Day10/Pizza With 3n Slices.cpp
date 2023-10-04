 // Pizza With 3n Slices
//https://leetcode.com/problems/pizza-with-3n-slices/
class Solution {
public:
   int abc(int ind, int end, vector<int>&slices,int n, vector<vector<int>>&dp)
   {
       if(n==0||ind>end)
         return 0;
         if(dp[ind][n]!=-1)
            return dp[ind][n];
        int take=slices[ind]+abc(ind+2, end, slices, n-1, dp);
        int notTake=0 + abc(ind+1, end, slices, n, dp);
        return dp[ind][n]= max(take,notTake);
   }

    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        int r1=abc(0,n-2,slices,n/3, dp1);
        int r2=abc(1,n-1,slices,n/3, dp2);
        return max(r1,r2);
    }
};