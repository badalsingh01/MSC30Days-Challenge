class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n+1,vector<int> (4,0));
        for(int i=0;i<n;i++){
            for(int k=1;k<4;k++){
                if(k==nums[i]){
                    f[i+1][k] = 1 + f[i][k];
                }
                else{
                    f[i+1][k] = f[i][k];
                }   
            }
        }
            
//     for(int i=0;i<n;i++){
//                     cout<<f[i+1][1]<<" "<<f[i+1][2]<<" "<<f[i+1][3]<<endl;

//     }
        
        int ans = n;
        for(int i=0;i<=n;i++){
            for(int j=i;j<=n;j++){
                for(int k=j;k<=n;k++){
                    int one = f[i][1];
                    int two = f[j][2]-f[i][2];
                    int three = f[k][3]-f[j][3];
                    // cout<<"o"<<" "<<one<<" "<<two<<" "<<three<<endl;
                    ans = min(ans,n-one-two-three);
                }
            }
        }
        return ans;
        
    }
};