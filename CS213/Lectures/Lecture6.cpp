# the only non trivial part is the stack block and its implementation like the linked list of stacks

#include <iostream>
#include <vector>

using namespace std;


struct StackBlock {
    const int capacity = 512;
    char stk[512];
    int top = -1;

    bool pop(char& x) {
        if (top < 0) {
            return false;
        }
        x=stk[top];
        top--;
        return true;
    }
    bool try_push(char x){
        if(top==capacity-1){
            return false;
        }
        stk[++top]=x;
        return true;
    }
    void clear(){
        top=-1;
        return;
    } 
    bool empty(){
        return top==-1;
    }
};

    //List of bounded stacks 
struct StackNode{
    StackBlock block;
    StackNode* below=nullptr;
};

struct StackList{
    StackNode* head=nullptr;
    bool empty(){
        return head==nullptr;
    }

    void push(char x){
        if(head==nullptr){
            head=new StackNode;
            head->block.try_push(x);
            return;
        }

        if(!head->block.try_push(x)){
            //we couldnt push in head as it was full
            StackNode* tmp=new StackNode;
            tmp->below=head;
            head=tmp;
            head->block.try_push(x);
        }
        return;
    }

    bool pop(char& x){
        if(head==nullptr){
            return false;
        }

        //we have atleast one element 
        head->block.pop(x);
        if(head->block.empty()){
            StackNode* tmp=head;
            head=head->below;
            delete(tmp);
        }
        return true;
    }
};




