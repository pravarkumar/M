#include <iostream>

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
                }
                else{
                    from=LEFT;
                    return;
                }


            case LEFT:
                if(curr->right){
                    curr=curr->right;
                    from=PARENT;
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
        }
        return;
    }
};