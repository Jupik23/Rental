#include "Wypozyczalnia.h"
//1
void Wypozyczalnia::Oferta()
{
	for (auto it = listaPrzyrzadow.begin(); it != listaPrzyrzadow.end(); ++it)
	{
		(*it)->wyswietlInformacje();
		std::cout << std::endl;
	}

}

void Wypozyczalnia::wypisz_co_siedem() {
	int i = 0;
	for (const auto& przyrzad : listaPrzyrzadow) {
		std::cout << i << ".";
		przyrzad->getNazwa();
		std::cout << std::endl;
		i++;
	}
}
//wypisz liste klientow
void Wypozyczalnia::wypisz_co_piec() {
	int i = 0;
	for (const auto& przyrzad : listaPrzyrzadow) {
		std::cout << i << ".";
		przyrzad->getImie();
		std::cout << std::endl;
	}
	i++;
}
//wypisz liste zarezerwowanych
void Wypozyczalnia::wypisz_co_piec2() {
	int i = 0;
	for (const auto& przyrzad : listaPrzyrzadow) {
		if (!przyrzad->czyDostepny()) {
			std::cout << i << ".";
			przyrzad->wyswietlInformacje();
			i++;
		}
	}
}

void Wypozyczalnia::wypozyczPrzedmiot() {
	int i=0;
	int a;
	std::string nazwa;
	std::string data1;
	std::string data2;
	if (listaPrzyrzadow.empty()){
				std::cout<<"Brak przyrzadow do wypozyczenia"<<std::endl;
				return;
			}
	for (const auto& wyp : listaPrzyrzadow) {
		std::cout << i<<".	";
		wyp->wyswietlInformacje();
		std::cout << std::endl;
		i++;
	}
	std::cout <<"Podaj ID do wypozyczenia "<<std::endl;
	std::cin >> a;
	std::cout << "Podaj nazwe osoby wypozyczajacej " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, nazwa);
	std::cout << "Podaj date wypozyczenia dd.mm.yyyy  " << std::endl;
	std::cin >> data1;
	std::cout << "Podaj date oddania dd.mm.yyyy  " << std::endl;
	std::cin >> data2;
	Wypozyczenie wypo(a, nazwa, data1, data2);
	listaWypozyczen.push_back(wypo);
	listaPrzyrzadow[a]->zmienDostepnosc(false);
	std::cout <<"Przyrzad "<<listaPrzyrzadow[a]->getNazwa()<<" zostal wypozyczony"<<std::endl;
}

void Wypozyczalnia::zwrocPrzedmiot(){
	int i = 0;
	if (listaPrzyrzadow.empty()) {
		std::cout<<"Brak przyrzadow do zwrocenia"<<std::endl;
		return;
	}
	for (const auto& wyp : listaPrzyrzadow) {
		std::cout << i << " "; 
		wyp->wyswietlInformacje();
		std::cout << std::endl;
		i++;
	}
	std::cout << "Podaj ID do zwrocenia" << std::endl;
	std::cin >> i;
	listaPrzyrzadow[i]->zmienDostepnosc(true);
	std::cout <<"Przyrzad "<<listaPrzyrzadow[i]->getNazwa()<<" zostal zwrocony"<<std::endl;
	
}

void Wypozyczalnia::zapisz_do_pliku2(const std::string& Nazwa_pliku)
{
	std::ofstream file(Nazwa_pliku);
	if (file.good())
	{
		for (const auto& wyp : listaWypozyczen) {
			file << std::to_string(wyp.getID())<<" ";
			file << wyp.getOsobaWypozyczajaca() << " ";
			file << wyp.getDataWypozyczenia() << " ";
			file << wyp.getDataOddania() << std::endl;
		
		}
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
	}
}

void Wypozyczalnia::zapisz_do_pliku(const std::string& Nazwa_pliku)
{
	std::ofstream file(Nazwa_pliku);
	if (file.good())
	{
		for (const auto& wyp : listaPrzyrzadow) {
			file << wyp->zapisz_do_pliku();
		}
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
	}
}

void Wypozyczalnia::wczytaj_z_pliku2()
{
	std::string nazwa_PLIKU;
	std::cout << "Podaj nazwe pliku wypozyczen w formacie .txt (inny niz przyrzady.txt): ";
	std::cin >> nazwa_PLIKU;
	while (std::cin.fail() || nazwa_PLIKU.substr(nazwa_PLIKU.size() - 4) != ".txt" || nazwa_PLIKU.length() < 5)
	{
		std::cout << "Podaj poprawna nazwe pliku: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> nazwa_PLIKU;
	}

	std::ifstream file(nazwa_PLIKU);
	if (file)
	{
		std::string osoby;
		std::string line;
		std::string data;
		std::string data2;
		int id;

		while (file >> id >> osoby >> data >> data2)
		{
				Wypozyczenie wypozyczenie(id, osoby, data, data2);
				listaWypozyczen.push_back(wypozyczenie);
		}
		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
	}
}

