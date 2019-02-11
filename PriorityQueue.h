#ifndef Heap_H
#define Heap_H

#include <vector>
using namespace std;

template <class heapdata>
class Heap {
private:
    vector<heapdata> A;
    void heapify(vector<heapdata> &A, int i);
    void heapify(vector<heapdata>& A, int i, bool(*compar)(heapdata, heapdata));
    void build(vector<heapdata> &A);
    void build(vector<heapdata> &A, bool(*compar)(heapdata, heapdata));
    
public:
    Heap();
    Heap(vector<heapdata> A2);
    void insert(heapdata data);
    void insert(heapdata data, bool(*compar)(heapdata, heapdata));
    void sort();
    void sort(bool(*compar)(heapdata, heapdata));
    void pop();
    void pop(bool(*compar)(heapdata, heapdata));
    void print();
    bool isEmpty();
    int getSize();
    vector<heapdata> getArray();
    heapdata top();
    void writeToFile(ofstream& outFile);
};

template <class heapdata>
Heap<heapdata>::Heap() {
}

template <class heapdata>
Heap<heapdata>::Heap(vector<heapdata> A2) {
    A = A2;
}

template <class heapdata>
void Heap<heapdata>::heapify(vector<heapdata>& A, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int max = i;
    
    if (l <= A.size() && A[l - 1] > A[i - 1])
        max = l;
    if (r <= A.size() && A[r - 1] > A[max - 1])
        max = r;
    if (i != max) {
        swap(A[i - 1], A[max - 1]);
        heapify(A, max);
    }
}

template <class heapdata>
void Heap<heapdata>::heapify(vector<heapdata>& A, int i, bool(*compar)(heapdata, heapdata)) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int max = i;
    
    if (l <= A.size() && !compar(A[l - 1], A[i - 1]))
        max = l;
    if (r <= A.size() && !compar(A[r - 1], A[max - 1]))
        max = r;
    if (i != max) {
        swap(A[i - 1], A[max - 1]);
        heapify(A, max, compar);
    }
}

template <class heapdata>
void Heap<heapdata>::build(vector<heapdata>& A) {
    for (int i = A.size() / 2; i > 0; i--) {
        heapify(A, i);
    }
}

template <class heapdata>
void Heap<heapdata>::build(vector<heapdata>& A, bool(*compar)(heapdata, heapdata)) {
    for (int i = A.size() / 2; i > 0; i--) {
        heapify(A, i, compar);
    }
}

template <class heapdata>
void Heap<heapdata>::insert(heapdata data) {
    A.push_back(data);
    build(A);
}

template <class heapdata>
void Heap<heapdata>::insert(heapdata data, bool(*compar)(heapdata, heapdata)) {
    A.push_back(data);
    build(A, compar);
}

template <class heapdata>
void Heap<heapdata>::sort() {
    build(A);
    vector<heapdata> B;
    for (int i = A.size(); i > 0; i--) {
        B.insert(B.begin(), A[0]);
        swap(A[i - 1], A[0]);
        A.pop_back();
        heapify(A, 1);
    }
    A = B;
}

template <class heapdata>
void Heap<heapdata>::sort(bool(*compar)(heapdata, heapdata)) {
    build(A, compar);
    vector<heapdata> B;
    for (int i = A.size(); i > 0; i--) {
        B.push_back(A[0]);
        swap(A[i - 1], A[0]);
        A.pop_back();
        heapify(A, 1, compar);
    }
    reverse(B.begin(), B.end());
    A = B;
}

template <class heapdata>
void Heap<heapdata>::pop() {
    if (isEmpty()) {
        return;
    }
    swap(A[0], A[A.size() - 1]);
    A.pop_back();
    build(A);
}

template <class heapdata>
void Heap<heapdata>::pop(bool(*compar)(heapdata, heapdata)) {
    if (isEmpty()) {
        return;
    }
    swap(A[0], A[A.size() - 1]);
    A.pop_back();
    build(A, compar);
}

template <class heapdata>
void Heap<heapdata>::print() {
    for (int i = 0; i < A.size(); i++)
        cout << A[i];
    cout << endl;
}

template <class heapdata>
bool Heap<heapdata>::isEmpty() {
    return A.empty();
}

template <class heapdata>
int Heap<heapdata>::getSize() {
    return A.size();
}

template <class heapdata>
heapdata Heap<heapdata>::top() {
    return A[0];
}

template <class heapdata>
vector<heapdata> Heap<heapdata>::getArray() {
    return A;
}

template <class heapdata>
void Heap<heapdata>::writeToFile(ofstream& outFile) {
    for (int i = 0; i < A.size(); i++) {
        A[i]->writeToFile(outFile);
    }
}
#endif // !Heap_H
