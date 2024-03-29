ListNode* mergeList(ListNode* l1,ListNode* l2){

        ListNode* head;

        if(l1==NULL){
            return l2;
        }

        if(l2==NULL){
            return l1;
        }

        if(l1->val<=l2->val){
            head=l1;
            head->next=mergeList(l1->next,l2);
        }
        else{
            head=l2;
             head->next=mergeList(l1,l2->next);
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }

        ListNode *head=lists[0];
        for(int i=1;i<lists.size();i++){
        head=mergeList(head,lists[i]);
        
    }
    return head;
    }
