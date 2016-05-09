    void print(ListNode *s) {
        if (s) fprintf(stderr, "%d|", s->val); else fprintf(stderr, "nil|");
    }
    
    void printList(ListNode *s) {
        ListNode *cur = s;
        while (cur) {
            fprintf(stderr, "%d->", cur->val);
            cur = cur->next;
        }
        print(NULL);
    }