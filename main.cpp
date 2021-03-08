//
// Created by DELL on 2021/3/5.
//

#include "tree/tree.h"

int main(int argc, char* argv[]) {
    Tree<int> tree(Tree<int>::CreateNode(10));

    tree.RootAppendChild(Tree<int>::CreateNode(1));
    tree.RootAppendChild(Tree<int>::CreateNode(2));
    tree.RootAppendChild(Tree<int>::CreateNode(3));

    int i = 0;
    i++;
}

