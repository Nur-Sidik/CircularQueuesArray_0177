#include <iostream>
using namespace std;

class Queues 
{
    private: 
        static const int max = 15;
        int FRONT, REAR;
        int queue_array[5];

    public:
        Queues()
        {
            FRONT = -1;
            REAR = -1;
        }

    void insert()
    {
        int num;
        cout << "Masukkan sebuah angka : ";
        cin >> num;
        cout << endl;
    }
};