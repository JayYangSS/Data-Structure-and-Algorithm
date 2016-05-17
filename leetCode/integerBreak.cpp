/*Given a positive integer n, break it into the sum of at least two positive integers and 
maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
*/



//my way to solve the problem, time complexity O(N^2)
class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)return 1;
        vector<int> table={0,1,1};
        for(int i=3;i<=n;i++){
            int max=0;
            for(int j=1;j<i;j++){
                int multipleVal=j*table[i-j]<j*(i-j)?j*(i-j):j*table[i-j];
                if(multipleVal>max)max=multipleVal;
            }
            table.push_back(max);
        }
        
        return table[n];
    }
};



//better way to solve, space comlexity O(1)
//when the factors are 2 or 3, the product is maximum
class Solution {
public:
    int integerBreak(int n) {
        if (n==2) return 1;
        else if (n==3) return 2;
        else {
            switch(n%3) {
                case 0: return pow(3, n/3); break;
                case 1: return pow(3, n/3-1)*4; break;
                case 2: return pow(3, n/3)*2; break;
            }
        }
        return 0;
    }
};