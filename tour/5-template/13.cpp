// Lambda function
#include <iostream>
#include <vector>

template<typename C, typename Oper>
void for_all(C& c, Oper op) {
    for (auto &x: c)
        op(*x); // Designed to work for pointer container
}

void print_all(const std::vector<int*> vec) {
    for (auto& x: vec) std::cout << x << " " << *x << std::endl;
}

int main() {
    int sz = 10;

    std::vector<int*> vec(sz);
    for (int i=0; i<sz; i++) vec[i]=new int(i);
    print_all(vec);
    std::cout << std::endl;

    for_all(vec, [](int& x) {x=x*2;});
    print_all(vec);

    return 0;
}