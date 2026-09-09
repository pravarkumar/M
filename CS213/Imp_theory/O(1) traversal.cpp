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


//is there an even better way to do this like what if we want to reduce 
//the large no of calls to the step function this not helping the non recursion part much 
//we need to do soemhting about this 

//Imp Observation :
//remeber when i said what will we do if there is no left and no right child then its a problem so we used th eloop
//we actually would had come from node and like:
//if its the inorder case f the right child exists then grat we can just print the most left guy of the right subtree yusigna simple while loop
//on the other hand if right does not exist then we need to backtrack where we came from we need to keep goign t parent till we get 
//the situation that we were from left subtree then we can just print the guy who we are at otherwise great if we were from right subtree keep going up 

node* first_inoder(node* curr){
    while(curr->left){
        curr=curr->left;
    }
    return curr;
}


node* next_up(node* curr){
    while(curr->parent&&curr->parent->right==curr){
        curr=curr->parent;
    }
    return curr->parent;
}

node* inorder_next(node* curr){
    if(!curr){
        return nullptr;
    }

    if(curr->right){
        return first_inoder(curr->right);
    }
    else{
        return next_up(curr);
    }

}



node* preorder_next(node* curr){
    if(!curr){
        return nullptr;
    }

    if(curr->left){
        return curr->left;
    }

    if(curr->right){
        return curr->right;
    }

    while(curr->parent){
        if(curr == curr->parent->left && curr->parent->right){
            return curr->parent->right;
        }
        curr = curr->parent;
    }

    return nullptr;
}





node* first_postorder(node* curr){
    while(curr->left || curr->right){
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return curr;
}


node* postorder_next(node* curr){
    if(!curr){
        return nullptr;
    }

    while(curr->parent){
        if(curr->parent&&curr->parent->right==curr){
            return curr->parent;
        }
        if(curr->parent&&curr->parent->left==curr){
            if(curr->parent->right){
                return first_postorder(curr->parent->right);
            }
            return curr->parent;
        }
        curr=curr->parent;
    }
    return nullptr;
}


