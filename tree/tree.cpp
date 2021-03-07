//
// Created by DELL on 2021/3/5.
//

#include "tree.h"

template<typename Tp>
Tree<Tp>::Node::Node(Tree::const_pointer value)
    : value_(value)
    , parent_(nullptr) {

}

template<typename Tp>
Tree<Tp>::Node::Node(const Tree::Node* parent, Tree::const_pointer value)
    : parent_(parent)
    , value_(value) {

}

template<typename Tp>
uint32_t Tree<Tp>::Node::MaxDegree() const {
    uint32_t maxDegree = Degree();

    for (auto it = children_.cbegin(); it != children_.cend(); it++) {
        if ((*it).children_.empty()) {
            continue;
        }

        uint32_t childMaxDegree = MaxDegree();
        if (childMaxDegree > maxDegree) {
            maxDegree = childMaxDegree;
        }
    }

    return maxDegree;
}

template<typename Tp>
Tree<Tp>::Node::Node()
    : value_(nullptr)
    , parent_(nullptr) {

}

template<typename Tp>
uint32_t Tree<Tp>::Node::Level() const {
   uint32_t level = 0;

    Node* root = parent_;
    while (root != nullptr) {
        level++;
        root = root->parent();
    }

    return level;
}


template<typename Tp>
bool Tree<Tp>::empty() {
    return root_ == nullptr;
}

