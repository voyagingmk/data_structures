
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr) return pHead2;
    if (pHead2 == nullptr) return pHead1;
    ListNode *mergeList = nullptr;
    if (pHead1->val < pHead2->val) {
        mergeList = pHead1;
        mergeList->next = Merge(pHead1->next, pHead2);
    }
    else {
        mergeList = pHead2;
        mergeList->next = Merge(pHead1, pHead2->next);
    }
    return mergeList;
}

int main() {
    return 0;
}