#include <iostream>

int customStringToInt(const std::string& str) {
    try {
        int result = 0;
        int sign = 1;
        size_t i = 0;

        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
        }

        for (; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                int digit = str[i] - '0';

                if (result > (std::numeric_limits<int>::max() - digit) / 10) {
                    throw std::overflow_error("Conversion resulted in overflow");
                }

                result = result * 10 + digit;
            }
            else {
                throw std::invalid_argument("Invalid characters in the string");
            }
        }

        return result * sign;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    std::string input;
    std::cout << "Enter a decimal number as a string: ";
    std::cin >> input;

    int result = customStringToInt(input);

    std::cout << "Result: " << result << std::endl;

    return 0;
}