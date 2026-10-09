#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int main()
{
    std::ifstream file("text.txt");

    std::map<std::string, int> freq;

    if (!file.is_open())
    {
        std::cout << "Файл не открылся" << std::endl;
        return 1;
    }

    std::string line;
    std::string word;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        while (stream >> word)
        {
            freq[word]++;
        }
    }

    for (auto &word : freq)
    {
        std::cout << word.first << ": " << word.second << std::endl;
    }
    file.close();
    return 0;
}
