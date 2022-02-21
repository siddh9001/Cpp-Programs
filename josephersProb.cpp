#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
}*head = nullptr;

void create_list(int data)
{
    node* nn = new node;
    nn->data = data;
    nn->next = NULL;

    if(head == NULL)
    {
        head = nn;
        head->next = head;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
}

int Jcircle(node* head)
{
    node *temp = head;
    int k;
    
    while(temp->next != temp)
    {
        k = key;
        for(i=0;i<key-1;i++)
            temp = temp->next;
        
        node* t = temp->next;
        temp->next = next;
        free(t);
    }
    return temp->data;
}


int main()
{
    int n;
    
}