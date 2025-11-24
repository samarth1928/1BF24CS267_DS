#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* create(int x){
    struct node *head=NULL;
    int data;
    if(x<0){
        printf("Invalid input\n");
    }
    struct node *newnode;
    struct node *temp;
    for(int i=0;i<x;i++){
         newnode=(struct node*)malloc(sizeof(struct node));
         printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        newnode->data=data;
        newnode->next=NULL;
        if (head == NULL) {
            head = newnode;     
            temp = newnode;      
        } else {
            temp->next = newnode; 
            temp = newnode;       
        }
    }
    return head;
}
void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void sort(struct node* head){
    struct node *i,*j;
    int temp;
    for(i=head;i->next!=NULL;i=i->next){
       for(j=i->next;j->next!=NULL;j=j->next){
        if(i->data>j->data){
          temp=i->data;
          i->data=j->data;
          j->data=temp;
    }
}
}}


struct node* reverse(struct node *head) {
struct node* prev = NULL;
struct node* curr = head;
struct node* front = NULL;

    while (curr != NULL) {
        front = curr->next;  
        curr->next = prev;    
        prev = curr;         
        curr = front;         
    }
    return prev;
}
struct node* concat(struct node* head1,struct node *head2){
    if(head1==NULL){
         return head2;
    }
    if(head2==NULL){
         return head1;
    }
    else{
        struct node *temp=head1;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head2;
    }
    return head1;
}
int main(){
    int n1,n2;
    printf("Enter number of nodes for list 1:\n");
    scanf("%d",&n1);
    struct node* head1=create(n1);
    printf("Enter number of nodes for list 2:\n");
    scanf("%d",&n2);
    struct node* head2=create(n2);
    printf("\nOriginal First List: ");
    printList(head1);
    printf("Original Second List: ");
    printList(head2);

  
    sort(head1);
    sort(head2);
    printf("\nSorted First List: ");
    printList(head1);
    printf("Sorted Second List: ");
    printList(head2);

    head1=reverse(head1);
    printf("\nReversed First List: ");
    printList(head1);

    struct node* concatenatedList = concat(head1,head2);
    printf("\nConcatenated List: ");
    printList(concatenatedList);

}