#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct dataGame
{
	int kode;
	string nama;
	string genre;
	string developer;
	int tanggalRilis;
	int harga;
};
struct dataAkun
{
	string username;
	string password;
	int saldo = 0;
};

string replaceSpasi(string str);
string replaceUnderscore(string str);
void inputGame(dataGame data[], int &jumlahGame);
void outputGame(dataGame data[], int &jumlahGame);
void registerAkun(dataAkun data, int &jumlahAkun, string username, string password);
void beliGame(dataGame datagame[], dataGame game[], string username, int &jumlahBeli, int &nomorakun, dataAkun akun);
void tambahSaldo(dataAkun dataakun, string username);
void libraryGame(dataGame game[], string username, int i);
int totalHarga(int harga[], int jumlahBeli);

int main()
{
	string username, password, menuAwal, beligame, menulogin;
	int pilih1, pilih2, pilih3, pilih4, banyakMasukan = 0, banyakAkun = 0, banyakBeli = 0, nomorAkun = 0;
	dataGame game[100];
	dataGame tempGame[100];
	dataGame gameSaya[100];
	dataAkun akun;

	do
	{
		//Menu Awal
		cout << "1. Login" << endl;
		cout << "2. Register" << endl;
		cout << "3. Menu Developer" << endl;
		cout << "4. Exit" << endl;
		cout << "Pilih : ";
		cin >> pilih1;
		cin.ignore();
		system("cls");
		//Pengecekan Menu Awal
		if (pilih1 == 1)
		{
			int jumlahGagal = 0, i = 0;
			bool isGagal = true;
			cout << "Masukkan username : ";
			getline(cin, username);
			cout << "Masukkan password : ";
			getline(cin, password);
			nomorAkun = 0;
			//Pengecekan Username dan Password
			string namaFile = username + ".txt";
			ifstream ifs(namaFile);
			if (ifs.is_open())
			{
				ifs >> akun.username >> akun.password >> akun.saldo;
				if ((username == akun.username) && (password == akun.password))
				{
					cout << "Login Berhasil" << endl;
					isGagal = false;
				}
				else
				{
					cout << "Login Gagal" << endl;
					isGagal = true;
				}
				ifs.close();
			}
			system("pause");
			system("cls");
			if (isGagal == false)
			{
				do
				{
					ifstream ifs(namaFile);
					if (ifs.is_open())
					{
						ifs >> akun.username >> akun.password >> akun.saldo;
						ifs.close();
					}
					//Menu User
					cout << "Hello, " << akun.username << endl;
					cout << "Jumlah Saldo Anda : " << akun.saldo << endl;
					cout << "\n1. Game Saya" << endl;
					cout << "2. Beli Game" << endl;
					cout << "3. Tambah Saldo" << endl;
					cout << "4. Logout" << endl;
					cout << "Pilih : ";
					cin >> pilih3;
					system("cls");
					//Pengecekan Menu User
					if (pilih3 == 1)
					{
						//Menu Game Saya
						libraryGame(game, username, i); //Menampilkan Game Yang Telah Dibeli
						cout << "Kembali?(y/n) : ";
						cin >> menulogin;
						system("cls");
					}
					else if (pilih3 == 2)
					{
						//Menu Beli Game
						dataGame temporary;
						ifstream ifs("dataGame.txt");
						int jumlahGame = 0;
						i = jumlahGame;
						if (ifs.is_open())
						{
							while (!ifs.eof())
							{
								ifs >> tempGame[i].kode >> tempGame[i].nama >> tempGame[i].genre >> tempGame[i].developer >> tempGame[i].tanggalRilis >> tempGame[i].harga;
								i++;
							}
							jumlahGame += i - 1;
							ifs.close();
						}
						//Menampilkan Data Game
						cout << setfill('-') << setw(115) << "-" << endl;
						cout << left << "|" << setfill(' ') << setw(16) << " Kode Game"
							 << "|" << setfill(' ') << setw(23);
						cout << " Nama"
							 << "|" << setfill(' ') << setw(19) << " Genre"
							 << "|" << setfill(' ') << setw(19);
						cout << " Developer"
							 << "|" << setfill(' ') << setw(19) << " Tanggal Rilis"
							 << "|" << setfill(' ') << setw(18) << " Harga"
							 << endl;
						cout << setfill('-') << setw(115) << "-" << endl;

						for (int i = 0; i < jumlahGame; i++)
						{
							cout << "| " << setfill(' ') << setw(15) << tempGame[i].kode << "| " << setfill(' ') << setw(22) << replaceUnderscore(tempGame[i].nama);
							cout << "| " << setfill(' ') << setw(18) << tempGame[i].genre << "| " << setfill(' ') << setw(18) << tempGame[i].developer;
							cout << "| " << setfill(' ') << setw(18) << tempGame[i].tanggalRilis << "| " << setfill(' ') << setw(17) << tempGame[i].harga << endl;
						}
						cout << setfill('-') << setw(115) << "-" << endl;
						//Menu Pilihan Beli Game
						cout << "1. Cari Game Berdasarkan Nama" << endl;
						cout << "2. Urutkan Game Berdasarkan Harga Termurah" << endl;
						cout << "3. Urutkan Game Berdasarkan Harga Termahal" << endl;
						cout << "4. Beli Game" << endl;
						cout << "Pilih : ";
						cin >> pilih4;
						cin.ignore();
						//Pengecekan Menu Pilihan Beli Game
						if (pilih4 == 1)
						{
							//Menu Cari Game Berdasarkan Nama
							int i = 0;
							string cariNama;
							cout << "Masukkan nama game : ";
							getline(cin, cariNama);
							bool pencarian = false;
							//Pengecekan Nama Game
							for (int i = 0; i < jumlahGame; i++)
							{
								if (replaceSpasi(cariNama) == replaceSpasi(tempGame[i].nama)) //Fungsi Untuk Mengganti Spasi Dengan Underscore Pada String
								{
									pencarian = true;
									break;
								}
							}
							if (pencarian)
							{
								//Menampilkan Data Game Yang Dicari
								cout << "Kode\t\t: " << tempGame[i].kode << endl
									 << "Nama\t\t: " << replaceUnderscore(tempGame[i].nama) << endl //Fungsi Untuk Mengganti Underscore Dengan Spasi Pada String
									 << "Genre\t\t: " << tempGame[i].genre << endl
									 << "Developer\t: " << tempGame[i].developer << endl
									 << "Tanggal Rilis\t: " << tempGame[i].tanggalRilis << endl
									 << "Harga\t\t: " << tempGame[i].harga << endl;
								cout << "Beli Game?(y/n) : ";
								cin >> beligame;
								if (beligame == "y")
								{
									banyakBeli++;
									beliGame(tempGame, gameSaya, username, banyakBeli, nomorAkun, akun); //Fungsi Beli Game
								}
								else
								{
									cout << "Terima Kasih" << endl;
								}
							}
							else
							{
								cout << "Nama tidak ditemukan" << endl;
							}
						}
						else if (pilih4 == 2)
						{
							//Menu Urutkan Game Berdasarkan Harga Termurah
							for (int i = 0; i < jumlahGame - 1; i++)
							{
								for (int j = 0; j < jumlahGame - 1 - i; j++)
								{
									if (tempGame[j].harga > tempGame[j + 1].harga)
									{
										temporary = tempGame[j];
										tempGame[j] = tempGame[j + 1];
										tempGame[j + 1] = temporary;
									}
								}
							} //Code Sorting Mencari Harga Termurah
							cout << setfill('-') << setw(115) << "-" << endl;
							cout << left << "|" << setfill(' ') << setw(16) << " Kode Game"
								 << "|" << setfill(' ') << setw(23);
							cout << " Nama"
								 << "|" << setfill(' ') << setw(19) << " Genre"
								 << "|" << setfill(' ') << setw(19);
							cout << " Developer"
								 << "|" << setfill(' ') << setw(19) << " Tanggal Rilis"
								 << "|" << setfill(' ') << setw(18) << " Harga"
								 << endl;
							cout << setfill('-') << setw(115) << "-" << endl;

							for (int i = 0; i < jumlahGame; i++)
							{
								cout << "| " << setfill(' ') << setw(15) << tempGame[i].kode << "| " << setfill(' ') << setw(22) << replaceUnderscore(tempGame[i].nama);
								cout << "| " << setfill(' ') << setw(18) << tempGame[i].genre << "| " << setfill(' ') << setw(18) << tempGame[i].developer;
								cout << "| " << setfill(' ') << setw(18) << tempGame[i].tanggalRilis << "| " << setfill(' ') << setw(17) << tempGame[i].harga << endl;
							}
							cout << setfill('-') << setw(115) << "-" << endl;
							cout << "Beli Game?(y/n) : ";
							cin >> beligame;
							if (beligame == "y")
							{
								banyakBeli++;
								beliGame(tempGame, gameSaya, username, banyakBeli, nomorAkun, akun); //Fungsi Beli Game
							}
							else
							{
								cout << "Terima Kasih" << endl;
							}
						}
						else if (pilih4 == 3)
						{
							//Menu Urutkan Game Berdasarkan Harga Termahal
							for (int i = 0; i < jumlahGame - 1; i++)
							{
								for (int j = 0; j < jumlahGame - 1 - i; j++)
								{
									if (tempGame[j].harga < tempGame[j + 1].harga)
									{
										temporary = tempGame[j];
										tempGame[j] = tempGame[j + 1];
										tempGame[j + 1] = temporary;
									}
								}
							}//Code Sorting Mencari Harga Termahal
							cout << setfill('-') << setw(115) << "-" << endl;
							cout << left << "|" << setfill(' ') << setw(16) << " Kode Game"
								 << "|" << setfill(' ') << setw(23);
							cout << " Nama"
								 << "|" << setfill(' ') << setw(19) << " Genre"
								 << "|" << setfill(' ') << setw(19);
							cout << " Developer"
								 << "|" << setfill(' ') << setw(19) << " Tanggal Rilis"
								 << "|" << setfill(' ') << setw(18) << " Harga"
								 << endl;
							cout << setfill('-') << setw(115) << "-" << endl;

							for (int i = 0; i < jumlahGame; i++)
							{
								cout << "| " << setfill(' ') << setw(15) << tempGame[i].kode << "| " << setfill(' ') << setw(22) << replaceUnderscore(tempGame[i].nama);
								cout << "| " << setfill(' ') << setw(18) << tempGame[i].genre << "| " << setfill(' ') << setw(18) << tempGame[i].developer;
								cout << "| " << setfill(' ') << setw(18) << tempGame[i].tanggalRilis << "| " << setfill(' ') << setw(17) << tempGame[i].harga << endl;
							}
							cout << setfill('-') << setw(115) << "-" << endl;
							cout << "Beli Game?(y/n) : ";
							cin >> beligame;
							if (beligame == "y")
							{
								banyakBeli++;
								beliGame(tempGame, gameSaya, username, banyakBeli, nomorAkun, akun); //Fungsi Beli Game
							}
							else
							{
								cout << "Terima Kasih" << endl;
							}
						}
						else if (pilih4 == 4)
						{
							banyakBeli++;
							beliGame(tempGame, gameSaya, username, banyakBeli, nomorAkun, akun); //Fungsi Beli Game
						}
						else
						{
							cout << "Pilihan tidak ada" << endl;
						}
						cout << "Kembali?(y/n) : ";
						cin >> menulogin;
						system("cls");
					}
					else if (pilih3 == 3)
					{
						tambahSaldo(akun, username); //Fungsi Tambah Saldo
						cout << "Kembali?(y/n) : ";
						cin >> menulogin;
						system("cls");
					}
					else if (pilih3 == 4)
					{
						menulogin = "n";
						pilih2 = 3;
					}
					else
					{
						cout << "Pilihan tidak ada" << endl;
					}
				} while (menulogin == "y");
			}
			else
			{
				cout << "Username atau Password Salah" << endl;
				pilih2 = 3;
			}
		}
		else if (pilih1 == 2)
		{
			registerAkun(akun, banyakAkun, username, password); //Fungsi Untuk Menambahkan Akun
			cout << "\nKembali ke Menu Awal?(y/n) ";
			cin >> menuAwal;
			if (menuAwal == "y" || menuAwal == "Y")
			{
				pilih2 = 3;
			}
			else
			{
				cout << "Pilihan Tidak Ada" << endl;
			}
			system("cls");
		}
		else if (pilih1 == 3)
		{
			//Menu Developer
			cout << "1. Masukkan data game" << endl;
			cout << "2. Tampilkan data game" << endl;
			cout << "3. Kembali ke Menu Awal" << endl;
			cout << "Pilih = ";
			cin >> pilih2;
			system("cls");
			if (pilih2 == 1)
			{
				inputGame(game, banyakMasukan); //Fungsi Untuk Menambahkan Game
				cout << "\nKembali ke Menu Awal?(y/n) ";
				cin >> menuAwal;
				if (menuAwal == "y" || menuAwal == "Y")
				{
					pilih2 = 3;
				}
				else
				{
					cout << "Pilihan Tidak Ada" << endl;
				}
			}

			else if (pilih2 == 2)
			{
				outputGame(tempGame, banyakMasukan); //Fungsi Untuk Menampilkan Game
				cout << "\nKembali ke Menu Awal?(y/n) ";
				cin >> menuAwal;
				if (menuAwal == "y" || menuAwal == "Y")
				{
					pilih2 = 3;
				}
				else
				{
					cout << "Pilihan Tidak Ada" << endl;
				}
			}
			else if (pilih2 == 3)
				pilih2 = 3;
			else
				cout << "Pilihan tidak ada" << endl;
			system("cls");
		}
		else if (pilih1 == 4)
		{
			cout << "Terima Kasih" << endl;
			return 0;
		}
		else
		{
			cout << "Pilihan tidak ada" << endl;
		}
	} while (pilih2 == 3);
}

