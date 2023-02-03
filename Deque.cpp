#include <iostream>

using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;

    Node()
    {
        data;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Deque
{
public:
    Node *head, *tail;

    Deque()
    {
        head = NULL;
        tail = NULL;
    }

    void print_list()
    {
        Node *node = this->head;

        while (node != NULL)
        {
            cout << node->data << endl;
            node = node->next;
        }
        cout << endl;
    }

    void add_first(int data)
    {
        Node *new_node = new Node(data);

        if (this->head == NULL)
        {
            this->head = new_node;
        }

        new_node->next = head;
        this->head = new_node;
    }

    void add_last(int data)
    {
        Node *new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;

        if (this->head == NULL)
        {
            this->head = new_node;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    void remove_first()
    {
        Node *node = this->head;

        if (node == NULL)
        {
            cout << "Deque is empty" << endl;
        }

        else
        {
            this->head = node->next;
        }
    }

    void remove_last()
    {
        Node *node = this->head;

        if (node == NULL)
        {
            cout << "The list is empty." << endl;
        }
        if (node->next == NULL)
        {
            node = NULL;
        }

        Node *second_last = this->head;
        while (second_last->next->next != NULL)
        {
            second_last = second_last->next;
        }
        delete second_last->next;
        second_last->next = NULL;
    }

    bool is_empty()
    {
        if (this->head == NULL)
        {
            cout << "The list is empty." << endl;
            return true;
        }

        else
        {
            cout << "The list is not empty." << endl;
            return false;
        }
    }

    void size()
    {
        Node *node = this->head;
        int counter = 0;

        while(node != NULL)
        {
            counter++;
            node = node->next;
        }

        cout << counter << " nodes." << endl;
    }
};

int main(int argc, char const *argv[])
{
    Deque *d = new Deque();
    int size;

    d->add_first(3);
    d->add_last(4);
    d->add_first(2);
    d->add_last(5);

    cout << "First list: " << endl;
    d->print_list();

    d->remove_first();

    cout << "Removed first: " << endl;
    d->print_list();

    d->remove_last();
    cout << "Removed last: " << endl;
    d->print_list();
    
    cout << "Running is_empty(): " << endl;
    d->is_empty();

    cout << "Size of list: " << endl;
    d->size();

    return 0;
}
