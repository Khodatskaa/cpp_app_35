#include <iostream>
#include <stdexcept>

class BaseException : public std::exception {
public:
    virtual const char* what() const noexcept {
        return "Base Exception";
    }
};

class MathException : public BaseException {
public:
    virtual const char* what() const noexcept override {
        return "Math Exception";
    }
};

class DivideByZeroException : public MathException {
public:
    const char* what() const noexcept override {
        return "Division By Zero Exception";
    }
};

class MemoryException : public BaseException {
public:
    virtual const char* what() const noexcept override {
        return "Memory Exception";
    }
};

class OutOfMemoryException : public MemoryException {
public:
    const char* what() const noexcept override {
        return "Out of Memory Exception";
    }
};

class FileException : public BaseException {
public:
    virtual const char* what() const noexcept override {
        return "File Exception";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "File Not Found Exception";
    }
};

double divide(double a, double b) {
    if (b == 0.0) {
        throw DivideByZeroException();
    }
    return a / b;
}

void allocateMemory(int size) {
    if (size <= 0) {
        throw OutOfMemoryException();
    }
}

void openFile(const std::string& filename) {
    if (filename == "nonexistent.txt") {
        throw FileNotFoundException();
    }
}

int main() {
    try {
        double result = divide(15.0, 0.0);
    }
    catch (const MathException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        allocateMemory(-1);
    }
    catch (const MemoryException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        openFile("nonexistent.txt");
    }
    catch (const FileException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
