#include <iostream>

using namespace std;

class DynamicArray {
    private:
        int m_size;
        int m_capacity;
        int *m_storage;

    public:
        DynamicArray() {
            m_capacity = 10;
            m_size = 0;
            m_storage = new int[m_capacity];
        }

        DynamicArray(int capacity){
            this->m_capacity = capacity;
            m_size = 0;
            m_storage = new int[capacity];
        }

        ~DynamicArray() {
            delete[] m_storage;
        }

        int *getStorage(){
            return m_storage;
        }
};

int main() {
    DynamicArray test(100);
    int *tmp = test.getStorage();

    tmp[0] = 1;
    cout << tmp[0] << endl;

    return 0;
}


