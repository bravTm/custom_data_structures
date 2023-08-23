/* 

-------------------------- CUSTOM DATA STRUCTURE - Singly Linked Array -----------------------------
__ Created by https://github.com/bravTm

*/

#include <iostream>
#include <chrono>

using namespace std;


class Node {
public:
    int value; // can use any type
    Node * next;

    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};


class SLinkedArray { // S = Singly
private:
    Node* findPosition(int index){
        int i = 0;

        for(Node * item = head; item != NULL; item = item->next){
            if(index == -1){
                if(item->next->next == NULL) return item;
                continue;
            }

            if(i == index - 1) return item;
            i++;
        }
        // index - 1 = previous element before insert(it's a singly linked array and there is only one link(to the next one))
        // INSERT: For example index = 2,          1, [2] - we find, insert, 3, 4, 5, 6

        return NULL;
    }
public:
    Node * head;
    Node * tail;

    SLinkedArray(){
        this->head = NULL;
        this->tail = NULL;
    }

    ~SLinkedArray(){}


    void push_front(int value){
        Node * newItem = new Node(value);
        if(!head) {
            head = newItem;
            tail = newItem;
            return;
        }

        newItem->next = head;
        head = newItem;
    }

    void push_back(int value){
        Node * newItem = new Node(value);

        if(!tail){
            head = newItem;
            tail = newItem;
            return;
        }   

        tail->next = newItem;
        tail = newItem;
    }

    void insert(int index, int value){
        if(index <= 0) return push_front(value);

        Node * node = findPosition(index);

        if(!node) return push_back(value);

        Node * newItem = new Node(value);

        newItem->next = node->next;
        node->next = newItem;
    }

    void pop_front(){
        if(!head) return;

        Node * node = head;
        head = node->next;

        delete node;
    }

    void pop_back(){
        if(!tail) return;

        Node * node = findPosition(-1);
        delete tail;
        node->next = NULL;
        tail = node;
    }

    void erase(int index){
        if(index <= 0) return pop_front();

        Node * node = findPosition(index);
        Node * tmp = node->next;
        node->next = node->next->next;

        delete tmp;
    }


    int find(int index){
        int i = 0;
        for(Node * item = head; item != NULL; item = item->next){
            if(i == index) return item->value;

            i++;
        }

        return -1;
    }


    void display(){
        cout << "[";
        for(Node * item = head; item != NULL; item = item->next){
            cout << item->value;

            if(item->next != NULL) cout << ", "; 
        }
        cout << "]" << endl;
    }

};



int main(){
    SLinkedArray array;

    array.push_front(20);
    array.push_back(30);
    array.push_back(40);
    array.push_front(50);

    cout << array.find(2) << endl;

    array.display(); // [50, 20, 30, 40]

    array.pop_back();
    array.pop_front();

    array.display(); // [20, 30]

    return 0;
}