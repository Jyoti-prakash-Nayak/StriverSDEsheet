vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>res;
    stack<TreeNode*>st;
    TreeNode* curr=root;
    while(curr!=NULL || st.size()>0){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        res.push_back(curr->data);
        curr=curr->right;
    }
    return res;
}