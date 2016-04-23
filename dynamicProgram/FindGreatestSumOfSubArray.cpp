/*
*find the Greatest Sum Of SubArray for an array
*use the DP:if the sum of the previous ones is larger than zero,then the max value can be 
*calculated based on the previsous sum,otherwise, the previous sum can be discarded.
*
*/


class MySolution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len=array.size();
        if(len==0)return 0;
        int sum=array[0],max=array[0];
         
        for(int i=1;i<len;i++){
            if(sum>=0){
                if(array[i]>0)
                    max=sum+array[i];
 
                sum+=array[i];
            }else{
                if(array[i]>0){
                    max=array[i];
                    sum=array[i];
                }else{
                     
                    if(array[i]>max)
                        max=array[i];
                    sum+=array[i];
                }
            }
             
        }
        return max;  
    }
};



//more concise solution
class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len=array.size();
        if(len==0)return 0;
        int sum=array[0],max=array[0];
         
        for(int i=1;i<len;i++){
            sum=sum>0?sum+array[i]:array[i];
            max=max<sum?sum:max;
        }
        return max;  
    }
}