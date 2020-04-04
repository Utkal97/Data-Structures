#include "SinglyLinkedListClass.h"
using namespace std;

void print(Node *head) {
	while(head) {
		cout<<head->data;
		head = head->next;
		if(head)
			cout<<" ";
	}
	cout<<endl;
	return;
}

Node* partition(struct Node **head, struct Node **tail) {

    if(!head)
        return *head;
    else if(head == tail)
        return *head;

    Node *pivot = *head;
    Node *curr = pivot->next, *prev = pivot;

    while(curr!=NULL) {
        if(curr->data < pivot->data) {
        	cout<<"repositioning "<<curr->data<<" "<<pivot->data<<endl;
            Node *temp = curr;
            prev->next = curr->next;

            curr->next = *head;
            *head = curr;
            prev = curr;
            curr = pivot->next;
            print(*head);
        }

        prev = curr;
        curr = curr->next;
    }
    cout<<"after partition : ";
    print(*head);
    return pivot;
}

Node *sort(struct Node **head, struct Node **tail) {

    if(!(*head))
        return NULL;
    else if( (*head) == (*tail) )
        return *head;

    Node *pivot = partition(*head, *tail);
    cout<<"Head : "<<(*head)->data<<" Chosen Pivot : "<<pivot->data<<" tail : "<<(*tail)->data<<endl;

    pivot = sort(&head, pivot);
    pivot->next = sort(&pivot->next, tail);

    if(pivot->next)
        cout<<"pivot next : "<<pivot->next->data<<endl;

    return head;
}

Node* quickSort(struct Node **headRef) {
    if(!(*headRef)) {
        *headRef = NULL;
        return NULL;
    }
    Node *tail = *headRef;
    while(tail->next)
        tail = tail->next;

    *headRef = sort(*headRef, &tail);

    return *headRef;
}

int main(){
    SinglyLinkedList list;
    list.append(3);
    list.append(1);
    list.append(6);
    list.append(2);
    list.append(4);
	list.printList();
    Node* head = list.getHead();
    head = quickSort(&head);
    list.setHead(head);
    list.printList();
    return 0;
}
