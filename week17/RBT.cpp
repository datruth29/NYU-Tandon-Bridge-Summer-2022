/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);
    void balanceTree(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    // Right then Left
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    // Left then Right
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    // Right Rotation
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    RBTNode<T> *child = parent->right;

    // 1) Change grandparents right to childs parent
    grandparent->left = child;
    if (child)
    {
        child->parent = grandparent;
    }

    // 2) Change parents parent to grandparents parent
    parent->parent = grandparent->parent;
    if (grandparent->parent == nullptr)
    {
        root = parent;
    } else if (grandparent == grandparent->parent->left)
    {
        grandparent->parent->left = parent->parent;
    } else if (grandparent == grandparent->parent->right)
    {
        grandparent->parent->right = parent->parent;
    }

    // 3) Change parents right child to grandparent
    parent->right = grandparent;
    grandparent->parent = parent;
    // TODO: ADD ROTATION CODE HERE
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    // Left Rotation
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    RBTNode<T> *child = parent->left;

    // 1) Change grandparents left to childs parent
    grandparent->right = child;
    if (child)
    {
        child->parent = grandparent;
    }

    // 2) Change parent of grandparent to the parent of parent
    parent->parent = grandparent->parent;
    if (grandparent->parent == nullptr)
    {
        root = parent;
    } else if (grandparent == grandparent->parent->left)
    {
        grandparent->parent->left = parent;
    } else if (grandparent == grandparent->parent->right)
    {
        grandparent->parent->right = parent;
    }

    // 3) Change parents left child to grandparent
    parent->left = grandparent;
    grandparent->parent = parent;

    // TODO: ADD ROTATION CODE HERE
}

template<class T>
void RBT<T>::balanceTree(RBTNode<T> *&point)
{
    /*
    Rules:
    1) point == root, change to black
    2) point.uncle == red, parent + uncle change to black, gp change to red
    3) point.uncle == black (triangle), rotate parent right
    4) point.uncle == black (line), rotate grandparent left
    */

    // 1) point == root, change to black
    if (point->parent == nullptr)
    {
        root = point;
        if (getColor(point) == RED)
            swapColor(point);
        return;
    }

    if (root == point->parent)
    {
        return;
    }

    RBTNode<T>* parent = point->parent;
    RBTNode<T>* grandparent = parent->parent;
    RBTNode<T>* uncle;

    if (grandparent->left == parent)
    {
        uncle = grandparent->right;
    } else if (grandparent->right == parent) {
        uncle = grandparent->left;
    } else {
        uncle = nullptr;
    }

    if(grandparent && getColor(parent) == RED)
    {
        if (uncle && getColor(uncle) == RED)
        {
            swapColor(uncle);
            swapColor(parent);
            swapColor(grandparent);
            balanceTree(grandparent);
            return;
        }

        if (uncle == nullptr || getColor(uncle) == BLACK)
        {
            if (parent == grandparent->right && point == parent->right)
            {
                singleCCR(grandparent);
                swapColor(grandparent);
                swapColor(parent);
                balanceTree(parent);
                return;
            }

            if (parent == grandparent->left && point == parent->left)
            {
                singleCR(grandparent);
                swapColor(grandparent);
                swapColor(parent);
                balanceTree(parent);
                return;
            }

            if (parent == grandparent->right && point == parent->left)
            {
                doubleCCR(grandparent);
                swapColor(grandparent);
                swapColor(parent);
                balanceTree(parent);
                return;
            }

            if (parent == grandparent->left && point == parent->right)
            {
                doubleCR(grandparent);
                swapColor(grandparent);
                swapColor(parent);
                balanceTree(parent);
                return;
            }
        }
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree

        balanceTree(curr_node);
        // TODO: ADD RBT RULES HERE
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}