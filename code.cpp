
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* solve(TreeNode* root ,int A,int B)
 {
     if(root==NULL)
     {
         return root;
     }
      if(root->val==A || root->val==B)
      {
          return root;
      }
      TreeNode* lefti=solve(root->left,A,B);
     TreeNode* righty= solve(root->right,A,B);
      if(lefti!=righty && lefti!=NULL && righty!=NULL)
      {
          return root;
      }
      else if(lefti==NULL && righty!=NULL)
      {
          return righty;
      }
       else if(lefti!=NULL && righty==NULL)
      {
          return lefti;
      }
      
 }
 
int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode* curr=NULL;
    curr =solve(A,B,C);
    if(curr==NULL)
    {
        return -1;
    }
    if(curr->val==B)
    {
        stack<TreeNode*>s;
        s.push(A);
        int flag=0;
        
        while(!s.empty())
        {
            TreeNode* vali=s.top();
            s.pop();
            if((vali->val)==C)
            {
                flag=1;
                break;
            }
           
                if(vali->left!=NULL){
                s.push(vali->left);
                }
                if(vali->right!=NULL){
                s.push(vali->right);
                }
            
           
          //  s.pop();
        }
        if(flag==1)
        {
            return B;
        }
       
    }
     else  if(curr->val==C)
    {
        int flag=0;
        stack<TreeNode*>s;
        s.push(A);
        
        while(!s.empty())
        {
            TreeNode*vali=s.top();
           s.pop();
            if(vali->val==B)
            {
                flag=1;
                break;
            }
           
                if(vali->left!=NULL){
                s.push(vali->left);
                }
                if(vali->right!=NULL){
                s.push(vali->right);
                }
            
           
           // s.pop();
        }
        if(flag==1)
        {
            return C;
        }
       
    }
    else if(curr->val!=B && curr->val!=C)
    {
        return curr->val;
    }
    return -1;
}
