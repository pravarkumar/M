<img width="664" height="108" alt="Screenshot 2026-09-10 at 8 28 59 PM" src="https://github.com/user-attachments/assets/5d26e6c4-10af-484f-a714-b8f25c0043c8" />

Stack size can be any of N+1 values (0 through N), but the gap between
top and bot can be only one of N values (0 through N-1)
• Will use a flag to distinguish between two cases (zero or one item)


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


case 1 ) top==bottom and we have 0 elemnts -> is_empty=false;
case 2 ) top==bottom and we have 1 element -> is_empty=true;
case 3 ) top==bottom and we have n elements -> is_empty=false (we will force bot also to move forward so technically the situation of top==bottom was about to arise but never really arises)

