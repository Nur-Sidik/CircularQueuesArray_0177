/**
 * @mainpage Documentation for Circular Queue
 * 
 * @section Introduction
 * Project Ini merupakan project struktur data menggunakan struktur data Queue dengan pendekatan Circular Array.
 * 
 * @section Operations
 * Project ini mendukung operasi dasar pada Queue, yaitu:
 * 1. Insertion
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Pengunaan
 * Berikut Beberapa Menu Yang Tersedia, Antara Lain:
 * 1. Enqueue (Insert)
 * 2. Dequeue (Remove)
 * 3. Display
 * 4. Exit
 * 
 * @author Profile
 * - Nama   : Nur Sidik Zainu Ahmad
 * - NIM    : 20240140177
 * - Kelas  : D
 * 
 * @brief
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright sidik@umy.ac.id (c) 2025
 * 
 */



#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief Class ini untuk operasi lengkap Queues 
 * 
 */

class Queues 
{
    private: 
        int FRONT; ///< variable private form untuk menyimpan posisi depan antrian
        int REAR; ///< variable private form untuk menyimpan posisi belakang antrian
        int max = 5; ///< variable private max untuk menyimpan ukuran maksimum antrian
        int queue_array[5]; ///< variable private queue_array untuk menyimpan elemen antrian

    public:
        /**
         * @brief Construct a new Queues object
         * Set Default Queues null
         * with FRONT and REAR initialized to -1
         */
        Queues()
        {
            FRONT = -1;
            REAR = -1;
        }

    /**
     * @brief Method untuk memasukkan Data ke dalam antrian
     * Data di masukkan dalam variable queue_array
     * 
     */
    void insert()
    {
        int num; ///< variable num untuk menyimpan input dari user
        cout << "Masukkan sebuah angka : "; ///< output untuk memasukkan angka
        cin >> num; ///< mengambil input dari user
        cout << endl; ///< baris baru setelah output

    
    /**
     * @brief Constructor untuk menginisialisasi antrian
     * Method ini untuk mengecek apakah antrian penuh atau tidak
     * kondisi jika antrian penuh adalah ketika 
     * - FRONT == 0 dan REAR == max - 1
     * - atau ketika FRONT == REAR + 1
     * 
     * @param FRONT 
     */

      if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) 
      {
        cout << "Queue Overflow" << endl; ///< output jika antrian penuh
        return;
      } 

      if (FRONT == -1) ///< kondisi jika antrian kosong
      {
        FRONT = 1; ///< set posisi depan antrian ke 1
        REAR = 1; ///< set posisi belakang antrian ke 1
      } 
      else 
      {
        if (REAR == max - 1) ///< kondisi jika posisi belakang antrian sudah mencapai maksimum
            REAR = 0; ///< set posisi belakang antrian ke 1
        else 
            REAR = REAR + 1; ///< jika tidak, tambahkan posisinya pada belakang antrian
      }
      queue_array[REAR] = num; ///< memasukkan data ke dalam variable queue_array pada posisi REAR
    }


    /**
     * @brief Remove Method
     * Method ini berfungsi untuk menghapus data pada antrian
     * Data yang dihapus adalah data pada posisi depan antrian
     * Kondisi Jika Antrian kosong adalah ketika FRONT == -1
     * 
     */
    void remove()
    {
        if (FRONT == -1) ///< kondisi jika antrian kosong
        {
            cout << "Queues Underflow" << endl;
            return;
        }
        cout << "Element telah di hapus dari Queue :" << queue_array[FRONT] << endl;

        if (FRONT == REAR) ///< kondisi jika hanya ada satu elemen di antrian
        {
            FRONT = -1; ///< set posisi depan antrian ke 0
            REAR = -1; ///< set posisi belakang antrian ke 0
        }
        else 
        {
            if  (FRONT == max - 1) ///< kondisi jika posisi depan antrian sudah mencapai maksimum
                FRONT = 0; ///< set posisi depan antrian ke 1
            else 
                FRONT = FRONT + 1; ///< jika tidak, tambahkan posisinya pada depan antrian
        }
    }



    /**
     * @brief Display Method
     * Method ini berfungsi sebagai output untuk menampilkan elemen-elemen yang ada di dalam antrian
     * Kondisi jika antrian kosong adalah ketika FRONT == -1
     * 
     * 
     * 
     */
    void display()
    {
        int FRONT_possitiion = FRONT; ///< variable untuk menyimpan posisi depan antrian
        int REAR_position = REAR; ///< variable untuk menyimpan posisi belakang antrian

        if (FRONT == -1) ///< kondisi jika antrian kosong
        {
            cout << "Queues Kosong" << endl;
            return;
        }

        cout << "Elements di dalam Queue adalah... " << endl;
        
        if (FRONT_possitiion <= REAR_position) ///< kondisi jika posisi depan antrian kurang dari atau sama dengan posisi belakang antrian
        {
            while (FRONT_possitiion <= REAR_position) ///< menampilkan elemen dari posisi depan antrian sampai posisi belakang antrian
            {
                cout << queue_array[FRONT_possitiion] << "  "; 
                FRONT_possitiion++;
            }
            cout << endl;
        }
        else
        {
            while (FRONT_possitiion <= max - 1) ///< kondisi jika posisi depan antrian lebih besar dari posisi belakang antrian
            {
                cout << queue_array[FRONT_possitiion] << "  "; ///< maka akan menampilkan elemen dari posisi depan antrian sampai akhir antrian
                FRONT_possitiion++;
            }
            FRONT_possitiion =  0; ///< set posisi depan antrian ke 0

            while (FRONT_possitiion <= REAR_position) ///< menampilkan elemen dari posisi depan antrian sampai posisi belakang antrian
            {
                cout << queue_array[FRONT_possitiion] << "  ";
                FRONT_possitiion++;
            }
            cout << endl;
        }
    }
};


/**
 * @brief Main Function
 * 
 * Fungsi ini adalah fungsi utama dari program ini
 * Program akan terus berjalan sampai user memilih untuk keluar
 * 
 * @return int 
 */
int main()
{
    Queues q; ///< membuat objek dari class Queues
    int choice; ///< variable untuk menyimpan pilihan user

    while (true) 
    {
        try /// try-catch block untuk menangani exception
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
                    return 0;
                default:
                    cout << "Pilihan tidak valid." << endl;
                    break;
            }
        }
        catch (exception &e) ///< menangkap execption yang mungkin terjadi
        {
            cout << " Periksa setiap nilai yang masuk" << endl;
        }
        
    }
    return 0; ///< mengembalikan nilai 0 sebagai tanda program selesai
}