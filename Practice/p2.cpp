#include <iostream>
#include <vector>
using namespace std;
int main(){
    struct Node{
       int data;
       Node*next;

    } ;
    
void insertatbeginning{ Node** head_ref, int new_data) {
    Node* new_node = New Node();
    new_node->data = new_data;
    new_node-> next = (*head_ref);
    (*head_ref) = new_Node;
}
}

    return 0;
}