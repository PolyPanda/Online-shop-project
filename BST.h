//
//  BST.hpp
//  lab 6
//
//  Created by Andie Yu on 5/20/17.
//  Copyright � 2017 Andie Yu. All rights reserved.
//
#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <iostream>
#include <assert.h>
#include "Shoe.h"

using namespace std;
template<typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* left;
        Node* right;
        
        Node(bstdata newdata):left(NULL), right(NULL), data(newdata) {}
    };
    
    typedef struct Node* NodePtr;
    
    NodePtr root;
    
    /**Private helper functions*/
    void insertData(NodePtr& root, bstdata value);
    void insertHelper(NodePtr root, bstdata value, bool(*compar)(bstdata, bstdata));
    //private helper function for insert
    //recursively inserts a value into the BST
    
    void inOrderPrint(ostream& out, NodePtr &root);
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest
    
    void preOrderPrint(ostream& out, NodePtr root);
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order
    
    void postOrderPrint(ostream& out, NodePtr root);
    //private helper function for postOrderPrint
    //recursively prints tree values in post order
    
    void makeCopy(NodePtr copy);
    //recursive helper function to the copy constructor
    
    void freeNode(NodePtr root);
    //private helper function for the destructor
    //recursively frees the memory in the BST
    
    bool search(NodePtr root, bstdata value);
    //recursive helper function to search
    //returns whether the value is found in the tree
    
    bstdata minimum(NodePtr root);
    //recursive helper function to minimum
    //returns the minimum value in the tree
    
    bstdata maximum(NodePtr root);
    //recursive helper function to maximum
    //returns the maximum value in the tree
    
    NodePtr deleteData(NodePtr root, bstdata value);
    //recursive helper function to removeData
    //removes value from the tree
    NodePtr removeHelper(NodePtr root, bstdata value, bool(*compar)(bstdata, bstdata));
    
    void size(NodePtr root, int& size);
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size
    
    int height(NodePtr root);
    //recursive helper function to the height function
    //returns the height of the tree
    bstdata findByPrimaryKeyHelper(Node* root, int primary);
    bstdata findBySecondaryKeyHelper(Node* root, string secondaryKey);
public:
    
    /**constructors and destructor*/
    
    BST();
    //Instantiates a new BST
    
    BST(const BST &bst);
    //copy constructor
    
    ~BST();
    //deallocates the tree memory
    
    /**access functions*/
    
    bstdata minimum();
    //returns the minimum value in the BST
    //pre: !empty()
    
    bstdata maximum();
    //returns the maximum value in the BST and returns it
    //pre: !empty()
    
    bool empty() const;
    //determines whether the BST is empty
    
    int size();
    //returns the size of the tree
    
    bstdata getRoot();
    //returns the value stored at the root of the BST
    //pre: !empty()
    
    int height();
    //returns the height of the tree
    
    bool search(bstdata value);
    //returns whether the value is found in the tree
    //pre: !empty()
    
    /**manipulation procedures*/
    
    void insertData(bstdata value);
    //inserts a new value into the BST
    
    void removeData(bstdata value);
    //removes the specified value from the tree
    //pre: value is located in the tree
    
    /**additional functions*/
    
    void inOrderPrint(ostream& out);
    //calls the inOrderPrint function to print out the values
    //stored in the BST
    
    void preOrderPrint(ostream& out);
    //calls the reOrderPrint function to print out the values
    //stored in the BST
    
    void postOrderPrint(ostream& out);
    //calls the postOrderPrint function to print out the values
    //stored in the BST
    
    bstdata findByPrimaryKey(int primary);
    bstdata findBySecondaryKey(string secondaryKey);
    void insert(bstdata value, bool(*compar)(bstdata, bstdata));
    void remove(bstdata value, bool(*compar)(bstdata, bstdata));
};
template<typename bstdata>
BST<bstdata>::BST()
{
    root = NULL;
}

template<typename bstdata>
BST<bstdata>::BST(const BST &bst)
{
    if(bst.root == NULL)
    {
        root = NULL;
    }
    else{
        root = new Node(bst.root->data);
        makeCopy(bst.root);
    }
}

template<typename bstdata>
void BST<bstdata>::makeCopy(NodePtr copy)
{
    if(copy != NULL)
    {
        insertData(root, copy->data);
        makeCopy(copy->left);
        makeCopy(copy->right);
    }
}

