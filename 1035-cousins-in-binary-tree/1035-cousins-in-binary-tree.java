/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int xDepth,yDepth;
    TreeNode xParent,yParent;
    private void helper(TreeNode root,TreeNode parent, int level, int x, int y){
        if(root==null) return ;
        if(root.val==x){
            xDepth=level;
            xParent=parent;
        }
        if(root.val==y){
            yDepth=level;
            yParent=parent;
        }
        helper(root.left,root,level+1,x,y);
        helper(root.right,root,level+1,x,y);


    }
    public boolean isCousins(TreeNode root, int x, int y) {
        helper(root,null,0,x,y);
        return xDepth==yDepth && xParent!=yParent;
    }
}