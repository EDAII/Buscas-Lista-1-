#include <iostream>
#include <queue>

using namespace std;

enum Color {RED, BLACK};

struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;

    // Constructor
    Node(int data)
    {
       this->data = data;
       left = right = parent = NULL;
    }
};

// Class to represent Red-Black Tree
class RBTree
{
private:
    Node *root;
protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);
public:
    // Constructor
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

// A recursive function to do level order traversal
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;

    inorderHelper(root->left);
    cout << root->data;
    if(root->color == 0)
        cout << " [VERMELHO] ";
    else
        cout << " [PRETO] ";
    inorderHelper(root->right);
}

/* A utility function to insert a new node with given key
   in BST */
Node* BSTInsert(Node* root, Node *pt) {
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;

    /* Otherwise, recur down the tree */
    if (pt->data <= root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    /* return the (unchanged) node pointer */
    return root;
}

void RBTree::rotateLeft(Node *&root, Node *&pt) {
    cout << "Rotação para a Esquerda" << endl;
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(Node *&root, Node *&pt) {
    cout << "Rotação para a Direita" << endl;
    Node *pt_left = pt->left;

    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

// This function fixes violations caused by BST insertion
void RBTree::fixViolation(Node *&root, Node *&pt) {
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;

    if(pt == root)
        cout << "== Caso 1: Nó é a raiz, muda a cor do nó ==" << endl;

    if(pt->color == BLACK)
        cout << "== Caso 2: Não viola as propriedades ==" << endl;

    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        /*  Case : A
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {

            Node *uncle_pt = grand_parent_pt->right;

            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == RED) {
                cout << "== Caso 3: Pai vermelho e tio vermelho ==" << endl;
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right) {
                    cout << "== Caso 4: Rotação para fora ==" << endl;
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                cout << "== Caso 5: Rotação muda cor do pai e do avo ==" << endl;
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }

        /* Case : B
           Parent of pt is right child of Grand-parent of pt */
        else {
            Node *uncle_pt = grand_parent_pt->left;

            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == RED)) {
                cout << "== Caso 3: Pai vermelho e tio vermelho ==" << endl;
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left) {
                    cout << "== Caso 4: Rotação para fora ==" << endl;
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                cout << "== Caso 5: Rotação muda cor do pai e do avo ==" << endl;
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

// Function to insert a new node with given data
void RBTree::insert(const int &data)
{
    Node *pt = new Node(data);
    // Mensage to visualize insert
    cout << endl << "Inserir novo nó: " << endl;
    cout << "valor = " << pt->data << endl;
    if(pt->color  == 0)
        cout << "cor = VERMELHO" << endl << endl;
    else
        cout << "cor = PRETO" << endl << endl;

    // Do a normal BST insert
    root = BSTInsert(root, pt);

    // fix Red Black Tree violations
    fixViolation(root, pt);
}

// Function to do inorder and level order traversals
void RBTree::inorder() {
    inorderHelper(root);
}

int main() {
    RBTree tree;
    int value;

    cout << "Insira valores na arvore." << endl
         << "(Qualuer valor não numerico para sair)" << endl;
    // Read the values and insert in the tree
    while(scanf("%d", &value)) {
        tree.insert(value);
    }

    cout << endl << "Travessia em ordem" << endl;
    tree.inorder();

    cout << endl;

    return 0;
}
