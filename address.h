#include<string>
#include<iostream>

using namespace std;

void MakeName(string &str){
	for(int i=0; str[i]; ++i){
		if(str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 'a'-'A';
		}
	str[0] -= 'a'-'A';
	}

class Address{
private:
	string city;
	string street;
	int house;
	int flat;
public:
	Address();
	Address(
		const string &city,
		const string &street,
		int house = 1,
		int flat = 1
		) {
		this->city = city;
		this->street = street;
		this->house = house;
		this->flat = flat;
		this->Normalize();
		}
	
	void Normalize(){
		MakeName(city);
		MakeName(street);
		}
	
	friend ostream& operator<< (ostream &out, const Address &adr){
		out	<< adr.city << " "
			<< adr.street << " "
			<< adr.house << " "
			<< adr.flat;
		return out;
		}

	bool belongsTo(string city, string street = "") const{
		MakeName(city);
		if(this->city != city)
			return false;
		if(street.size() == 0)
			return true;
		MakeName(street);
		return this->street == street;
		}

	// A = B    = 0
	// A < B    = -
	// A > B    = +
	friend int AdrComp(const Address &A, const Address &B){
		int temp;
		temp = A.city.compare(B.city);
		if(temp != 0)
			return temp;
		temp = A.street.compare(B.street);
		if(temp != 0)
			return temp;
		if(A.house != B.house)
			return A.house - B.house;
		return A.flat - B.flat;
		}
	friend bool operator==(const Address &A, const Address &B)
		{return AdrComp(A, B) == 0;}
	friend bool operator!=(const Address &A, const Address &B)
		{return AdrComp(A, B) != 0;}
	friend bool operator< (const Address &A, const Address &B)
		{return AdrComp(A, B) <  0;}
	friend bool operator<=(const Address &A, const Address &B)
		{return AdrComp(A, B) <= 0;}
	friend bool operator> (const Address &A, const Address &B)
		{return AdrComp(A, B) >  0;}
	friend bool operator>=(const Address &A, const Address &B)
		{return AdrComp(A, B) >= 0;}
	
	friend bool operator& (const Address &A, const Address &B){
		if(!A.belongsTo(B.city, B.street))
			return false;
		int temp = A.house - B.house;
		if(temp < 0)
			temp = -temp;
		return temp == 1;
		}
	
};

Address operator""_adr(const char* str, size_t n){
	int	i = 0;

	string city;
	for( ; str[i] != ' '; ++i)
		city += str[i];
	++i;

	string street;
	for( ; str[i] != ' '; ++i)
		street += str[i];
	++i;

	int house;
	for(house = 0; str[i] != ' '; ++i){
		house *= 10;
		house += str[i] - '0';
		}
	++i;

	int flat;
	for(flat=0; i<n; ++i){
		flat *= 10;
		flat += str[i] - '0';
		}

	return Address(city, street, house, flat);
	}
