#include <iostream>
#include <queue>
#include <new>
#include <map>
using namespace std;

typedef struct binarytreenode
{
    int data;
    struct binarytreenode *left,*right;
}Node;

Node * create_btree();
void vertical_trav(Node *);

int main()
{
    Node *root;
    root=create_btree();
    vertical_trav(root);
}
Node * create_btree()
{
    int inp;
    cout<<"Enter data: ";
    cin>>inp;
    if(inp==-1)
        return NULL;
    Node *new_node=new Node;
    new_node->data=inp;
    cout<<"Enter for Left Child:-\n";
    new_node->left=create_btree();
    cout<<"Enter for Right Child:-\n";
    new_node->right=create_btree();
    return new_node;
}

void vertical_trav(Node *root)
{
   // Base case
    if (!root)
        return;

    // Create a map and store vertical oder in
    // map using function getVerticalOrder()
    map<int, vector<int> > m;
    int hd = 0;

    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node*, int> > que;
    que.push(make_pair(root, hd));

    while (!que.empty()) {
        // pop from queue front
        pair<Node*, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node* node = temp.first;

        // insert this node's data in vector of hash
        m[hd].push_back(node->data);

        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }

    // Traverse the map and print nodes at
    // every horigontal distance (hd)
    map<int, vector<int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
