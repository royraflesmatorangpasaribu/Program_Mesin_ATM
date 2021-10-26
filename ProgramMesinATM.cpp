#include <iostream>
#include <ctime>

using namespace std;
//variabel
int opsiMainMenu, menuATM, jumlahPenarikan= 0, jumlahSetor= 0, jumlahTransfer= 0, menuPenarikan=0, jumlahTransaksi, cekRekening = 1, cekRekeningPenerima = 1, hasilCek, nr, rekeningKe, notifikasiRekening = 0, notifikasiPIN = 0;
string nomorRekening, nomorAkun, cetak, jenisTransaksi, inputanUsername, inputanPIN, ulangInput, idUsername, noPIN ;
//penyimpan data no rekening
string noRekening[] = {"2117051058", "2117051045", "2117051007","2110505003"}; 
//penyimpan data username
string username[20] = {"royrafmp", "gitajes", "naufale"};
//penyimpan data PIN
string PIN[20] = {"123456", "112233", "123654"};
//penyimpan data saldo
int saldo[20] = {500000, 350000, 150000};
//penyimpan jumlah kesalahan input PIN
int cekPINSalah[20] = {0,0,0};

//membuat prosedur header
void header(){
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"-----------------------------BANK BNR----------------------------"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

//membuat prosedur pembuatan akun
void buatAkun(int y){
    cout<<"Masukkan Username Anda\t\t: ";
	cin>>idUsername;
	cout<<"Masukkan PIN Anda\t\t: ";
	cin>>noPIN;
	int sizeU = sizeof(username)/sizeof(username[0]);
	for (int i=0; i<sizeU; i++){
		if(username[i]==idUsername){
			notifikasiPIN = 1;
			break;
		}
		else if(username[i]!=idUsername && noPIN.length()==6){
			PIN[y]=noPIN;
			username[y]=idUsername;
			notifikasiPIN = 2;
			break;					//notifikasiPIN = 2 akan menyimpan data username dan pin ke array
		}
		else{
			notifikasiPIN = 3;		//notifikasiPIN = 3 untuk memberikan notifikasi kesalahan digit PIN
		}
		cekPINSalah[y]=0;			//set jumlah kesalahan PIN = 0
	
	}
}

//membuat fungsi cek akun
int cekAkun(string un, string p){
	int temp;
	int sizeU = sizeof(username)/sizeof(username[0]);		//menghitung panjang array username
	int sizeP = sizeof(PIN)/sizeof(PIN[0]);					//menghitung panjang array PIN
	for (int i=0; i<sizeU; i++){
		if(username[i]==un && PIN[i]==p){
			hasilCek = 0;	//0 untuk menyatakan username&PIN sudah benar
			temp = i;		//untuk mencari akun ATM ke-i
			break;			//menghentikan looping apabila kondisi username&pin TRUE
		}
		else if(username[i]==un && PIN[i]!=p){
			hasilCek = 2; 	//2 untuk menyatakan PIN salah
			temp = i;
			break;
		}
		else if(username[i]!=un && PIN[i]==p){
			hasilCek = 1;	//1 untuk menyatakan username tidak terdaftar
			temp = i;
		}
		else{
			hasilCek = 1;
			temp = i;
		}
	}
	return temp;
}

//membuat prosedur cetak Transaksi
void cetakTransaksi(string noRekening, string jenisTransaksi, int jumlahTransaksi, int sisaSaldo){
	time_t now = time(0);
    char* dt = ctime(&now);
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"--------------------------BUKTI TRANSAKSI------------------------"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Tanggal Transaksi\t: "<<dt<<endl;
    cout<<"Nomor Rekening\t\t: "<<noRekening<<endl;
    cout<<"Jenis Transaksi\t\t: "<<jenisTransaksi<<endl;
    cout<<"Jumlah Transaksi\t: Rp."<<jumlahTransaksi<<",-"<<endl;
    cout<<"Sisa Saldo\t\t: Rp."<<sisaSaldo<<",-"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"-----------------------------BANK BNR----------------------------"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}

//membuat fungsi ATM
int ATM(int no){
	system("CLS");
	/*system(“CLS”) di C++ berfungsi untuk membersihkan layar pada program yang akan dijalankan 
	sehingga pemrogram dapat menenentukan saat untuk menghapus data yang telah dijalankan tanpa 
	harus menutup program tersebut dan membukanya kembal*/
	header();
	cout<<"1. Tarik Tunai"<<endl;
	cout<<"2. Setor Tunai"<<endl;
	cout<<"3. Transfer"<<endl;
	cout<<"4. Cek Saldo"<<endl;
	cout<<"5. Keluar"<<endl;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	if(notifikasiRekening==3){
		cout<<"NOTIFIKASI ATM: NOMOR REKENING TUJUAN TIDAK TERDAFTAR!"<<endl;
	}
	if(notifikasiRekening==4){
		cout<<"NOTIFIKASI ATM: SALDO ANDA TIDAK CUKUP!"<<endl;
	}
	if(notifikasiRekening==5){
		cout<<"NOTIFIKASI ATM: SETOR TUNAI HARUS KELIPATAN RP.100.000,-!"<<endl;
	}
	if(notifikasiRekening==6){
		cout<<"NOTIFIKASI ATM: TARIK TUNAI HARUS KELIPATAN RP.100.000,-!"<<endl;
	}
	cout<<"PILIHAN :";
    cin>>menuATM;
    
    if(menuATM==1){
    	system("CLS");
    	header();
    	cout<<"Nominal Penarikan: "<<endl;
    	cout<<"1. Rp.100.000,-"<<endl;
		cout<<"2. Rp.300.000,-"<<endl;
		cout<<"3. Rp.500.000"<<endl;
		cout<<"4. Rp.1.000.000"<<endl;
		cout<<"5. Rp.2.000.000"<<endl;
		cout<<"6. Nominal lain (Kelipatan Rp.100.000,-)"<<endl;
		cout<<"PILIHAN : ";
    	cin>>menuPenarikan;
		switch(menuPenarikan){
			case 1:
				jumlahPenarikan = 100000;
				break;
			case 2:
				jumlahPenarikan = 300000;
				break;
			case 3:
				jumlahPenarikan = 500000;
				break;
			case 4:
				jumlahPenarikan = 1000000;
				break;
			case 5:
				jumlahPenarikan = 2000000;
				break;
			default:
				cout<<"Jumlah Penarikan: ";
    			cin>>jumlahPenarikan;
		}
    	if(saldo[no]>0 && saldo[no]>jumlahPenarikan && jumlahPenarikan%100000==0){
    		saldo[no] = saldo[no] - jumlahPenarikan;
    		cout<<"\nBerhasil! Saldo ATM Anda sekarang Rp."<<saldo[no]<<",-"<<endl;
    		jenisTransaksi = "Tarik Tunai";
    		jumlahTransaksi = jumlahPenarikan;
    		notifikasiRekening = 1;		//1 jika transaksi berhasil
		}
		else{
			if(jumlahPenarikan%100000==0){
				notifikasiRekening =4;
			}
			else{
				notifikasiRekening =6;
			}
		}
	}
	else if(menuATM==2){
		system("CLS");
    	header();
    	cout<<"Jumlah Nominal : ";
    	cin>>jumlahSetor;
    	if(jumlahSetor%100000 == 0){
    		saldo[no] = saldo[no] + jumlahSetor;
	    	cout<<"\nSetor Tunai Berhasil! Saldo Anda Sekarang Rp."<<saldo[no]<<",-"<<endl;
	    	jenisTransaksi = "Setor Tunai";
	    	jumlahTransaksi = jumlahSetor;
	    	notifikasiRekening = 1;		//1 jika transaksi berhasil
		}
		else{
			notifikasiRekening = 5;
		}	
	}
	else if(menuATM==3){
		system("CLS");
    	header();
		cout<<"Masukkan nomor rekening\t\t: ";
    	cin>>nomorAkun;
    	
    	int size = sizeof(noRekening)/sizeof(noRekening[0]);
    	int temp;
    	for(int i=0;i<size;i++){
	    	if(nomorAkun == noRekening[i]){
	    		cekRekeningPenerima = 0;
	    		temp = i;
			}
		}
		if(cekRekeningPenerima == 0){
			cout<<"Masukkan jumlah transfer\t: ";
	    	cin>>jumlahTransfer;
	    	
	    	if(saldo[no]>0 && saldo[no]>jumlahTransfer){
	    		saldo[no] = saldo[no] - jumlahTransfer;
	    		saldo[temp] = saldo[temp] + jumlahTransfer;
	    		cout<<"\nBerhasil! Transfer ke nomor Rekening"<<" "<<nomorAkun<<","<<"Saldo Anda Sekarang Rp."<<saldo[no]<<",-"<<endl;
	    		jenisTransaksi = "Transfer";
	    		jumlahTransaksi = jumlahTransfer;
	    		notifikasiRekening = 1;		//1 jika transaksi berhasil
			}
			else{
				notifikasiRekening = 4;
			}	
		}
		else{
			notifikasiRekening = 3;
			cout<<"Nomor Rekening Tidak Terdaftar di Bank BNR!"<<endl;
			system("CLS");
		}
		
	}
	else if(menuATM==4){
		cout<<"\nSaldo Anda Sekarang Rp."<<saldo[no]<<endl;
		jenisTransaksi = "Cek Saldo";
		jumlahTransaksi = 0;
		notifikasiRekening = 1;				//1 jika transaksi berhasil
	}
	else{
		cout<<"Terima Kasih Telah Menggunakan ATM BNR!"<<endl;
		return 0;
	}
	return notifikasiRekening;
}

int main()
{
    menu:
        system("CLS");
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"--------------------SELAMAT DATANG DI ATM BNR--------------------"<<endl;
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        cout<<"PILIHAN MENU:"<<endl;
        cout<<"1. Pendaftaran"<<endl;
        cout<<"2. Menu ATM"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		if(notifikasiPIN==1){
			cout<<"NOTIFIKASI ATM: USERNAME SUDAH DIGUNAKAN!"<<endl;
		}
		if(notifikasiPIN==3){
			cout<<"NOTIFIKASI ATM: PIN HARUS BERJUMLAH 6 DIGIT!"<<endl;
		}
    
	cout<<"PILIHAN: ";
    cin>>opsiMainMenu;
    system("CLS");
    if (opsiMainMenu == 1){
    	ulang:
	    	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	        cout<<"-----------------FORM PENDAFTARAN ATM BANK BNR-------------------"<<endl;
	        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	    	cout<<"Masukkan Nomor Rekening Anda \t: ";
	    	cin>>nomorRekening;
    	int size = sizeof(noRekening)/sizeof(noRekening[0]);
    	for(int i=0;i<size;i++){
	    	if(nomorRekening == noRekening[i]){
	    		cekRekening = 0;
			}
			rekeningKe = i;			//menggunakan akun ATM ke-i untuk bertransaksi
		}
		if (cekRekening == 0){
			buatAkun(rekeningKe); 	//memanggil prosedur pembuatan akun
			goto menu;
		}
		else{
			cout<<"Nomor rekening salah/tidak terdaftar! Coba lagi? (Y/N)!"<<endl;
			cin>>ulangInput;
			system("CLS");
			if(ulangInput=="Y" || ulangInput=="y"){
    			getchar();
				goto ulang;
			}
			else if(ulangInput=="N" || ulangInput=="n"){
				cout << "Jika nomor rekening anda tidak terdaftar, silahkan daftar melalui teller Bank BNR!";
				return 0;
			}
			else{
				cout<<"Inputan Tidak Sesuai!"<<endl;
				goto transaksi;
			}	
		}	
    }
    else if(opsiMainMenu == 2){
    	login:
    		system("CLS");
    		header();
	    	cout<<"Masukkan Username Anda \t: ";
	    	cin>>inputanUsername;
	    	cout<<"Masukkan PIN Anda \t: ";
	    	cin>>inputanPIN;
	    nr = cekAkun(inputanUsername,inputanPIN);
	    if(hasilCek == 0 && cekPINSalah[nr] <= 3){
	    	ATM(nr);		//memanggil fungsi ATM
	    	cekPINSalah[nr] = 0;
	    	do{
	    		if(notifikasiRekening==1){
	    			BuktiTransaksi:
			    		cout<<"Cetak Bukti Transaksi? (Y/N)!"<<endl;
						cin>>cetak;
					if(cetak=="Y" || cetak=="y"){
						cetakTransaksi(noRekening[nr], jenisTransaksi, jumlahTransaksi, saldo[nr]);	//memanggil prosedur cetak transaksi
						transaksi:
							cout<<"Apakah ingin bertransaksi lagi? (Y/N)"<<endl;
				    		cin>>ulangInput;
			    		if(ulangInput=="Y" || ulangInput=="y"){
		    				goto menu;
						}
						else if(ulangInput=="N" || ulangInput=="n"){
							cout << "Terima Kasih Telah Melakukan Transaksi di ATM BNR"<<endl;
							return 0;
						}
						else{
							cout<<"Inputan Tidak Sesuai!"<<endl;
							goto transaksi;
						}	
					}
					else if(cetak=="N" || cetak=="n" ){
						cout << "Terima Kasih Telah Melakukan Transaksi di ATM BNR"<<endl;
						goto transaksi;
					}
					else{
						cout<<"Inputan Tidak Sesuai!!!!!"<<endl;
						goto BuktiTransaksi;
					}
				}
			}while (ATM(nr)==1);		
		}
		else if(hasilCek == 1){
			cout<<"Username tidak terdaftar!"<<endl;
			inputUlang:
				cout<<"Login ulang? (Y/N)"<<endl;
		    	cin>>ulangInput;
	    	if(ulangInput=="Y" || ulangInput=="y"){
    			goto menu;
			}
			else if(ulangInput=="N" || ulangInput=="n"){
				cout << "Terima Kasih Telah Menggunakan ATM BNR"<<endl;
				return 0;
			}
			else{
				cout<<"Inputan Tidak Sesuai!"<<endl;
				goto inputUlang;
			}
		}
		else{
			cekPINSalah[nr]++;
			if(cekPINSalah[nr]<=3){
				input:
					cout<<"Anda salah memasukkan password sebanyak "<<cekPINSalah[nr]<<" kali! Coba lagi? (Y/N)"<<endl;
					cin>>ulangInput;
				if(ulangInput=="Y" || ulangInput=="y"){
	    			goto login;
				}
				else if(ulangInput=="N" || ulangInput=="n"){
					cout << "Terima Kasih Telah Melakukan Transaksi di ATM BNR"<<endl;
				return 0;
				}
				else{
					cout<<"Inputan Tidak Sesuai!"<<endl;
					goto input;
				}
			}
			else{
				cout<<"Akun ATM anda terblokir! Silahkan datang ke Bank BNR untuk aktivasi akun anda!"<<endl;
				menuutama:
					cout<<"Ke menu utama? (Y/N)"<<endl;
					cin>>ulangInput;
				if(ulangInput=="Y" || ulangInput=="y"){
	    			goto menu;
				}
				else if(ulangInput=="N" || ulangInput=="n"){
					cout << "Terima Kasih Telah Melakukan Transaksi di ATM BNR!"<<endl;
				return 0;
				}
				else{
					cout<<"Inputan Tidak Sesuai!"<<endl;
					goto menuutama;
				}
			}
		}
	}
	else{
		cout<<"Terima Kasih Telah Menggunakan ATM BNR!"<<endl;
    	return 0;		
	}
}

