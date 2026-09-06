    vector<int> postorderTraversal(TreeNode* root) {
      stack<TreeNode*> st;
      vector<int> ans;

    TreeNode* curr = root;
    TreeNode* last = nullptr;

    while (curr || !st.empty()) {

        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();

        // If right subtree exists and hasn't been processed
        if (curr->right && last != curr->right) {
            curr = curr->right;
        }
        else {
            // Both subtrees are done
            ans.push_back(curr->val);
            last = curr;
            st.pop();
            curr = nullptr;
        }
    }

    return ans;
    }


    # post order traversal for a binary tree using a stack instead of a recursion 



    # inorder
    
    void stack_inorder(Node* root){
    stack<Node*> st;
    Node* curr=root;
    while(curr||!st.empty()){
        //we need to go to the left most and then come back print then go to right 
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->val<<' ';
        curr=curr->right;
        //we are at the left most pos now 
    }
    cout<<'\n';
        return;
    }


