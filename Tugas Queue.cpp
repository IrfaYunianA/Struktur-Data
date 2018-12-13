#include<iostream>
#include<conio.h>
#define max 20
using namespace std;
int a,b;
typedef struct{
	char no[2];
	char nama[50];
	char posisi[20];
}pemain;

void awal(){
	a=0;
	b=-1;
}

main(){
	pemain data[max];
	int pilih;
	awal();
	atas:
		cout<<"Queue Data Pemain Bola\n\n";
		cout<<"------------------------\n";
		do{
			cout<<"1. Enqueue\n";
			cout<<"2. Dequeue\n";
			cout<<"3. Cetak\n";
			cout<<"4. Exit\n";
			cout<<"------------------------\n";
			cout<<"Masukkan Pilihan : ";
			cin>>pilih;
			switch(pilih){
				case 1:
					if(b<max-1){
						b++;
						cout<<endl<<"Masukkan No. Pung.	: ";
						cin>>data[b].nama;
						cout<<"Masukkan Nama	: ";
						cin>>data[b].nama;
						cout<<"Masukkan Posisi	: ";
						cin>>data[b].posisi;
					}else{
						cout<<"Antrian Penuh\n";
					}break;
				case 2:
					if(a<b+1){
						cout<<endl<<"Data Yang di Inputkan\n\n";
						cout<<"No. Punggung	: "<<data[a].no<<endl;
						cout<<"Nama		: "<<data[a].nama<<endl;
						cout<<"posisi	: "<<data[a].posisi<<endl;
						a++;
						if((a==b+1)&&(b==max-1)){
							awal();
						}
					}else{
						cout<<"Atrian Kosong\n";
					}break;
				case 3:
					if(a<b+1){
						cout<<endl<<"Data Yang di Inputkan\n\n";
						cout<<"No. Punggung	: "<<data[a].no<<endl;
						cout<<"Nama		: "<<data[a].nama<<endl;
						cout<<"posisi	: "<<data[a].posisi<<endl;
					}else{
						cout<<"Antrian Kosong\n";
					}goto atas;
					break;
				case 4:
					cout<<"Terima Kasih";
					exit;
					break;	
			}
		}while((pilih>=1)&&(pilih<=3));
		getch();
}
