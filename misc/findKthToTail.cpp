struct ListNode {
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* FindKthToTail(ListNode* p, unsigned int k) {
    //if(!p) return nullptr;
    auto p1=p;
    for(int i=0;i!=k;++i)
        if(!p1)return nullptr;
    else
        p1=p1->m_pNext;
    while(p1){
        p1=p1->m_pNext;
        p=p->m_pNext;
    }
    return p;
}
int main() {
    return 0;
}