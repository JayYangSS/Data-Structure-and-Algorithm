/*从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。 
*/

vector<vector<int> > Print(TreeNode* pRoot) {
    deque<pair<TreeNode*,int>> que;
    vector<vector<int>> result;
    int count=0;
            
    if(pRoot==NULL)return result;
    pair<TreeNode*,int> tmp=make_pair(pRoot,0);
    que.push_back(tmp);
            
    while(count<que.size()){
        TreeNode *p=que[count].first;
        int layer=que[count].second;
                
        if(p->left!=NULL){
            que.push_back(make_pair(p->left,layer+1));
        }
        if(p->right!=NULL){
            que.push_back(make_pair(p->right,layer+1));
        }
        count++;
    }
            
    int layer=0;
    int i=0;
			
    while(i<que.size()){
        vector<int> tmpContainer;
        while(layer==que[i].second){
            tmpContainer.push_back(que[i].first->val);
            i++;
        }
        result.push_back(tmpContainer);
        layer++;
    }
             
    return result;    
			
}