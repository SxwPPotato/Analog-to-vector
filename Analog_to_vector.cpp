#include <iostream>

template<class T>
class vec {
private:
    int size;
    T* arr;
    int position = 0;
public:
    vec() {
        arr = new T[size];
        position = 0;
    }

    ~vec() {
        delete[] arr;
    }

    auto at(int index) {
        return arr[index];
    }

    void push_back(T num) {      
        if (position >= size) {
            delete[] arr;
            size += 10;
            arr = new T[size];
        }
        arr[position] = num;
        position++;
    }

    int size_() {
        return position;
    }

    int capacity() {
        return size;
    }

};

int main()
{
    vec<int> vector;
    vector.push_back(4);
    vector.push_back(5);
    vector.push_back(7);
    vector.push_back(9);
    std::cout << vector.at(2) << "\n";
    std::cout << vector.size_() << "\n";
    std::cout << vector.capacity() << "\n";
    vector.push_back(7);
    vector.push_back(9);
    vector.push_back(4);
    vector.push_back(6);
    vector.push_back(9);
    vector.push_back(53);
    vector.push_back(32);
    vector.push_back(12);
    std::cout << vector.capacity() << "\n";

    return 0;
}
