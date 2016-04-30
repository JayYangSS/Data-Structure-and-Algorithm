/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只
出现一次的数字。 
*/

//思路：若数字相同且都出现了2次，将数组中元素全部异或应该结果为0，但是若存在2个不同的
//只出现了一次的元素，所有元素异或后结果不为0，找到该结果的位为1的最低位，则说明2个不
//同元素在该位上一个为1，一个为0，将这2个元素分到2个数组中在处理就OK了





class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int len=data.size();
        if(len<2)return;
        
        int tmpcon=data[0];
        for(int i=1;i<len;i++)
            tmpcon^=data[i];
        if(tmpcon==0)return;
        
        
        int mask=0;
        for(int i=0;i<32;i++){
            mask=1<<i;
            if(mask&tmpcon)
                break;
        }
        
        vector<int> v1,v2;
        for(int i=0;i<len;i++){
            if(mask&data[i])
                v1.push_back(data[i]);
            else
                v2.push_back(data[i]);
        }
        
        *num1=v1[0];
        *num2=v2[0];
        for(int i=1;i<v1.size();i++)
            *num1^=v1[i];
        
        for(int i=1;i<v2.size();i++)
            *num2^=v2[i];
        
    }
};