// Function Object (functor)
#include <iostream>
#include <vector>
#include <random>

template<typename T>
class Less_than {
    const T val;

public:
    explicit Less_than(const T& v) : val(v) {}
    bool operator()(const T& x) const { return x<val; }
};


// Randomize integer
int randomInt() {
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Mersennse twister    
    std::uniform_int_distribution<> distr(1, 10);

    return distr(gen);
}

template<typename V>
void printAll(const std::vector<V> &vect) {
    for (auto &x : vect)
        std::cout << x << " ";
    std::cout << std::endl;
}

// Counter
template<typename C, typename P>
int count(const C& c, P pred) {
    int cnt = 0; // stands for count :v
    for (auto& x : c)
        if(pred(x)) ++cnt;
    return cnt;
}

void f(const std::vector<int>& vec, int x) {
    std::cout << "Number of values less than " << x
              << ": " << count(vec, Less_than<int> {x})
              << std::endl;
}

int main() {
    std::vector<int> v_int(10);
    for (auto &x : v_int)
        x = randomInt();
    printAll(v_int);

    f(v_int, 5);

    return 0;
}