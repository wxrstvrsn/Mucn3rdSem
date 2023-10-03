#include <iostream>
#include <memory>

template<typename T>
class ForwardList {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head;

public:
    ForwardList() : head(nullptr) {}

    void pushFront(const T &value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    void popFront() {
        if (!empty()) {
            head = std::move(head->next);
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    const T &front() const {
        if (!empty()) {
            return head->data;
        } else {
            throw std::runtime_error("List is empty.");
        }
    }
};

int main() {
    ForwardList<int> myList;

    myList.pushFront(3);
    myList.pushFront(2);
    myList.pushFront(1);

    std::cout << "Front element: " << myList.front() << std::endl;

    myList.popFront();
    std::cout << "Front element after popFront: " << myList.front() << std::endl;

    myList.popFront();
    myList.popFront();

    if (myList.empty()) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }

    return 0;
}
