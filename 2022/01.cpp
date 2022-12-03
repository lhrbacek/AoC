#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> process_file(std::string file_name)
{
    std::ifstream input;
    input.open(file_name);

    std::vector<int> elfs;
    std::string line;
    std::size_t pos = 0;
    while (std::getline(input, line))
    {
        if (line == "")
        {
            pos++;
        }
        else
        {
            int calories = std::stoi(line);
            if (elfs.size() <= pos)
            {
                elfs.push_back(calories);
            }
            else
            {
                elfs[pos] += calories;
            }
        }
    }
    input.close();
    return elfs;
}

int main(int argc, char *argv[])
{
    std::vector<int> elfs = process_file("in-01.txt");

    std::sort(elfs.begin(), elfs.end(), std::greater<int>());
    int sum = std::accumulate(elfs.begin(), elfs.begin() + 3, decltype(elfs)::value_type(0));
    std::cout << sum << '\n';
}
