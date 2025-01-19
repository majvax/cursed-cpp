#include "cursed.hpp"


int main() {
    final f1(69);
    if (auto ptr = f1.finall(100)) {
        std::cout << "f1 value: " << *ptr << '\n';
        std::cout << "Final value: " << f1.fine_all() << '\n';
    }


    final<double> f2(3.14);
    auto ptr = f2.finall(2.718); // return nullptr since T isn't integral
    std::cout << (ptr ? "not null" : "null") << '\n';

    int z = static_cast<int>(f2);
    std::cout << "z: " << z << '\n';


    const int x = 10;
    final f3(x); // T is deduced as int


    f1.pinal();


    return 0;
}
