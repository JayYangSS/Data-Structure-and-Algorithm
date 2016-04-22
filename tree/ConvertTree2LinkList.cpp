/*
*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新
*的结点，只能调整树中结点指针的指向。 
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};



class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL||(pRootOfTree->left==NULL&&pRootOfTree->right==NULL))
            return pRootOfTree;
        
        TreeNode* left=Convert(pRootOfTree->left);
        TreeNode* right=Convert(pRootOfTree->right);
        
        //第一次没有考虑到左右子树递归返回为空的情况，出现段错误
        if(right!=NULL){
            right->left=pRootOfTree;
        	pRootOfTree->right=right;
        }
        
        if(left!=NULL){
            TreeNode* p=left;
        	while(p->right!=NULL)p=p->right;
        	p->right=pRootOfTree;
        	pRootOfTree->left=p;
            return left;
        }
        
        return pRootOfTree;
    }
};