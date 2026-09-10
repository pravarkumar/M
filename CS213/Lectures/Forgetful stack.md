<img width="646" height="111" alt="Screenshot 2026-09-10 at 8 05 23 PM" src="https://github.com/user-attachments/assets/c081cdbe-db33-4fb4-a632-d4ed3843175a" />


# write the capacity as a global variable if its a constant as otherwise array wont get size it will get error if the 
capacity is declared inside the struct itself

Stackring also technically has predetermined capacity 

#include <iostream>
#include <vector>

using namespace std;

const int N=512;
struct Forgetful_Stack{
    char array[N];
    int top=0;
    int bot=0;
    bool is_empty=false;

    void inc(int& i){
        if(i==N-1){
            i=0;
        }
        else{
            i=i+1;
        }
        return;
    }

    void dec(int& i){
        if(i==0){
            i=N-1;
        }
        else{
            i=i-1;
        }
        return;
    }

    void push(char& x){
        if(is_empty){
            is_empty=false;
        }
        else{
            inc(top);
            if(top==bot){
                inc(bot);
            }
        }
        array[top]=x;
    }

    bool pop(char& x){
        if(is_empty){
            return false;
        }
        x=array[top];
        if(top==bot){
            is_empty=true;
        }
        else{
            dec(top);
        }
        
    }
};
