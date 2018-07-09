struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    bool isSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if(!pRootB)return true;
        if(!pRootA)return false;
        if(pRootA->val==pRootB->val)
        {
            if(isSubtree(pRootA->left,pRootB->left)&&isSubtree(pRootA->right,pRootB->right))
                return true;
        }
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2||!pRoot1){return false;}
         
        if(pRoot1->val==pRoot2->val)
        {
            if(isSubtree(pRoot1,pRoot2))
                return true;
        }
        if(HasSubtree(pRoot1->left,pRoot2))
        {
            return true;
        }
        if(HasSubtree(pRoot1->right,pRoot2))
        {
            return true;
        }
        return false;
                
     }
};
int main() {
    return 0;
}