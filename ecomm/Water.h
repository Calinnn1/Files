// Class for
// 1) calculand cantitatea in depozit "Admin"
// 2) schimband pretul "Admin"
// 3) pentru cumparare produs

#pragma once
#include <iostream>

using namespace std;

class Product_WaterBeverages
{
private:

	// numai "Admin"
	// acesti 3 intregi pentru cantitate in depozit
	// cantitatea in depozit poate fi schimbata de "Admin"
	int storage_quantity_water_hydrolife_750ml;
	int storage_quantity_drink_aloe_500ml;
	int storage_quantity_nectar_zet_125ml;

	// preturile produselor
	// preturile pot fi schimbate doar de "Admin"
	int price_water_hydrolife_750ml;
	int price_drink_aloe_500ml;
	int price_nectar_zet_125ml;

	// "User" - vizibil numai pentru utilizatori
	// poate fi decrementat cand "User" cumpara acest produs
	int quantity_water_hydrolife_750ml;
	int quantity_drink_aloe_500ml;
	int quantity_nectar_zet_125ml;

public:

	//constructor implicit
	Product_WaterBeverages();

	//constructor parametrizat
	//Product_VegetablesFruits(int sp, int sc, int so, int pp, int pc, int po);

	// numai pentru "Admin" setand parametrii pentru depozit
	void set_storage_quantity_water_hydrolife_750ml(int storage_quantity_water_hydrolife_750ml) {
		this->storage_quantity_water_hydrolife_750ml = storage_quantity_water_hydrolife_750ml;
	}
		int get_storage_quantity_water_hydrolife_750ml() {
		return storage_quantity_water_hydrolife_750ml;
	}

	void set_storage_quantity_drink_aloe_500ml(int storage_quantity_drink_aloe_500ml) {
		this->storage_quantity_drink_aloe_500ml = storage_quantity_drink_aloe_500ml;
	}
		int get_storage_quantity_drink_aloe_500ml() {
		return storage_quantity_drink_aloe_500ml;
	}

	void set_storage_quantity_nectar_zet_125ml(int storage_quantity_nectar_zet_125ml) {
		this->storage_quantity_nectar_zet_125ml = storage_quantity_nectar_zet_125ml;
	}
		int get_storage_quantity_nectar_zet_125ml() {
		return storage_quantity_nectar_zet_125ml;
	}

	// setand preturile produselor
	void set_price_water_hydrolife_750ml(int price_water_hydrolife_750ml) {
		this->price_water_hydrolife_750ml = price_water_hydrolife_750ml;
	}
		int get_price_water_hydrolife_750ml() {
		return price_water_hydrolife_750ml;
	}
	void set_price_drink_aloe_500ml(int price_drink_aloe_500ml) {
		this->price_drink_aloe_500ml = price_drink_aloe_500ml;
	}
		int get_price_drink_aloe_500ml() {
		return price_drink_aloe_500ml;
	}
	void set_price_nectar_zet_125ml(int price_nectar_zet_125ml) {
		this->price_nectar_zet_125ml = price_nectar_zet_125ml;
	}
		int get_price_nectar_zet_125ml() {
		return price_nectar_zet_125ml;
	}

	// Admin "User"
	// if '1'  incrementand ... ar trebui +1, if '2' decrementand ... ar trebui -1
	void set_quantity_water_hydrolife_750ml_incrementing() {
		quantity_water_hydrolife_750ml++;
		storage_quantity_water_hydrolife_750ml--;
	}
	void set_quantity_water_hydrolife_750ml_decrementing() {
		quantity_water_hydrolife_750ml--;
		storage_quantity_water_hydrolife_750ml++;
	}
		int get_quantity_water_hydrolife_750ml() {
		return quantity_water_hydrolife_750ml;
	}

	//bautura_aloe_500ml
	void set_quantity_drink_aloe_500ml_incrementing() {
		quantity_drink_aloe_500ml++;
		storage_quantity_drink_aloe_500ml--;
	}
	void set_quantity_drink_aloe_500ml_decrementing() {
		quantity_drink_aloe_500ml--;
		storage_quantity_drink_aloe_500ml++;
	}
		int get_quantity_drink_aloe_500ml() {
		return quantity_drink_aloe_500ml;
	}
	//nectar_zet_125ml
	void set_quantity_nectar_zet_125ml_incrementing() {
		quantity_nectar_zet_125ml++;
		storage_quantity_nectar_zet_125ml--;
	}
	void set_quantity_nectar_zet_125ml_decrementing() {
		quantity_nectar_zet_125ml--;
		storage_quantity_nectar_zet_125ml ++ ;
	}
		int get_quantity_nectar_zet_125ml() {
		return quantity_nectar_zet_125ml;
	}
};


// Constructor implicit
Product_WaterBeverages::Product_WaterBeverages() {
	// in depozit avem...
	storage_quantity_water_hydrolife_750ml = 10;
	storage_quantity_drink_aloe_500ml = 10;
	storage_quantity_nectar_zet_125ml = 10;

	// preturi implicite
	price_water_hydrolife_750ml = 2390;
	price_drink_aloe_500ml = 8990;
	price_nectar_zet_125ml = 8890;

	//cantitate cumparata implicit de utilizator
	quantity_water_hydrolife_750ml = 0;
	quantity_drink_aloe_500ml = 0;
	quantity_nectar_zet_125ml = 0;
}