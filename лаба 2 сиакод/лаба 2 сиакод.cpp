/*33.Построить хеш - таблицу, содержащую последовательность из m = 51 элементов размерности n = 3.
Элементы генерируются с помощью датчика случайных чисел.
Хеш - функция - средняя часть квадрата ключа.*/
#include <iomanip>
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
const int AllElem = 51;
const int HshElem = AllElem * 2;
void vivod(int a[], int b) {
	for (int i = 0; i < b; i++)
	{
		cout << "" << "" << i << "." << "" << "" << a[i] << "\t" << " ";
		
	}
	cout << endl;
}
	
	void poisk(int mas[]) {
		int elem;
		int nomerelem;
		std::cout << "Введите число\n";
		cin >> elem;
		nomerelem = ((elem * elem) % 10000 / 100);

		if (mas[nomerelem] == 0) {
			cout << "Элемента в таблице нет\n";
		}
		else {
			if (elem == mas[nomerelem]) {
				cout << "Элемент в таблице есть\n";
				cout << "Элемент:" << elem << endl;
				cout << "Индекс:" << nomerelem << endl;
			}
			else {
				while (elem != mas[nomerelem]) {
					nomerelem = (nomerelem + 1) % 100;
					if (nomerelem == 0) break;
				}
				if (elem != mas[nomerelem]) {
					cout << "Элемента в таблице нет\n";
				}
				else {
					cout << "Элемент в таблице есть\n";
					cout << "Элемент:" << elem << endl;
					cout << "Индекс:" << nomerelem << endl;
				}
			}
		}
	}
	int poisk2(int mas[], int elem, int b) {
		bool f = false;
		if (mas[b] == 0) {
			cout << "Элемента в таблице нет\n";
		}
		else {
			if (elem == mas[b]) {
				f = true;
				cout << "Элемент в таблице есть\n";
				cout << "Элемент:" << elem << endl;
				cout << "Индекс:" << b << endl;
			}
			else {
				while (elem != mas[b]) {
					b = (b + 1) % HshElem;
					if (b == 0) break;
				}
				if (elem != mas[b]) {
					cout << "Элемента в таблице нет\n";
				}
				else {
					f = true;
					cout << "Элемент в таблице есть\n";
					cout << "Элемент:" << elem << endl;
					cout << "Индекс:" << b << endl;
				}
			}
		}
		return f;
	}
	
