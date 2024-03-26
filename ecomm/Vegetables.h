// Class for
// 1) calculand cantitatea in depozit "Admin"
// 2) schimband pretul "Admin"
// 3) pentru cumparare produs

#pragma once
#include <iostream>

using namespace std;

class Product_VegetablesFruits
{
private:

	// Numai "administratorul"
	// acesti 3 intregi pentru cantitatea in depozit
	// cantitatea in depozit poate fi schimbata de "Admin"
	int storage_quantity_potatoes;
	int storage_quantity_carrot;
	int storage_quantity_onion;

	// prterurile produselor
	// preturile pot fi modificate de "Admin"
	int price_potatoes;
	int price_carrot;
	int price_onion;

	// vizibil pt "user"
	// poate fi decrementat cand userul cumpara produse
	int quantity_potatoes;
	int quantity_carrot;
	int quantity_onion;

public:

	// constructor implicit
	Product_VegetablesFruits();

	// constructor parametrizat
	// Product_VegetablesFruits(int sp, int sc, int so, int pp, int pc, int po);

	// numai pentru "Admin" regland parametrii pt depozit
	void set_storage_quantity_potatoes(int storage_quantity_potatoes) {
		this->storage_quantity_potatoes = storage_quantity_potatoes;
	}
		int get_storage_quantity_potatoes() {
		return storage_quantity_potatoes;
	}

	void set_storage_quantity_carrot(int storage_quantity_carrot) {
		this->storage_quantity_carrot = storage_quantity_carrot;
	}
		int get_storage_quantity_carrot() {
		return storage_quantity_carrot;
	}

	void set_storage_quantity_onion(int storage_quantity_onion) {
		this->storage_quantity_onion = storage_quantity_onion;
	}
		int get_storage_quantity_onion() {
		return storage_quantity_onion;
	}

	// regland pretul produselor
	void set_price_potatoes(int price_potatoes) {
		this->price_potatoes = price_potatoes;
	}
		int get_price_potatoes() {
		return price_potatoes;
	}
	void set_price_carrot(int price_carrot) {
		this->price_carrot = price_carrot;
	}
		int get_price_carrot() {
		return price_carrot;
	}
	void set_price_onion(int price_onion) {
		this->price_onion = price_onion;
	}
		int get_price_onion() {
		return price_onion;
	}

	// pentru "User"
	// if '1'  incrementand ... ar trebui +1, if '2' decrementand ... ar trebui -1
	void set_quantity_potatoes_incrementing() {
		quantity_potatoes++;
		storage_quantity_potatoes--;
	}
	void set_quantity_potatoes_decrementing() {
		quantity_potatoes--;
		storage_quantity_potatoes++;
	}
		int get_quantity_potatoes() {
		return quantity_potatoes;
	}

	// morcov
	void set_quantity_carrot_incrementing() {
		quantity_carrot++;
		storage_quantity_carrot--;
	}
	void set_quantity_carrot_decrementing() {
		quantity_carrot--;
		storage_quantity_carrot++;
	}
		int get_quantity_carrot() {
		return quantity_carrot;
	}
	// ceapa
	void set_quantity_onion_incrementing() {
		quantity_onion++;
		storage_quantity_onion--;
	}
	void set_quantity_onion_decrementing() {
		quantity_onion--;
		storage_quantity_onion++;
	}
		int get_quantity_onion() {
		return quantity_onion;
	}
};


// Constructor implicit
Product_VegetablesFruits::Product_VegetablesFruits() {
	// in depozit avem ...
	storage_quantity_potatoes = 10;
	storage_quantity_carrot = 10;
	storage_quantity_onion = 10;

	// preturi implicite
	price_potatoes = 60;
	price_carrot = 40;
	price_onion = 40;

	//cantitatea implicita cumparata de user 
	quantity_potatoes = 0;
	quantity_carrot = 0;
	quantity_onion = 0;
}