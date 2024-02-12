#include <iostream>

template<class T>
class vec {
private:
    int size = 2;
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
        if (index < 0 || index > position) {
            throw std::runtime_error("Array index out of bounds");
            
        }

        return arr[index];
    }

    void push_back(T num) {      
        if (position >= size) {
            T* tmp = new T[size];
            for (int i = 0; i < position; i++) {
                tmp[i] = arr[i];
            }
            delete[] arr;
            size += 10;
            arr = new T[size];
            for (int i = 0; i < position; i++) {
                arr[i] = tmp[i];
            }
            delete[] tmp;
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
    try
    {
        std::cout << vector.at(1) << "\n";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << vector.size_() << "\n";
    std::cout << vector.capacity() << "\n";
    vector.push_back(7);
    vector.push_back(9);
    vector.push_back(4);
    vector.push_back(6);
    vector.push_back(9);

    std::cout << "\n" << vector.at(1) << "\n" << "\n";

    vector.push_back(53);
    vector.push_back(32);
    vector.push_back(12);

    std::cout << vector.capacity() << "\n";

    return 0;
}
