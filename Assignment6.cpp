#include <bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
    bool leftthread;
    bool rightthread;
};

class TBT
{
public:
    struct Node *insert(struct Node *root, int kkey)
    {
        Node *ptr = root;
        Node *par = NULL;
        while (ptr != NULL)
        {
            if (kkey == (ptr->data))
            {
                printf("Duplicate Key !\n");
                return root;
            }
            par = ptr;
            if (kkey < ptr->data)
            {
                if (ptr->leftthread == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else
            {
                if (ptr->rightthread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        Node *tmp = new Node;
        tmp->data = kkey;
        tmp->leftthread = true;
        tmp->rightthread = true;

        if (par == NULL)
        {
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (ikey < (par->data))
        {
            tmp->left = par->left;
            tmp->right = par;
            par->leftthread = false;
            par->left = tmp;
        }
        else
        {
            tmp->left = par;
            tmp->right = par->right;
            par->rightthread = false;
            par->right = tmp;
        }

        return root;
    }

    struct Node *inorderSuccessor(struct Node *ptr)
    {

        if (ptr->rightthread == true)
            return ptr->right;

        ptr = ptr->right;
        while (ptr->leftthread == false)
            ptr = ptr->left;
        return ptr;
    }

    void inorder(struct Node *root)
    {
        if (root == NULL)
            printf("Tree is empty");

        struct Node *ptr = root;
        while (ptr->leftthread == false)
            ptr = ptr->left;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = inorderSuccessor(ptr);
        }
    }
    void preorder(struct Node *root)
    {
        struct Node *ptr;
        if (root == NULL)
        {
            printf("Tree is empty");
            return;
        }
        ptr = root;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            if (ptr->leftthread == false)
                ptr = ptr->left;
            else if (ptr->rightthread == false)
                ptr = ptr->right;
            else
            {
                while (ptr != NULL && ptr->rightthread == true)
                    ptr = ptr->right;
                if (ptr != NULL)
                    ptr = ptr->right;
            }
        }
    }
};

int main()
{
    struct Node *root = NULL;
    TBT t = TBT();
    cout << "Press 1 to Insert Element:- " << endl;
    cout << "Press 2 for Inorder Traversal:- " << endl;
    cout << "Press 3 for Preorder Traversal:- " << endl;
    cout << "Press 4 to Exit." << endl;

    bool check = true;
    while (check)
    {
        cout << "Enter Option:- " << endl;
        int op;
        cin >> op;
        switch (op)
        {

        case 1:
            cout << "Enter Element you want to Insert." << endl;
            int element;
            cin >> element;
            root = t.insert(root, element);
            break;

        case 2:
            cout << "Inorder Traversal:- " << endl;
            t.inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal:- " << endl;
            t.preorder(root);
            cout << endl;
            break;

        case 4:
            check = false;
            break;

        default:
            break;
        }
    }

    return 0;
}
