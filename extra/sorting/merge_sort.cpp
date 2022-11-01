#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_sort(vector<int>& vec);
vector<int> min_and_max(vector<int>& vec);
vector<int> print_array(vector<int>& vec);
int main()
{
    vector<int> test = {1, 4, 2, 6, 7, 2};
    vector<int> result = min_and_max(test);

    cout << "Minimum = " << result.at(0) << '\n';
    cout << "Maximum = " << result.at(1) << '\n';
}

vector<int> merge_sort(vector<int>& vec)
{
    if (vec.size() == 1)
    {
        return vec;
    }

    if (vec.size() == 2)
    {
        if (vec.at(1) < vec.at(0))
        {
            int temp = vec.at(1);
            vec.at(1) = vec.at(0);
            vec.at(0) = temp;
            return vec;
        }
    }

    return vector<int>{};
}
vector<int> min_and_max(vector<int>& vec)
{
    if (vec.size() < 0)
    {
        return vector<int>{};
    }
    if (vec.size() == 1)
    {
        int num = vec.at(0);
        return vector<int> {num, num};
    }
    if (vec.size() == 2)
    {
        int max, min;
        if (vec.at(0) > vec.at(1))
        {
            max = vec.at(0);
            min = vec.at(1);
        } 
        else 
        {
            max = vec.at(1);
            min = vec.at(0);
        }
        
        return vector<int> {min, max};
    }

    unsigned int mid = vec.size() / 2;
    vector<int> left{};
    vector<int> right{};

    for(size_t i = 0; i < mid; ++i)
    {
        left.push_back(vec.at(i));
    }

    for(size_t i = mid; i < vec.size(); ++i)
    {
        right.push_back(vec.at(i));
    }

    vector<int> left_min_max = min_and_max(left);
    vector<int> right_min_max = min_and_max(right);

    int min = 0;
    int max = 0;

    if (left_min_max.at(0) < right_min_max.at(0))
    {
        min = left_min_max.at(0);
    }
    else
    {
        min = right_min_max.at(0);
    }

    if (left_min_max.at(1) > right_min_max.at(1))
    {
        max = left_min_max.at(1);
    }
    else
    {
        max = right_min_max.at(1);
    }

    return vector<int>{min, max};
}
