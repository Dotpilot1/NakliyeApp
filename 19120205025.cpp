#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

class Plaka
{
public:
	Plaka(char c_plaka[8])
    {
		if (c_plaka[0] <= '8' && c_plaka[0] >= '1') {
			m_plaka[0] = c_plaka[0];
		}
		else
			throw invalid_argument("Uygun aralikta degildir!");
		if (c_plaka[0] >= '1' && c_plaka[0] < '8')
		{
			if (c_plaka[1] >= '0' && c_plaka[1] <= '9')
				m_plaka[1] = c_plaka[1];
		}
		else if (c_plaka[0] == '8')
		{
			if (c_plaka[1] == '0' || c_plaka[1] == '1')
				m_plaka[1] = c_plaka[1];
		}
		else
			throw invalid_argument("Uygun aralikta degildir!");
		
		if (c_plaka[2] >= 'A' && c_plaka[2] <= 'Z')
			m_plaka[2] = c_plaka[2];
		else
			throw invalid_argument("Uygun aralikta degildir!");

		for (int i{ 3 };i <= 5;++i) {
			if (c_plaka[i] >= 'A' && c_plaka[i] <= 'Z')
				m_plaka[i] = c_plaka[i];
			else if(c_plaka[i] >= '0' && c_plaka[i] <= '9')
				m_plaka[i] = c_plaka[i];
			else
				throw invalid_argument("Uygun aralikta degildir!");
		}

		for (int i{ 6 };i <= 7;++i) {
			if (c_plaka[i] >= '0' && c_plaka[i] <= '0')
				m_plaka[i] = c_plaka[i];
			else
				throw invalid_argument("Uygun aralikta degildir!");
		}
	}

private:
	char m_plaka[8];
};
class AracTuru
{
public:
	AracTuru(vector<char>& c_aracTuru) :m_aracTuru{ c_aracTuru }
	{

	}

private:
	vector<char>m_aracTuru;
};
class Sofor
{
public:
	Sofor(string c_name,string c_surname):
		m_name{ c_name }, m_surname{ c_surname }
	{

	}
private:
	string m_name;
	string m_surname;

};
class Yuk
{
public:
	enum class YukTuru {
		KURU_YUK,
		GIDA,
		KIMYASAL
	};

	Yuk(const string& c_yukIsým,YukTuru c_yukTipi,int c_yukHacmi,int c_yukAgirligi):
		m_yukIsim{ c_yukIsým }, m_yukTipi{ c_yukTipi }
	{
		setYukHacmi(c_yukHacmi);
		setYukAgirligi(c_yukAgirligi);
	}
	void setYukIsim(const string& c_yukIsim) {
		m_yukIsim = c_yukIsim;
	}
	string getYukIsim()const {
		return m_yukIsim;
	}

	void setYukHacmi(int c_yukHacmi) {
		if (c_yukHacmi >= 0)
			m_yukHacmi = c_yukHacmi;
		else
			throw invalid_argument("0 >= olmali!");
	}
	int getYukHacmi()const {
		return m_yukHacmi;
	}

	void setYukAgirligi(int c_yukAgirligi) {
		if (c_yukAgirligi >= 0)
			m_yukHacmi = c_yukAgirligi;
		else
			throw invalid_argument("0 >= olmali!");
	}
	int getYukAgirligi()const {
		return m_yukAgirligi;
	}

	void setYukTuru(YukTuru c_tur) {
		m_yukTipi = c_tur;
	}
	YukTuru getYukTuru() const {
		return m_yukTipi;
	}



private:
	string m_yukIsim;
	int m_yukHacmi;
	int m_yukAgirligi;
	YukTuru m_yukTipi;
};



class Arac
{
	friend ostream& operator<<(ostream& out, const Arac& c_arac)
	{
		out << "Plaka:" << c_arac.getPlaka()<< endl
			<< "Sofor" << c_arac.getAracSofor() << endl
			<<"Arac Turu:"<<c_arac.getAracTuru()<<endl
		
		for (auto& ite : c_arac.m_yukListesi)
		{
			out << "Yuk Adi" << ite.getYukIsim() << endl
				<< "Yuk Turu" << ite.getYukTuru() << endl
				<< "Yuk Hacmi" << ite.getYukHacmi() << endl
				<< "Yuk Agirligi" << ite.getYukAgirligi() << endl;
		}
		return out;
	}

public:
    Arac(Plaka c_aracPlaka,Sofor c_aracSofor,list<Yuk> c_yukListesi,AracTuru c_aracTuru):
		m_aracPlaka{c_aracPlaka},
		m_aracSofor{ c_aracSofor },
		m_aracTuru{ c_aracTuru }
	{
		setYukListesi(c_yukListesi);
	}

	virtual ~Arac();

	virtual void setPlaka(Plaka c_aracPlaka) {
		m_aracPlaka = c_aracPlaka;
	}
	virtual Plaka getPlaka() const {
		return m_aracPlaka;
	}

