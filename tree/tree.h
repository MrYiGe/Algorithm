//
// Created by DELL on 2021/3/5.
//

#ifndef ALGORITHM_TREE_H
#define ALGORITHM_TREE_H

#include <cstdint>
#include <list>


template<typename Tp>
class Tree {
public:
    typedef Tp 	    			    value_type;
    typedef value_type*			        pointer;
    typedef const value_type*           const_pointer;
    typedef value_type&         reference;
    typedef const value_type& const_reference;
    typedef value_type*          		      iterator;
    typedef const value_type*			      const_iterator;
    typedef std::size_t                    	      size_type;
    typedef std::ptrdiff_t                   	      difference_type;
    typedef std::reverse_iterator<iterator>	      reverse_iterator;
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

    struct Node {
        explicit Node();
        explicit Node(const_pointer value);
        Node(const Node* parent, const_pointer value);

        const Node* parent() const { return parent_; }

        const_pointer value() const { return value_; }
        Node& set_value(const_pointer value) { value_ = value; }

        const std::list<Node*> children() const { return children_; }

        size_type size() const { return children_.size(); }

        Node& AddChild(const_pointer value) { children_.template emplace_back(Node(this, value)); }
        Node& AddChild(const Node& node) { node.parent_ = this; children_.template emplace_back(node); }

        /** 结点的度，即子结点树 */
        size_type Degree() const { return size(); }

        /** 当前结点的孩子结点的最大度 */
        uint32_t MaxDegree() const;

    private:
        pointer value_;
        Node*    parent_;
        std::list<Node*> children_;
    };

public:
    explicit Tree();
    ~Tree();

    Tree& Append(const_pointer value);

public:
    bool empty();
    const Node* root() const { return root_;}

private:
    Node* root_;
};


template<typename Tp>
Tree<Tp>::Tree()
        : root_(nullptr) {
}

template<typename Tp>
Tree<Tp>::~Tree() {
    delete root_;
}



#endif //ALGORITHM_TREE_H
