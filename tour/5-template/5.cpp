#include <iostream>
#include <string>

template<typename T, int N>
struct Buffer {
    using type_name = T;
    constexpr int size() {return N;}
    T data[N];
};

template<typename B>
void process_buffer(B& buffer) {
    typename B::type_name temporary_item;
    
    std::cout << "Type: " << typeid(temporary_item).name() << " processed." << std::endl;
}

int main() {
    Buffer<double, 64> glob;
    std::cout << "Size: " << glob.size() << std::endl;
    process_buffer(glob);

    Buffer<std::string, 32> glob2;
    process_buffer(glob2);

    return 0;
}