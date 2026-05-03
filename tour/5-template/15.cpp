// Aliases
#include <iostream>
#include <vector>

template<typename C>
using Element_type = typename C::value_type;

template<typename Container>
void algo(Container& c) {
    std::vector<Element_type<Container>> vec(c.size());
    for(size_t i=0; i<c.size(); i++)
        vec[i] = c[i];

    std::cout << "Successfully copy " << c.size() << " elements." << std::endl;
}

int main() {
    std::vector<int> x = {1, 2, 3, 4, 5};
    algo(x);

    return 0;
}