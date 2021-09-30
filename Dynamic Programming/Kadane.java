//KADANE ALGO
//for finding maximum sum subarray
class Solution {
    public int maxSubArray(int[] nums) {
        int ans=-1000000;
        int sum=0;
        
        for(int i=0;i<nums.length;i++)
        {
            sum=sum+nums[i];
            ans=(int)Math.max(ans,sum);
            if(sum<0)
                sum=0;
            
        }
        
        return ans;
    }
}
