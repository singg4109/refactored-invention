#include "BST.h"
#include <iostream>

using namespace std;

template <typename T>
BST<T>::BST(){
    //cout << "default constructor" << endl;
}

template <typename T>
BST<T>::BST(BST&& other){
    this->root = other.root;
    other.root = nullptr;
}
template <typename T>
BST<T>::BST(const BST& other): root(other.data, other.key, other.left, other.right){
    //cout << "Copy Constructor" << endl;
}

template <typename T>
BST<T>::~BST(){
    // cout << "Destructor" << endl;
    delete root;
}

template <typename T>
bool BST<T>::is_empty() const {
    return (this->root == nullptr);
}

template <typename T>
bool BST<T>::contains(int key) const {
    // base case
    if(is_empty()){
        return false;
    }

    if(this->root->key == key){
        return true;
    }

    // recursive case
    if(this->root->key < key){
        return this->root->right.contains(key);
    }
    else
    {
        return this->root->left.contains(key);
    }
}

template <typename T>
const T* BST<T>::get(int key) const {
    // base case
    if(is_empty()){
        return nullptr;
    }

    if(this->root->key == key){
        return &(this->root->data);
    }

    // recursive case
    if(this->root->key < key){
        return this->root->right.get(key);
    }
    else
    {
        return this->root->left.get(key);
    }
}

template <typename T>
const T& BST<T>::find_max(int& x) const {
    const BSTnode* p = this->root;

    while(p->right.is_empty() == false){
        p = p->right.root;
    }

    x = p->key;
    return p->data;
}

template <typename T>
const T& BST<T>::find_min(int &x) const {
    const BSTnode* p = this->root;

    while(p->left.is_empty() == false){
        p = p->left.root;
    }

    x = p->key;
    return p->data;
}

template <typename T>
bool BST<T>::insert(const T& data, int key){
    // base case
    if(is_empty()){
        this->root = new BSTnode(data, key);
        return true;
    }

    if(this->root->key == key){
        return false;
    }

    // recursive case
    if(this->root->key < key){
        return this->root->right.insert(data, key);
    }
    else
    {
        return this->root->left.insert(data, key);
    }
}
/*
template <typename T>
T& BST<T>::remove(int key){
   
    // 
    if(this->root->key == key){
        // case 1: a leaf and no child
        if(this->root->left.is_empty() && this->root->right.is_empty()){
            T* temp = &(this->root->data);
            delete this->root;
            return *temp;
        }
        // case 2: single child
        BST<double>* left_child = this->root->left;
        BST<double>* right_child = this->root->right; 

        // contain right child only
        if(left_child->is_empty() && (right_child->is_empty() == false)){
            T* temp = &(this->root->data);
            this->root->data = right_child->root->data;
            this->root->key = right_child->root->key;
            this->root->left = right_child->root->left;
            this->root->right = right_child->root->right;
            delete right_child->root;
            return *temp;
        }
        // contain left child only
        else if((left_child->is_empty() == false) && right_child->is_empty())
        {
            T* temp = &(this->root->data);
            this->root->data = left_child->root->data;
            this->root->key = left_child->root->key;
            this->root->left = left_child->root->left;
            this->root->right = left_child->root->right;
            delete left_child->root;
            return *temp;
        }
        // contain two childs, find a smallest node in right subtree and replace to removed node
        else if(left_child->is_empty() == right_child->is_empty() == true){
            T* temp = &(this->root->data);
            BSTnode* min_node = find_min(); // it never be a nullptr
            this->root->data = min_node->data;
            this->root->key = min_node->key;
            this->root->left = min_node->left;
            this->root->right = min_node->right;
            delete min_node;
            return *temp;
        }

        // recursive case
        if(this->key < key){
            return this->root->right.remove(key);
        }
        else
        {
            return this->root->left.remove(key);
        }
    }
}
*/

template <typename T>
bool BST<T>::remove(int key){

    // if no node is matched to input key
    if(is_empty()){
        return false;
    }

    // assume replace with min data in right sub-tree
    if(key < root->key){
        root->left.remove(key);
    } 
    else if(key > root->key) {
        root->right.remove(key);
    } 
    else if(root->left.root && root->right.root){
        // replace with the assumption
        int x;
        root->data = root->right.find_min(x);
        root->key = x;

        // remove
        root->right.remove(root->data);
        return true;

    }
    else {
        // set a pointer for deletion
        BSTnode *deleted_node = root;
        // redirect the child to be a root
        root = (root->left.is_empty())? root->right.root: root->left.root;
        // set the left and right child of the deleted node to nullptr
        deleted_node->left.root = nullptr;
        deleted_node->right.root = nullptr;
        delete deleted_node;
        return true;
    }

    return false;
}

template <typename T>
void BST<T>::print(int depth) const {
    // base case:
    if(is_empty()){
        return;
    }    

    // print with rotating 90 degrees
    // travel to right first
    root->right.print( depth + 1);

    // remark: In runtime, this should be loop to max depth first, i < 3 then i < 2
    for(int i = 0; i < depth; i++){
        cout << "\t";
    }

    cout << root->data << endl;

    // travel to left
    root->left.print( depth + 1);
}

template <typename T>
void BST<T>::travel_in_order(){
    if(is_empty()){
        return;
    }

    // travel to left -> current -> right
    this->root->left.travel_in_order();
    cout << this->root->key << " ";
    this->root->right.travel_in_order();
}

template <typename T>
void BST<T>::travel_post_order(){
    if(is_empty()){
        return;
    }
    
    // travel to left -> right -> current
    this->root->left.travel_post_order();
    this->root->right.travel_post_order();
    cout << this->root->key << " ";

}

template <typename T>
void BST<T>::travel_pre_order(){
    if(is_empty()){
        return;
    }

    // travel to current -> left -> right
    cout << this->root->key << " ";
    this->root->left.travel_pre_order();
    this->root->right.travel_pre_order();


    
}

