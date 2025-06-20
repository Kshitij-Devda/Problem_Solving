class Solution {
public:
    ListNode* rotateRight(ListNode* head, int n) {
        if (!head || !head->next || n == 0) return head;

        ListNode *i, *j, *ans;
        i = head;
        int cnt = 0, pos;
        while(i){
            cnt++;
            i = i->next;
        }
        pos = n % cnt;
        i = head;
        if(pos == 0) return head;

        for(int m = 0; m < cnt - pos - 1; m++)i = i->next; 

        j = i->next;
        i->next = nullptr;
        ans = j;
        if (j == nullptr) return head;

        while(j && j->next) j = j->next;
        j->next = head;

        return ans;
    }
};