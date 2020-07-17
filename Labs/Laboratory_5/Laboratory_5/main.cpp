#include "Domain.h"
#include "UI.h"
#include <crtdbg.h>
#include <assert.h>
#include "Comparator.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
#include "CVS_ShopList.h"
#include "File_ShopList.h"
#include "HTML_Shoplist.h"


using namespace std;


void test_domain()
{
	Rock_Tshirt rt;
	Rock_Tshirt rt2{ 1, "S", "Black", 90, 80, "https://www.amplifiedclothing.com/item/278/Metallica/METALLICA-MASTER-OF-PUPPETS-Charcoal.html", "Metallica" };
	rt.set_colour("blue");
	assert(rt.get_colour() == "blue");
	rt.set_formation("Volbeat");
	assert(rt.get_formation() == "Volbeat");
	rt.set_price(17);
	assert(rt.get_price() == 17);
	rt.set_quantity(27);
	assert(rt.get_quantity() == 27);
	rt.set_size("M");
	assert(rt.get_size() == "M");
	rt.set_photo("M");
	assert(rt.get_photo() == "M");
	assert(rt2.get_ID() == 1);
	assert((rt == rt2) == 0);
	rt2.display();
}

void test_dv()
{
	int i = 1;
	int j = 0;
	dynamic_vector<int> dv1(1);
	dv1.add(7);
	dv1.add(23);
	assert(dv1.get_size() == 2);
	assert(dv1.get_element(1) == 23);
	dynamic_vector<int> dv2 = dv1;
	dv2.delete_element(i);
	assert(dv2.get_size() == 1);
	assert(dv1.get_all_elems()[0] == 7);
	dv2 = dv2 - 7;
	assert(dv2.get_size() == 0);
	dv2 = dv1;
	assert(dv2.get_size() == 2);
	dv2.delete_element(j);
	assert(dv2.get_size() == 1);
}

void test_shop_list()
{
	std::vector<Rock_Tshirt> v;
	Rock_Tshirt rt{ 1, "S", "Black", 90, 80, "https://www.amplifiedclothing.com/item/278/Metallica/METALLICA-MASTER-OF-PUPPETS-Charcoal.html", "Metallica" };
	Rock_Tshirt rt2{ 2, "M", "Black", 33, 56, "http://store.verkkopaita.com/product/567/triviumthe-crusade-t-shirt", "Trivium" };
	Rock_Tshirt rt3;
	v.push_back(rt);
	v.push_back(rt2);
	Shop_list sh;
	rt = sh.get_current_tshirt();
	rt = sh.next();
	assert(sh.is_empty() == 1);
	sh.set_tshirts(v);
	assert(sh.is_empty() == 0);
	rt = sh.get_current_tshirt();
	assert(rt.get_ID() == 1);
	rt = sh.next();
	assert(rt.get_ID() == 2);
	rt = sh.get_current_tshirt();
	assert(rt.get_ID() == 2);
}

void test_controller()
{
	/*
	std::string str = "sad";
	Rock_Tshirt rt{ 1, "S", "Black", 90, 80, "https://www.amplifiedclothing.com/item/278/Metallica/METALLICA-MASTER-OF-PUPPETS-Charcoal.html", "Metallica" };
	Rock_Tshirt rt2{ 2, "M", "Black", 33, 56, "http://store.verkkopaita.com/product/567/triviumthe-crusade-t-shirt", "Trivium" };
	Rock_Tshirt rt8{ 8, "M", "Black", 19, 49, "https://bestrocktshirts.com/index.php/categories/heavy-metal/accept-blind-rage-world-tour-dates-2014-udo-saxon-judas-priest-heavy-metal-new-black-t-shirt", "Accept" };
	Repository repo{};
	repo.add_rock_tshirt(rt);
	repo.add_rock_tshirt(rt2);
	Controller ctrl{ repo };
	assert(ctrl.add_rock_tshirt_ctrl(rt) == 0);
	assert(ctrl.add_rock_tshirt_ctrl(rt8) == 1);
	assert(ctrl.delete_rock_tshirt_ctrl(8) == 1);
	assert(ctrl.delete_rock_tshirt_ctrl(8) == 0);
	assert(ctrl.update_rock_thsirt_photo_ctrl(8, str) == 0);
	assert(ctrl.update_rock_thsirt_photo_ctrl(1, str) == 1);
	assert(ctrl.update_rock_tshirt_colour_ctrl(8, str) == 0);
	assert(ctrl.update_rock_tshirt_colour_ctrl(1, str) == 1);
	assert(ctrl.update_rock_thsirt_size_ctrl(8, str) == 0);
	assert(ctrl.update_rock_thsirt_size_ctrl(1, str) == 1);
	assert(ctrl.update_rock_thsirt_price_ctrl(8, 25) == 0);
	assert(ctrl.update_rock_thsirt_price_ctrl(1, 25) == 1);
	assert(ctrl.update_rock_thsirt_quantity_ctrl(8, 30) == 0);
	assert(ctrl.update_rock_thsirt_quantity_ctrl(1, 30) == 1);
	std::vector<Rock_Tshirt> v = ctrl.get_repo().get_rock_tshirts();
	Rock_Tshirt aux = v.at(0);
	assert(aux.get_colour() == str);
	assert(aux.get_photo() == str);
	assert(aux.get_size() == str);
	assert(aux.get_price() == 25);
	assert(aux.get_quantity() == 30);
	ctrl.add_rock_tshirt_ctrl(rt8);
	v = ctrl.filter_by_size("M");
	assert(v.size() == 2);
	*/
}

