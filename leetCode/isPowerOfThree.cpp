//Given an integer, write a function to determine if it is a power of three.

//my solution:
class MySolution {
public:
    bool isPowerOfThree(int n) {
        int i=1;
        
        if(n==1)return true;
        if(n%3!=0)return false;
        while(n!=i){
            i*=3;
            if(n==i)return true;
            if(n<i)return false;
        }
    }
};


//the better solution with O(1) complexity
class Solution {
public:
    int const Max3PowerInt = 1162261467; // int类型中最大的3的指数的数字为3^19
    int const MaxInt = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};