#include <iostream>
#include <string>

using namespace std;

// CUSTOM DATA STRUCTURE - Binary Tree   ---------------------------------------------------------------

class TreeNode {
public:
    int value;
    TreeNode * left_child;
    TreeNode * right_child;

    TreeNode(int value){
        this->value = value;
        left_child = NULL;
        right_child = NULL;
    }
};

class BinaryTree {
private:
    TreeNode* findPlaceToInsert(int value){
        TreeNode * item = root;
        TreeNode * place_to_insert = NULL;

        while(item != NULL){
            place_to_insert = item;
            if(item->value >= value) item = item->left_child;
            else item = item->right_child;
        }

        return place_to_insert;
    }
    
public:
    TreeNode * root;

    BinaryTree(){
        this->root = NULL;
    }

    void insert(int value){
        TreeNode * ptr = new TreeNode(value);

        if(root == NULL){
            root = ptr;
            return;
        }

        TreeNode * place_to_insert = findPlaceToInsert(value);

        if(place_to_insert->value >= value) place_to_insert->left_child = ptr;
        else place_to_insert->right_child = ptr;
    }


    void print(TreeNode * node){
        if (!node) return;
        if (node->right_child)
            print(node->right_child);

        cout << to_string(node->value) << std::endl;

        if (node->left_child)
            print(node->left_child);        
    }
};


int main(){
    BinaryTree tree; 

    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(23);
    tree.insert(15);
    tree.insert(17);


    tree.print(tree.root);

    return 0;
}