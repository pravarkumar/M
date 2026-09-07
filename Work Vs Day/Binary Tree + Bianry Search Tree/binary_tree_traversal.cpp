#include<iostream>
#include<vector>
#include <stack>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;
};

void inorder_traversal(Node* root){
    if(root==nullptr){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->val<<" ";
    inorder_traversal(root->right);
    return;
}


void preorder_traversal(Node* root){
    if(root==nullptr){
        return;
    }

    cout<<root->val<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    return;
}

void postorder_traversal(Node* root){
    if(root==nullptr){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->val<<" ";
    return;
}

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


void stack_postorder(Node* root){
    stack<Node*>st;
    Node* curr=root;
    Node* lastVisited = nullptr;
    while(!st.empty()||curr){
    while(curr){
        st.push(curr);
        curr=curr->left;
    }
    if(!st.empty() && st.top()->right == nullptr){
            // no right subtree → left + right are done
            curr=st.top();
            cout<<curr->val<<' ';
            lastVisited=curr;
            st.pop();
    }

    
    if(!st.empty()&&lastVisited==st.top()->left){
        //we have coverd left subtree now
        curr=st.top();
        curr=curr->right;
    }
    else if(!st.empty()&&lastVisited==st.top()->right){
        //we need to still myself  
        curr=st.top();
        cout<<curr->val<<' ';
        lastVisited=curr;
        st.pop();
    }
}
}

int main(){
    int n;
    cin>>n;
    return 0;
}