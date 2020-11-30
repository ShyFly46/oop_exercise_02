/*	Савченко Илья Владимирович
 *	М8О-208Б-19
 *
 *	вариант 19
 *	Создать класс Address для работы с адресами домов.
 *	Адрес должен состоять из строк с названием города и улицы и чисел с номером дома и квартиры.
 *	Реализовать операции сравнения адресов,
 *	а также операции проверки принадлежности адреса к улице и городу.
 *	В операциях не должен учитываться регистр строки.
 *	Так же необходимо сделать операцию,
 *	которая возвращает истину если два адреса находятся по соседству
 *	(на одной улице в одном городе и дома стоят подряд).
 *	Операцию сравнения равенства реализовать в виде перегрузки оператора.
 *	Операцию нахождения «по соседству» реализовать в виде перегрузки оператора &.
 *	Необходимо реализовать пользовательский литерал для работы с константами типа Address.
 */


#include<iostream>
#include<string>
#include"address.h"

using namespace std;

int main(){
	Address myHome = "mOskoW puSHkinA 13 37"_adr;
	string newCity,
		   newStreet;
	int newHouse,
		newFlat;

	cin >> newCity
		>> newStreet
		>> newHouse
		>> newFlat;

	Address friendHome(newCity, newStreet, newHouse, newFlat);

	cout << '\n';
	cout << myHome << '\n'
	     << friendHome << '\n';
	cout << "In Moscow?  "<<  friendHome.belongsTo("mOsKow") << '\n';
	cout << "myHome is in Moscow, Pushkina  " << myHome.belongsTo("MoskOw", "pushkINA") << '\n';
	cout << "Adress in Moscow Pushkina?     " << friendHome.belongsTo("MOSKOW", "pushkina") << '\n';
	cout << "\nmyHome * friendHome\n"
		 << (myHome & friendHome) << "  &\n"
	     << (myHome < friendHome) << "  <\n"
	     << (myHome > friendHome) << "  >\n";
	}
