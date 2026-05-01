#include <iostream>

template<typename T, int N>
struct Buffer {
    using type_name = T;
    constexpr int size() {return N;}
    T data[N];
};

template<typename B>
void process_buffer(B& b) {
    typename B::type_name temp;
    std::cout << temp << std::endl;
}

int main() {
    Buffer<char, 1024> bf_c;
    process_buffer(bf_c);
    std::cout << "Buffer size: " << bf_c.size() << std::endl;

    return 0;
}