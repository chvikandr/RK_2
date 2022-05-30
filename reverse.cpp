#include <iostream>
#include <random>


struct Tree {
    int value = 0;
    struct Tree *parent = nullptr;
    struct Tree *left = nullptr;
    struct Tree *right = nullptr;
};


void addLeft(int value, Tree *pTree) {
    pTree->left = new Tree;
    pTree->left->value = value;
    pTree->left->parent = pTree;
}

void addRight(int value, Tree *pTree) {
    pTree->right = new Tree;
    pTree->right->value = value;
    pTree->right->parent = pTree;
}


void reverse(Tree *tree, std::vector<int> &out) {
    if (tree == nullptr) return;

    reverse(tree->left, out);

    reverse(tree->right, out);
    out.push_back(tree->value);


}


