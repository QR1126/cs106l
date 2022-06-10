// system and timing
#include <iostream>
#include <chrono>

// data structure imports
#include <deque>
#include <vector>
#include <iterator>
#include <utility> // pair

using std::cout;    using std::endl;

// count_occurrences
// int count_occurrences(std::vector<std::string> vec, std::string target) {
//     int res = 0;
//     for (size_t i = 0; i < vec.size(); i++) {
//         if (vec[i] == target) res++; 
//     }
//     return res;
// }

// int count_occurrences(std::string str, char target) {
//     int res = 0;
//     for (size_t i = 0; i < str.size(); ++i) {
//         if (str[i] == target) res++;
//     }
//     return res;
// }

template <typename InputIt, typename T>
int count_occurrences(InputIt begin, InputIt end, T target) {
    int res = 0;
    for (InputIt it = begin; it != end; ++it) {
        if (*it == target) res++;
    }
    return res;
}

int main() {

    // vector of strings
    std::vector<std::string> lands = {"Xadia", "Drakewood", "Innean"};
    // how can we count the number of times "Xadia" appears in this?
    auto res1 = count_occurrences(lands.begin(), lands.end(), "Xadia");
    cout << res1 << endl;
    // string itself (array of chars)
    std::string str = "Xadia";
    // how can we count the number of times 'a' appears in this?
    auto res2 = count_occurrences(str.begin(), str.end(), 'a');
    cout << res2 << endl;
    return 0;
}

