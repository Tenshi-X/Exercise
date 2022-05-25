#include <iostream>
#include <iomanip>

using namespace std;

void daftarbarang(string barang[], int stok[], int databarang);
void daftarharga(string barang[], int harga[], int databarang);
void hitungpembelian(string barang[6], int stok[6], int harga[6], int databarang);
void updatebarang(string barang[6], int stok[6], int databarang);
void updateharga(string barang[6], int harga[6], int databarang);
void tabelpembelian(string nama_barang[50], int hargasatuan[50], int jumlah[50], int subtotal[50], int total, int jml_beli);

int main(){
	string barang[6] = {"Sabun Mandi","Minyak Goreng","Sikat Gigi","Pasta Gigi","Mie Instan","Tissue"};
	string username,password;
	char kembali_menu,hitung_kembali,ulang_login,updatedaftar;
	int stok[6] = {100,90,110,80,85,100};
	int harga[6] = {5000,12000,4000,7000,3000,10000};
	int menu, databarang = sizeof(barang)/sizeof(barang[0]);
	
	do{
	system("CLS");
	cout<<"PROGRAM KASIR MINIMARKET"<<endl;
	cout<<setfill('=')<<setw(52)<<"="<<endl;
	cout<<"Silakan Masukkan Username & Password"<<endl;
	cout<<"Username\t= ";
	cin>>username;
	cout<<"Password\t= ";
	cin>>password;
	
	//username dan password benar
	if ((username == "Seva" && password == "123210061")||(username == "Tsania" && password == "123210090"))
	do{
	system("CLS");
	cout<<"PROGRAM KASIR MINIMARKET"<<endl;
	cout<<setfill('=')<<setw(52)<<"="<<endl
		<<"\nSelamat Datang "<<username<<" ^^"<<endl
		<<"\nSilakan Pilih Menu"<<endl
		<<"1. Daftar Barang"<<endl
		<<"2. Daftar Harga"<<endl
		<<"3. Hitung Pembelian"<<endl
		<<"4. Logout"<<endl
		<<"\nPilih Menu\t= ";
	cin>>menu;
	if (menu == 1){
		system("CLS");
		daftarbarang(barang,stok,databarang);
		cout<<"Update Daftar Barang (Y/N)? "; cin>>updatedaftar;
		if (updatedaftar == 'y' || updatedaftar == 'Y') updatebarang(barang,stok,databarang);
	}
	else if (menu == 2){
		system("CLS");
		daftarharga(barang,harga,databarang);
		cout<<"Update Daftar Harga (Y/N)? "; cin>>updatedaftar;
		if (updatedaftar == 'y' || updatedaftar == 'Y') updateharga(barang,harga,databarang);
	}
	else if (menu == 3){do{
		system("CLS");
		cout<<"3. Hitung Pembelian"<<endl;
		hitungpembelian(barang,stok,harga,databarang);
		cout<<"\nHitung Kembali (Y/N)? ";
		cin>>hitung_kembali;
		}while (hitung_kembali == 'Y' || hitung_kembali == 'y');
	}
	else if (menu == 4){
		cout<<"\nTerima Kasih, Semoga Anda Bahagia."<<endl
		<<"\nProgram Selesai"<<endl;
		return 0;
		}
	else{
		cout<<endl<<"Input Tidak Sesuai";	
	}
	cout<<"\nKembali ke Menu (Y/N)? ";
	cin>>kembali_menu;
	if (kembali_menu == 'y' || kembali_menu == 'Y') system("CLS");
	}while (kembali_menu == 'y' || kembali_menu == 'Y');
	
	//username atau password salah
	else{
		cout<<"\nUsername/Password Salah"<<endl;
		cout<<"Input ulang username & password (Y/N)? ";
		cin>>ulang_login;
		}
	}while (ulang_login == 'y' || ulang_login == 'Y');
	
	return 0;
}

