// Value type argument
#include <iostream>

template<typename T, int N>
struct Buffer {
    using value_type = T;

    // Added 'const' to ensure it can be called on const objects
    constexpr int size() const { return N; }

    // Arrays must have a member name
    T data[N]; 
};

int main() {
    // This now works perfectly
    Buffer<char, 1024> glob;
    
    std::cout << "Buffer size: " << glob.size() << " bytes." << std::endl;

    return 0;
}