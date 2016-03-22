#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//reverse print the linklist

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        
        //if(head==NULL)return NULL;
        ListNode *p=head;
        stack<int> s;
        vector<int> result;
        
        while(p!=NULL)
        {
            s.push(p->val);
            p=p->next;
        }
        
        while(s.size()!=0){
            result.push_back(s.top());
            s.pop();
        }
        
        return result;
    }

    //recursive version
    vector<int> printListFromTailToHead2(struct ListNode* head){
    	vector<int> vec;
    	if(head==NULL)return vec;
    	if(head->next!=NULL){
    		vec=printListFromTailToHead2(head->next);
    	}
    	vec.push_back(head->val);

    	return vec;
    }
};

int main(){
    ListNode p1(1);
    ListNode p2(2);
    ListNode p3(4);

    p1.next=&p2;
    p2.next=&p3;

    Solution s;

    vector<int> result1=s.printListFromTailToHead(&p1);
    vector<int> result2=s.printListFromTailToHead2(&p1);

    for(int i=0;i<result1.size();i++)
        cout<<result1[i]<<endl;

    for(int i=0;i<result2.size();i++)
        cout<<result2[i]<<endl;
}