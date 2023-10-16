
template <class T>
struct Node {
    T data;
    Node* next;

    Node(const T& item) : data(item), next(nullptr) {}
};

template <class T>
class StackList {
private:
    Node<T>* topNode;

public:
    StackList() : topNode(nullptr) {}

    ~StackList() {
        while (!empty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = topNode;
        topNode = newNode;
    }

    T top() const {
        if (empty()) {
            throw std::out_of_range("La pila está vacía");
        }
        return topNode->data;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("La pila está vacía");
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    bool empty() const {
        return topNode == nullptr;
    }
};
