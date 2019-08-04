// Project Abstraktni datove typy. Test project

#include <iostream>

// Usings
using std::cout;
using std::cin;
using std::endl;

class Tvar
{
public:
	Tvar() {}
	virtual ~Tvar() {}
	virtual long ZjistitPlochu() { return -1; } // Error
	virtual long ZjistitObvod() { return -1; }
	virtual void Nakreslit() {}
private:
};

class Kruznice : public Tvar
{
public:
	Kruznice(int polomer):jejiPolomer(polomer) {  }
	~Kruznice() {}
	long ZjistitPolohu() { return 3 * jejiPolomer * jejiPolomer; }
	long ZjistitObvod() { return 6 * jejiPolomer; }
	void Nakreslit();
private:
	int jejiPolomer;
	int jejiObvod;
};

void Kruznice::Nakreslit()
{
	cout << "Tuna prebieha kreslenie kruznice! " << endl;
}


// Main
int main()
{
	Tvar* tvar = new Tvar();
	tvar->Nakreslit();
	cin.get();
}

