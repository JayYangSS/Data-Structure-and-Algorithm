/*给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。 
*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};


TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)return NULL;
        if(pNode->right!=NULL){
            //寻找右子树的最左节点
            TreeLinkNode* p=pNode->right;
            while(p->left!=NULL)
                p=p->left;
            return p;
        }
        //右子节点为空
        else{
            TreeLinkNode* parent=pNode->next;
            //if(parent!=pNode)return parent;
             
            while(parent!=NULL){
                if(parent->left==pNode)return parent;
                parent=parent->next;
                pNode=pNode->next;
            }
            return NULL;
        }
    }



//比较混乱的代码，先找到根节点，然后中序遍历

TreeLinkNode* GetNext2(TreeLinkNode* pNode)
    {
        if (pNode == NULL)return NULL;
        stack<TreeLinkNode*> container;
        TreeLinkNode* p = pNode;
        int sign = 0;//make sign
        //get the root of root node
        while (p->next != NULL)p = p->next;
        //mid order scan
        container.push(p);

        while (!container.empty()){
            p = container.top();
            while (p->left != NULL){
                p = p->left;
                container.push(p);
            }

            while (p->right == NULL){
                if (p == pNode){
                    sign++;
                }
                container.pop();
                if (container.empty())return NULL;
                p = container.top();
            }

            if (p == pNode)sign++;
            if (sign == 2)return p;
            container.pop();
            container.push(p->right);
        }
        return NULL;
    }