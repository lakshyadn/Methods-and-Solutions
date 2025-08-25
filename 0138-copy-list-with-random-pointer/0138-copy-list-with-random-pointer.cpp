/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* og = head;
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        //make a clone list first
        while (og != NULL){
            Node* newnode = new Node(og -> val);
            if (clonehead == NULL){
                clonehead = newnode;
                clonetail = newnode;
            }
            else {
                clonetail -> next = newnode;
                clonetail = newnode;
            }
            og = og -> next;
        }

        // connect both 
        Node* ognode = head;
        Node* clonenode = clonehead;

        while (ognode != NULL && clonenode != NULL){
            Node* ognext = ognode -> next;
            ognode -> next = clonenode;
            ognode = ognext;

            Node* clonenext = clonenode -> next;
            clonenode -> next = ognext;
            clonenode = clonenext;
        }

        ognode = head;
        clonenode = clonehead;

        //random assign

        while (ognode != NULL && clonenode != NULL){
            if (ognode->random != NULL) {
                clonenode->random = ognode->random->next;
            } else {
                clonenode->random = NULL;
            }
            ognode = ognode -> next -> next;

            if (clonenode -> next != NULL){
                clonenode = clonenode -> next -> next;
            }
        }
        // diconnection lists

        ognode = head;
        clonenode = clonehead;
        while (ognode && clonenode){
            
            ognode -> next = clonenode -> next;
            ognode = ognode -> next;
            if (clonenode -> next != NULL){
                clonenode -> next = ognode-> next;
            }
            clonenode = clonenode -> next;
        }

        return clonehead;
    }
};