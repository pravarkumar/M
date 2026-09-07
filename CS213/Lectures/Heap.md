#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node* parent;;
    node* left;
    node* right;
};

void bubbleup(node* curr,int newval){
    //had only one choice 
    node* t=curr;
    while(t->parent&&t->parent->val>newval){
        t->val=t->parent->val;
        t=t->parent;
    }
    t->val=newval;
    return;
}


void bubbledown(node* curr,int newval){
    //we have 2 choices i want to take the lower one 
    if(!curr){
        return;
    }
    int smallest=newval;
    if(curr->left){
        smallest=min(smallest,curr->left->val);
    }
    if(curr->right){
        smallest=min(smallest,curr->right->val);
    }

    if(smallest==newval){
        //we at the right location 
        curr->val=smallest;
        return;
    }

    if(curr->left&&curr->left->val==smallest){
        //the left guy is the one 
        curr->val=curr->left->val;
        curr=curr->left;
        bubbledown(curr,newval);
    }
    else{
        //the right guy is the one
        curr->val=curr->right->val;
        curr=curr->right;
        bubbledown(curr,newval);
    }

}

void update(node* curr,int newval){
    if(curr->val>newval){
        //need to bubbleup
        bubbleup(curr,newval);
    }
    else if(curr->val<newval){
        //need to bubbledown
        bubbledown(curr,newval);
    }
    else{
        return;
    }
}


struct heap{
    vector<int> Keys;
    int Left(int i){
        if(2*i+1<Keys.size()){
            return 2*i+1;
        }
        return -1;
    }

    int Right(int i){
        if(2*i+2<Keys.size()){
            return 2*i+2;
        }
        return -1;
    }

    int Parent(int i){
        if(i>0){
            return (i-1)/2;
        }
        return -1;
    }

    void BubbleUp(int i,int new_key){
        while(Parent(i)!=-1&&Keys[Parent(i)]>new_key){
            i=(i-1)/2;
        }
        Keys[i]=new_key;
        return;
    }

    void BubbleDown(int i,int new_val){
        if(i==-1){
            return;
        }
        int smallest=Keys[i];
        if(Left(i)!=-1){
            smallest=min(smallest,Keys[Left(i)]);
        }

        if(Right(i)!=-1){
            smallest=min(smallest,Keys[Right(i)]);
        }
        
        if(smallest==new_val){
            Keys[i]=new_val;
            return;
        }

        if(Left(i)!=-1&&Keys[Left(i)]==smallest){
            Keys[i]=Keys[Left(i)];
            i=Left(i);
            BubbleDown(i,new_val);
        }

        else{
            Keys[i]=Keys[Right(i)];
            i=Right(i);
            BubbleDown(i,new_val);
        }
    }

};
