ListNode* f(ListNode* l, ListNode* r){
    if(l == nullptr || r == nullptr) return nullptr;
    
    ListNode *L = l;
    ListNode *R = r;
    
    int len1 = 0;
    while(L != nullptr){
        len1++;
        L = L->next;
    }
    
    int len2 = 0;
    while(R != nullptr){
        len2++;
        R = R->next;
    }
    
    L = l;
    R = r;
    if(len1 > len2){
        int diff = len1 - len2;
        for(int i = 0; i < diff; ++i){
            L = L->next;
        }
    } else if(len2 > len1){
        int diff = len2 - len1;
        for(int i = 0; i < diff; ++i){
            R = R->next;
        }
    } 
    
    ListNode* ans = nullptr;
    while(L != nullptr && R != nullptr){
        if(L == R){
            ans = L;
        }
        L = L->next;
        R = R->next;
    }
    
    return ans;
}
