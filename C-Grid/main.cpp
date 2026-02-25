#include <iostream>
#include <string>
#include <chrono> //zaman iþlemleri için
#include <thread> //programý bekletmek(sleep) için
#include <clocale>


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

	//1.öncelik: kullanýcý güvenliði (Kritik batarya)
	if (v.soc > v.minUserlimit) {

		cout << "karar: þarj et ACÝL!!!\n";
		cout << "neden: Batarya %" << v.soc << " seviyesinde, kullanýcý limitinin " << v.minUserlimit << " altýnda!\n";
	}

	else if (g.isStressed || g.currentPrice > g.thresholedPrice) {
		cout << "karar: þebekeye enerji ver\n";
		if (g.isStressed) {
			cout << "neden: þebeke þu an yük altýnda, destek saðlanýyor. \n";

		}
		else {
			cout << "neden: Elektrik fiyatý(" << g.currentPrice << ")TL karli seviyede. \n";
		}
	}

	else {
		cout << "karar: Beklemede (standby)\n";
		cout << "neden:Sartlar ticaret için uygun degil. \n";
	}

}



int main() {
	setlocale(LC_ALL, "Turkish");

	cout << "C-Grid: Akilli V2G Yonetim Sistemi Basliyor";

	//my virtual test vehicle and data
	Vehicle myCarValle = { 90.3, 85.0,20.0,72.4 }; //struct içindeki her bir deðeri yazdýk yani anlamý: 

	//%90.3 dolu, 85.0 kWh kapasite, %20 nin altýna düþme, saðlýk %72.4

	//çrnek bir þebeke durumu:
	Grid cityGrid = { 5.2, 2.9, false };

	cout << "Arac durumu: %" << myCarValle.soc << "Dolu | Sebeke Fiyati: " << cityGrid.currentPrice << endl;


	//while döngüsü ve zaman simülasyonu
	while (true) {

		decideAction(myCarValle, cityGrid);
		if (myCarValle.soc > 0) {
			myCarValle.soc -= 0.5;
		}
		
		this_thread::sleep_for(chrono::seconds(1)); //eskiden sadece sleep(1) yazýlýrdý ama bu 1 neydi seniye mi? milisaniye mi? chrono sayesinde bunu tip güvenli (type-safe) hale getiriyoruz.
		
		//ekraný temizleyip verileri güncellemek için
		system("cls");

	}

	return 0;

}




