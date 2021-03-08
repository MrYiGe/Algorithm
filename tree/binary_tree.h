//
// Created by DELL on 2021/3/7.
//

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <cstddef>
#include <iterator>

template<typename Tp>
class BinaryTree {
public:
    typedef Tp 	    			        value_type;
    typedef value_type*			        pointer;
    typedef const value_type*           const_pointer;
    typedef value_type&                 reference;
    typedef const value_type&           const_reference;
    typedef value_type*          		iterator;
    typedef const value_type*			const_iterator;
    typedef std::size_t                 size_type;
    typedef std::ptrdiff_t                   	    difference_type;
    typedef std::reverse_iterator<iterator>	        reverse_iterator;
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

    struct Node {
    public:
        explicit Node(const_reference value);
        Node(const_pointer value, Node* parent = nullptr);
        Node(const_pointer value, Node* parent, Node* left = nullptr);
        Node(const_pointer value, Node* parent, Node* left, Node* right = nullptr);
        ~Node();

        const_pointer value() const { return value_; }
        void set_value(const_pointer value) { value_ = value; }

        Node* parent() const { return parent_; }
        void set_parent(const Node* parent) { parent_ = parent; }

        Node* left() const { return left_;}
        void set_left(const Node* left) { left_ = left; }

        Node* right() const { return right_; }
        void set_right(const Node* right) { right_ = right; }

    private:
        pointer value_;
        Node*   parent_;
        Node*   left_;
        Node*   right_;
    };

public:
    explicit BinaryTree();

    Node* root() const { return root_; }

private:

    Node* root_;
};

template<typename Tp>
BinaryTree<Tp>::BinaryTree()
    : root_(root) {

}


#endif //__BINARY_TREE_H__
