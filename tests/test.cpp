#include "../reverse.cpp"
#include "gtest/gtest.h"

using namespace std;

TEST(Tree, Empty) {
    vector<int> out_expect = {0};
    vector<int> out;
    Tree *tree = new Tree{};
    reverse(tree, out);
    EXPECT_EQ(out_expect, out);
}


TEST(Tree, element_right) {
    vector<int> out_expect = {1, 0};
    vector<int> out;
    Tree *tree = new Tree{};
    addRight(1, tree);
    reverse(tree, out);
    EXPECT_EQ(out_expect, out);
}

TEST(Tree, FullTree) {
    vector<int> out;
    vector<int> out_expect = { 204, 1037, 43, -43, 185, 12, 12, -1, 98, 543, 56};


    Tree *tree = new Tree{56, nullptr, nullptr};

    addLeft(12, tree);
    addRight(543, tree);

    addLeft(-1, tree->right);
    addRight(98, tree->right);

    addLeft(43, tree->left);
    addRight(12, tree->left);

    addLeft(-43, tree->left->right);
    addRight(185, tree->left->right);

    addLeft(204, tree->left->left);
    addRight(1037, tree->left->left);

    reverse(tree, out);
    EXPECT_EQ(out_expect, out);

}
