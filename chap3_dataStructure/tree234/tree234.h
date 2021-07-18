#ifndef _234TREE_H
#define _234Tree_H
#include <iostream>
using namespace std;

class TreeNode_234{
    public :
        TreeNode_234 *left, *leftMid, *rightMid, *right;
        int key1, key2, key3;
}

class Tree_234{
    private :
        TreeNode_234 *root;
        int node_number;
        TreeNode_234* getLocartion(int key) const;
        void treeBalancing(TreeNode_234 *parent, Tree_234 *child);
        bool  nodeBalancing(TreeNode_234 *p, int key);
        bool isNodeFull(TreeNode_234 *p) const;
        TreeNode_234* create_node();
        TreeNode_234* searchKeyNode(int key) const;
        TreeNode_234* searchParentNode(int key) const;
    public :
        Tree_234(){node_number = 0;}
        ~Tree_234();
        void add_item(int key);
        void delete_item(int key);
};
#endif