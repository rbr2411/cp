#include <bits/stdc++.h>
using namespace std;
map<int, int> m;

class Node{
    int data;
    Node* next;

    public:Node* insert(Node* head, int data)
    {
        Node* track = head;
        while(track -> next != NULL)
            track = track -> next;
        Node* temp = new Node();
        temp -> data = data;
        temp -> next = NULL;
        track -> next = temp;
        m[data]++;
        return head;
    }

    public: Node* Delete(Node* head, int data)
    {
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != data)
            temp = temp -> next;
        Node* rem = temp-> next;
        temp->next = temp->next->next;
        free(rem);
        m[data]--;
        return rem;
    }

    public: void printList(Node* head)
    {
        Node* temp = head;
        while(temp-> next!= nullptr)
        {
            temp = temp -> next;
            cout << temp-> data << endl;
        }
    }

    public: void DeleteDups(Node* head)
    {
        head = head->next;
        map<int, int> mp;
        Node* prev = NULL;
        while(head != NULL)
        {
            if(mp[head->data] > 0)
            {   
                Node* temp = head;
                prev->next = head->next;
                head = head->next;
                free(temp);
            }
            else
            {
                mp[head->data]++;
                prev = head;
                head = head->next;
            }
        }
    }

    public: void deleteDups2(Node* head)
    {
        head = head->next;
        Node* current = head;
        while(current != nullptr)
        {
            Node* runner = current;
            while(runner->next != NULL)
            {
                if(runner->next->data == current->data)
                {
                    runner->next = runner->next->next;
                }
                else
                    runner = runner->next;
            }
            current = current ->next;
        }
    }
};

int main()
{
    Node b;
    Node* p = new Node();
    b.insert(p,11);
    b.insert(p,9);
    b.insert(p,8);
    b.insert(p,11);
    b.insert(p,5);
    b.insert(p,4);
    b.insert(p,0);
    b.insert(p,3);
    b.insert(p,8);
    b.insert(p,9);

    b.printList(p);

    cout << "----------------------" << endl;
    // b.Delete(p,8);
    // b.Delete(p,8);
    // b.printList(p);
    
    // for(auto it : m)
    // {
    //     if(it.second > 1)
    //         b.Delete(p,it.first);
    // }
    //b.DeleteDups(p);
    b.deleteDups2(p);
    b.printList(p);
}