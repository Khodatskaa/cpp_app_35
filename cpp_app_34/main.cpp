#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;

    int* data;
    int top;

public:
    Stack() : data(new int[MAX_SIZE]), top(-1) {
        if (data == nullptr) {
            throw std::bad_alloc(); // Memory allocation failure
        }
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        try {
            if (top == MAX_SIZE - 1) {
                throw std::overflow_error("Stack overflow");
            }

            data[++top] = value;
        }
        catch (const std::overflow_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw;
        }
    }

    int pop() {
        try {
            if (top == -1) {
                throw std::underflow_error("Stack underflow");
            }

            return data[top--];
        }
        catch (const std::underflow_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw;
        }
    }

    int peek() const {
        try {
            if (top == -1) {
                throw std::underflow_error("Cannot peek an empty stack");
            }

            return data[top];
        }
        catch (const std::underflow_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw;
        }
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }
};

int main() {
    try {
        Stack myStack;

        int inputValue;

        std::cout << "Enter values to push onto the stack (enter - to stop):" << std::endl;

        while (std::cin >> inputValue) {
            myStack.push(inputValue);
        }

        if (std::cin.fail() && !std::cin.eof()) {     // cin.eof() is true if end of file is reached
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //numeric_limits<std::streamsize>::max() - maximum number of characters to ignore
            throw std::invalid_argument("Invalid input. Please enter integers only");
        }

        while (!myStack.isEmpty()) {
            std::cout << "Popped: " << myStack.pop() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
