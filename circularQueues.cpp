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
    

      if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) 
      {
        cout << "Queue Overflow" << endl;
        return;
      } 
      if (FRONT == -1) 
      {
        FRONT = 0;
        REAR = 0;
      } 
      else 
      {
        if (REAR == max - 1)
            REAR = 0;
        else 
            REAR = REAR + 1;
      }
      queue_array[REAR] = num;
    }

    void remove()
    {
        if (FRONT == -1)
        {
            cout << "Queues Underflow" << endl;
            return;
        }
        cout << "Element telah di hapus dari Queue :" << queue_array[FRONT] << endl;

        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else 
        {
            if  (FRONT == max - 1)
                FRONT = 0;
            else 
                FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_possitiion = FRONT;
        int REAR_position = REAR;

        if (FRONT == -1)
        {
            cout << "Queues Kosong" << endl;
            return;
        }

        
    }
};