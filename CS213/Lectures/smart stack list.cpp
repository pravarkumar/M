struct StackList{
    StackNode* head=nullptr;
    int sz=0;
    bool empty(){
        return sz==0;
    }

    void push(char x){
        if(head==nullptr){
            head=new StackNode;
            head->block.try_push(x);
            sz++;
            return;
        }

        if(!head->block.try_push(x)){
            //we couldnt push in head as it was full
            StackNode* tmp=new StackNode;
            tmp->below=head;
            head=tmp;
            head->block.try_push(x);
        }
        sz++;
        return;
    }

    bool pop(char& x){
        if(sz==0){
            return false;
        }
        //we have atleast one element
        if(!head->block.empty()){
            head->block.pop(x);
        }
        else if(!head->below){
            head->block.pop(x);
        } 
        else if(head->below&&head->below->block.top==0){
            //we need to remove the lower block
            head=head->below;
            head->block.pop(x);
        }
        else{
            head->below->block.pop(x);
        }

        sz--;
        return true;
    }
};

