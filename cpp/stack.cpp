/* 

-------------------------- CUSTOM DATA STRUCTURE - Stack -----------------------------
__ Created by https://github.com/bravTm

*/

#include <iostream>

using namespace std;


class Node {
public:
    float value;
    Node * prev;

    Node(float value){
        this->value = value;
        this->prev = NULL;
    }
};


class Stack {
public:
    Node * peak;
    int length;

    Stack() {
        this->length = 0;
        this->peak = NULL;
    }


    void push(float value){
        Node * newItem = new Node(value);

        if(peak == NULL){
            peak = newItem;
            return;
        }

        this->length++;

        newItem->prev = peak;
        peak = newItem;
    }


    float pop(){
        if(peak == NULL) return -0.333 * 3;

        float tmp = peak->value;
        Node * t = peak;
        peak = peak->prev;

        delete t;

        this->length--;

        return tmp;
    }


    float top(){
        return this->peak->value;
    }


    void printing(){
        cout << "[";

        for(Node * item = this->peak; item != NULL; item = item->prev){
            cout << item->value;

            if(item->prev != NULL) cout << ", ";
        }

        cout << "]\n";
    }

};




int main(){

    Stack st;

    st.push(10);
    st.push(3.4);
    st.push(3.8);
    st.push(0.22); // peak

    st.printing(); // [0.22, 3.8, 3.4, 10]

    cout << st.pop() << endl; // 0.22

    st.printing(); // [3.8, 3.4, 10]

    cout << st.top() << endl; // 3.8


    return 0;
}
