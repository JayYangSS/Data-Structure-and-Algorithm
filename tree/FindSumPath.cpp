/*
*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为
*从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。 
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
         
        vector<vector<int> > result={};
        if(root==NULL){
            return result;
        }
         

        int val=root->val;
        vector<vector<int> > leftV=FindPath(root->left,expectNumber-val);
        vector<vector<int> > rightV=FindPath(root->right,expectNumber-val);
         
        //如果一个节点的左右子树中都不存在子路径，则该节点也不在问题的解中
        if(leftV.size()==0&&rightV.size()==0){
             //若该节点为叶子节点且此节点的值为expectNumber，则放入问题的解中
            if(root->left==NULL&&root->right==NULL&&root->val==expectNumber){
                vector<int> v;
                v.push_back(root->val);
                result.push_back(v);
            }
            return result;
        }else{

            leftV.insert(leftV.end(),rightV.begin(),rightV.end());
            for(int i=0;i<leftV.size();i++){
                leftV[i].insert(leftV[i].begin(),val);
            }
            return leftV;
        }     
         
    }
};