class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
       int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int a=nums[i];
            int b=a+1;
            
            if(a==2)
                ans[i]=-1;
            else
                ans[i]=a-((b)&(-b))/2; 
        }
        return ans; 
    }
};
