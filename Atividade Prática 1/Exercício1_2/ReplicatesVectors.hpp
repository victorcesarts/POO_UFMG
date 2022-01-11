#ifndef COUNTVECTORS_H
#define COUNTVECTORS_H
#include <vector>
#include <iostream>
#include <algorithm>

class ReplicatesVectors
{
    public:
        ReplicatesVectors();
        void addSort(int numbers);
        void countingReplicates();
        void printing();

    private:
        std::vector<int> _numberSort;
        std::vector< std::pair<int, int>> _elements;
};
#endif