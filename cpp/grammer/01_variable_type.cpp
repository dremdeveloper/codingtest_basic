#include <iostream>
#include <string>
#include <typeinfo>

int main() {
    int number = 10;
    double pi = 3.14;
    std::string text = "python";
    bool flag = true;

    std::cout << "number 타입: " << typeid(number).name() << " 값: " << number << "\n";
    std::cout << "pi 타입: " << typeid(pi).name() << " 값: " << pi << "\n";
    std::cout << "text 타입: " << typeid(text).name() << " 길이: " << text.size() << "\n";
    std::cout << "flag 타입: " << typeid(flag).name() << " 값: " << std::boolalpha << flag << "\n";
}
