/*33.Построить хеш - таблицу, содержащую последовательность из m = 51 элементов размерности n = 3.
Элементы генерируются с помощью датчика случайных чисел.
Хеш - функция - средняя часть квадрата ключа.*/

#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

int main()
{


	setlocale(LC_ALL, "Russian");
	int f = 0;
	int tmp = 0;
	int k = 0;
	int n1 = 100; //Размер хэш-таблицы
	int adress; //Хэш-адрес
	int k1 = 0; //Общее число проб
	int hash[100] = { 0 }; //Хэш-таблица
	int np = 1; //Номер пробы

	long int mas[100]; //Массив генерируемых элементов

	srand(time(0));

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

	for (int i = 0; i < m; i++)
	{
		cout << "" << "" << i << "." << "" << "" << mas[i] << "\t" << " ";
	}

	cout << endl;


	cout << "Хэш-таблица: " << endl;

	for (int ht = 0; ht < m; ht++)
	{

		adress = ((((mas[ht] * mas[ht])) % 10000 / 100)); //метод середины квадрата 

		k1++; //Общее число проб
		int adress0 = adress;

		if (hash[adress] == 0) //Если есть свободная ячейка
		{
			hash[adress] = mas[ht];
		}
		else
		{
			while (hash[adress] != NULL)
			{
				adress = (adress0 + np) % n1;
				np++;
				k1++;
			}
			hash[adress] = mas[ht];

		}
		np = 1;

	}
	for (int ht = 0; ht < n1; ht++) {
		cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

	}
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
				cout << "введите элемент индекс которого хотите найти" << endl;
				int nomerelem;
				int i = 0;
				int elem;
				int nampr = 1;

				cin >> elem;


				nomerelem = ((elem * elem) % 10000 / 100);

				if (elem == hash[nomerelem])
				{
					cout << nomerelem << endl;
				}

				else {

					for (int v = 0; v < 100; v++) {
						if (elem != hash[nomerelem])
						{
							int nomerelem0 = ((elem * elem) % 10000 / 100);
							nomerelem = (nomerelem0 + nampr) % n1;
							nampr++;


							if (elem == hash[nomerelem]) {
								cout << nomerelem << "  была разрешена коллизия   " << endl;

							}
						}
					}

					if (elem != hash[nomerelem]) {
						cout << "такого элемента нет" << endl;
					}
				}

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

				if (elem == hash[nomerelem])
				{

					elem = -1;

					cout << "элемент был удален из ячейки " << nomerelem << endl;
					for (int ht=0; ht < n1; ht++) {
						if (hash[ht] == -1) {
							m--;
						}
						if (hash[nomerelem] = elem)
						{
							cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

						}

					}

					cout << endl << "Коэффициент заполнения таблицы: " << double(m) / double(n1) << endl;
					cout << "Среднее число проб:" << double(k1 + p) / double(m) << endl;
					cout << "количество шагов  " << k1 + p << endl;
					cout << "количество элементов  " << m << endl;
				}
				else {

					for (int v = 0; v <= nomerelem; v++) {

						if (elem != hash[nomerelem])
						{
							k1++;
							int nomerelem0 = ((elem * elem) % 10000 / 100);
							nomerelem = (nomerelem0 + nampr) % n1;
							nampr++;

							if (elem == hash[nomerelem]) {


								elem = -1;

								cout << "элемент был удален из ячейки " << nomerelem << endl;
								for (int ht = 0; ht < n1; ht++) {
									if (hash[ht] == -1) {
										m--;
									}
									if (hash[nomerelem] = elem)
									{
										cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

									}

								}
								cout << endl << "Коэффициент заполнения таблицы: " << double(m) / double(n1) << endl;
								cout << "Среднее число проб:" << double(k1 + p) / double(m) << endl;
								cout << "количество шагов  " << k1 + p << endl;
							}
						}

					}

					if (elem != hash[nomerelem]) {
						cout << "такого элемента нет" << endl;
					}
				}

				break;
		}



		//////////////////////////ДОБАВЛЕНИЕ НОВОГО ЭЛЕМЕНТА//////////////////////////////




		case 3:
		{
			int k1 = 0;
			
				int nomerelem;
				int i = 0;

				int elem;
				int nomerpr = 1;

				cin >> elem;

				nomerelem = ((elem * elem) % 10000 / 100);

				if (elem == hash[nomerelem])
				{
					cout << "этот элемент уже существует," << "находится в ячейке " << nomerelem << endl;

				}
				else {

					for (int v = 0; v <= nomerelem; v++) {
						if (elem != hash[nomerelem])
						{

							int nomerelem0 = ((elem * elem) % 10000 / 100);
							nomerelem = (nomerelem0 + nomerpr) % n1;
							nomerpr++;
							if (elem == hash[nomerelem]) {
								cout << "этот элемент уже существует," << "находится в ячейке " << nomerelem << endl;
							}
						}
					}

					if (elem != hash[nomerelem])
					{
						nomerelem = ((elem * elem) % 10000 / 100);
						nomerpr = 1;
						for (int c = 0; c <100; c++) {

							if ((hash[nomerelem] == NULL) || (hash[nomerelem] == -1)) {
								hash[nomerelem] == elem;

							}
							else {
								if ((hash[nomerelem] != NULL) || (hash[nomerelem] == -1))
								{

									k1++;
									int nomerelem0 = ((elem * elem) % 10000 / 100);
									nomerelem = (nomerelem0 + nomerpr) % n1;
									nomerpr++;

								}
							}

						}
						m++;
						cout << "число добавлено в ячейку  " << nomerelem << endl;

						for (int ht = 0; ht < n1; ht++) {
							if (hash[nomerelem] = elem)
							{

								cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

							}

						}
						cout << endl << "Коэффициент заполнения таблицы: " << double(m) / double(n1) << endl;
						cout << "Среднее число проб:" << double(k1 + p) / double(m) << endl;
						cout << "количество шагов  " << k1 + p << endl;
						cout << "количество элементов  " << m << endl;
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
			
			int ybr, vsv;
			cout << "введите число, которое хотите заменить" << endl;
			cin >> ybr;
			int ybr0 = ybr;
			cout << "введите число на которое хотите заменть" << endl;
			cin >> vsv;
			nomervsv = ((vsv * vsv) % 10000 / 100);
			nomerybr = ((ybr * ybr) % 10000 / 100);
			///////удаление в замене////////
			
					
       /* if (nomervsv == nomerybr) {
			 hash[nomervsv] = -1;
		    }*/
			//if (nomervsv != 0 && nomerybr != 0) {
				if (nomervsv == nomerybr) {
					hash[nomervsv] = -1;
				}
			//} 
			
			
				nomerybr = ((ybr * ybr) % 10000 / 100);

				if (ybr == hash[nomerybr])
				{

					ybr = -1;

					cout << "элемент был удален из ячейки " << nomerybr << endl;

				}
				else {

					for (int v = 0; v < 100; v++) {

						if (ybr != hash[nomerybr])
						{
							k1++;
							int nomerybr0 = ((ybr * ybr) % 10000 / 100);
							nomerybr = (nomerybr0 + nampr) % n1;
							nampr++;

							if (ybr == hash[nomerybr]) {

								ybr = -1;

								hash[nomerybr] = ybr;
								cout << "элемент был удален из ячейки " << nomerybr << endl;
								
								
							}
						}
					}
				}
				
			
				////////////добавление элемента в замене /////////////////////
			
				for (int i = 0; i < 1; i++) {
					nomervsv = ((vsv * vsv) % 10000 / 100);

					if (vsv == hash[nomervsv])
					{
						cout << "этот элемент уже существует," << "находится в ячейке  " << nomervsv << endl;
						ybr = ybr0;

					}
					else {
						int nomervsv0 = ((vsv * vsv) % 10000 / 100);
						for (int v = 0; v <= nomervsv0; v++) {
							if (vsv != hash[nomervsv])
							{

								int nomervsv0 = ((vsv * vsv) % 10000 / 100);
								nomervsv = (nomervsv0 + nomerpr) % n1;
								nomerpr++;
								if (vsv == hash[nomervsv]) {
									cout << "этот элемент уже существует," << "находится в ячейке " << nomervsv << endl;
									ybr = ybr0;
								}
							}
						}

						if (vsv != hash[nomervsv])
						{

							nomervsv = ((vsv * vsv) % 10000 / 100);
							nomerpr = 1;
							for (int c = 0; c < n1; c++) {
								if ((hash[nomervsv] == 0) || (hash[nomervsv] == -1)) {

									hash[nomervsv] == vsv;
								}
								else {

									k1++;
									int nomervsv0 = ((vsv * vsv) % 10000 / 100);
									nomervsv = (nomervsv0 + nomerpr) % n1;
									nomerpr++;


								}
							}
							m++;
							hash[nomervsv] = vsv;
							cout << "число добавлено в ячейку  " << nomervsv << endl;
							
						}
					}
					
					for (int ht = 0; ht < n1; ht++) {
						
						
						//if ((hash[nomervsv] = vsv)&& (hash[nomerybr]=ybr))

						{

							cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

						}
					}
				}
			break;
		}
		}
  }
 return 0;
}
	