void hitungpembelian(string barang[6], int stok[6], int harga[6], int databarang){
	int jml_beli = 1, total = 0;
	int subtotal[50] = {0}, jumlah[50] = {0}, hargasatuan[50] = {0};
	string nama_barang[50];
	char tambah, notfound;
	
	cout<<"\nDaftar Barang"<<endl;
	cout<<resetiosflags(ios::adjustfield);
	cout<<setfill('-')<<setw(32)<<"-"<<endl;
	cout<<"|"<<setiosflags(ios::left)<<setfill(' ')<<setw(3)<<"No"
		<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<"Barang"<<"| "<<endl;
	cout<<setfill('-')<<setw(32)<<"-"<<endl;
	for(int k = 0; k < databarang; k++){
		cout<<resetiosflags(ios::adjustfield);
		cout<<"|"<<k+1<<setiosflags(ios::left)<<setfill(' ')<<setw(2)<<"."
			<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<barang[k]<<"|"<<endl;
	}
	cout<<setfill('-')<<setw(32)<<"-"<<endl;
	
	for (int i=0; i<jml_beli; i++){		
		cout<<"\nMasukkan Barang Ke-"<<i+1<<endl;
		cout<<"Nama Barang\t: ";
		cin.ignore();
		getline(cin, nama_barang[i]);
		
		for (int j=0; j<databarang; j++){
			if (nama_barang[i] == barang[j]){
				hargasatuan[i] = harga[j];
				cout<<"Harga Satuan\t: "<<hargasatuan[i];
				cout<<"\nJumlah\t\t: ";
				cin>>jumlah[i];
				stok[j] = stok[j] - jumlah[i];
				subtotal[i] = (jumlah[i]*hargasatuan[i]);
				total += subtotal[i];
				cout<<"Sub Total\t: "<<subtotal[i];
				j=databarang; notfound = 'x';
			}
			else notfound = 'o';
		}
		if (notfound == 'o'){
			cout<<"Harga Barang Tidak Ditemukan\n";
		}
		
		cout<<"\nTambahkan Barang Berikutnya (Y/N)? "; cin>>tambah;
		if (tambah == 'Y' || tambah == 'y') jml_beli++;
		else if (tambah == 'N' || tambah == 'n'){
			tabelpembelian(nama_barang,hargasatuan,jumlah,subtotal,total,jml_beli);
		}
	}
}

void updatebarang(string barang[6], int stok[6], int databarang){
	int pilih,jumlah_stok = 1,stok_baru,stok_barang;
	string perbarui,nama_barang,lihatbarang;
	
	for(int i = 0;i<jumlah_stok;i++){
		cout<<"Pilih Nomor Barang\t: ";
		cin>>pilih;
		for(int z=0; z<databarang; z++){
			if (pilih == z+1){
				nama_barang = barang[z];
				stok_barang = stok[z];
				cout<<"\n"<<nama_barang<<"\nStok Lama\t\t\t= "<<stok_barang<<endl;
				cout<<"Masukkan Jumlah Stok Baru\t= ";
				cin>>stok_baru;
				stok[z] = stok_baru;
				cout<<"STOK BARANG BERHASIL DIPERBARUI.\n";
			}
		}
		if (pilih > databarang) cout<<"Barang Tidak Ditemukan\n";
		cout<<"\nPerbarui Stok Barang Lain (Y/N)? ";
		cin>>perbarui;
		if (perbarui == "Y" || perbarui == "y")jumlah_stok++;
		else if (perbarui == "N" || perbarui == "n"){
			cout<<"Tampilkan daftar barang (Y/N)? ";
			cin>>lihatbarang;
			if (lihatbarang == "Y" || lihatbarang == "y") daftarbarang(barang,stok,databarang);
		}
	}
}
void updateharga(string barang[6], int harga[6], int databarang){
	int jumlah_harga = 1,harga_baru,harga_barang,pilih;
	string perbarui,nama_barang,lihatharga;
	
	for(int i = 0;i<jumlah_harga;i++){
		cout<<"Pilih Nomor Barang\t: ";
		cin>>pilih;
		for(int z=0; z<databarang; z++){
			if (pilih == z+1){
				nama_barang = barang[z];
				harga_barang = harga[z];
				cout<<"\n"<<nama_barang<<"\nHarga Lama\t\t\t= "<<harga_barang<<endl;
				cout<<"Masukkan Harga Baru\t\t= ";
				cin>>harga_baru;
				harga[z] = harga_baru;
				cout<<"HARGA BARANG BERHASIL DIPERBARUI.\n";
			}
		}
		if (pilih > databarang) cout<<"Barang Tidak Ditemukan\n";
		cout<<"\nPerbarui Harga Barang Lain (Y/N)? ";
		cin>>perbarui;
		if (perbarui == "Y" || perbarui == "y")jumlah_harga++;
		else if (perbarui == "N" || perbarui == "n"){
			cout<<"Tampilkan daftar barang (Y/N)? ";
			cin>>lihatharga;
			if (lihatharga == "Y" || lihatharga == "y") daftarharga(barang,harga,databarang);
		}
	}
}

