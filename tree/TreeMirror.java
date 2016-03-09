/*
*get the mirror of a binary tree
*/


class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
 
    public TreeNode(int val) {
        this.val = val;
 
    }
 
}
 
public class TreeMirror {
    public void Mirror(TreeNode root) {
        if(root==null)
            return;
        //swap
        if(root.left==null&&root.right==null)
            return;
         
        TreeNode temp=root.left;
        root.left=root.right;
        root.right=temp;
         
        Mirror(root.left);
        Mirror(root.right);
    }
}