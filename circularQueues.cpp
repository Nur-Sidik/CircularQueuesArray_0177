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

        cout << "Elements di dalam Queue adalah... " << endl;
        
        if (FRONT_possitiion <= REAR_position)
        {
            while (FRONT_possitiion <= REAR_position)
            {
                cout << queue_array[FRONT_possitiion] << "  ";
                FRONT_possitiion++;
            }
            cout << endl;
        }
        else
        {
            while (FRONT_possitiion <= max - 1)
            {
                cout << queue_array[FRONT_possitiion] << "  ";
                FRONT_possitiion++;
            }
            FRONT_possitiion =  0;

            while (FRONT_possitiion <= REAR_position)
            {
                cout << queue_array[FRONT_possitiion] << "  ";
                FRONT_possitiion++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q;
    int choice;

    while (true)
    {
        try
        {
            cout << "1. Insert" << endl;
            cout << "2. Remove" << endl;
            cout << "3. Display" << endl;
            cout << "4. Exit" << endl;
            cout << "Masukkan pilihan anda: ";
            cin >> choice;
            cout << endl;

            switch (choice) 
            {
                case 1:
                    q.insert();
                    break;
                case 2:
                    q.remove();
                    break;
                case 3:
                    q.display();
                    break;
                case 4:
                    cout << "Keluar dari program." << endl;
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
            }
        }
        catch (exception &e)
        {
            cout << " Periksa setiap nilai yang masuk" << endl;
        }
        return 0;
    }
}