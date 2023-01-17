class Solution {
public:
    int helper(ListNode *head,int k){
        ListNode *temp=head;  //For traversing through the List and delete every kth Node 
        while(head->next!=head){   //Till the last Node remains in the list i.e. the winner
            ListNode *pre=NULL;
            for(int i=1; i<k; i++){
                pre=temp;
                temp=temp->next;
            }
            //Deletion procedure
            if(temp==head)
                head=head->next;
            pre->next=temp->next;
            delete(temp);
            temp=pre->next;
        }
        //The last node remaining becomes the head of the Circular Linked List i.e. Winner
        return head->val;
    }
    int findTheWinner(int n, int k) {
        if(k==1)
            return n;
        //Designing Circular Linked List for Node 1,2,3,4,.....,n
        ListNode *head=NULL,*tail=NULL;
        for(int i=1; i<=n; i++){
            ListNode *node=new ListNode(i);
            if(head==NULL)
                head=tail=node;
            else{
                tail->next=node;
                tail=node;
            }
            tail->next=head;
        }
        //Helper function will eliminate the nodes and give us the winner
        return helper(head,k);
    }
};