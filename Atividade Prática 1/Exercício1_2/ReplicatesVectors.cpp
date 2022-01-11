#include "ReplicatesVectors.hpp"
using namespace std;

ReplicatesVectors::ReplicatesVectors(){}

void ReplicatesVectors::addSort(int number){
    _numberSort.push_back(number);
    sort(_numberSort.begin(), _numberSort.end());
}

void  ReplicatesVectors::countingReplicates(){
    for (auto it = _numberSort.begin(); it != _numberSort.end(); ++it){
        int aux = count(_numberSort.begin(), _numberSort.end(), *it);
        if (aux > 1){
            _numberSort.erase(it);
        }
        _elements.push_back(make_pair(aux, *it));
    }
}

void ReplicatesVectors::printing(){
    int n = _elements.size();
    for (int i = 0; i < n; i++){
        cout << _elements[i].first << " "
        << _elements[i].second << endl;
    }
}