template<typename bstdata>
BST<bstdata>::~BST()
{
    freeNode(root);
}

template<typename bstdata>
void BST<bstdata>:: freeNode(NodePtr root)
{
    if(root != NULL)
    {
        freeNode(root->left);
        freeNode(root->right);
        delete root;
    }
}

template<typename bstdata>
bool BST<bstdata>::empty() const
{
    return root == NULL;
}

template<typename bstdata>
void BST<bstdata>::insertData(bstdata value)
{
    insertData(root, value);
}

template<typename bstdata>
void BST<bstdata>::insertData(NodePtr& root, bstdata value)
{
    if(root == NULL)
    {
        root = new Node(value);
        root->left = NULL;
        root->right = NULL;
    }
    else if(value < root->data)
    {
        if(root->left!=NULL)
            insertData(root->left, value);
        else
        {
            root->left=new Node(value);
            root->left->data=value;
            root->left->left=NULL;
            root->left->right=NULL;
        }
    }
    else
    {
        if(root->right!=NULL)
            insertData(root->right, value);
        else
        {
            root->right=new Node(value);
            root->right->data=value;
            root->right->left=NULL;
            root->right->right=NULL;
        }
    }
}

template<typename bstdata>
void BST<bstdata>::removeData(bstdata value)
{
    deleteData(root,value);
}

template<typename bstdata>
typename BST<bstdata>::NodePtr BST<bstdata>::deleteData(NodePtr root, bstdata value)
{
    if (root == NULL)
    {
        return root;
    }
    else if(value < root->data)
    {
        root->left = deleteData(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = deleteData(root->right, value);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->right == NULL)
        {
            root = root->left;
            deleteData(root, value);
        }
        else if (root->left == NULL)
        {
            root = root->right;
            deleteData(root,value);
        }
        else
        {
            bstdata min = minimum(root->right);
            root->data = min;
            root->right = deleteData(root->right, min);
        }
    }
    return root;
}


template<typename bstdata>
void BST<bstdata>:: inOrderPrint(ostream& out)
{
    inOrderPrint(out, root);
}

template<typename bstdata>
void BST<bstdata>:: inOrderPrint(ostream& out, NodePtr &root)
{
    if(root == NULL)
    {
        return;
    }
    inOrderPrint(out,root->left);
    Shoe *shoe1 = root->data;
    out<< *shoe1<<" "<<endl;
    inOrderPrint(out,root->right);
}

template<typename bstdata>
void BST<bstdata>:: preOrderPrint(ostream& out)
{
    preOrderPrint(out,root);
}

template<typename bstdata>
void BST<bstdata>:: preOrderPrint(ostream& out, NodePtr root)
{
    if(root == NULL)
    {
        return;
    }
    Shoe *shoe1 = root->data;
    cout<< *shoe1<<""<<endl;
    cout<<endl;
    preOrderPrint(cout,root->left);
    preOrderPrint(cout,root->right);
}

template<typename bstdata>
void BST<bstdata>:: postOrderPrint(ostream& out)
{
    postOrderPrint(out,root);
}

template<typename bstdata>
void BST<bstdata>:: postOrderPrint(ostream& out, NodePtr root)
{
    if(root == NULL)
    {
        return;
    }
    postOrderPrint(cout,root->left);
    postOrderPrint(cout,root->right);
    Shoe *shoe1 = root->data;
    cout<< *shoe1<<""<<endl;
    cout<<endl;
}

template<typename bstdata>
bstdata BST <bstdata>::maximum()
{
    return maximum(root);
}

template<typename bstdata>
bstdata BST <bstdata>::maximum(NodePtr root)
{
    if(root->right != NULL)
    {
        return maximum(root->right);
    }
    else
        return root->data;
}

template<typename bstdata>
bstdata BST <bstdata>::minimum()
{
    return minimum(root);
}

template<typename bstdata>
bstdata BST <bstdata>::minimum(NodePtr root)
{
    if(root->left != NULL)
    {
        return minimum(root->left);
    }
    else
        return root->data;
}

template<typename bstdata>
int BST<bstdata>:: size()
{
    int size = 0;
    this->size(root, size);
    return size;
}

