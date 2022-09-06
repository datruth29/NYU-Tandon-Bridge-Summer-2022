#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;}

std::vector<int> create_random_array(int size);
void print_array(std::vector<int> vec);

int main() {
    std::vector<int> arr = create_random_array(10);
    print_array(arr);

    
    return 0;
}

std::vector<int> create_random_array(int size) {
    srand(time(0));
    std::vector<int> arr;
    int random;

    for (int i = 0; i < size; i++) {
        random = (rand() % 19) - 9;
        std::cout << "@" << i << " => " << random << std::endl;
        arr.push_back(random);
    }

    return arr;
}

void print_array(std::vector<int> vec) {
    for (int i : vec) {
        std::cout << i << std::endl;
    }
}