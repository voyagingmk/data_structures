struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

 void Mirror(TreeNode *pRoot) {
    if(pRoot==nullptr){
        return;
    }
    TreeNode *tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

int main() {
    return 0;
}