void Wypozyczalnia::wczytaj_z_pliku()
{
	std::string nazwa_PLIKU;
	std::cout << "Podaj nazwe pliku z przyrzadami w formacie .txt : ";
	std::cin >> nazwa_PLIKU;
	while (std::cin.fail() || nazwa_PLIKU.substr(nazwa_PLIKU.size() - 4) != ".txt" || nazwa_PLIKU.length() < 5)
	{
		std::cout << "Podaj poprawna nazwe pliku: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> nazwa_PLIKU;
	}
	std::ifstream file(nazwa_PLIKU);
	if (file)
	{
		std::string nazwaosoby;
		std::string line;
		std::string typ;
		std::string nazwa;
		int kanaly;
		bool dostepnosc;
		double rozdzielczosc;
		double cena;

		while (std::getline(file, line))
		{
			std::string typprzy;
			std::getline(file, typprzy);
			
			if (typprzy == "Typ przyrzadu: Multimetr")
			{
				typ = "Multimetr";
				nazwaosoby= line.substr(line.find(":") + 2);
				std::getline(file, line);
				nazwa = line.substr(line.find(":") + 1);
				std::getline(file, line);
				kanaly = std::stoi(line.substr(line.find(":") + 2));
				std::getline(file, line);
				if (line.substr(line.find(":") + 2) == "Dostepny")
					dostepnosc = true;
				else
					dostepnosc = false;
				std::getline(file, line);
				rozdzielczosc = std::stod(line.substr(line.find(":") + 2));
				std::getline(file, line);
				cena = std::stod(line.substr(line.find(":") + 2));

				Multimetr* multimetr = new Multimetr(nazwaosoby,typ, nazwa, kanaly, dostepnosc, rozdzielczosc, cena);
				listaPrzyrzadow.push_back(multimetr);
			}
			else if (typprzy == "Typ przyrzadu: Oscyloskop")
			{
				typ = "Oscyloskop";
				nazwaosoby = line.substr(line.find(":") + 2);
				std::getline(file, line); 
				nazwa = line.substr(line.find(":") + 1);
				std::getline(file, line);
				kanaly = std::stoi(line.substr(line.find(":") + 2));
				std::getline(file, line);
				dostepnosc = (line.substr(line.find(":") + 2) == "Dostepny");
				std::getline(file, line);
				rozdzielczosc = std::stod(line.substr(line.find(":") + 2));
				std::getline(file, line);
				cena = std::stod(line.substr(line.find(":") + 2));

				Oscyloskop* oscyloskop = new Oscyloskop(nazwaosoby,typ, nazwa, kanaly, dostepnosc, rozdzielczosc, cena);
				listaPrzyrzadow.push_back(oscyloskop);
			}
			else if (typprzy == "Typ przyrzadu: Generator")
			{
				typ = "Generator";
				nazwaosoby = line.substr(line.find(":") + 2);
				std::getline(file, line); 
				nazwa = line.substr(line.find(":") + 1);
				std::getline(file, line);
				kanaly = std::stoi(line.substr(line.find(":") + 2));
				std::getline(file, line);
				dostepnosc = (line.substr(line.find(":") + 2) == "Dostepny");
				std::getline(file, line);
				rozdzielczosc = std::stod(line.substr(line.find(":") + 2));
				std::getline(file, line);
				cena = std::stod(line.substr(line.find(":") + 2));

				Generator* generator = new Generator(nazwaosoby,typ, nazwa, kanaly, dostepnosc, rozdzielczosc, cena);
				listaPrzyrzadow.push_back(generator);
			}

		
		}

		file.close();
	}
	else
	{
		std::cout << "B³¹d podczas odczytu pliku." << std::endl;
	}
}

void Wypozyczalnia::dodajPrzyrzad(PrzyrzadPomiarowy* przyrzad) {
	listaPrzyrzadow.push_back(przyrzad);
}

bool Wypozyczalnia::CzyPrzyrzadDostepny(const std::string& nazwaPrzyrzadu)const {
	for (const auto& przyrzad : listaPrzyrzadow) {
		if (przyrzad->getNazwa() == nazwaPrzyrzadu) {
			return przyrzad->czyDostepny();
		}
	}
	return false;
}


void Wypozyczalnia::wyswietlPrzyrzady() {
	for (const auto& przyrzad : listaPrzyrzadow) {
		przyrzad->wyswietlInformacje();
		std::cout << std::endl;
	}
}


Wypozyczalnia::~Wypozyczalnia() {
	for (const auto& przyrzad : listaPrzyrzadow) {
		delete przyrzad;
	}
	listaPrzyrzadow.clear();
}


