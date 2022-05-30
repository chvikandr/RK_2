#include "../reverse.cpp"
#include "gtest/gtest.h"


TEST(Tree, Empty) {
    std::vector<int> expected_out = {0};
    std::vector<int> out;
    Tree *tree = new Tree{};
    reverse(tree, out);
    EXPECT_EQ(expected_out, out);
}


TEST(Tree, element_right) {
    std::vector<int> expected_out = {1,0};
    std::vector<int> out;
    Tree *tree = new Tree{};
    pushRight(1, tree);
    reverse(tree, out);
    EXPECT_EQ(expected_out, out);
}

TEST(Tree, FullTree) {
    std::vector<int> out;
    std::vector<int> expected_out = {250, 1337, 42, -87, 171, 18, 35, -35, 69, 48, 56};
    srandom(time(nullptr));
    Tree *tree = new Tree{56, nullptr, nullptr};

    pushLeft(35, tree);
    pushRight(48, tree);

    pushLeft(-35, tree->right);
    pushRight(69, tree->right);

    pushLeft(42, tree->left);
    pushRight(18, tree->left);

    pushLeft(-87, tree->left->right);
    pushRight(171, tree->left->right);

    pushLeft(250, tree->left->left);
    pushRight(1337, tree->left->left);

    reverse(tree, out);
    EXPECT_EQ(expected_out, out);

}
