#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int key; 
    node *parent=nullptr;
    node *left=nullptr;
    node *right=nullptr;
};

struct tree{
    node* root=nullptr;

    void insert(int v){
        if(root==nullptr){
            root=new node;
            root->key=v;
            return;
        }

        node* curr=root;
        node* prev=nullptr;
        while(curr){
            prev=curr;
            if(v<curr->key){
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
        if(v<prev->key){
            node* nw=new node;
            nw->key=v;
            nw->parent=prev;
            prev->left=nw;
        }
        else{
            node* nw=new node;
            nw->key=v;
            nw->parent=prev;
            prev->right=nw;
        }
        return;
    }

    node*& where(node* p){
        if(p==root){
            return root;
        }
        return p->parent->left==p?p->parent->left:p->parent->right;
    }

    node* minimum(node* p){
        node* curr=p;
        while(curr->left){
            curr=curr->left;
        }
        return curr;
    }

    void detach(node* p){
        node*& pp=where(p);
        if(!p->left||!p->right){
            pp=p->left?p->left:p->right;
            if(pp){
                pp->parent=p->parent;
            }
            return;
        }

        //both the kids are existing then we need to fidn the minimum
        node* q=minimum(p->right);
        detach(q);
        pp=q;
        p->left->parent=q;
        if(p->right){
            p->right->parent=q;
        }
        q->left=p->left;
        q->right=p->right;
        q->parent=p->parent;
        p->left=p->right=p->parent=nullptr;
    }

    void erase(node* p){
        if(p==nullptr){
            return;
        }
        detach(p);
        delete(p);
    }
};


enum from_t{
    PARENT,LEFT,RIGHT
};

struct state{
    node* p;
    from_t from;
    void step(){
        switch(from){
            case PARENT:
            //if we have come from parent 
            if(p->left){
                p=p->left;
                from=LEFT;//if we were to come back we will eb coming bakc from the left side
            }
            else{
                from=LEFT;
            }
            return;

            case LEFT:
            if(p->right){
                p=p->right;
                from=RIGHT;
            }
            else{
                from=RIGHT;
            }
            return;
            

            case RIGHT:
            from=(p->parent && p==p->parent->left)?LEFT:RIGHT;
            p=p->parent;
        }
    }

    void explore_inorder(node* root){
        for(state st={root,PARENT};st.p;st.step()){
            if(st.from==LEFT){
                cout<<st.p->key<<' ';
            }
        }
        return;
    }

    void explore_postorder(node* root){
        for(state st={root,PARENT};st.p;st.step()){
            if(st.from==RIGHT){
                cout<<st.p->key<<' ';
            }
        }
    }

    void explore_preorder(node* root){
        for(state st={root,PARENT};st.p;st.step()){
            if(st.from==PARENT){
                cout<<st.p->key<<' ';
            }
        }
    }

    node* next_inorder(node* p){
        if(p==nullptr){
            return nullptr;
        }
        
        //we we will pretend that the current p has alreayd been printed 
        state st={p,LEFT};
        //we prented to come after finsihign the left subtree we also printed ourself sow e need to get to the leftmost 
        //of the right subtree now 

        do st.step();
        while(st.p&&st.from!=LEFT);
            //basically till we dont revert back we will keep goign to more and more left 
        return st.p;
    }

    node* next_postorder(node* p){
        if(p==nullptr){
            return nullptr;
        }
        
        //we we will pretend that the current p has alreayd been printed 
        state st={p,RIGHT};
        //we prented to come after finsihign the left subtree we also printed ourself sow e need to get to the leftmost 
        //of the right subtree now 

        do st.step();
        while(st.p&&st.from!=RIGHT);
            //basically till we dont revert back we will keep goign to more and more left 
        return st.p;
    }

    node* next_preorder(node* p){
        if(p==nullptr){
            return nullptr;
        }
        
        //we we will pretend that the current p has alreayd been printed 
        state st={p,PARENT};
        //we prented to come after finsihign the left subtree we also printed ourself sow e need to get to the leftmost 
        //of the right subtree now 

        do st.step();
        while(st.p&&st.from!=PARENT);
            //basically till we dont revert back we will keep goign to more and more left 
        return st.p;
    }


    node* next_inorder(node* p){
        if(!p){
            return nullptr;
        }
        if(p->right){
            return first_inorder(p->right);
        }
        else{
            return next_up(p);
        }

    }
    
    node* first_inorder(node* p){
        while(p->left){
            p=p->left;
        }
        return p;
    }

    node* next_up(node* p){
        while(p->parent && p->parent->right==p){
            p=p->parent;
        }
        return p->parent;
    }

    node* next_preorder(node* p){
        if(!p){
            return nullptr;
        }
        if(p->left){
            return p->left;
        }
        if(p->right){
            return p->right;
        }
        while(p->parent&&p->parent->right){
            p=p->parent;
        }
        return p;
    }
    //obviously like a better way is for inorder print the minimum of the right subtree and if right doesnnot eist then print the 

    node* next_postorder(node* p){
        if(!p||!p->parent){
            return nullptr;
        }
        if(p==p->parent->left&&p->parent->right){
            return next_postorder(p->right);
        }
        else{
            return p->parent;
        }
    }

    node* next_postorder(node* p){
        while(p->left||p->right){
            if(p->left){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        return p;
    }

    node* makeBST(queue<int>&q ,node* parent=nullptr,int bound=INT_MAX){
        if(q.empty()||q.front()>=bound){
            return;
        }

        node* root=new node;
        root->key=q.front();
        q.pop();
        root->left=makeBST(q,root,root->key);
        root->right=makeBST(q,root,bound);
        return;
    }


};



node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    if (n == 0) return nullptr;

    stack<node*> st;

    node* root = new node;
    root->key = preorder[0];

    st.push(root);

    int j = 0;

    for (int i = 1; i < n; i++) {

        node* x = new node();
        x->key = preorder[i];

        node* parent = nullptr;

        while (!st.empty() && st.top()->key == inorder[j]) {
            parent = st.top();
            st.pop();
            j++;
        }

        if (parent) {
            parent->right = x;
            x->parent = parent;
        }
        else {
            st.top()->left = x;
            x->parent = st.top();
        }

        st.push(x);
    }

    return root;
}
