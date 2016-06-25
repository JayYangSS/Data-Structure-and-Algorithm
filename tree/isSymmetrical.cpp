/*judge wetheir a tree is symetrical
*/


 bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot==NULL)return true;
    return isSame(pRoot->left,pRoot->right);
}
    

    
bool isSame(TreeNode* leftT,TreeNode* rightT){
    if(leftT!=NULL&&rightT!=NULL){
        if(isSame(leftT->left,rightT->right)&&isSame(leftT->right,rightT->left)&&(leftT->val==rightT->val))
            return true;
        else
            return false;
    }
    else if(leftT==NULL&&rightT==NULL)
        return true;
    else
        return false;
        
}