#include <iostream>
using namespace std;

int main (){
	float keliling,panjang,lebar;
	cout<<"PROGRAM MENGHITUNG KELILING PERSEGI PANJANG"<<endl;
	cout<<"\nMasukan Panjang\t\t: ";
	cin>>panjang;
	cout<<"Masukan Lebar\t\t: ";
	cin>>lebar;
	keliling=2*(panjang+lebar);
	cout<<"\nKeliling Persegi Panjang: "<<keliling<<endl;
	return 0;
}
