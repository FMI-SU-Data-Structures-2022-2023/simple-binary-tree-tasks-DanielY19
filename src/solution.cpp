#include "solution.h"

#include <iostream>

int countElements(Node *tree) {
    if (!tree)
        return 0;

    return 1 + countElements(tree->left) + countElements(tree->right);
}

int countLeafs(Node *tree) {
    if (!tree)
        return 0;

    if (!tree->left && !tree->right)
        return 1;

    return countLeafs(tree->left) + countLeafs(tree->right);
}

int height(Node *tree) {
    if (!tree)
        return 0;

    return 1 + std::max(height(tree->left), height(tree->right));
}

int sumElements(Node *tree) {
    if (!tree)
        return 0;

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}

int sumElementsAtLevel(Node *tree, unsigned level) {
    if (!tree)
        return 0;
    if (!level)
        return tree->key;

    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}

bool helper(Node *leftTree, Node *rightTree) {
    if (!leftTree && !rightTree) return true;
    if (!leftTree || !rightTree) return false;

    if (leftTree->key == rightTree->key)
        return helper(leftTree->left, rightTree->right) && helper(leftTree->right, rightTree->left);

    return false;
}

bool isSymmetric(Node *tree) {
    if (!tree) return true;
    if (!tree->left && !tree->right) return true;
    return helper(tree->left, tree->right);
}

int getMax(Node *tree) {
    if (!tree)
        return 0;

    if (!tree->left && !tree->right)
        return tree->key;

    int maxElement = tree->key;
    int leftElement = getMax(tree->left);
    int rightElement = getMax(tree->right);

    if (tree->left && leftElement > maxElement)
        maxElement = leftElement;

    if (tree->right && rightElement > maxElement)
        maxElement = rightElement;

    return maxElement;
}

int getMin(Node *tree) {
    if (!tree)
        return 0;

    if (!tree->left && !tree->right)
        return tree->key;

    int minElement = tree->key;
    int leftElement = getMin(tree->left);
    int rightElement = getMin(tree->right);

    if (tree->left && leftElement < minElement)
        minElement = leftElement;

    if (tree->right && rightElement < minElement)
        minElement = rightElement;

    return minElement;
}

bool isBST(Node *tree) {
    if (!tree)
        return true;

    if (!tree->left && !tree->right)
        return true;

    if (tree->left && getMax(tree->left) >= tree->key)
        return false;
    if (tree->right && getMax(tree->right) <= tree->key)
        return false;

    return isBST(tree->left) && isBST(tree->right);
}