#include "tree234.h"

Tree_234::~Tree_234(){

}
TreeNode_234* Tree_234::getLocartion(int key) const{
    TreeNode_234 *p = root, *t;
    while(1){
        switch(key){
            case key > -1 && key < p->key1 : t = p ; p = p->left; break;
            case key >= p->key1 && key < p->key2 : t = p; p = p->leftMid; break;
            case key >= p->key2 && key < p->key3 : t = p; p = p->rightMid; break;
            default : t = p; p = p->right; break;
        }
            if(p->left == NULL && p->leftMid == NULL && p->rightMid == NULL && p->right == NULL)
                break;
    }
    return t;
}
void Tree_234::treeBalancing(TreeNode_234* parent, TreeNode_234* child){
    if(!parent)   return;

    if(isNodeFull(child) && child != NULL){
        TreeNode_234* new_child = create_node();
        if(!new_child){cout << "memory error" << endl; return;}

        if((parent->key1 != -1) && (parent->key2 == -1) && (parent->key3 == -1)){//if parent has only one item
            if(parent->left == child){
                new_child->key1 = child->key3;
                new_child->left = child->rightMid;
                new_child->leftMid = child->right;

                parent->key2 = parent->key1;
                parent->key1 = child->key2;
                parent->left = child;
                parent->leftMid = new_child
                
                child->key2 = child->key3 = -1;
                child->rightMid = child->right = NULL;
            }
            else{
                new_child->key1 = child->key3;
                new_child->left = child->rightMid;
                new_child->leftMid = child->right;

                parent->key2 = child->key2;
                parent->leftMid = child;
                parent->rightMid = new_child;
                
                child->key2 = child->key3 = -1;
                child->rightMid = child->right = NULL;
            }

        }
        else if((parent->key1 != -1) && (parent->key2 != -1) && (parent->key3 == -1)){
            TreeNode_234* new_child = create_node();
            if(!new_child){cout << "memory error" << endl; return;}

            if(parent->left == child){
                new_child->key1 = child->key3;
                new_child->left = child->rightMid;
                new_child->leftMid = child->right;

                parent->key2 = parent->key1;
                parent->key3 = parent->key2;
                parent->key1 = child->key2;
                parent->right = parent->rightMid;
                parent->rightMid = parent->leftMid;
                parent->leftMid = new_child;

                child->key2 = child->key3 = -1;
                child->rightMid = child->right = NULL;
            }
            else if(parent->leftMid == child){
                new_child->key1 = child->key3;
                new_child->left = child->rightMid;
                new_child->leftMid = child->right;

                parent->key3 = parent->key2;
                parent->key2 = child->key2;
                parent->rightMid = new_child;

                child->key2 = child->key3 = -1;
                child->rightMid = child->right = NULL;
            }
            else if(parent->rightMid == child){
                new_child->key1 = child->key3;
                new_child->left = child->rightMid;
                new_child->leftMid = child->right;

                parent->key3 = child->key2;
                parent->right = new_child;

                child->key2 = child->key3 = -1;
                child->rightMid = child->right == NULL;
            }
        }
    }
    if(isNodeFull(parent)){//when the root node is full & node is alread balanced
        if(!(TreeNode_234 *child1 = create_node())){cout << "memory error" << endl; return;};
        if(!(TreeNode_234 *child2 = create_node())){cout << "memory error" << endl; return;};
        
        child1->key1 = parent->key1;
        child1->left = parent->left;
        child1->leftMid = parent->leftMid;

        child2->key1 = parent->key3;
        child2->left = parent->rightMid;
        child2->leftMid = parent->right;

        parent->key1 = parent->key2;
        parent->key2 = parent->key3 = -1;
        parent->left = child1;  parent->leftMid = child2;
        parent->rightMid = parent->right = NULL;
    }
    
}
#if 1
bool Tree_234::nodeBalancing(TreeNode_234 *p, int key){
        if(p->key1 > key){
            p->key3 = p->key2;
            p->key2 = p->key1;
            p->key1 = key;
        }
        else if(p->key2 > key){
            p->key3 = p->key2;
            p->key2 = key;
        }
        else{
            p->key3 = key;
        }
        if(p->key3 != -1)   return false;
        else                return true;
}
#endif
void Tree_234::isNodeFull(TreeNode_234* p) const{
    return (p->key1 != -1 && p->key2 != -1 && p->key3 != -1);
}
TreeNode_234* Tree_234::create_node(){
    TreeNode_234 *p = new TreeNode_234;
    p->key1 = p->key2 = p->key3 = -1;
    p->left = p->leftMid = p->rightMid = p->right = NULL;
    return p;
}
void Tree_234::add_item(int key){
    TreeNode_234* p = getLocartion(key), *t;
    if(!nodeBalancing(p, key)){
        if(key > -1 && key < p->key1)   t = p->left;
        else if(key >= p->key1 && key < p->key2)    t = p->leftMid;
        else if(key >= p->key2 && key < p->key3)    t = p->rightMid;
        else                                        t = p->right;
        treeBalancing(p, t);
    }
}
void Tree_234::delete_item(int key){
    TreeNode_234 *parent = searchParentNode(key), *child = searchKeyNode(key);
    
    
}
TreeNode_234* Tree_234::searchParentNode(int key) const{
    TreeNode_234 *p = root, *t;
    while(1){
        switch(key){
            case key > -1 && key < p->key1 : t = p ; p = p->left; break;
            case key >= p->key1 && key < p->key2 : t = p; p = p->leftMid; break;
            case key >= p->key2 && key < p->key3 : t = p; p = p->rightMid; break;
            default : t = p; p = p->right; break;
        }
            if(p->key1 == key || p->key2 == key || p->key3 == key)  break;
    }
    return t;
}
TreeNode_234* Tree_234::searchKeyNode(int key) const{
     TreeNode_234 *p = root, *t;
    while(1){
        switch(key){
            case key > -1 && key < p->key1 : t = p ; p = p->left; break;
            case key >= p->key1 && key < p->key2 : t = p; p = p->leftMid; break;
            case key >= p->key2 && key < p->key3 : t = p; p = p->rightMid; break;
            default : t = p; p = p->right; break;
        }
            if(p->key1 == key || p->key2 == key || p->key3 == key)  break;
    }
    return p;
}