void tambahSaldo(dataAkun akun, string username)
{
	int saldo;
	cout << "Silakan Masukan Jumlah Saldo Yang Ingin Ditambahkan" << endl;
	cout << "Jumlah Saldo : ";
	cin >> saldo;
	string namaFile1 = username + ".txt";
	ofstream ofs(namaFile1);
	if (ofs.is_open())
	{
		ofs << akun.username << " " << akun.password << " " << akun.saldo + saldo << endl;
		ofs.close();
	}
	cout << "\nTop Up Berhasil!" << endl;
}
string replaceSpasi(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '_';
		}
	}
	return str;
}
string replaceUnderscore(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
		{
			str[i] = ' ';
		}
	}
	return str;
}
void inputGame(dataGame data[], int &jumlahGame)
{
	string lanjut = "ya", namaFile = "dataGame.txt";
	int i = 0;
	while ((i < 100) && (lanjut == "ya"))
	{
		cout << "Masukkan Kode Game\t: ";
		cin >> data[i].kode;
		cout << "Masukkan Nama\t\t: ";
		cin.ignore();
		getline(cin, data[i].nama);
		cout << "Masukkan Genre\t\t: ";
		getline(cin, data[i].genre);
		cout << "Masukkan Developer\t: ";
		getline(cin, data[i].developer);
		cout << "Masukkan Tanggal Rilis\t: ";
		cin >> data[i].tanggalRilis;
		cout << "Masukkan Harga\t\t: ";
		cin >> data[i].harga;

		cout << "Lanjut data selanjutnya? (ya/tidak) : ";
		cin >> lanjut;
		i++;
		jumlahGame++;
	}

	for (int i = 0; i < jumlahGame; i++)
		data[i].nama = replaceSpasi(data[i].nama);

	ofstream ofs(namaFile, ios::app);
	if (ofs.is_open())
	{
		for (int i = 0; i < jumlahGame; i++)
		{
			ofs << data[i].kode << " "
				<< data[i].nama << " "
				<< data[i].genre << " "
				<< data[i].developer << " "
				<< data[i].tanggalRilis << " "
				<< data[i].harga << endl;
		}
		ofs.close();
	}
}
void outputGame(dataGame data[], int &jumlahGame)
{
	int i = 0;
	jumlahGame = 0;
	string namaFile = "dataGame.txt";
	ifstream ifs(namaFile);
	while (!ifs.eof())
	{
		ifs >> data[i].kode;
		ifs >> data[i].nama;
		ifs >> data[i].genre;
		ifs >> data[i].developer;
		ifs >> data[i].tanggalRilis;
		ifs >> data[i].harga;
		i++;
	}
	ifs.close();
	jumlahGame += i - 1;
	cout << setfill('-') << setw(115) << "-" << endl;
	cout << left << "|" << setfill(' ') << setw(16) << " Kode Game"
		 << "|" << setfill(' ') << setw(23);
	cout << " Nama"
		 << "|" << setfill(' ') << setw(19) << " Genre"
		 << "|" << setfill(' ') << setw(19);
	cout << " Developer"
		 << "|" << setfill(' ') << setw(19) << " Tanggal Rilis"
		 << "|" << setfill(' ') << setw(18) << " Harga"
		 << endl;
	cout << setfill('-') << setw(115) << "-" << endl;
	for (int i = 0; i < jumlahGame; i++)
	{
		cout << "| " << setfill(' ') << setw(15) << data[i].kode << "| " << setfill(' ') << setw(22) << replaceUnderscore(data[i].nama);
		cout << "| " << setfill(' ') << setw(18) << data[i].genre << "| " << setfill(' ') << setw(18) << data[i].developer;
		cout << "| " << setfill(' ') << setw(18) << data[i].tanggalRilis << "| " << setfill(' ') << setw(17) << data[i].harga << endl;
	}
	cout << setfill('-') << setw(115) << "-" << endl;
}
void registerAkun(dataAkun data, int &jumlahAkun, string username, string password)
{
	string lanjut = "ya";
	while (lanjut == "ya")
	{
		cout << "Masukkan Username\t: ";
		cin >> data.username;
		cout << "Masukkan Password\t: ";
		cin >> data.password;
		cout << "Masukkan Saldo\t\t: ";
		cin >> data.saldo;

		string namaFile = data.username + ".txt";
		ofstream ofs(namaFile, ios::app);
		if (ofs.is_open())
		{
			ofs << data.username << " "
				<< data.password << " "
				<< data.saldo << endl;
			ofs.close();
		}
		cout << "Lanjut data selanjutnya? (ya/tidak) : ";
		cin >> lanjut;
		jumlahAkun++;
	}
}
void beliGame(dataGame datagame[], dataGame game[], string username, int &jumlahBeli, int &nomorakun, dataAkun akun)
{
	int harga[100], totalGame = 1;
	string belilain, topup;
	int kodegame;
	do
	{
		int jumlahGame = 0, i = 0, j = 0;
		cout << "Masukkan Kode Game : ";
		cin >> kodegame;

		ifstream ifs("dataGame.txt");
		if (ifs.is_open())
		{
			while (!ifs.eof())
			{
				ifs >> datagame[i].kode;
				ifs >> datagame[i].nama;
				ifs >> datagame[i].genre;
				ifs >> datagame[i].developer;
				ifs >> datagame[i].tanggalRilis;
				ifs >> datagame[i].harga;
				i++;
			}
			ifs.close();
		}
		jumlahGame += i - 1;
		bool found = false;
		bool found2 = false;
		for (i = 0; i < jumlahGame; i++)
		{
			if (kodegame == datagame[i].kode)
			{
				found = true;
				break;
			}
		}
		if (found == true && (akun.saldo - datagame[i].harga > 0))
		{
			string namaFile = username + "-Game.txt";
			ifstream ifs(namaFile);
			if (ifs.is_open())
			{
				while (!ifs.eof())
				{
					ifs >> game[j].kode;
					ifs >> game[j].nama;
					ifs >> game[j].genre;
					ifs >> game[j].developer;
					ifs >> game[j].tanggalRilis;
					ifs >> game[j].harga;
					j++;
				}
				for (j = 0; j < jumlahGame; j++)
				{
					if (game[j].kode == kodegame)
					{
						found2 = true;
						break;
					}
					ifs.close();
				}
			}
			else
				found2 = false;
			if (found2)
			{
				cout << "\nGame Sudah Ada Di Library" << endl;
				totalGame--;
			}
			else
			{
				cout << "\nPembelian Berhasil" << endl;
				cout << "Nama Game\t: " << replaceUnderscore(datagame[i].nama) << endl;
				string namaFile = username + "-Game.txt";
				ofstream ofs(namaFile, ios::app);
				if (ofs.is_open())
				{
					ofs << datagame[i].kode << " "
						<< datagame[i].nama << " "
						<< datagame[i].genre << " "
						<< datagame[i].developer << " "
						<< datagame[i].tanggalRilis << " "
						<< datagame[i].harga << endl;
					ofs.close();
				}
				string namaFile2 = username + ".txt";
				ofstream ofs2(namaFile2);
				if (ofs2.is_open())
				{
					ofs2 << akun.username << " "
						 << akun.password << " "
						 << akun.saldo - datagame[i].harga << endl;
					ofs2.close();
				}
				ifstream ifs(namaFile2);
				if (ifs.is_open())
				{
					ifs >> akun.username >> akun.password >> akun.saldo;
					ifs.close();
				}
				harga[totalGame - 1] = datagame[i].harga;
			}
			cout << "Lakukan Pembelian lain?(y/n) : ";
			cin >> belilain;
			if (belilain == "y")
			{
				totalGame++;
				jumlahBeli++;
				belilain = "y";
			}
			else
			{
				cout << "Total Harga : " << totalHarga(harga, totalGame) << endl; //Menampilkan Total Harga Pembelian
				belilain = "n";
			}
		}
		else if (found == true && (akun.saldo - datagame[i].harga < 0))
		{
			cout << "\nSaldo Anda Tidak Cukup" << endl;
			cout << "Apakah Anda Ingin Top Up Saldo?(y/n) : ";
			cin >> topup;
			if (topup == "y")
			{
				belilain = "n";
				system("cls");
				tambahSaldo(akun, username);
			}
			else
				belilain = "n";
		}
		else
		{
			cout << "\nKode Game Tidak Ditemukan" << endl;
			belilain = "n";
		}
	} while (belilain == "y");
}
void libraryGame(dataGame game[], string username, int i)
{
	int jumlahGame = 0;
	string tempUsername, tempPassword, tempSaldo;
	string namaFile = username + "-Game.txt";
	ifstream ifs2(namaFile);
	if (ifs2.is_open())
	{
		i = jumlahGame;
		while (!ifs2.eof())
		{
			ifs2 >> game[i].kode >> game[i].nama >> game[i].genre;
			ifs2 >> game[i].developer >> game[i].tanggalRilis >> game[i].harga;
			i++;
		}
		ifs2.close();
		jumlahGame += i - 1;
		if (jumlahGame > 0)
		{
			cout << setfill('-') << setw(115) << "-" << endl;
			cout << left << "|" << setfill(' ') << setw(16) << " Kode Game"
				 << "|" << setfill(' ') << setw(23);
			cout << " Nama"
				 << "|" << setfill(' ') << setw(19) << " Genre"
				 << "|" << setfill(' ') << setw(19);
			cout << " Developer"
				 << "|" << setfill(' ') << setw(19) << " Tanggal Rilis"
				 << "|" << setfill(' ') << setw(18) << " Harga"
				 << endl;
			cout << setfill('-') << setw(115) << "-" << endl;

			for (int j = 0; j < jumlahGame; j++)
			{
				cout << "| " << setfill(' ') << setw(15) << game[j].kode << "| " << setfill(' ') << setw(22) << replaceUnderscore(game[j].nama);
				cout << "| " << setfill(' ') << setw(18) << game[j].genre << "| " << setfill(' ') << setw(18) << game[j].developer;
				cout << "| " << setfill(' ') << setw(18) << game[j].tanggalRilis << "| " << setfill(' ') << setw(17) << game[j].harga << endl;
			}
			cout << setfill('-') << setw(115) << "-" << endl;
		}
	}
	else
		cout << "Anda belum memiliki game" << endl;
}
int totalHarga(int harga[], int jumlahBeli)
{
	if (jumlahBeli <= 1)
	{
		return harga[jumlahBeli - 1];
	}
	else
	{
		return harga[jumlahBeli - 1] + (totalHarga(harga, jumlahBeli - 1));
	}
}