void test_comporator()
{
	dynamic_vector<Rock_Tshirt> dv;
	Rock_Tshirt rt{ 1, "S", "Black", 90, 80, "https://www.amplifiedclothing.com/item/278/Metallica/METALLICA-MASTER-OF-PUPPETS-Charcoal.html", "Metallica" };
	Rock_Tshirt rt2{ 2, "M", "Black", 33, 56, "http://store.verkkopaita.com/product/567/triviumthe-crusade-t-shirt", "Trivium" };
	Rock_Tshirt rt6{ 6, "S", "White", 14, 67, "https://judaspriest.backstreetmerch.com/t-shirts/screaming-eagle-white", "Judas Priest" };
	Rock_Tshirt rt7{ 7, "S", "Black", 123, 100, "https://www.amazon.com/Roses-Floral-Bullet-Adult-T-Shirt/dp/B00UBBCB46", "Guns'N'Roses" };
	Rock_Tshirt rt8{ 8, "M", "Black", 19, 49, "https://bestrocktshirts.com/index.php/categories/heavy-metal/accept-blind-rage-world-tour-dates-2014-udo-saxon-judas-priest-heavy-metal-new-black-t-shirt", "Accept" };
	dv.add(rt);
	dv.add(rt2);
	dv.add(rt6);
	dv.add(rt7);
	dv.add(rt8);
	compare_ascending_price<Rock_Tshirt> c;
	generic_sort(dv, c);
	int i = 0;
	for (i = 1; i < dv.get_size(); i++)
		assert(c.compare(dv[i], dv[i - 1]) >= 0);
}

class Base
{
	int x;
public:
	Base() { cout << "Base default constructor" << "\n"; }
};

class Derived : public Base
{
	int y;
public:
	Derived() { cout << "Derived default constructor" << "\n";
	}
	Derived(int i) { cout << "Derived parameterized constructor" << "\n";
	}
};

