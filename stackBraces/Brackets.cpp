#include <iostream>
#include <stack>
#include <string>

unsigned findMismatchedBracket(const std::string &input) {
    std::stack<unsigned> openParenStack;
    std::stack<unsigned> openBracketStack;
    std::stack<unsigned> openBraceStack;
    unsigned ret = 0;

    for (unsigned i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            openParenStack.push(i + 1);
        } else if (input[i] == ')') {
            if (openParenStack.empty()) {
                return i + 1;
            } else {
                openParenStack.pop();
            }
        } else if (input[i] == '[') {
            openBracketStack.push(i + 1);
        } else if (input[i] == ']') {
            if (openBracketStack.empty()) {
                return i + 1;
            } else {
                openBracketStack.pop();
            }
        } else if (input[i] == '{') {
            openBraceStack.push(i + 1);
        } else if (input[i] == '}') {
            if (openBraceStack.empty()) {
                return i + 1;
            } else {
                openBraceStack.pop();
            }
        }
    }

    if (!openParenStack.empty()) {
        return openParenStack.top();
    } else if (!openBracketStack.empty()) {
        return openBracketStack.top();
    } else if (!openBraceStack.empty()) {
        return openBraceStack.top();
    }

    return ret;
}

int main() {
    std::string input_str;

    while (true) {
        std::getline(std::cin, input_str);

        if (input_str.empty()) {
            break;
        }

        unsigned result = findMismatchedBracket(input_str);
        if (result == 0) {
            std::cout << "Success" << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }

    return 0;
}
