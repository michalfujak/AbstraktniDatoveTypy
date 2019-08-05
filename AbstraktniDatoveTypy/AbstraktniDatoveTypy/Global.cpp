// Project Abstraktni datove typy. Test project

#include <iostream>

// Usings
using std::cout;
using std::cin;
using std::endl;

/*
* Class Tvar
*/
class Tvar
{
public:
	Tvar() {}
	virtual ~Tvar() {}
	virtual long ZjistitPlochu() { return -1; } // Error
	virtual long ZjistitObvod() { return -1; }
	virtual void Nakreslit() {}
};


/*
* Class Kruznice 
*/
class Kruznice : public Tvar
{
public:
	Kruznice(int polomer) : jejiPolomer(polomer) {}
	~Kruznice() {}
	long ZjistitPolohu() { return 3 * jejiPolomer * jejiPolomer; }
	long ZjistitObvod() { return 6 * jejiPolomer; }
	void Nakreslit();
private:
	int jejiPolomer;
	// int jejiObvod;
};

void Kruznice::Nakreslit()
{
	cout << "Tuna prebieha kreslenie kruznice! " << endl;
}

/*
* Class Obdelnik
*/
class Obdelnik : public Tvar
{
public:
	Obdelnik(int dlzka, int sirka) :
		jehoDlzka(dlzka), jehoSirka(sirka){}
	virtual ~Obdelnik() {}
	virtual long ZjistitPlochu() { return jehoDlzka * jehoSirka; }
	virtual long ZjistitObvod() { return (2 * jehoDlzka) + (2 * jehoSirka); }
	virtual int ZjistitDlzku() { return jehoDlzka; }
	virtual int ZjistitSirku() { return jehoSirka; }
	virtual void Nakreslit();
private:
	int jehoSirka;
	int jehoDlzka;
};

// Obdelnik::Nakreslit <body>
//
void Obdelnik::Nakreslit()
{
	for (int i = 0; i < jehoDlzka; i++)
	{
		for (int j = 0; j < jehoSirka; j++)
		{
			cout << "x ";
		}
		cout << "\n";
	}
}

/*
* Class Ctverec
*/
class Ctverec : public Obdelnik
{
public:
	Ctverec(int dlzka);
	Ctverec(int dlzka, int sirka);
	~Ctverec() {}
	long ZjistitObvod() { return 4 * ZjistitDlzku(); }
};

// Ctverec::Ctverec <body-construct(param)>
//
Ctverec::Ctverec(int dlzka): 
	Obdelnik(dlzka, dlzka)
{
	// Empty
}

// Ctverec::Ctverec <body-construct(param, param)> 
//
Ctverec::Ctverec(int dlzka, int sirka) :
	Obdelnik(dlzka, sirka)
{
	if (ZjistitDlzku() != ZjistitSirku())
	{
		cout << "Error, toto nieje je ctverec... Alebo sa jedna o obdlznik??" << endl;
	}
}


// Main thread, master process
int main()
{
	int volba;
	bool fKonec = false;
	Tvar* tvar;

	while (!fKonec)
	{
		cout << "(1)Kruznica (2)Obdlznik (3)Ctverec (0)Koniec " << endl;
		cin >> volba;

		switch (volba)
		{
		case 0:
			fKonec = true;
			break;

		case 1:
			tvar = new Kruznice(5);
			if (!fKonec)
			{
				tvar->Nakreslit();
			}
			delete tvar;
			tvar = 0;
			break;

		case 2:
			tvar = new Obdelnik(4, 6);
			if (!fKonec)
			{
				tvar->Nakreslit();
			}
			delete tvar;
			tvar = 0;
			break;

		case 3:
			tvar = new Ctverec(5);
			if (!fKonec)
			{
				tvar->Nakreslit();
			}
			delete tvar;
			tvar = 0;
			break;
		default:
			cout << "Zadajte cislo medzi 0 az 3, 0 znamena koniec programu" << endl;
			continue;
			break;
		}
		cout << "\n" << endl;
	}
	return 0;
}
