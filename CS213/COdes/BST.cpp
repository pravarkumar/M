#include <iostream>
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
    

};