template<typename bstdata>
void BST<bstdata>:: size(NodePtr root, int& size)
{
    if(root != NULL)
    {
        size++;
        this->size(root->left, size);
        this->size(root->right, size);
    }
}

template<typename bstdata>
bstdata BST<bstdata>:: getRoot()
{
    assert(!empty());
    return root->data;
}

template<typename bstdata>
bool BST<bstdata> :: search(bstdata value)
{
    return search(root,value);
}

template<typename bstdata>
bool BST<bstdata> :: search(NodePtr root, bstdata value)
{
    if(root == NULL)
    {
        return false;
    }
    if(value == root->data)
    {
        return true;
    }
    else if(value < root->data)
    {
        return search(root->left,value);
    }
    else if(value > root->data)
    {
        return search(root->right,value);
    }
    else
    {
        return false;
    }
    return false;
}

template<typename bstdata>
int BST<bstdata>:: height()
{
    return height(root);
}

template<typename bstdata>
int BST<bstdata>:: height(NodePtr root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int lheight = height(root->left) + 1;
        int rheight = height(root->right) + 1;
        if(lheight > rheight)
        {
            return lheight;
        }
        else
        {
            return rheight;
        }
    }
}

template <class bstdata>
bstdata BST<bstdata>::findByPrimaryKey(int primaryKey) {
    assert(root != NULL);
    return findByPrimaryKeyHelper(root, primaryKey);
}

template <class bstdata>
bstdata BST<bstdata>::findByPrimaryKeyHelper(Node* root, int primaryKey) {
    if (root->data->getPrimaryKey() == primaryKey)
        return root->data;
    else if (primaryKey < root->data->getPrimaryKey()) {
        if (root->left == NULL)
            return NULL;
        else
            return findByPrimaryKeyHelper(root->left, primaryKey);
    }
    else if (primaryKey > root->data->getPrimaryKey()) {
        if (root->right == NULL)
            return NULL;
        else
            return findByPrimaryKeyHelper(root->right, primaryKey);
    }
    else
        return NULL;
}

template <class bstdata>
bstdata BST<bstdata>::findBySecondaryKey(string secondaryKey) {
    assert(root != NULL);
    return findBySecondaryKeyHelper(root, secondaryKey);
}

template <class bstdata>
bstdata BST<bstdata>::findBySecondaryKeyHelper(Node* root, string secondaryKey) {
    if (root->data->getSecondaryKey() == secondaryKey)
        return root->data;
    else if (secondaryKey < root->data->getSecondaryKey()) {
        if (root->left == NULL)
            return NULL;
        else
            return findBySecondaryKeyHelper(root->left, secondaryKey);
    }
    else if (secondaryKey > root->data->getSecondaryKey()) {
        if (root->right == NULL)
            return NULL;
        else
            return findBySecondaryKeyHelper(root->right, secondaryKey);
    }
    else
        return NULL;
}

template <class bstdata>
void BST<bstdata>::insert(bstdata value, bool(*compar)(bstdata, bstdata)) {
    if (root == NULL)
        root = new Node(value);
    else
        insertHelper(root, value, compar);
}

template <class bstdata>
void BST<bstdata>::remove(bstdata value, bool(*compar)(bstdata, bstdata)) {
    root = removeHelper(root, value, compar);
}

template <class bstdata>
typename BST<bstdata>::NodePtr
BST<bstdata>::removeHelper(NodePtr root, bstdata value, bool(*compar)(bstdata, bstdata)) {
    
    if (root == NULL)
        return root;
    else if (compar(value, root->data))
        root->left = removeHelper(root->left, value, compar);
    else if(value == root->data){
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            root = temp;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            root = temp;
        }
        else {
            root->data = minimum(root->right);
            root->right = removeHelper(root->right, minimum(root->right), compar);
        }
    } else
        root->right = removeHelper(root->right, value, compar);
    return root;
}

template <class bstdata>
void BST<bstdata>::insertHelper(Node* root, bstdata value, bool(*compar)(bstdata, bstdata)) {
    if (value == root->data)
        return;
    if (compar(value, root->data)) {
        if (root->left == NULL)
            root->left = new Node(value);
        else
            insertHelper(root->left, value, compar);
    } else {
        if (root->right == NULL)
            root->right = new Node(value);
        else
            insertHelper(root->right, value, compar);
    }
}


#endif /* BST_H_ */
