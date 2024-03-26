// Class for
// 1) calculand cantitatea in depozit "Admin"
// 2) schimband pretul "Admin"
// 3) pentru cumparare produs

#pragma once
#include <iostream>

using namespace std;

class Product_BreadBakery
{
private:

	// Numai "administratorul"
	// acesti 3 intregi pentru cantitatea in depozit
	// cantitatea in depozit poate fi schimbata de "Admin"
	int storage_quantity_bun_smart_food;
	int storage_quantity_cracker_tuc_cheese_100g;
	int storage_quantity_bread_samarkand;

	// prterurile produselor
	// preturile pot fi modificate de "Admin"
	int price_bun_smart_food;
	int price_cracker_tuc_cheese_100g;
	int price_bread_samarkand;

	// vizibil pentru "user"
	// poate fi decrementat cand userul cumpara produse
	int quantity_bun_smart_food;
	int quantity_cracker_tuc_cheese_100g;
	int quantity_bread_samarkand;

public:

	// constructor implicit
	Product_BreadBakery();

	// constructor parametrizat
	//Product_VegetablesFruits(int sp, int sc, int so, int pp, int pc, int po);

	// numai pentru "Admin", setand parametrii pentru depozit
	void set_storage_quantity_bun_smart_food(int storage_quantity_bun_smart_food) {
		this->storage_quantity_bun_smart_food = storage_quantity_bun_smart_food;
	}
		int get_storage_quantity_bun_smart_food() {
		return storage_quantity_bun_smart_food;
	}

	void set_storage_quantity_cracker_tuc_cheese_100g(int storage_quantity_cracker_tuc_cheese_100g) {
		this->storage_quantity_cracker_tuc_cheese_100g = storage_quantity_cracker_tuc_cheese_100g;
	}
		int get_storage_quantity_cracker_tuc_cheese_100g() {
		return storage_quantity_cracker_tuc_cheese_100g;
	}

	void set_storage_quantity_bread_samarkand(int storage_quantity_bread_samarkand) {
		this->storage_quantity_bread_samarkand = storage_quantity_bread_samarkand;
	}
		int get_storage_quantity_bread_samarkand() {
		return storage_quantity_bread_samarkand;
	}

	// regland pretul produselor
	void set_price_bun_smart_food(int price_bun_smart_food) {
		this->price_bun_smart_food = price_bun_smart_food;
	}
		int get_price_bun_smart_food() {
		return price_bun_smart_food;
	}
	void set_price_cracker_tuc_cheese_100g(int price_cracker_tuc_cheese_100g) {
		this->price_cracker_tuc_cheese_100g = price_cracker_tuc_cheese_100g;
	}
		int get_price_cracker_tuc_cheese_100g() {
		return price_cracker_tuc_cheese_100g;
	}
	void set_price_bread_samarkand(int price_bread_samarkand) {
		this->price_bread_samarkand = price_bread_samarkand;
	}
		int get_price_bread_samarkand() {
		return price_bread_samarkand;
	}

	// pentru "User"
	// if '1'  incrementand ... ar trebui +1, if '2' decrementand ... ar trebui -1
	void set_quantity_bun_smart_food_incrementing() {
		quantity_bun_smart_food++;
		storage_quantity_bun_smart_food--;
	}
	void set_quantity_bun_smart_food_decrementing() {
		quantity_bun_smart_food--;
		storage_quantity_bun_smart_food++;
	}
		int get_quantity_bun_smart_food() {
		return quantity_bun_smart_food;
	}

	//cracker_tuc_cheese_100g
	void set_quantity_cracker_tuc_cheese_100g_incrementing() {
		quantity_cracker_tuc_cheese_100g++;
		storage_quantity_cracker_tuc_cheese_100g--;
	}
	void set_quantity_cracker_tuc_cheese_100g_decrementing() {
		quantity_cracker_tuc_cheese_100g--;
		storage_quantity_cracker_tuc_cheese_100g++;
	}
		int get_quantity_cracker_tuc_cheese_100g() {
		return quantity_cracker_tuc_cheese_100g;
	}
	//bread_samarkand
	void set_quantity_bread_samarkand_incrementing() {
		quantity_bread_samarkand++;
		storage_quantity_bread_samarkand--;
	}
	void set_quantity_bread_samarkand_decrementing() {
		quantity_bread_samarkand--;
		storage_quantity_bread_samarkand++;
	}
		int get_quantity_bread_samarkand() {
		return quantity_bread_samarkand;
	}
};


// Constructor implicit
Product_BreadBakery::Product_BreadBakery() {
	// in depozit avem...
	storage_quantity_bun_smart_food = 10;
	storage_quantity_cracker_tuc_cheese_100g = 10;
	storage_quantity_bread_samarkand = 10;

	// preturi implicite
	price_bun_smart_food = 3290;
	price_cracker_tuc_cheese_100g = 7390;
	price_bread_samarkand = 5990;

	//cantitate cumparata implicit de ustilizator
	quantity_bun_smart_food = 0;
	quantity_cracker_tuc_cheese_100g = 0;
	quantity_bread_samarkand = 0;
}