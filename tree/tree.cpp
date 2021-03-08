//
// Created by DELL on 2021/3/5.
//

#include "tree.h"

template<typename Tp>
typename Tree<Tp>::size_type Tree<Tp>::Node::Degree() const {
    if (child_ == nullptr) {
        return 0;
    }

    if (child_->brother() == nullptr) {
        return 1;
    }

    return 1 + child_->brother()->Degree();
}

template<typename Tp>
typename Tree<Tp>::size_type Tree<Tp>::Node::Level() const {
    size_type level = 1;
    const Node* child = child_;

    while (child != nullptr) {
        level += 1;
        child = child->child();
    }

    return level;
}



template<typename Tp>
bool Tree<Tp>::empty() {
    return root_ == nullptr;
}

