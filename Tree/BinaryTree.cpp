#include "BinaryTree.h"

void BinaryTree::Erase(NodeTree*& t)
{
    if (t) { 
        Erase(t->left); 
        Erase(t->right); 
        delete t; 
        t = nullptr;
    }
}

void BinaryTree::Insert(int info) {
    NodeTree** pp = &pTree;
    while (*pp)
        pp = (info < (*pp)->info) ? &((*pp)->left) : &((*pp)->right);
    *pp = new NodeTree(info);
}

SubtreeInfo BinaryTree::GetSubtreeInfo(NodeTree* root) {
    if (root == nullptr)
        return SubtreeInfo(0, -1);

    SubtreeInfo leftInfo = GetSubtreeInfo(root->left);
    SubtreeInfo rightInfo = GetSubtreeInfo(root->right);

    int height = std::max(leftInfo.height, rightInfo.height) + 1;
    int size = leftInfo.size + rightInfo.size + 1;

    return SubtreeInfo(size, height);
}

NodeTree* BinaryTree::FindMaxSubtree() {
    return FindMaxSubtreeHelper(pTree);
}

NodeTree* BinaryTree::FindMaxSubtreeHelper(NodeTree* root) {
    if (root == nullptr)
        return nullptr;

    if (std::abs(GetSubtreeInfo(root->left).height - GetSubtreeInfo(root->right).height) <= 2)
        return root;

    NodeTree* leftSubtree = FindMaxSubtreeHelper(root->left);
    NodeTree* rightSubtree = FindMaxSubtreeHelper(root->right);

    if (leftSubtree != nullptr && rightSubtree != nullptr)
        return (GetSubtreeInfo(leftSubtree).size > GetSubtreeInfo(rightSubtree).size) ? leftSubtree : rightSubtree;
    else if (leftSubtree != nullptr)
        return leftSubtree;
    else
        return rightSubtree;
}
