// system and timing
#include <iostream>
#include <chrono>

// data structure imports
#include <deque>
#include <vector>
#include <iterator>
#include <utility> // pair
#include <string.h>

using std::cout;    using std::endl;

// myMin function from lecture
template <typename T>
T myMin(T a, T b) {
    return a < b ? a : b;
}

template <typename T1, typename T2>
auto myMin_multiple_type(const T1& a, const T2& b) {
    return a < b ? a : b;
}

template <typename T>
auto myMin_ref(const T& a, const T& b) {
    return a < b ? *a : *b;
}

int main() {

    /*
     * explicit instantiation of template function (3, 4), (3.2, 3.1), (Frankie, Sathya)
     */
    cout << myMin<int>(3, 4) << endl;
    cout << myMin<double>(3.2, 3.1) << endl;
    cout << myMin<std::string>("Frankie", "Sathya") << endl;

    /*
     * implicit (type-deduced) instantiation of template function (4, 5), (4, 3.2)
     */
    cout << myMin(4, 5) << endl;
    cout << myMin_multiple_type(4, 3.2) <<endl;
    cout << myMin("Frankie", "Sathya") << endl;
    std::string str1 = "abcd";
    std::string str2 = "efg";
    cout << myMin_ref(&str1, &str2) << endl;
    // string literals like the ones below are c-strings, with a "char *" data type.
    // char *'s are pointers, which means myMin is comparing the addresses of these two strings,
    // and not the letters themselves! this is a danger of type deduction.

    return 0;
}

