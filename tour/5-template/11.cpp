#include <iostream>
#include <vector>
#include <random>
#include <string>

template<typename T>
class Less_than {
    T val;

public:
    explicit Less_than(const T &v) : val(v) {}
    bool operator()(const T &x) const { return x<val; }
};

int randomInt(const int& min, const int& max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}

void askUser(int& val, const std::string& txt) {
    std::cout << txt;
    std::cin >> val;
    std::cout << std::endl;
}

template<typename C, typename P>
int count(const C& c, P predicate) {
    int count = 0;
    for (auto& x: c)
        if (predicate(x)) count++;
    return count;
}

void f(const std::vector<int>& vec, const int& x) {
    std::cout << "Number of element less than: "
              << " : " << count(vec, Less_than<int>{x})
              << std::endl;
}

void printAll(const std::vector<int>& x) {
    for (auto& element : x)
        std::cout << element << " ";
    std::cout << std::endl;
}

int main() {
    int sz, x, bound_min, bound_max;
    askUser(sz, "Size of the vector: ");
    askUser(x, "Less than: ");
    askUser(bound_min, "Minimum value: ");
    askUser(bound_max, "Max value: ");

    std::vector<int> vec_int(sz);
    for (auto& element: vec_int)
        element = randomInt(bound_min, bound_max);
    
    printAll(vec_int);
    f(vec_int, x);

    return 0;
}