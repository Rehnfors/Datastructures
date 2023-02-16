#include <iostream>
#include <list>

using namespace std;

class Node
{
private:
    list<Node> Nodelist;

public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int size()
    {
        int s = 1;

        if (this->left != NULL)
        {
            s += this->left->size();
        }
        if (this->right != NULL)
        {
            s += this->right->size();
        }

        return s;
    }

    int height(int height = 1)
    {
        int lhs = height, rhs = height;

        if (this->left != NULL)
        {
            lhs = this->left->height(height + 1);
        }
        if (this->right != NULL)
        {
            rhs = this->right->height(height + 1);
        }

        return (lhs > rhs ? lhs : rhs);
    }

    void print_tree()
    {
        int lhs = 1, rhs = 1;
        if (this->left != NULL)
        {
            cout << this->value << endl;
        }
        if (this->right != NULL)
        {
            cout << this->value << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Node root_node = Node(8);
    Node n1 = Node(3);
    Node n2 = Node(10);
    Node n3 = Node(1);
    Node n4 = Node(6);
    Node n5 = Node(14);
    Node n6 = Node(4);
    Node n7 = Node(7);
    Node n8 = Node(13);

    root_node.left = &n1;
    root_node.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n2.right = &n5;
    n4.left = &n6;
    n4.left = &n7;
    n5.left = &n8;

    return 0;
}
