//
// Created by DELL on 2021/3/7.
//

#include "binary_tree.h"

template<typename Tp>
BinaryTree<Tp>::Node::Node(BinaryTree::const_reference value)
    : value_(new value_type(value))
    , parent_(nullptr)
    , left_(nullptr)
    , right_(nullptr) {

}

template<typename Tp>
BinaryTree<Tp>::Node::Node(BinaryTree::const_pointer value, BinaryTree::Node *parent)
    : value_(value)
    , parent_(parent)
    , left_(nullptr)
    , right_(nullptr) {

}

template<typename Tp>
BinaryTree<Tp>::Node::Node(BinaryTree::const_pointer value, BinaryTree::Node *parent, BinaryTree::Node *left)
    : value_(value)
    , parent_(parent)
    , left_(left)
    , right_(nullptr) {

}

template<typename Tp>
BinaryTree<Tp>::Node::Node(BinaryTree::const_pointer value, BinaryTree::Node *parent, BinaryTree::Node *left,
                           BinaryTree::Node *right)
   : value_(value)
   , parent_(parent)
   , left_(left)
   , right_(right) {

}

template<typename Tp>
BinaryTree<Tp>::Node::~Node() {
    delete value_;
    value_ = nullptr;

    if (left_) {
        delete left_;
        left_ = nullptr;
    }

    if (right_) {
        delete right_;
        right_ = nullptr;
    }
}
