#include <iostream>
#include <iomanip>

template <typename Tc>
struct Node
{
        Tc value;
        struct Node *link;
};

template <typename Tc>
struct Iterator
{
        Tc *itr;
        bool hasNext() const {

        };
        Tc *operator++(){

        };
        Tc *operator--(){

        };
};

template <typename Tc>
Node<Tc> *initList(Tc value)
{
        Node<Tc> *node = new Node<Tc>();
        node->value = value;
        node->link = nullptr;
        return node;
};

template <typename Tc>
void insertNode(Node<Tc> *node, Tc val)
{
        if (node == nullptr)
        {
                try
                {
                        initList(val);
                }
                catch (const std::exception &err)
                {
                        std::cout << err.what() << std::endl;
                };
        }
        else
        {
                Node<Tc> *newnode = new Node<Tc>();
                newnode->value = val;
                newnode->link = nullptr;

                while (node->link != nullptr)
                {
                        node = node->link;
                }
                node->link = newnode;
        }
}

template <typename Tc>
bool search(Node<Tc> *node, Tc val)
{
        if (node == nullptr)
        {
                return false;
        }
        else
        {
                Node<Tc> *current = node;
                while (current != nullptr)
                {
                        if (current->value == val)
                        {
                                return true;
                        }
                        current = current->link;
                }

                return false;
        }
}

template <typename Tc>
void deleteNode(Node<Tc> *node, Tc value)
{
        if (node == nullptr)
        {
                return;
        }
        else
        {
            
        }
}

template <typename Tc>
void print(Node<Tc> *node)
{
        Node<Tc> *current = node;
        while (current != nullptr)
        {
                std::cout << current->value << std::endl;
                current = current->link;
        }
}

template <typename Tc>
void TestLink(Node<Tc> *head)
{
        insertNode(head, 56);
        insertNode(head, 23);
        insertNode(head, 12);
        insertNode(head, 67);
        insertNode(head, 89);
        std::cout
            << std::boolalpha << search(head, 90) << std::endl;
        deleteNode(head, 12);
        print(head);
        //free head
        delete head;
}

int main(int argc, const char **argv)
{
        Node<int> *head = initList(45);

        TestLink(head);

        return 0;
}