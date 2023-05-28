/*Beginning with an empty binary search tree, Construct a binary search tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Display BST
iv. Minimum data value found in the tree
 
***********************************************************************************************/
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class btree
{
public:
    node *root;
    btree()
    {
        root = NULL;
    }
    void create()
    {

        int i, n, ch;

        cout << "Enter total no. of nodes: ";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            node *newnode = new node;
            cout << "Enter the element: ";
            cin >> ch;

            newnode->data = ch;
            if (root == NULL)
            {
                root = newnode;
            }
            else
            {
                insert(root, newnode);
            }
        }
    }

    void insert(node *temp, node *newnode)
    {
        if (temp->data < newnode->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newnode;
            }
            else
            {
                insert(temp->right, newnode);
            }
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = newnode;
            }
            else
            {
                insert(temp->left, newnode);
            }
        }
    }
    

    
    void min_value(node *temp)
    {
        if (temp != NULL)
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
        cout << temp->data;
    }
    

    void find(node *root, int key)
    {
        if (root != NULL)
        {
            if (key == root->data)
                cout << "Key found" << endl;

            else if (key < root->data)
                find(root->left, key);
            else
                find(root->right, key);
        }
    }

    int depth(node *root)
    {
        int hleft, hright;
        if (root == NULL || ((root->left == NULL) && (root->right == NULL)))
            return (0);
        else
        {
            hleft = depth(root->left);
            hright = depth(root->right);
        }
        if (hleft > hright)
        {
            return (hleft + 1);
        }
        else
        {
            return (hright + 1);
        }
    }

    void inorder(node *temp)
    {
        if (temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << "\t";
            inorder(temp->right);
        }
    }

    void disp_in()
    {
        if (root != NULL)
        {
            inorder(root);
        }
    }

};

int main()
{
    btree v;
    int n;
    char ch;

    do
    {
        cout << "\n\n## MENU ##\n\n1)Insert";
        cout << "\n2)Number of nodes in longest path from root\n3)Dispaly\n4)Find minimum value \nEnter your choice:";
        cin >> n;
        switch (n)
        {
        case 1:
            v.create();
            cout << "Binary tree constructed successfully\n";
            break;
        case 2:
            cout << "Number of nodes in longest path from root : " << (v.depth(v.root)+1)<< endl;
            break;
        case 3:
            cout << "Inorder of tree" << endl;
            v.disp_in();
            break;
        case 4:
            cout << "Minimum value is:";
            v.min_value(v.root);
            break;
        }
        cout << "\n\nContinue?(Y/N)" << endl;
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}