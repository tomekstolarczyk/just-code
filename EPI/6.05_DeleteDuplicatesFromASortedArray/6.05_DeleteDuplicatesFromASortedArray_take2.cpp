#include <vector>
#include <iostream>

std::vector<int> deleteDupes(std::vector<int> A)
{
    int writeIdx = 1;
    int iter = 1;
    int count = 0;
    while (iter < A.size())
    {
        if (A[iter] != A[iter - 1])
        {
            A[writeIdx] = A[iter];
            writeIdx += 1;
            count += 1;
        }
        iter++;
    }
    for (int i = count + 1; i < A.size(); i++)
    {
        A[i] = 0;
    }

    return A;
}

int main()
{
    std::vector<int> result1 = deleteDupes({2, 3, 5, 5, 7, 11, 11, 11, 13});
    for (const auto &element : result1)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::vector<int> result2 = deleteDupes({});
    if (result2.empty())
    {
        std::cout << "empty";
    }
    else
    {
        for (const auto &element : result2)
        {
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;
}