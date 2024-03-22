#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int MAKS_SLOT_MOTOR = 30;
const int MAKS_SLOT_MOBIL = 15;
const int TARIF_JAM_PERTAMA_MOTOR = 2000;
const int TARIF_JAM_PERTAMA_MOBIL = 5000;

int main() {
    string nomorPlatMotor[MAKS_SLOT_MOTOR];
    time_t waktuMasukMotor[MAKS_SLOT_MOTOR];
    int waktuParkirMotor[MAKS_SLOT_MOTOR]; 
    int jumlahMotor = 0;

    string nomorPlatMobil[MAKS_SLOT_MOBIL];
    time_t waktuMasukMobil[MAKS_SLOT_MOBIL];
    int waktuParkirMobil[MAKS_SLOT_MOBIL]; 
    int jumlahMobil = 0;

    while (true) {
        int pilihan;
        cout << "Selamat\n";
        cout << "datang"<<endl;
        
        cout << "+--------------------------+\n";
        cout << "¦   Selamat Datang di      ¦\n";
        cout << "¦       Tempat Parkir      ¦\n";
        cout << "¦--------------------------¦\n";
        cout << "¦ Pilih jenis kendaraan:  ¦\n";
        cout << "¦ 1. Motor                 ¦\n";
        cout << "¦ 2. Mobil                 ¦\n";
        cout << "¦ 3. Keluar                ¦\n";
        cout << "¦ 4. Info Parkir           ¦\n";
        cout << "+--------------------------+\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahMotor < MAKS_SLOT_MOTOR) {
                    string plat;
                    cout << "Masukkan nomor identitas motor: ";
                    cin >> plat;

                    time_t waktuMasuk = time(0);
                    nomorPlatMotor[jumlahMotor] = plat;
                    waktuMasukMotor[jumlahMotor] = waktuMasuk;

                    cout << "Motor berhasil masuk. Nomor tiket: " << jumlahMotor + 1 << endl;
                    jumlahMotor++;
                } else {
                    cout << "Tempat parkir motor penuh!" << endl;
                }
                break;
            case 2:
                if (jumlahMobil < MAKS_SLOT_MOBIL) {
                    string plat;
                    cout << "Masukkan nomor identitas mobil: ";
                    cin >> plat;

                    time_t waktuMasuk = time(0);
                    nomorPlatMobil[jumlahMobil] = plat;
                    waktuMasukMobil[jumlahMobil] = waktuMasuk;

                    cout << "Mobil berhasil masuk. Nomor tiket: " << jumlahMobil + 1 << endl;
                    jumlahMobil++;
                } else {
                    cout << "Tempat parkir mobil penuh!" << endl;
                }
                break;
            case 3:
                int tiketKeluar;
                cout << "Pilih jenis kendaraan yang keluar:\n";
                cout << "1. Motor\n2. Mobil\nPilihan: ";
                cin >> pilihan;

                if (pilihan == 1 && jumlahMotor > 0) {
                    cout << "Masukkan nomor tiket motor yang keluar: ";
                    cin >> tiketKeluar;

                    if (tiketKeluar > 0 && tiketKeluar <= jumlahMotor) {
                        string plat = nomorPlatMotor[tiketKeluar - 1];
                        time_t waktuKeluar = time(0);
						int waktuTotal=static_cast<int>(difftime(waktuKeluar,waktuMasukMotor[tiketKeluar - 1]) / 60.0); 
						
                        cout << "Waktu masuk: " << ctime(&waktuMasukMotor[tiketKeluar - 1]);
                        cout << "Waktu keluar: " << ctime(&waktuKeluar);
                        cout << "Waktu parkir motor: " << waktuTotal << " menit" << endl;

                        int biayaTotal = TARIF_JAM_PERTAMA_MOTOR;
                   		 waktuTotal -= 60; 
                    	int tarifJamBerikutnya = TARIF_JAM_PERTAMA_MOTOR; 
                  		  while (waktuTotal > 0) {
                        biayaTotal += tarifJamBerikutnya;
                        waktuTotal -= 60;
                    }
                    cout << "Biaya Parkir: Rp " << biayaTotal << endl;
                    cout << "-------------------\n";
                    
                       for (int i = tiketKeluar - 1; i < jumlahMotor - 1; ++i) {
                            nomorPlatMotor[i] = nomorPlatMotor[i + 1];
                            waktuMasukMotor[i] = waktuMasukMotor[i + 1];
                            waktuParkirMotor[i] = waktuParkirMotor[i + 1];
						}
                        jumlahMotor--;
                        
                    } else {
                        cout << "Nomor tiket tidak ditemukan!" << endl;
                    }
                } else if (pilihan == 2 && jumlahMobil > 0) {
                    cout << "Masukkan nomor tiket mobil yang keluar: ";
                    cin >> tiketKeluar;

                    if (tiketKeluar > 0 && tiketKeluar <= jumlahMobil) {
                        string plat = nomorPlatMobil[tiketKeluar - 1];
                        time_t waktuKeluar = time(0);
                        int waktuTotal = static_cast<int>(difftime(waktuKeluar, waktuMasukMobil[tiketKeluar - 1]) / 60.0); 

                        cout << "Waktu masuk: " << ctime(&waktuMasukMobil[tiketKeluar - 1]);
                        cout << "Waktu keluar: " << ctime(&waktuKeluar);
                        cout << "Waktu parkir mobil: " << waktuTotal << " menit" << endl;

                        int biayaTotal = TARIF_JAM_PERTAMA_MOBIL;
                   		 waktuTotal -= 60;
                  		int tarifJamBerikutnya = TARIF_JAM_PERTAMA_MOBIL;
                   		 while (waktuTotal > 0) {
                        biayaTotal += tarifJamBerikutnya;
                        waktuTotal -= 60;
                   		}
                   		
                    cout << "Biaya Parkir: Rp " << biayaTotal << endl;
                    cout << "-------------------\n";
                    
                         for (int i = tiketKeluar - 1; i < jumlahMobil - 1; ++i) {
                            nomorPlatMobil[i] = nomorPlatMobil[i + 1];
                            waktuMasukMobil[i] = waktuMasukMobil[i + 1];
                            waktuParkirMobil[i] = waktuParkirMobil[i + 1];
                        }
                        jumlahMobil--;
                        
                    } else {
                        cout << "Nomor tiket tidak ditemukan!" << endl;
                    }
                } else {
                    cout << "Tidak ada kendaraan yang tersedia untuk dikeluarkan!" << endl;
                }
                break;
            case 4:
               cout << "\nInfo Parkir Motor:\n";
				for (int i = 0; i < jumlahMotor; ++i) {
				    cout << "Nomor Tiket: " << i + 1 << endl;
				    cout << "Nomor Identitas: " << nomorPlatMotor[i] << endl;
				    cout << "Waktu Masuk: " << ctime(&waktuMasukMotor[i]);
				    
				    time_t waktuSekarang = time(0);  
				    int waktuParkir = static_cast<int>(difftime(waktuSekarang, waktuMasukMotor[i]) / 60.0); 
				
				    cout << "Waktu Parkir: " << waktuParkir << " menit" << endl;
				    cout << "-------------------\n";
				}

               cout << "\nInfo Parkir Mobil:\n";
				for (int i = 0; i < jumlahMobil; ++i) {
				    cout << "Nomor Tiket: " << i + 1 << endl;
				    cout << "Nomor Identitas: " << nomorPlatMobil[i] << endl;
				    cout << "Waktu Masuk: " << ctime(&waktuMasukMobil[i]);
				    
				    time_t waktuSekarang = time(0);  
				    int waktuParkir = static_cast<int>(difftime(waktuSekarang, waktuMasukMobil[i]) / 60.0); 
				
				    cout << "Waktu Parkir: " << waktuParkir << " menit" << endl;
				    cout << "-------------------\n";
				}
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << "\n+---------------------------------+\n";
        cout << "¦ Jumlah kendaraan yang masuk:    ¦\n";
        cout << "¦ Motor: " << jumlahMotor << " dari " << MAKS_SLOT_MOTOR << "                ¦\n";
        cout << "¦ Mobil: " << jumlahMobil << " dari " << MAKS_SLOT_MOBIL << "                ¦\n";
        cout << "+---------------------------------+\n";
    }

    return 0;
}

