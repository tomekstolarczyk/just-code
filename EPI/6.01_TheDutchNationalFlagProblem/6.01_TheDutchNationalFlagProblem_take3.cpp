#include <vector>
#include <utility>

void dutchNationalFlag(std::vector<int> &A, int idx)
{
    if (A.empty())
    {
        return;
    }

    int pivot = A[idx];

    int smaller = 0;
    int greater = static_cast<int>(A.size() - 1);

    int equal = 0;
    while (equal <= greater)
    {
        int badany = A[equal];
        if (badany < pivot)
        {
            std::swap(A[smaller], A[equal]);
            smaller++;
            equal++;
        }

        else if (badany == pivot)
        {
            equal++;
        }

        else // badany > pivot
        {
            std::swap(A[greater], A[equal]);
            greater--;
        }
    }
}