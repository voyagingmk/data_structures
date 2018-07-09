
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

ListNode* ReverseList(ListNode* pHead) {

    if(pHead==nullptr)
        return pHead;
    ListNode* pre = nullptr;
    ListNode* cur = pHead;
    ListNode* nxt = nullptr;
    ListNode* res = nullptr;
    while(cur != nullptr){
        nxt = cur->next;
        cur->next = pre;
        if (nxt == nullptr){
            break;
        }
        pre = cur;
        cur = nxt;
    }
    return cur;
}

int main() {
    return 0;
}