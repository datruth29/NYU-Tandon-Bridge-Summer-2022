#include <iostream>
#include <vector>

void print_vector(std::vector<int> vec);
std::vector<int> insertion_sort_asc(std::vector<int> vec);

int main()
{
    std::vector<int> test = {5, 2, 4, 5, 6, 1, 4};

    print_vector(insertion_sort_asc(test));

}

void print_vector(std::vector<int> vec)
{
    for (auto& v: vec)
    {
        std::cout << v << ", ";
    }
}

std::vector<int> insertion_sort_asc(std::vector<int> vec)
{
    int temp;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        temp = vec.at(i);

        for (size_t j = i; j > 0 && vec.at(j) < vec.at(j-1); --j)
        {
            vec.at(j) = vec.at(j-1);
            vec.at(j-1) = temp;
        }
        
    }
    return vec;
}