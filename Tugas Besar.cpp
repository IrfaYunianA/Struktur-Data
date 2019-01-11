#include <iostream>
#include <conio.h>
using namespace std;

typedef struct{
	string nama[10];
	string Nama[10];
	int harga[10];
	int lama[10];
	int noant[10];
	int Harga[10];
	int Lama[10];
	int Noant[10];
	int front=1;
	int rear=0;
	int Front=1;
	int Rear=0;
}Penyewa;
Penyewa penyewa;
int noS=0;
int noB=0;


bool kosongS(Penyewa X){
	if(X.rear==0){
		return true;
	}
	else{
		return false;
	}
}

bool penuhS(Penyewa X){
	if(X.rear==10){
		return true;
	}
	else{
		return false;
	}
}

bool kosongB(Penyewa X){
	if(X.Rear==0){
		return true;
	}
	else{
		return false;
	}
}

bool penuhB(Penyewa X){
	if(X.Rear==10){
		return true;
	}
	else{
		return false;
	}
}

void header(){
	cout<<"-----------------------------------------\n";
	cout<<"Sistem Pernyewaan Lapangan Futsal  Pak RT\n";
	cout<<"Jl. Kabupaten Trihanggo Sleman Yogyakarta\n";
	cout<<"-----------------------------------------\n";
}
void input(Penyewa &X){
	int pil;
	cout<<"	1. Lapangan Sintetis\n";
	cout<<"	2. Lapangan Biasa\n";
	cout<<"	Pilih Lapangan : ";
	cin>>pil;
	if(pil==1){
		if(penuhS(penyewa)){
			cout<<"Antrian Lapangan Sintetis Sudah Penuh\n";
		}else{
			noS++;
			cout<<"	Anda no urut : "<<noS<<endl;
			X.rear++;
			X.noant[X.rear]=noS;
			cout<<"	Masukkan Nama		: ";
			cin>>X.nama[X.rear];
			cout<<"	Masukkan Lama Sewa	: ";
			cin>>X.lama[X.rear];
			X.harga[X.rear]=X.lama[X.rear]*110000;
			cout<<"-----------------------------------------\n";
		}
	}else if(pil==2){
		if(penuhB(penyewa)){
			cout<<"Antrian Lapangan Biasa Sudah Penuh\n";	
		}else{
			noB++;
			cout<<"	Anda no urut : "<<noB<<endl;
			X.Rear++;
			X.Noant[X.Rear]=noB;
			cout<<"	Masukkan Nama		: ";
			cin>>X.Nama[X.Rear];
			cout<<"	Masukkan Lama Sewa	: ";
			cin>>X.Lama[X.Rear];
			X.Harga[X.Rear]=X.Lama[X.Rear]*90000;
			cout<<"-----------------------------------------\n";
		}
	}
}

void tampil(Penyewa &X){
	cout<<"LAPANGAN SINTETIS\n";
	for(int i=X.front;i<=X.rear;i++){
		cout<<"	No		: "<<X.noant[i]<<endl;
		cout<<"	Nama		: "<<X.nama[i]<<endl;
		cout<<"	Durasi		: "<<X.lama[i]<<" Jam\n";
		cout<<"	Total Harga	: Rp."<<X.harga[i]<<endl;
		cout<<"-----------------------------------------\n";
	}cout<<"LAPANGAN BIASA\n";
	for(int i=X.Front;i<=X.Rear;i++){
		cout<<"	No		: "<<X.Noant[i]<<endl;
		cout<<"	Nama		: "<<X.Nama[i]<<endl;
		cout<<"	Durasi		: "<<X.Lama[i]<<" Jam\n";
		cout<<"	Total Harga	: Rp."<<X.Harga[i]<<endl;
		cout<<"-----------------------------------------\n";
	}
}

void sintetis(Penyewa &X){
	cout<<"Selamat Datang Di Lapangan Futsal Pak RT\n";
	cout<<"Silakan Penyewa Atas Nama : \n";
	cout<<"	Nama		: "<<X.nama[X.front];
	cout<<"\n	Lama Sewa	: "<<X.lama[X.front]<<" Jam";
	cout<<"\n	Total Bayar	: "<<X.harga[X.front];
	cout<<"\nUntuk Menggunakan Lapangan sintetis\n";
	for(int i=1;i<=X.rear-1;i++){
		X.nama[i]=X.nama[i+1];
		X.lama[i]=X.lama[i+1];
		X.harga[i]=X.harga[i+1];
	}X.rear--;
	cout<<"-----------------------------------------\n";
}

void biasa(Penyewa &X){
	cout<<"Selamat Datang Di Lapangan Futsal Pak RT\n";
	cout<<"Silakan Penyewa Atas Nama : \n";
	cout<<"	Nama		: "<<X.Nama[X.Front];
	cout<<"\n	Lama Sewa	: "<<X.Lama[X.Front]<<" Jam";
	cout<<"\n	Total Bayar	: "<<X.Harga[X.Front];
	cout<<"\nUntuk Menggunakan Lapangan Biasa\n";
	for(int i=1;i<=X.Rear-1;i++){
		X.Nama[i]=X.Nama[i+1];
		X.Lama[i]=X.Lama[i+1];
		X.Harga[i]=X.Harga[i+1];
	}X.Rear--;
	cout<<"-----------------------------------------\n";
}

int main(){
	int pilih;
	do{
		system("cls");
		header();
		cout<<"	Pilih Menu\n";
		cout<<"	1. Input Penyewa\n";
		cout<<"	2. Tampilkan Daftar Sewa\n";
		cout<<"	3. Pop Lap.Sintetis\n";
		cout<<"	4. Pop Lap.Biasa\n";
		cout<<"	0. Keluar\n";
		cout<<"	Pilih Menu : ";
		cin>>pilih;
		cout<<"-----------------------------------------\n";
		switch(pilih){
			case 1:
				if((penuhS(penyewa))&&(penuhB(penyewa))){
					cout<<"Antian Sudah Penuh Semua\n";
				}else{
					input(penyewa);
				}break;
			case 2:
				if((kosongS(penyewa))&&(kosongB(penyewa))){
					cout<<"Belum Ada Penyewa\n";
				}else{
					tampil(penyewa);
				}break;
			case 3:
				if(kosongS(penyewa)){
					cout<<"Penyewa Kosong\n";
				}else{
					sintetis(penyewa);
				}break;
			case 4:
				if(kosongB(penyewa)){
					cout<<"Penyewa Kosong\n";
				}else{
					biasa(penyewa);
				}break;	
		}system("pause");
	}while(pilih!=0);
}
