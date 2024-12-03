#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value); 
    }

    if (value < root->data) {
        root->left = insert(root->left, value); 
    } else {
        root->right = insert(root->right, value); 
    }

    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false; 
    }
    if (root->data == value) {
        return true; 
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

void printTree(Node* root, int space = 0, int COUNT = 5) {
    if (root == nullptr) {
        return;
    }

    space += COUNT;

    printTree(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data;

    printTree(root->left, space);
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Digite o número de elementos na árvore: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "Digite o número que deseja buscar: ";
    cin >> value;
    if (search(root, value)) {
        cout << "O número " << value << " foi encontrado" << endl;
    } else {
        cout << "O número " << value << " não foi encontrado" << endl;
    }

    cout << "Impressão Árvore Binária:" << endl;
    printTree(root);

    cout << "\nNúmero de nós: " << countNodes(root) << endl;


    cout << "Número de folhas: " << countLeaves(root) << endl;

    return 0;
}