void tabelpembelian(string nama_barang[50], int hargasatuan[50], int jumlah[50], int subtotal[50], int total, int jml_beli){
	cout<<"\n";
	cout<<setfill('=')<<setw(60)<<"="<<endl
		<<resetiosflags(ios::adjustfield)
		<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(18)<<"ITEM"<<"| "
		<<setiosflags(ios::left)<<setfill(' ')<<setw(10)<<"HARGA"<<"| "
		<<setiosflags(ios::left)<<setfill(' ')<<setw(12)<<"JUMLAH ITEM"<<"| "
		<<setiosflags(ios::left)<<setfill(' ')<<setw(11)<<"SUBTOTAL"<<"|"<<endl
		<<setfill('=')<<setw(60)<<"="<<endl;
	for(int p=0; p<jml_beli; p++){
		cout<<resetiosflags(ios::adjustfield);
		cout<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(18)<<nama_barang[p]<<"|"
			<<setiosflags(ios::right)<<setfill(' ')<<setw(10)<<hargasatuan[p]<<" |"
			<<setiosflags(ios::right)<<setfill(' ')<<setw(12)<<jumlah[p]<<" |"
			<<setiosflags(ios::right)<<setfill(' ')<<setw(11)<<subtotal[p]<<" |"<<endl;
	}
	cout<<setfill('-')<<setw(60)<<"-"<<endl
		<<"|"<<setiosflags(ios::right)<<setfill(' ')<<setw(44)<<"TOTAL"<<" |"
		<<setfill(' ')<<setw(11)<<total<<" |"<<endl
		<<setfill('-')<<setw(60)<<"-"<<endl;
}

void daftarbarang(string barang[], int stok[], int databarang){
	cout<<"1. Daftar Barang"<<endl;
	cout<<resetiosflags(ios::adjustfield);
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
	cout<<"|"<<setiosflags(ios::left)<<setfill(' ')<<setw(3)<<"No"
		<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<"Barang"<<"| "
		<<setiosflags(ios::left)<<setfill(' ')<<setw(22)<<"Stok Barang"<<"|"<<endl;
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
	for(int k = 0; k < databarang; k++){
		cout<<resetiosflags(ios::adjustfield);
		cout<<"|"<<k+1<<setiosflags(ios::left)<<setfill(' ')<<setw(2)<<"."
			<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<barang[k]<<"|"
			<<setiosflags(ios::right)<<setw(22)<<stok[k]<<" |"<<endl;
	}
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
}

void daftarharga(string barang[], int harga[], int databarang){
	cout<<"2. Daftar Harga"<<endl;
	cout<<resetiosflags(ios::adjustfield);
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
	cout<<"|"<<setiosflags(ios::left)<<setfill(' ')<<setw(3)<<"No"
		<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<"Barang"<<"| "
		<<setiosflags(ios::left)<<setfill(' ')<<setw(22)<<"Harga Barang"<<"|"<<endl;
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
	for(int k = 0; k < databarang; k++){
		cout<<resetiosflags(ios::adjustfield);
		cout<<"|"<<k+1<<setiosflags(ios::left)<<setfill(' ')<<setw(2)<<"."
			<<"| "<<setiosflags(ios::left)<<setfill(' ')<<setw(25)<<barang[k]<<"|"
			<<setiosflags(ios::right)<<setw(22)<<harga[k]<<" |"<<endl;
	}
	cout<<setfill('-')<<setw(56)<<"-"<<endl;
}
