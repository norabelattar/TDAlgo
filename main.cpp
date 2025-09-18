#include <iostream>

int b = 12;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
        int x = 50;
        int * p = new int(666);

        std::cout << x << std::endl;
        std::cout << &x << std::endl;

        std::cout << p << std::endl;
        std::cout << *p << std::endl;
}