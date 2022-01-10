void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here
        if(!head || N==0)
        return;
        if(M==0){
            head=NULL;
            return;
        }
        struct Node* temp=head;
        int m=M,n=N;
        while(temp){
            while(--M && temp){
                temp=temp->next;
            }
            if(!temp || !temp->next)
            return;
            M=m;
            struct Node* t=temp->next;
            while(--N && t){
                t=t->next;
            }
            if(!t)
            {
                temp->next=NULL;
                return;
            }
            temp->next=t->next;
            temp=temp->next;
            N=n;
        }
        
    }
