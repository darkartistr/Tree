#include <iostream>

struct NodeTree {

    NodeTree(int _info = 0, NodeTree* _left = nullptr, NodeTree* _right = nullptr) :
        info(_info), left(_left), right(_right) {}

    int info;
    NodeTree* left;
    NodeTree* right;
};

struct SubtreeInfo {

    int size;
    int height;

    SubtreeInfo(int s, int h) : size(s), height(h) {}
};

class BinaryTree {
public:
    BinaryTree() : pTree(nullptr) {}
    ~BinaryTree() { Erase(pTree); }
    void Insert(int info);

    NodeTree* FindMaxSubtree();

private:
    void Erase(NodeTree*& t);
    SubtreeInfo GetSubtreeInfo(NodeTree* root);
    NodeTree* FindMaxSubtreeHelper(NodeTree* root);

    NodeTree* pTree;
};
