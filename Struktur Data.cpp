#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int main(){
	int pilih, data=0;
	char nama[20][20], posisi[20][20];
	awal:
	cout<<"==============================\n";
	cout<<"	Menu Pilihan\n";
	cout<<"==============================\n";
	cout<<"1. Input Data\n";
	cout<<"2. Keluarkan Data\n";
	cout<<"3. Hapus Semua Data\n";
	cout<<"4. Cetak Data\n";
	cout<<"5. Keluar\n";
	cout<<"Masukkan Pilihan : ";
	cin>>pilih;
	system("cls");
	switch(pilih){
		case 1:
			cout<<"==============================\n";
			cout<<"	Input Data\n";
			cout<<"==============================\n";
			if(data==3){
				cout<<"Maaf, Tumpukan Sudah Penuh\n";
			}else{
				cout<<"Nama Pemain   : ";
				cin>>nama[data+1];
				cout<<"Posisi Pemain : ";
				cin>>posisi[data+1];
				cout<<"Tumpukan Sudah Dimasukkan\n";
				data++;
			}cout<<"Tekan ENTER Untuk Lanjut";
			getch();
			system("cls");
			goto awal;
		case 2:
			cout<<"==============================\n";
			cout<<"	Keluarkan Data\n";
			cout<<"==============================\n";
			if(data<1){
				cout<<"Tumpukan Kosong\n";
			}else{
				cout<<"Tumpukan Ke : "<<data<<" Dikeluarkan";
				cout<<"\n------------------------------";
				cout<<"\nNama	: "<<nama[data];
				cout<<"\nPosisi	: "<<posisi[data]<<endl;
				data--;
				cout<<"Tumpukan Sudah Dikeluarkan\n";
			}cout<<"Tekan ENTER Untuk Lanjut";
			getch();
			system("cls");
			goto awal;
		case 3:
			cout<<"==============================\n";
			cout<<"   Hapus Semua Data\n";
			cout<<"==============================\n";
			data=0;
			cout<<"Tumpukan Sudah Dihapus Semua\n";
			cout<<"Tekan ENTER Untuk Lanjut";
			getch();
			system("cls");
			goto awal;
		case 4:
			cout<<"==============================\n";
			cout<<"	Cetak Data\n";
			cout<<"==============================\n";
			if(data==0){
				cout<<"Tumpukan Kososng";
			}else{
				cout<<"No	Nama		Posisi\n";
				cout<<"------------------------------\n";
				for(int i=1;i<=data;i++){
					cout<<setiosflags(ios::left)<<setw(8)<<i;
					cout<<setiosflags(ios::left)<<setw(17)<<nama[i];
					cout<<setiosflags(ios::left)<<setw(10)<<posisi[i]<<endl;
				}
			}cout<<"\nTekan ENTER Untuk Lanjut";
			getch();
			system("cls");
			goto awal;
		case 5:
			cout<<"Keluar";
			break;
			system("cls");
			goto awal;
		default:
			cout<<"==============================\n";
			cout<<"	Menu Pilihan\n";
			cout<<"==============================\n";
			cout<<"Pilihan yang anda masukkan salah\n";
			cout<<"Tekan ENTER Untuk Lanjut";	
			getch();
			system("cls");
			goto awal;
	}
}