int main()
{
	setlocale(LC_ALL, "Russian");
	int f = 0;
	int tmp = 0;
	int k = 0;
	int n1 = 100; //Размер хэш-таблицы
	int nomerelem; //Хэш-адрес
	int k1 = 0; //Общее число проб
	int hash[100] = { 0 }; //Хэш-таблица
	int np = 1; //Номер пробы
	int mas[51]; //Массив генерируемых элементов
	int m = 51; //Количество генерируемых элементов
	while (k < m) {
		f = 0;
		tmp = rand() % 599 + 400;

		for (int i = 0; i < k; i++) { //чтобы не было повторяющихся

			if (mas[i] == tmp) {
				f = 1;
				break;
			}
		}

		if (f == 0)
		{
			mas[k] = tmp;
			k++;
		}
	}

	cout << "Генерация неповторяющихся чисел: " << endl;

	vivod(mas, AllElem);


	cout << "Хэш-таблица: " << endl;

	for (int ht = 0; ht < m; ht++)
	{

		nomerelem = ((((mas[ht] * mas[ht])) % 10000 / 100)); //метод середины квадрата 

		k1++; //Общее число проб
		int nomerelem0 = nomerelem;

		if (hash[nomerelem] == 0) //Если есть свободная ячейка
		{
			hash[nomerelem] = mas[ht];
		}
		else
		{
			while (hash[nomerelem] != NULL)
			{
				nomerelem = (nomerelem0 + np) % n1;
				np++;
				k1++;
			}
			hash[nomerelem] = mas[ht];

		}
		np = 1;

	}
	vivod (hash, 100);
	cout << endl;
	cout << "Коэффициент заполнения таблицы: " << double(m) / double(n1) << endl;
	cout << "Среднее число проб:" << double(k1) / double(m) << endl;
	cout << "количество шагов " << k1 << endl;
	int p = k1;

	/////////////////////////////////////ЛАБА 2//////////////////////////////

	cout << "\n Выберите нужный вариант : \n 1- найти элемент \n 2-удалить элемент \n 3 - добавить новый элемент\n 4 - Заменить элемент \n 0-выход\n";
	int i = 0;
	while (i < 100)
	{
		i++;
		int var;
		cin >> var;
		if (var < 0 || var>4) {
			cout << "ошибка, введите число в диапазоне от 0 до 4" << endl;
		}
		switch (var)
		{
		case 0:
		{
			return 0;
			break;
		}

		///////////////////////////////НАЙТИ ЭЛЕМЕНТ/////////////////////////////////////////

		case 1:
		{
			poisk(mas);
			
			break;
		}

		//////////////////////////УДАЛЕНИЕ ЭЛЕМЕНТА//////////////////////////////


		case 2:
		{
			int k1 = 0;
			cout << "введите элемент который хотите удалить" << endl;
			int nomerelem;
			int i = 0;
			int elem;
			int nampr = 1;
			cin >> elem;


			nomerelem = ((elem * elem) % 10000 / 100);
			f = poisk2(hash, elem, nomerelem);
			if (f) {
				if (elem == hash[nomerelem]) {
					hash[nomerelem] = -1;
					vivod(hash, 100);
				}
				else {
					while (elem != hash[nomerelem]) {
						nomerelem = (nomerelem + 1) % 100;
					}
					hash[nomerelem] = -1;
					vivod(hash, 100);
				}
			}
			
			break;
		}

		//////////////////////////ДОБАВЛЕНИЕ НОВОГО ЭЛЕМЕНТА//////////////////////////////

		case 3:
		{
			int k1 = 0;
			cout << "введите элемент который хотите ввести" << endl;
			int nomerelem;
			int i = 0;
			int elem;
			int nampr = 1;
			cin >> elem;
			int nomerpr = 1;

			nomerelem = ((elem * elem) % 10000 / 100);
			f = poisk2(hash, elem, nomerelem);
			if (f == false) {
				if (hash[nomerelem] == 0 || hash[nomerelem] == -1) {
					hash[nomerelem] = elem;
					vivod(hash, 100);
				}
				else {
					while (hash[nomerelem]) {
						nomerelem = (nomerelem + 1) % 100;
						if (hash[nomerelem] == -1)break;
					}
					hash[nomerelem] = elem;
					vivod(hash, 100);
				}
			}
		
		break;
		}

		//////////////////////////ЗАМЕНА ЭЛЕМЕНТА//////////////////////////////

		case 4:
		{
			int nomerybr;
			int nomervsv;
			int i = 0;
			int nomerpr = 1;
			int nampr = 1;
			
			int elem;
			
			cout << "введите число, которое хотите заменить" << endl;
			cin >> elem;

			nomerelem = ((elem * elem) % 10000 / 100);
			f = poisk2(hash, elem, nomerelem);
			if (f) {
				if (elem == hash[nomerelem]) {
					hash[nomerelem] = -1;
					vivod(hash, 100);
				}
				else {
					while (elem != hash[nomerelem]) {
						nomerelem = (nomerelem + 1) % 100;
					}
					hash[nomerelem] = -1;
					vivod(hash, 100);
				}
			}
			cout << "введите число на которое хотите заменть" << endl;
			cin >> elem;
			nomerelem = ((elem * elem) % 10000 / 100);
			f = poisk2(hash, elem, nomerelem);
			if (f == false) {
				if (hash[nomerelem] == 0 || hash[nomerelem] == -1) {
					hash[nomerelem] = elem;
					vivod(hash, 100);
				}
				else {
					while (hash[nomerelem]) {
						nomerelem = (nomerelem + 1) % 100;
						if (hash[nomerelem] == -1)break;
					}
					hash[nomerelem] = elem;
					vivod(hash, 100);
				}
			}


			break;
		}
		}
  }
 return 0;
}

	