	virtual void setAracSofor(Sofor c_aracSofor) {
		m_aracSofor = c_aracSofor;
	}
	virtual Sofor getAracSofor() const {
		return m_aracSofor;
	}

	virtual void setYukListesi(list<Yuk> c_yukListesi) {
		m_yukListesi = c_yukListesi;
	}
	virtual list<Yuk> getYukListesi() const {
		return m_yukListesi;
	}

	virtual void setAracTuru(AracTuru c_aracTuru) {
		m_aracTuru = c_aracTuru;
	}
	virtual AracTuru getAracTuru() const {
		return m_aracTuru;
	}

	virtual void yukEkle(Yuk c_yuk) {
		m_yukListesi.push_back(c_yuk);
	}
	virtual void yukBosalt(Yuk c_yuk) {
		m_yukListesi.remove(c_yuk);
	}

	virtual void yukTemizle() {
		m_yukListesi.clear();
	}
	
	/*virtual void printYuk() {
		for (auto it = m_yukListesi.cbegin(); it != m_yukListesi.cend(); ++it)
			cout << it << ' ' ;
	}*/
	virtual bool bosMu() {
		return m_yukListesi.empty();
	}
	virtual double toplamHacim()
	{
		double _toplamHacim;
		for (auto& ite : m_yukListesi)
		{
			_toplamHacim += ite.getYukHacmi();
		}
		return _toplamHacim;
	}

	virtual double toplamAgirlik()
	{
		double _toplamAgirlik;
		for (auto& ite : m_yukListesi)
		{
			_toplamAgirlik += ite.getYukAgirligi();
		}
		return _toplamAgirlik;
	}

	Arac& operator+=(Arac& c_arac)
	{
		for (auto& ite : c_arac.m_yukListesi)
		{
			this->m_yukListesi.push_back(ite);
		}
		return *this;
	}

	Arac& operator-=(Arac& c_arac)
	{
		for (auto& ite : c_arac.m_yukListesi)
		{
			this->m_yukListesi.remove(ite);
		}
	}

	
	/*void siralama(list<Yuk>*, int boyut, bool(*comprasionPtr)(int, int))
	{
		for (int start{ 0 };start < (boyut - 1);++start) {

			int tercih{ start };

			for (int guncel{ start + 1 };
				guncel < boyut;++guncel) {

				if(comprasionPtr(list<Yuk>))
			}

		}

	}*/
private:
	Plaka m_aracPlaka;
	Sofor m_aracSofor;
	list<Yuk> m_yukListesi;
	AracTuru m_aracTuru;
};



class Kamyon :public Arac {
public:

Kamyon(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru,double max):
	Arac(c_plaka, c_sofor,  c_yukListesi, c_aracTuru)
		{
			
				setMaxAgirlik();
		}

		void setMaxAgirlik()
		{
			int c_maxAgirlik = toplamAgirlik();
			if (c_maxAgirlik >= 2000 && c_maxAgirlik <= 10000)
				throw out_of_range("Asiri Yukleme");
			
			else
				m_maxAgirlik = c_maxAgirlik;
		}

		double getMaxAgirlik()
		{
			return m_maxAgirlik;
		}

		

	private:
		double m_maxAgirlik;
};

	
class Kamyonet :public Arac
{
public:
	Kamyonet(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru) :
		Arac(c_plaka, c_sofor, c_yukListesi, c_aracTuru)
	{

	}

private:

};
class AcikKasaKamyonet :public Kamyonet 
{
public:
	AcikKasaKamyonet(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru,int max) :
		Kamyonet(c_plaka, c_sofor, c_yukListesi, c_aracTuru)
	{

	}
	void setMaxAgirlik(list<Yuk> p_yukListesi) {
		for(auto iterator)

	}
	int getMaxAgirlik()const {
		return m_maxAgirlik;
	}
private:
	int m_maxAgirlik;
};
class KapaliKasaKamyonet :public Kamyonet
{
public:
	KapaliKasaKamyonet(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru, int maxAgirlik,int maxHacim) :
		Kamyonet(c_plaka, c_sofor, c_yukListesi, c_aracTuru)
	{

	}

private:
	int m_maxAgirlik;
	int m_maxHacim;
};
class SogutmaliKasaKamyonet:public Kamyonet
{
public:
	SogutmaliKasaKamyonet(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru, int maxAgirlik, int maxHacim,int sicaklik) :
		Kamyonet(c_plaka, c_sofor, c_yukListesi, c_aracTuru)
	{

	}

private:
	int m_maxAgirlik;
	int m_maxHacim;
	int m_maxSicaklik;
};
class TIR: public Arac
{
public:
	TIR(Plaka c_plaka, Sofor c_sofor, list<Yuk> c_yukListesi, AracTuru c_aracTuru,char*dorse,int maxHacim) :
		Arac(c_plaka, c_sofor, c_yukListesi, c_aracTuru)
	{

	}
private:
	char* m_dorse;
	int m_hacim;
};
int main() {





	return 0;
}