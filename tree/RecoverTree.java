/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.  
 *
 *Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void recoverTree(TreeNode root) {
        Stack<TreeNode> stack=new Stack<TreeNode>();
        TreeNode pre=null,mNode=null,nNode=null;
        boolean first=true;
        while(true){
            while(root!=null){
                stack.push(root);
                root=root.left;
            }
            if(stack.isEmpty())break;
            
            TreeNode node=stack.pop();
            if(pre!=null&&node.val<pre.val){
                if(first){
                    mNode=pre;
                    first=false;
                }
                
                nNode=node;
            }
           
            pre=node;
            root=node.right;
        }
        
        //swap
        int tmp=mNode.val;
        mNode.val=nNode.val;
        nNode.val=tmp;
        
    }

}