int main()
{
	/*
	test_domain();
	test_dv();
	test_shop_list();
	test_controller();
	test_comporator();
	*/

	/*
	std::string s1 = "asbgdfhbkdjnbfbdhj";
	std::string s2 = "gdagsrhd";
	std::size_t find = s1.find(s2);
	cout << find << endl;
	cout << std::string::npos << endl;

	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);
	std::cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< "\n";

	// using std::find with array and pointer:
	int myints[] = { 10, 20, 30, 40 };
	int * p;

	p = std::find(myints, myints + 4, 30);
	if (p != myints + 4)
		std::cout << "Element found in myints: " << p-myints << '\n';
	else
		std::cout << "Element not found in myints\n";

	std::vector<int> myvector(myints, myints + 4);
	std::vector<int>::iterator it;

	std::cout << myvector.size() << "\n";

	it = std::find(myvector.begin(), myvector.end(), 20);
	myvector.erase(it);

	std::cout << myvector.size() << "\n";

	it = std::find(myvector.begin(), myvector.end(), 30);
	if (it != myvector.end())
		std::cout << "Element found in myvector: " << myvector.end()-myvector.begin() << '\n';
	else
		std::cout << "Element not found in myvector\n";
	 */
	//ifstream f("Rock_Tshirts.txt");
	/*std::string s;
	getline(f, s);
	cout << s;
	std::string delimiters = ",";
	size_t current;
	size_t next = -1;
	int i = 0;
	do
	{
		current = next + 1;
		next = s.find_first_of(delimiters, current);
		std::string str = s.substr(current, next - current);
		cout << str << endl;
		if (i == 0)
		{
			int nr = stoi(str);
			cout << "NR:" << nr << endl;
		}
		i++;
	} while (next != string::npos);
	cout << i << endl;
	*/
	//Rock_Tshirt r;
	//cout << r.get_ID() << ". Rock band: " << r.get_formation() << " Colour: " << r.get_colour() << " Size: " << r.get_size() << " Price: " << r.get_price() << " Quantity: " << r.get_quantity() << endl;


	{
		/*
		Repository repo{};
		Rock_Tshirt rt{ 1, "S", "Black", 90, 80, "https://www.amplifiedclothing.com/item/278/Metallica/METALLICA-MASTER-OF-PUPPETS-Charcoal.html", "Metallica" };
		Rock_Tshirt rt2{ 2, "M", "Black", 33, 56, "http://store.verkkopaita.com/product/567/triviumthe-crusade-t-shirt", "Trivium" };
		Rock_Tshirt rt3{ 3, "L", "Black", 50, 70, "https://www.hottopic.com/band-merch/shop-by-artist/green-day/", "Green Day" };
		Rock_Tshirt rt4{ 4, "XL", "White", 35, 75, "https://www.amazon.com/Aerosmith-Boston-Budokan-White-T-Shirt/dp/B009LJKX9Y", "Aerosmith" };
		Rock_Tshirt rt5{ 5, "M", "Black", 100, 45, "https://www.heavymetalonline.co.uk/shop/rotting-christ/rotting-christ-clothing/rotting-christ-clothing-t-shirts/rotting-christ-t-shirt-diavolus/", "Rotting Christ" };
		Rock_Tshirt rt6{ 6, "S", "White", 14, 67, "https://judaspriest.backstreetmerch.com/t-shirts/screaming-eagle-white", "Judas Priest" };
		Rock_Tshirt rt7{ 7, "S", "Black", 123, 100, "https://www.amazon.com/Roses-Floral-Bullet-Adult-T-Shirt/dp/B00UBBCB46", "Guns'N'Roses" };
		Rock_Tshirt rt8{ 8, "M", "Black", 19, 49, "https://bestrocktshirts.com/index.php/categories/heavy-metal/accept-blind-rage-world-tour-dates-2014-udo-saxon-judas-priest-heavy-metal-new-black-t-shirt", "Accept" };
		Rock_Tshirt rt9{ 9, "L", "Black", 67, 85, "https://www.amazon.com/Iron-Maiden-T-shirt-Trooper-British/dp/B007WSAG34", "Iron Maiden" };
		Rock_Tshirt rt10{ 10, "XL", "Grey", 200, 65, "https://www.volbeatstore.com/products/crashed-skullwing-t-shirt", "Volbeat" };
		repo.add_rock_tshirt(rt);
		repo.add_rock_tshirt(rt2);
		repo.add_rock_tshirt(rt3);
		repo.add_rock_tshirt(rt4);
		repo.add_rock_tshirt(rt5);
		repo.add_rock_tshirt(rt6);
		repo.add_rock_tshirt(rt7);
		repo.add_rock_tshirt(rt8);
		repo.add_rock_tshirt(rt9);
		repo.add_rock_tshirt(rt10);
		*/
		//int n;
		//cin >> n;
		//cin.ignore();
		//string s;
		//s = to_string(n);
		//s = s + "caca";
		//cout << n << " " << s << "\n";
		Base b;
		Derived d1;
		Derived d2(10);
		cout << "Please choose the type of file (1 for CSV or 2 for HTML):";
		int command{ 0 };
		cin >> command;
		cin.ignore();
		if (command == 1)
		{
			string t = "sh.txt";
			File_Shop_list* sh = new CVS_Shop_list{ "sh.txt" };
			File_Repo repo{ "Rock_Tshirts.txt" };
			Controller ctrl{ repo, sh };
			UI ui{ ctrl };
			ui.start();
		}
		if (command == 2)
		{
			string t = "sh.html";
			File_Shop_list* sh = new HTML_Shop_list{ t };
			File_Repo repo{ "Rock_Tshirts.txt" };
			Controller ctrl{ repo, sh };
			UI ui{ ctrl };
			ui.start();
		}
		
	}

	_CrtDumpMemoryLeaks();

	return 0;
}