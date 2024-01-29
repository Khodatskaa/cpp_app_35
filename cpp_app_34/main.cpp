#include <iostream>

class DoubleList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList() { DeleteAll(); }

    void AddToHead() {
        int value;
        std::cout << "Enter value to add to head: ";

        if (!(std::cin >> value)) {
            std::cout << "Error: Invalid input. Please enter a valid integer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        try {
            Node* newNode = new Node(value);
            if (newNode == nullptr) {
                throw std::bad_alloc(); // Out of memory exception
            }

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        catch (const std::bad_alloc& e) {
            std::cout << "Error: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void AddToTail() {
        int value;
        std::cout << "Enter value to add to tail: ";

        if (!(std::cin >> value)) {
            std::cout << "Error: Invalid input. Please enter a valid integer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        try {
            Node* newNode = new Node(value);
            if (newNode == nullptr) {
                throw std::bad_alloc(); // Out of memory exception
            }

            if (tail == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
        catch (const std::bad_alloc& e) {
            std::cout << "Error: " << e.what() << std::endl;
            exit(EXIT_FAILURE);
        }
    }


    void DeleteFromHead() {
        try {
            if (head == nullptr) {
                throw std::out_of_range("Cannot delete from an empty list");
            }
            else if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    void DeleteFromTail() {
        try {
            if (tail == nullptr) {
                throw std::out_of_range("Cannot delete from an empty list");
            }
            else if (head == tail) {
                delete tail;
                head = nullptr;
                tail = nullptr;
            }
            else {
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    void DeleteAll() {
        while (head != nullptr) {
            DeleteFromHead();
        }
    }

    void Show() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoubleList myList;

    int choice;
    int value;

    do {
        std::cout << "1. Add to Head\n";
        std::cout << "2. Add to Tail\n";
        std::cout << "3. Delete from Head\n";
        std::cout << "4. Delete from Tail\n";
        std::cout << "5. Show List\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            myList.AddToHead();
            break;
        case 2:
            myList.AddToTail();
            break;
        case 3:
            myList.DeleteFromHead();
            break;
        case 4:
            myList.DeleteFromTail();
            break;
        case 5:
            myList.Show();
            break;
        case 0:
            std::cout << "Exiting program...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again\n";
        }
    } while (choice != 0);

    return 0;
}

