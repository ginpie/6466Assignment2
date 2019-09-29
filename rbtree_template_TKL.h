#ifndef _RBTREE_H_
#define _RBTREE_H_

#include<iostream>
#include<fstream>
#include <vector>
using namespace std;

enum Color{RED, BLACK};

template <class T,class K, class L>
class Node{
public:
    Color color;//color
    T key;      //key
    K value;    //value
    L maxValue; // max value
    Node *parent;   //parent
    Node *left;     //left child
    Node *right;    //right child

    //initialization
    Node(T k, K v, L m, Color c, Node *p, Node *l, Node *r):
            key(k),value(v), maxValue(m),color(c),parent(p),left(l),right(r){}
};

template <class T,class K, class L>
class RBTree {
public:
    RBTree();
    ~RBTree();
    //pre-order visit the RBT
    void preOrder();
    //in-order visit the RBT
    void inOrder();
    //postorder visit the RBT
    void postOrder();
    //search by key
    Node<T,K,L>* search(T key);
    //find minimum key value
    T minimum();
    //find maximum key value
    T maximum();
    //find the successor, which is the smallest key value that greater than the current key value of the node
    Node<T,K,L>* successor(Node<T,K,L>* x);
    //find the predecessor, which is the largest key value that less than the current key value of the node
    Node<T,K,L>* predecessor(Node<T,K,L>* x);
    //insert a node (base on key value) into RBT
    void insert(T key, K value, L maxValue);
    //delete a node (base on key value) from RBT
    void remove(T key);
    //destory the RBT
    void destroy();
    //print the RBT
    void print();
    // get root
    Node<T,K,L>* root();
protected:
    Node<T,K,L> *rbRoot;//root
    //pre-order visit the RBT
    void preOrder(Node<T,K,L>* tree);
    //in-order visit the RBT
    void inOrder(Node<T,K,L>* tree);
    //postorder visit the RBT
    void postOrder(Node<T,K,L>* tree);
    //search by key
    Node<T,K,L>* search(Node<T,K,L>* x, T key);
    //find minimum key value
    Node<T,K,L>* minimum(Node<T,K,L>* tree);
    //find maximum key value
    Node<T,K,L>* maximum(Node<T,K,L>* tree);
    //left rotate
    void leftRotate(Node<T,K,L>* &root, Node<T,K,L>* x);
    //right rotate
    void rightRotate(Node<T,K,L>* &root, Node<T,K,L>* y);
    //insert a node into the RBT
    void insert(Node<T,K,L>* &root, Node<T,K,L>* node);
    //fix the violation after insertion
    void insertFixUp(Node<T,K,L>* &root, Node<T,K,L>* node);
    //delete a node from the RBT
    void remove(Node<T,K,L>* &root, Node<T,K,L>* node);
    //fix the violation after deletion
    void removeFixUp(Node<T,K,L>* &root, Node<T,K,L>* node, Node<T,K,L>* parent);
    //destructor function
    void destroy(Node<T,K,L>* &tree);
    //print out the RBT
    void print(Node<T,K,L>* tree, T key, int direction);
};

struct TimeInterval{
    int t1;//start time index
    int t2;//end time index
};

struct Attribute{
    int value;
    int maxValue;
    int lec [];
};

/*
 * constructor
 */
template <class T,class K, class L>
RBTree<T,K,L>::RBTree():rbRoot(NULL){
    rbRoot = NULL;
}

/*
 * destructor
 */
template <class T,class K, class L>
RBTree<T,K,L>::~RBTree(){
    destroy();
}

/*
 * pre-order
 */
