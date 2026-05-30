#include <iostream>
using namespace std;

// Function to merge two heaps
void mergeHeaps(int heap1[], int n1, int heap2[], int n2)
{
    cout << "Merged Heap: ";

    for(int i = 0; i < n1; i++)
    {
        cout << heap1[i] << " ";
    }

    for(int i = 0; i < n2; i++)
    {
        cout << heap2[i] << " ";
    }
}

int main()
{
    int heap1[] = {10, 20, 30};
    int heap2[] = {40, 50, 60};

    mergeHeaps(heap1, 3, heap2, 3);

    return 0;
}
