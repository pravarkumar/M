#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node* parent;
};


enum from_t{
    PARENT,LEFT,RIGHT
};

struct state{
    node* curr;
    from_t from;
    void step(){
        switch(from){
            case PARENT:
                //we have come from our parent we need to go to our left kid if the node exists 
                if(curr->left){
                    curr=curr->left;
                    from=PARENT;
                    return;
                }
                else{
                    from=LEFT;
                    return;
                }


            case LEFT:
                if(curr->right){
                    curr=curr->right;
                    from=PARENT;
                    return;
                }
                else{
                    from=RIGHT;
                    return;
                }

            case RIGHT:
                if(curr->parent){
                    if(curr->parent->left==curr){
                        from=LEFT;
                    }
                    else{
                        from=RIGHT;
                    }
                }
                curr=curr->parent;
                return;
        }
    }
};


void inorder_traversal(node* root){
    state s;
    s.curr=root;
    s.from=PARENT;
    for(s;s.curr;s.step()){
        if(s.from==LEFT){
            cout<<s.curr->val<<' ';
        }
    }
    return;
}


void preorder_traversal(node* root){
    state s;
    s.curr=root;
    s.from=PARENT;
    for(s;s.curr;s.step()){
        if(s.from==PARENT){
            cout<<s.curr->val<<' ';
        }
    }
    return;
}


void postorder_traversal(node* root){
    state s;
    s.curr=root;
    s.from=PARENT;
    for(s;s.curr;s.step()){
        if(s.from==RIGHT){
            cout<<s.curr->val<<' ';
        }
    }
    return;
}

node* next_preorder(node* current){
    state s={current,PARENT};
    if(!current){
        //this is just absurd like its not even a node how can I print the next one 
        return nullptr;
    }
    

    //wait hold up like why we looping wont the ans be just the left kid and if doesnt exist then the 
    //ans will be the right kid ohh we get it 
    //what if neither of them exist we may require to go a lot of levels above before printing 
    s.step();

    while(s.curr&&s.from!=PARENT){
        s.step();
    }

    //this is te next guy to be printed 

    return s.curr;
}


node* next_postorder(node* current){
    state s={current,RIGHT};
    if(!current){
        //this is just absurd like its not even a node how can I print the next one 
        return nullptr;
    }
    
    s.step();
    
    while(s.curr&&s.from!=RIGHT){
        s.step();
    }

    //this is te next guy to be printed 

    return s.curr;
}

node* next_inorder(node* current){
    state s={current,LEFT};
    if(!current){
        //this is just absurd like its not even a node how can I print the next one 
        return nullptr;
    }
    
    s.step();
    
    while(s.curr&&s.from!=LEFT){
        s.step();
    }

    //this is te next guy to be printed 

    return s.curr;
}
