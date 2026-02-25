#include <iostream>
#include <string>

using namespace std;

struct Vehicle {
	float soc;    //state of charge %
	float capacity;  //all(full) capacity (kwh) 
	float minUserlimit; //kulanýcýnýn arabadan sakýn bundan fazla çekme dediði yüzde
	float health;  //state of health: batarya ömrü kýsacasý
};

struct Grid {

	float currentPrice; //anlýk elektrik fiyatý (tl/kWh)
	float thresholedPrice; // bu fþyatýn üstündeyse þebekeye elektrik sat dediðimiz sýnýr
	bool isStressed; //þenekede aþýrý yük var mý? (V2G nin hayat kurtaracaðý yer)
};


void decideAction(Vehicle v, Grid g) {
	cout << "\n [C-Grid Analiz Yapiyor...]" << endl;

	if (v.soc > v.minUserlimit) {

	}
}



int main() {

	cout << "C-Grid: Akilli V2G Yonetim Sistemi Basliyor";


	//my virtual test vehicle and data

	Vehicle myCarValle = { 90.3, 85.0,20.0,72.4 }; //struct içindeki her bir deðeri yazdýk yani anlamý: 
	//%90.3 dolu, 85.0 kWh kapasite, %20 nin altýna düþme, saðlýk %72.4


	//çrnek bir þebeke durumu:
	Grid cityGrid = { 5.2, 2.9, false };

	cout << "Arac durumu: %" << myCarValle.soc << "Dolu | Sebeke Fiyati: " << cityGrid.currentPrice << endl;

	return 0;

}