template <class T,class K, class L>
void RBTree<T,K,L>::preOrder(Node<T,K,L>* tree){
    if (tree!=NULL){
        std::cout<<tree->key<<" " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T,class K,class L>
void RBTree<T,K,L>::preOrder(){
    preOrder(rbRoot);
}

/*
 * in-order
 */
template <class T,class K,class L>
void RBTree<T,K,L>::inOrder(Node<T,K,L>* tree){
    if (tree!=NULL){
        inOrder(tree->left);
        std::cout<<tree->key<<" " ;
        inOrder(tree->right);
    }
}

template <class T,class K,class L>
void RBTree<T,K,L>::inOrder(){
    inOrder(rbRoot);
}

/*
 * post-order
 */
template <class T,class K,class L>
void RBTree<T,K,L>::postOrder(Node<T,K,L>* tree){
    if (tree!=NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        std::cout<<tree->key<<" ";
    }
}

template <class T,class K,class L>
void RBTree<T,K,L>::postOrder(){
    postOrder(rbRoot);
}

/*
 * search the node with key value
 */
template <class T,class K,class L>
Node<T,K,L>* RBTree<T,K,L>::search(Node<T,K,L>* x, T key){
    if ((x==NULL) || (x->key==key))
        return x;
    if (key<x->key) {
        return search(x->left,key);
    } else {
        return search(x->right,key);
    }
}

template <class T,class K,class L>
Node<T,K,L>* RBTree<T,K,L>::search(T key){
    return search(rbRoot, key);
}

/*
 * find minimum key value
 */
template <class T,class K,class L>
Node<T,K,L>* RBTree<T,K,L>::minimum(Node<T,K,L>* tree){
    if (tree==NULL)
        return NULL;
    while (tree->left!=NULL)
        tree=tree->left;
    return tree;
}

template <class T,class K,class L>
T RBTree<T,K,L>::minimum(){
    Node<T,K,L> *p = minimum(rbRoot);
    if (p!=NULL)
        return p->key;
    return (T)NULL;
}

/*
 * find maximum key value
 */
template <class T,class K,class L>
Node<T,K,L>* RBTree<T,K,L>::maximum(Node<T,K,L>* tree){
    if (tree==NULL)
        return NULL;
    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T,class K,class L>
T RBTree<T,K,L>::maximum(){
    Node<T,K,L> *p = maximum(rbRoot);
    if (p!=NULL)
        return p->key;
    return (T)NULL;
}

/*
 * fix up the violation of RB Tree property after insertion
 */
template <class T,class K,class L>
void RBTree<T,K,L>::insertFixUp(Node<T,K,L>* &root, Node<T,K,L> *node){
    // case 0: parent is black
    while(node->parent!=NULL && node->parent->color==RED) {  // if parent is red
        // 1st half, if parent is left child of grandparent
        if(node->parent->parent->left==node->parent) {          // if inserted node is the left child of its parent
            Node<T,K,L> *uncle=node->parent->parent->right;       // set uncle node
            if(uncle->color==RED) {                             //case 1: uncle is red
                node->parent->parent->color=RED;
                uncle->color=BLACK;
                node->parent->color=BLACK;
                node=node->parent->parent;
            } else {
                if(node == node->parent->right)    //case 2: node is black, and right child of parent, -> node left rotate
                {
                    node=node->parent;
                    leftRotate(root,node);
                }
                node->parent->parent->color=RED;     //case 3: node is black, and left child of parent
                node->parent->color=BLACK;
                rightRotate(root,node->parent->parent);
            }
        }
        // 2nd half, if parent is right child of grandparent
        else {
            Node<T,K,L> *uncle=node->parent->parent->left;
            // case 1: if uncle is red
            if(uncle!=NULL && uncle->color==RED) {
                node->parent->parent->color=RED;
                uncle->color=BLACK;
                node->parent->color=BLACK;
                node=node->parent->parent;
            }
            // case 2 & 3: if uncle is black
            else {
                // case 2
                if(node->parent->left==node) {
                    node=node->parent;
                    rightRotate(root,node);
                }
                // case 3
                node->parent->parent->color=RED;
                node->parent->color=BLACK;
                leftRotate(root,node->parent->parent);
            }
        }
    }
    root->color=BLACK;   //make sure the root is black
}

/*
 * Insert a node into a RBT
 */
template <class T,class K,class L>
void RBTree<T,K,L>::insert(Node<T,K,L>* &root, Node<T,K,L>* node){
    // todo: implement RBT insert.
    Node<T,K,L> *y = NULL;
    Node<T,K,L> *x = root;

    while (x != NULL) {
        y = x;
        if (node->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;

    if (y == NULL){
        root = node;
    }
    else if (node->key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }

    // set child pointer to null, color to red
    node->left = NULL;
    node->right = NULL;
    node->color = RED;
    insertFixUp(root,node);   // insert fixup

}

/*
 * Insert a key and a value into the tree
 */
template <class T,class K,class L>
void RBTree<T,K,L>::insert(T key, K value, L maxValue){
    Node<T,K,L> *x=NULL;
    if ((x=new Node<T,K,L>(key,value,maxValue,RED,NULL,NULL,NULL))==NULL){
        std::cout<<"Error: memory could not be allocated"<<endl;
        return;
    }
    insert(rbRoot,x);
}

/*
 * fix up the violation of RB tree property after deletion
 */
template <class T,class K,class L>
void RBTree<T,K,L>::removeFixUp(Node<T,K,L>* &root, Node<T,K,L> *node, Node<T,K,L> *parent){
    Node<T,K,L> *brother;

    while (((node==NULL) || (node->color==BLACK)) && (node!=root)){
        //if current node is a left child
        if (parent->left==node){
            brother = parent->right;
            //Case 1: x's brother is red
            if (brother->color==RED){
                brother->color = BLACK;
                parent->color = RED;
                leftRotate(root, parent);
                brother = parent->right;
            }
            //Case 2: x's brother is black, and none of the children of x's brother are red
            if ((!brother->left || (brother->left->color==BLACK)) && (!brother->right || (brother->right->color==BLACK))){
                brother->color = RED;
                node = parent;
                parent = node->parent;
            }
            else{
                //Case 3: x's brother is black, and x's brother's left child is red, x's brother's right child is black
                if ((brother->right==NULL) || (brother->right->color==BLACK)){
                    brother->left->color = BLACK;
                    brother->color = RED;
                    rightRotate(root,brother);
                    brother = parent->right;
                }
                //Case 4: x's brother is black, and x's brother's right child is red
                brother->color = parent->color;
                parent->color = BLACK;
                brother->right->color = BLACK;
                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else//current node is a right child
        {
            brother = parent->left;
            //Case 1: x's brother is red
            if (brother->color==RED){
                brother->color = BLACK;
                parent->color = RED;
                rightRotate(root, parent);
                brother = parent->left;
            }
            //Case 2: x's brother is black, and none of the children of x's brother are red
            if (((brother->left==NULL) || (brother->left->color==BLACK)) && (!brother->right || (brother->right->color==BLACK))){
                brother->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                //Case 3: x's brother is black, and x's brother's left child is red, x's brother's right child is black
                if ((brother->left==NULL) || (brother->left->color==BLACK)){
                    brother->right->color = BLACK;
                    brother->color = RED;
                    leftRotate(root,brother);
                    brother = parent->left;
                }
                //Case 4: x's brother is black, and x's brother's right child is red
                brother->color = parent->color;
                parent->color = BLACK;
                brother->left->color = BLACK;
                rightRotate(root,parent);
                node = root;
                break;
            }
        }
    }
    if (node!=NULL)
        node->color=BLACK;
}

/*
 * delete a node from RBT
 */
template <class T,class K,class L>
void RBTree<T,K,L>::remove(Node<T,K,L>* &root, Node<T,K,L> *node){
    Node<T,K,L> *child, *parent;
    Color color;

    //current node has both children
    if ((node->left!=NULL) && (node->right!=NULL)){
        //find the successor of the deleting node, then use that node temp to replace the current node
        Node<T,K,L> *temp = node;
        temp = temp->right;
        while (temp->left!=NULL)
            temp = temp->left;

        //check the node is not root
        if (node->parent){
            if (node->parent->left == node)
                node->parent->left = temp;
            else
                node->parent->right = temp;
        }
        else
            root = temp;

        parent = temp->parent;
        //let child be the temp's right child, which might need to be adjusted
        child = temp->right;
        //keep the color of the node temp
        color = temp->color;

        //if temp's parent is the deleting node
        if (parent==node)
            parent = temp;
        else{
            if (child!=NULL)
                child->parent = parent;
            parent->left = child;
            temp->right = node->right;
            node->right->parent=temp;
        }

        temp->parent = node->parent;
        temp->color = node->color;
        temp->left = node->left;
        node->left->parent = temp;

        if (color==BLACK)
            removeFixUp(root, child, parent);
        delete node;
        return;
    }

    //case where current node has at most one child
    if (node->left!=NULL)
        child = node->left;
    else
        child = node->right;
    parent = node->parent;
    color = node->color;
    if (child!=NULL)
        child->parent = parent;

    //check the node is not root
    if (parent!=NULL){
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
    }
    else
        root = child;

    if (color==BLACK)
        removeFixUp(root, child, parent);
    delete node;
}

/*
 * delete a node based on its key value
 */
template <class T,class K,class L>
void RBTree<T,K,L>::remove(T key){
    Node<T,K,L> *node;
    if ((node = search(rbRoot, key))!=NULL)
        remove(rbRoot, node);
}

//left rotate
template <class T,class K,class L>
void RBTree<T,K,L>::leftRotate(Node<T,K,L>* &root, Node<T,K,L>* x){
    Node<T,K,L> *right_child = x->right;
    x->right = right_child->left;

    if (x->right != nullptr)
        x->right->parent = x;

    right_child->parent = x->parent;

    if (x->parent == nullptr)
        root = right_child;
    else if (x == x->parent->left)
        x->parent->left = right_child;
    else
        x->parent->right = right_child;

    right_child->left = x;
    x->parent = right_child;
}

//right rotate
template <class T,class K,class L>
void RBTree<T,K,L>::rightRotate(Node<T,K,L>* &root, Node<T,K,L>* y){
    Node<T,K,L> *left_child = y->left;
    y->left = left_child->right;

    if (y->left != nullptr)
        y->left->parent = y;

    left_child->parent = y->parent;

    if (y->parent == nullptr)
        root = left_child;
    else if (y == y->parent->left)
        y->parent->left = left_child;
    else
        y->parent->right = left_child;

    left_child->right = y;
    y->parent = left_child;
}

/*
 * destructor
 */
template <class T,class K,class L>
void RBTree<T,K,L>::destroy(Node<T,K,L>* &tree){
    if (tree==NULL)
        return;
    if (tree->left!=NULL)
        destroy(tree->left);
    if (tree->right!=NULL)
        destroy(tree->right);
    delete tree;
    tree=NULL;
}

template <class T,class K,class L>
void RBTree<T,K,L>::destroy(){
    destroy(rbRoot);
}

/*
 * print the RBT where direction 0 means root, -1 stands for left child, 1 stands for the right child
 */
template <class T,class K,class L>
void RBTree<T,K,L>::print(Node<T,K,L>* tree, T key, int direction){
    if (tree!=NULL){
        if (direction==0)//is root node
            std::cout<<tree->key<<"(B) is root" << endl;
        else//is non-root node
            std::cout<<tree->key<<((tree->color==RED)?"(R)":"(B)")<<" is "<< key <<"'s "<<(direction==1?"right child" : "left child")<<", value="<<tree->value<<", max value="<<tree->maxValue<<endl;
        print(tree->left,tree->key,-1);
        print(tree->right,tree->key,1);
    }
}

template <class T,class K,class L>
void RBTree<T,K,L>::print(){
    if (rbRoot!=NULL)
        print(rbRoot,rbRoot->key,0);
}

template <class T,class K,class L>
Node<T,K,L>* RBTree<T,K,L>::root() {
    return rbRoot;
}

#endif
