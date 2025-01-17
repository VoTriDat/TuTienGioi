#include <iostream>
using namespace std;
struct Node{
    int info;
    Node *left;
    Node *right;
};
Node *root;
void init(){
    root = NULL;
}
Node *taoNode(int x){
    Node *p = new Node();
    p ->info = x;
    p ->left =NULL;
    p->right =NULL;
    return p;
}
void insertTree(Node *& root, int x){
    if(root == NULL){
        root = taoNode(x);
    }
    else if(x < root ->info){
        insertTree(root->left, x);
    }
    else if(x > root ->info){
        insertTree(root->right, x);
    }
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);       // Duyệt trái
        cout << root->info << " "; // In giá trị node
        inorder(root->right);      // Duyệt phải
    }
}

// Duyệt cây theo thứ tự tiền tố (Pre-order Traversal)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->info << " "; // In giá trị node
        preorder(root->left);      // Duyệt trái
        preorder(root->right);     // Duyệt phải
    }
}

// Duyệt cây theo thứ tự hậu tố (Post-order Traversal)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);     // Duyệt trái
        postorder(root->right);    // Duyệt phải
        cout << root->info << " "; // In giá trị node
    }
}
Node *findMin(Node *root){
    if(root ->left != NULL){
        root = root ->left;
    }
    return root;
}
int main(){
    insertTree(root, 50);
    insertTree(root, 30);
    insertTree(root, 70);
    insertTree(root, 20);
    insertTree(root, 40);
    insertTree(root, 60);
    insertTree(root, 80);

    // Duyệt cây theo thứ tự In-order
    cout << "Cay nhi phan (In-order): ";
    inorder(root);
    cout << endl;
}