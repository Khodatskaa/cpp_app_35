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

class IOException : public FileException {
public:
    const char* what() const noexcept override {
        return "IO Exception";
    }
};

int main() {
    try {
        throw DivideByZeroException();
    }
    catch (const MathException& mathException) {
        std::cout << "Caught Math Exception: " << mathException.what() << std::endl;
    }
    catch (const OutOfMemoryException& memoryException) {
        std::cout << "Caught Memory Exception: " << memoryException.what() << std::endl;
    }
    catch (const BaseException& baseException) {
        std::cout << "Caught Base Exception: " << baseException.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
