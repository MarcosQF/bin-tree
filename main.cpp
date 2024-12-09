#include <iostream>
#include <queue>
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

Node* localizaMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->left == nullptr) {
        return root;
    }

    return localizaMin(root->left);
}

void desalocar(Node* node) {
    delete node;
}

void remove(Node*& root, int value) {
    if (root == nullptr) {
        return;
    }

    if (value < root->data) {
        remove(root->left, value);
    } else if (value > root->data) {
        remove(root->right, value);
    } else {
        
        if (root->left != nullptr && root->right != nullptr) {
            Node* auxPoint = localizaMin(root->right);
            root->data = auxPoint->data;
            remove(root->right, auxPoint->data);
        }
        else {
            Node* auxPoint = root;
            if (root->left != nullptr) {
                root = root->left;
            } else {
                root = root->right;
            }
            desalocar(auxPoint);
        }
    }
}

void preOrdem(Node* root){

    cout<<root->data<<" ";
    
    if (root->left != nullptr)
    {
        preOrdem(root->left);
    }

    if (root->right != nullptr)
    {
        preOrdem(root->right);
    } 
}

void ordemSimetrica(Node* root){
    if (root->left != nullptr)
    {
        ordemSimetrica(root->left);
    }

    cout<<root->data<<" ";

    if (root->right != nullptr)
    {
        ordemSimetrica(root->right);
    }   
}

void posOrdem(Node* root){
     if (root->left != nullptr)
    {
        preOrdem(root->left);
    }

    if (root->right != nullptr)
    {
        preOrdem(root->right);
    } 
    cout<<root->data<<" ";
}

void nivelOrdem(Node* root){
     if (root == nullptr) {
        return; 
    }

    queue<Node*> q;
    q.push(root); 

    while (!q.empty()) {
        Node* current = q.front(); 
        q.pop(); 

        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
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

    cout<<endl;
    cout << "\nNúmero de nós: " << countNodes(root) << endl;
    cout << "Número de folhas: " << countLeaves(root) << endl;

    int removeValue;
    cout << "Digite o número que deseja remover: " ;
    cin >> removeValue;
    remove(root, removeValue);
    printTree(root);
    cout<<endl;

    cout << "Visita árvore Pre Ordem: "<<endl;
    preOrdem(root);
    cout<<endl;

    cout << "Visita árvore Ordem Simetrica: "<<endl;
    ordemSimetrica(root);
    cout<<endl;

    cout << "Visita árvore Pós Ordem: "<<endl;
    posOrdem(root);
    cout<<endl;

    cout << "Visita árvore Por Nível: "<<endl;
    nivelOrdem(root);
    cout<<endl;

    return 0;
}
