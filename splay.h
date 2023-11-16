#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
#include <vector>

template <typename T>
class SplayNode {
public:
    T data;
    SplayNode* left;
    SplayNode* right;

    SplayNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class SplayTree {
private:
    SplayNode<T>* root;

    // Métodos de rotación
    SplayNode<T>* rightRotate(SplayNode<T>* node);
    SplayNode<T>* leftRotate(SplayNode<T>* node);

    // Métodos de splay
    SplayNode<T>* splay(SplayNode<T>* root, const T& value);

    // Métodos auxiliares para insertar y buscar
    SplayNode<T>* insert(SplayNode<T>* root, const T& value);
    SplayNode<T>* search(SplayNode<T>* root, const T& value);
    
    //Metodo auxiliar para hacer el recorrido
void inorderAux(SplayNode<T>* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << "Entre a InorderAux" << std::endl;
    if (node->left != nullptr) {
        inorderAux(node->left);
    }

    std::cout << "Nombre: " << node->data.getNombre() << ", Liga: " << node->data.getLiga() << ", Valor: " << node->data.getValor() << ", Goles: " << node->data.getGoles() << std::endl;

    if (node->right != nullptr) {
        inorderAux(node->right);
    }
    }

public:
    SplayTree() : root(nullptr) {}
    
    //Metodo principal para hacer el recorrido
    void inOrderTraversal() {
        inOrderTraversalAux(root);
    }
    //Metodo de inserción
    void insert(const T& value);
    // Metodo de búsqueda
    bool search(const T& value);
    void inorder() {
        inorderAux(root);
    }
};

template <typename T>
SplayNode<T>* SplayTree<T>::rightRotate(SplayNode<T>* node) {
    SplayNode<T>* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    return newRoot;
}

template <typename T>
SplayNode<T>* SplayTree<T>::leftRotate(SplayNode<T>* node) {
    SplayNode<T>* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    return newRoot;
}

template <typename T>
SplayNode<T>* SplayTree<T>::splay(SplayNode<T>* root, const T& value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        if (root->left == nullptr) {
            return root;
        }

        if (value < root->left->data) {
            root->left->left = splay(root->left->left, value);
            root = rightRotate(root);
        }
        else if (value > root->left->data) {
            root->left->right = splay(root->left->right, value);
            if (root->left->right != nullptr) {
                root->left = leftRotate(root->left);
            }
        }

        return (root->left == nullptr) ? root : rightRotate(root);
    }
    else {
        if (root->right == nullptr) {
            return root;
        }

        if (value < root->right->data) {
            root->right->left = splay(root->right->left, value);
            if (root->right->left != nullptr) {
                root->right = rightRotate(root->right);
            }
        }
        else if (value > root->right->data) {
            root->right->right = splay(root->right->right, value);
            root = leftRotate(root);
        }

        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

template <typename T>
SplayNode<T>* SplayTree<T>::insert(SplayNode<T>* root, const T& value) {
    if (root == nullptr) {
        return new SplayNode<T>(value);
    }

    root = splay(root, value);

    if (root->data == value) {
        return root;
    }

    SplayNode<T>* newNode = new SplayNode<T>(value);

    if (value < root->data) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }

    return newNode;
}

template <typename T>
SplayNode<T>* SplayTree<T>::search(SplayNode<T>* root, const T& value) {
    return splay(root, value);
}

template <typename T>
void SplayTree<T>::insert(const T& value) {
    root = insert(root, value);
}

template <typename T>
bool SplayTree<T>::search(const T& value) {
    root = search(root, value);
    return (root != nullptr && root->data == value);
}


#endif // SPLAYTREE_H
