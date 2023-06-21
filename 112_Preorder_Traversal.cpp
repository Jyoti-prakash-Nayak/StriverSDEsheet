vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>res;
    if(root==NULL)
      return res;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
       TreeNode* node=st.top();
       st.pop();
       res.push_back(node->data);
       if(node->right!=NULL){
           st.push(node->right);
       }
       if(node->left!=NULL){
           st.push(node->left);
       }
    }
    return res;
}