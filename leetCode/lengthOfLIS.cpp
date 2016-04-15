/*Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], 
therefore the length is 4. Note that there may be more 
than one LIS combination, it is only necessary for you to return the length.
*/


//my solution's time complexity is O(n^3),there are little problem in my solution
class MySolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)return 0;

        int len = nums.size();

        vector<int> container;
        for (int i = 0; i<len; i++){
            int result = 1;
            int val = nums[i];
            for (int m = i; m<len; m++){
                int p1 = nums[m];//first poiter
                result = 1;
                for (int j = m; j<len; j++){
                    int val2 = nums[j];
                    if (p1<val2){
                        result++;
                        p1 = val2;
                    }

                }
                container.push_back(result);
            }

        }
        //get maximum
        int max = container[0];
        for (int i = 0; i<container.size(); i++){
            if (max<container[i])
                max = container[i];
        }

        return max;
    }
};



//better solution,the time complexity is O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int> v={nums[0]};
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>v.back())v.push_back(nums[i]);
            else{
                vector<int>::iterator pos;
                //use binary search to find the first element in V that is larger than nums[i]
                pos=lower_bound(v.begin(),v.end(),nums[i]);
                *pos=nums[i];
            }
        }
        
        return v.size();
    }
};