/* 

-------------------------- CUSTOM DATA STRUCTURE - Queue -----------------------------
__ Created by https://github.com/bravTm

*/

#include <iostream>

using namespace std;


template <typename T>
class Node {
private:
public:
    Node * next;
    T value;
    

    Node(T value){
        this->next = NULL;
        this->value = value;
    }
};


template <typename T>
class Queue {
private:
    Node<T> * front_pointer;
    Node<T> * rear_pointer;
public:
    Queue(){
        this->front_pointer = NULL;
        this->rear_pointer = NULL;
    }


    void push(T value){
        Node<T> * newNode = new Node<T>(value);

        if (this->front_pointer == NULL && this->rear_pointer == NULL) {
            this->front_pointer = newNode;
            this->rear_pointer = newNode;
            return;
        }

        newNode->next = this->rear_pointer;
        this->rear_pointer = newNode;
    }


    T pop(){
        if (this->front_pointer == NULL) return -1;

        T value;

        for (Node<T> * item = this->rear_pointer; item != NULL; item = item->next){
            if(item->next != NULL) {
                if (item->next->next == NULL) {
                    value = item->next->value;
                    item->next = NULL;
                    this->front_pointer = item;
                    return value;
                }
            } 
        }

        return -1;
    }


    void print(){
        cout << "[";

        for(Node<T> * item = this->rear_pointer; item != NULL; item = item->next){
            cout << item->value;

            if (item->next != NULL) cout << ", ";
        }

        cout << "]";
    }
};



int main(void){
    Queue <int> q;

    q.push(40);
    q.push(30);
    q.push(20);
    q.push(10);

    q.print(); // [10, 20, 30, 40]

    q.pop();
    q.pop();

    q.print(); // [10, 20]

    return 0;
}
