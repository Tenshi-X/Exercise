#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct biodata{
    int nomorInduk,umur;
    string nama, pekerjaan;
};

string replaceSpasi(string str){
    for (int i = 0;i < str.length();i++){
        if (str[i] == ' '){
            str[i] = '_';
        }
    }
    return str;
}
string replaceUnderscore(string str){
    for (int i = 0;i < str.length();i++){
        if (str[i] == '_'){
            str[i] = ' ';
        }
    }
    return str;
}

int main() {
    int pilih, i = 0,pilihurutan,cariNomor,banyak_masukan = 0;
    string lanjut,kembaliMenu;
    string namafile = "dataPenduduk.txt";
    biodata dataPenduduk[100];
    biodata temp[100];
    int banyak_data = 0;
    
    do {
    cout <<"1. Masukkan Data" << endl;
    cout <<"2. Tampilkan Data" << endl;
    cout <<"3. Cari Data" << endl;
    cout <<"4. Urutkan Data" << endl;
    cout <<"5. Keluar" << endl;
    cout <<"Pilih Menu : ";
    cin >> pilih;

    if (pilih == 1) {  
        lanjut = "ya";
        while ((i < 100) && (lanjut == "ya"))
        {
            cout<<"Masukkan Nomor Induk\t: ";
            cin>>dataPenduduk[i].nomorInduk;
            cout <<"Masukkan Nama\t\t: ";
            cin.ignore();
            getline(cin, dataPenduduk[i].nama);
            cout << "Masukkan Umur\t\t: ";
            cin >> dataPenduduk[i].umur;
            cout << "Masukkan Pekerjaan\t: ";
            cin >> dataPenduduk[i].pekerjaan;
            cout<<"Lanjut data selanjutnya? (ya/tidak) : ";
            cin>>lanjut;
            i++;
            banyak_masukan++;
        }

        for (int i = 0; i < banyak_masukan; i++)
            dataPenduduk[i].nama = replaceSpasi(dataPenduduk[i].nama);

        ofstream ofs(namafile,ios::app);
        if (ofs.is_open()){
            for (int i = 0; i < banyak_masukan; i++)
            {
            ofs << dataPenduduk[i].nomorInduk << " "
                << dataPenduduk[i].nama << " "
                << dataPenduduk[i].umur << " "
                << dataPenduduk[i].pekerjaan
                << endl;
            }
            ofs.close();
        }
        
        cout <<"\nKembali ke Menu? (y/n) : ";
        cin >>kembaliMenu;
    }
    else if (pilih == 2) {
 
        ifstream ifs(namafile);
        
        if (ifs.is_open()) {
            int i = banyak_data;
            while (!ifs.eof())
            {
                ifs >> temp[i].nomorInduk >> temp[i].nama >> temp[i].umur >> temp[i].pekerjaan;
                i++;
            }
            banyak_data += i - 1;
            ifs.close();
        }

        for (int i = 0; i < banyak_data; i++){
            cout << "Nomor Induk\t: " << temp[i].nomorInduk << endl
            << "Nama\t\t: " << replaceUnderscore(temp[i].nama) << endl
            << "Umur anda\t: " << temp[i].umur << endl
            << "Pekerjaan anda\t: " << temp[i].pekerjaan << endl << endl;
        }
        
        cout << "\nKembali ke Menu? (y/n) : ";
        cin >> kembaliMenu;

    }
    
    else if (pilih == 3) {
        int i = 0;
        cout<<"Masukkan nomor induk yang ingin dicari : ";
        cin>>cariNomor;
        ifstream ifs(namafile);
        bool pencarian = false;

        if (ifs.is_open()){
            while (!ifs.eof() && !pencarian)
            {   
                if (cariNomor == temp[i].nomorInduk){
                    pencarian = true;
                }
                else{
                    i++;
                }
            }
            ifs.close();
        }
        if (pencarian){
            cout << "Nomor Induk\t: " << temp[i].nomorInduk << endl
            <<"Nama\t\t: "<<replaceUnderscore(temp[i].nama)<<endl
            <<"Umur anda\t: "<<temp[i].umur<<endl
            <<"Pekerjaan anda\t: "<<temp[i].pekerjaan<<endl;
        }
        else{
            cout<<"Nama tidak ditemukan";
        }
        cout<<"\nKembali ke Menu? (y/n) : ";
        cin>>kembaliMenu;

    }
    else if(pilih == 4){
    biodata temporary;
    cout<<"1. Urutkan dari yang terkecil"<<endl;
    cout<<"2. Urutkan dari yang terbesar"<<endl;
    cout<<"Pilih urutan : ";
    cin>> pilihurutan;
    if(pilihurutan == 1){
          for (int i = 0; i < banyak_data - 1; i++){
                for (int j = 0; j < banyak_data - 1 - i; j++){
                    if (temp[j].nomorInduk > temp[j + 1].nomorInduk){
                        temporary = temp[j];
                        temp[j] = temp[j + 1];
                        temp[j + 1] = temporary;
                    }
                }
            }
        for (int i = 0; i < banyak_data; i++){
            cout << "Nomor Induk\t: " << temp[i].nomorInduk << endl
            << "Nama\t\t: " << replaceUnderscore(temp[i].nama) << endl
            << "Umur anda\t: " << temp[i].umur << endl
            << "Pekerjaan anda\t: " << temp[i].pekerjaan << endl << endl;
        }
    }
    else if(pilihurutan == 2){
        for (int i = 0; i < banyak_data - 1; i++){
                for (int j = 0; j < banyak_data - 1 - i; j++){
                    if (temp[j].nomorInduk < temp[j + 1].nomorInduk){
                        temporary = temp[j];
                        temp[j] = temp[j + 1];
                        temp[j + 1] = temporary;
                    }
                }
            }
        for (int i = 0; i < banyak_data; i++){
            cout << "Nomor Induk\t: " << temp[i].nomorInduk << endl
            << "Nama\t\t: " << replaceUnderscore(temp[i].nama) << endl
            << "Umur anda\t: " << temp[i].umur << endl
            << "Pekerjaan anda\t: " << temp[i].pekerjaan << endl << endl;
        }
    } 
        cout<<"\nKembali ke Menu? (y/n) : ";
        cin>>kembaliMenu;

    }
    else if(pilih == 5){
        cout << "Terima Kasih" << endl;
        return 0;
    }
    else{
        cout << "Pilihan tidak ada" << endl;
    }
    }while (kembaliMenu == "y" || kembaliMenu == "Y");
}
