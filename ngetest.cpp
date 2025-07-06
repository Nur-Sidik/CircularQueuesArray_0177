/**
 * @mainpage Documentation for Circular Queue Implementation in C++
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular array.

 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * - Nama : Bimo Fadhlurrahman
 * - NIM  : 20240140189
 * - Kelas: D
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Bimo@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief Class ini untuk operasi lengkap queues
 * 
 */
class Queues
{
private:
     
    int FRONT; ///< variable private front untuk menyimpan posisi depan antrian
    int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null 
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1; 
        REAR = -1;
    }
    /**
     * @brief method untuk memasukkan data ke dalam antrian
     * data dimasukkan ke dalam variabel queue_array
     * 
     */
    void insert()
    {
        int num; ///< variable num untuk menyimpan inputan user
        cout << "Enter a number: "; ///< output untuk memasukkan angka
        cin >> num; /// < input angka dari user
        cout << endl; ///< baris baru untuk tampilan yang lebih baik


        // 1. Cek apakah antrian penuh

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) 
        {
            cout << "Queue penuh" << endl;
            return;
        }
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0;  // 2.b
        }
        else
        {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief Method untuk menghapus data di dalam antrian
     * data dihapus dari posisi FRONT
     */
    void remove()
    {
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe elemnt deleted from the queue is: " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief Method untuk menampilkan data di dalam antrian
     * data ditampilkan dari posisi FRONT hingga REAR
     */
    void display()
    {
        int FRONT_position = FRONT; ///< variable untuk menyimpan posisi depan antrian
        int REAR_position = REAR; ///< variable untuk menyimpan posisi belakang antrian

        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position <= REAR_position, iterasi daru front hingga rear
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            FRONT_position = 0;

            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief  function main untuk menjalankan program
 * function ini akan menampilkan menu
 * pengguna dapat memilih operasi yang ingin dilakukan
 * 1. Insert
 * 2. Delete
 * 3. Display
 * 4. Exit
 * Pengguna dapat memasukkan angka sesuai dengan pilihan yang ada
 * Jika pengguna memilih 1, maka akan memanggil method insert
 * Jika pengguna memilih 2, maka akan memanggil method remove
 * Jika pengguna memilih 3, maka akan memanggil method display
 * Jika pengguna memilih 4, maka program akan berhenti
 * Jika pengguna memasukkan angka yang tidak valid, maka program akan menampilkan pesan "Invalid option!!"
 * Jika terjadi kesalahan pada input, program akan menampilkan pesan "Check for the values entered."
 */
int main() 
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
    return 0; ///< mengembalikan nilai 0 sebagai tanda program selesai
}