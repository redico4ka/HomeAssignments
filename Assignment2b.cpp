/* Nagulyak Michail st132694@student.spbu.ru 
Assignment2b
*/

#include <iostream>
#include <cstring>

class Stack {
private:
    int* arr;
    int maxSize;
    int top;

public:
    Stack(int size) : maxSize(size), top(-1) {
        arr = new int[maxSize];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top < maxSize - 1) {
            arr[++top] = value;
        }
        else {
            std::cerr << "Стек переполнен!" << std::endl;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        else {
            std::cerr << "Стек пуст!" << std::endl;
            return -1; 
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            std::cerr << "Стек пуст!" << std::endl;
            return -1; 
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack stack(10);
    char input[100];
    
    std::cout << "Введите выражение (пробел - разделитель): ";
    std::cin.getline(input, 100);

    char* token = strtok(input, " ");
    while (token != nullptr) {
        if (isdigit(token[0])) {
            stack.push(atoi(token));
        }
        else {
            int b = stack.pop();
            int a = stack.pop();
            switch (token[0]) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                default: std::cerr << "Неизвестная операция!" << std::endl; break;
            }
        }
        token = strtok(nullptr, " ");
    }

    std::cout << "Результат: " << stack.peek() << std::endl;

    return 0;
}
