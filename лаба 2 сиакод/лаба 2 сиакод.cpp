/*33.Построить хеш - таблицу, содержащую последовательность из m = 51 элементов размерности n = 3.
Элементы генерируются с помощью датчика случайных чисел.
Хеш - функция - средняя часть квадрата ключа.*/

#include <iostream>
#include <time.h>
#include <ctime>
#include <iomanip>// для setw
#include <string>
using namespace std;

int main() {


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
	


	/////////////////////////////////////ЛАБА 2//////////////////////////////
  


	cout << "\n Выберите нужный вариант : \n 1- найти элемент \n 2-удалить элемент \n 3 - добавить новый элемент\n 4 - Заменить элемент \n";
	int i = 0;
	while (i < 100)
	{
		i++;
		int var;
		cin >> var;
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
		
			cout << "если вы хотите ввести элемент вручную- нажмите 1" << endl;
			cout << "если хотите найти рандомный элемент-нажмите 2" << endl;

			int r;
			cin >> r;
			switch (r)
			{
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
							int nomerelem0 = nomerelem;
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
			case 2:
			{
				int randelem;
				randelem = rand() % 599 + 400;

				int nomerelem;
				int i = 0;
				int nampr = 1;


				cout << randelem << endl;

				nomerelem = ((randelem * randelem) % 10000 / 100);

				if (randelem == hash[nomerelem])
				{
					cout << nomerelem << endl;


				}
				else {

					for (int v = 0; v < 100; v++) {
						if (randelem != hash[nomerelem])
						{
							int nomerelem0 = nomerelem;
							nomerelem = (nomerelem0 + nampr) % n1;
							nampr++;
							if (randelem == hash[nomerelem]) {
								cout << nomerelem << "  была разрешена коллизия   " << endl;


							}
						}



					}

					if (randelem != hash[nomerelem]) {
						cout << "такого элемента нет" << endl;
					}
				}

				break;
			}
			}
			break;
		}




		//////////////////////////УДАЛЕНИЕ ЭЛЕМЕНТА//////////////////////////////




		case 2:
		{
			
			cout << "если вы хотите ввести элемент вручную- нажмите 1" << endl;
			cout << "если хотите удалить рандомный элемент-нажмите 2" << endl;
			
			int r;
			cin >> r;
			switch (r)
			{
			case 1:
			{
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
					for (int ht = 0; ht < n1; ht++) {
						
						if (hash[nomerelem] = elem)
						{
							cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";
							
						}
						
					}
					
					
					
					
				}
				else {
					
					for (int v = 0; v < 100-nomerelem; v++) {
						
						if (elem != hash[nomerelem])
						{
							
							int nomerelem0 = ((elem * elem) % 10000 / 100);
							nomerelem = (nomerelem0 + nampr) % n1;
							nampr++;
							
							if (elem == hash[nomerelem]) {


								elem = -1;

								cout << "элемент был удален из ячейки " << nomerelem << endl;
								for (int ht = 0; ht < n1; ht++) {
									if (hash[nomerelem] = elem)
									{
										cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";
										
									}
									
								}
								
							}
						}

						


					}

					if (elem != hash[nomerelem]) {
						cout << "такого элемента нет" << endl;
					}
				}
				
				break;
			}
			case 2:
			{
				int randelem;
				randelem = rand() % 599 + 400;

				int nomerelem;
				int i = 0;
				int nampr = 1;


				cout << randelem << endl;

				nomerelem = ((randelem * randelem) % 10000 / 100);

				if (randelem == hash[nomerelem])
				{
					randelem = -1;
					cout << "элемент был удален из ячейки " << nomerelem << endl;


					for (int ht = 0; ht < n1; ht++) {
						if (hash[nomerelem] = randelem)
						{
							cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

						}

					}


				}
				else {

					for (int v = 0; v < 100-nomerelem; v++) {
						if (randelem != hash[nomerelem])
						{
							int nomerelem0 = nomerelem;
							nomerelem = (nomerelem0 + nampr) % n1;
							nampr++;
							if (randelem == hash[nomerelem]) {
								randelem = -1;
								cout << "элемент был удален из ячейки " << nomerelem << endl;


								for (int ht = 0; ht < n1; ht++) {
									if (hash[nomerelem] = randelem)
									{
										cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

									}

								}
							}
						}



					}

					if (randelem != hash[nomerelem]) {
						cout << "такого элемента нет" << endl;
					}
				}

				break;
			}
			}

			break;
		}



		//////////////////////////ДОБАВЛЕНИЕ НОВОГО ЭЛЕМЕНТА//////////////////////////////




		case 3:
		{
			cout << "если вы хотите ввести элемент вручную- нажмите 1" << endl;
			cout << "если хотите добавить рандомный элемент-нажмите 2" << endl;
			int g;
			cin >> g;
			switch (g)
			{
			case 1:
			{
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

					for (int v = 0; v < 100-nomerelem; v++) {
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
						for (int c = 0; c < n1-nomerelem; c++) {
							
							if ((hash[nomerelem] == NULL)||(hash[nomerelem] == -1)) {
								hash[nomerelem] == elem;

							}
							else {
								if ((hash[nomerelem] != NULL) || (hash[nomerelem] == -1))
								{
									int nomerelem0 = ((elem * elem) % 10000 / 100);
									nomerelem = (nomerelem0 + nomerpr) % n1;
									nomerpr++;

								}
							}

						}
						cout << "число добавлено в ячейку  " << nomerelem << endl;
						for (int ht = 0; ht < n1; ht++) {
							if (hash[nomerelem] = elem)
							{
								
								cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

							}
							


						}
					}
				}
			}
			break;
			case 2:
			{
				int randelem;
				randelem = rand() % 599 + 400;
				int nomerelem;
				int i = 0;

				
				int nomerpr = 1;

				cout << randelem << endl;


				nomerelem = ((randelem * randelem) % 10000 / 100);

				if (randelem == hash[nomerelem])
				{
					cout << "этот элемент уже существует," << "находится в ячейке " << nomerelem << endl;

				}
				else {

					for (int v = 0; v < 100-nomerelem; v++) {
						if (randelem != hash[nomerelem])
						{
							int nomerelem0 = nomerelem;
							nomerelem = (nomerelem0 + nomerpr) % n1;
							nomerpr++;
							if (randelem == hash[nomerelem]) {
								cout << "этот элемент уже существует," << "находится в ячейке " << nomerelem << endl;
							}
						}



					}

					if (randelem != hash[nomerelem])
					{
						nomerelem = ((randelem * randelem) % 10000 / 100);
						nomerpr = 1;
						
						for (int c = 0; c < n1 - nomerelem; c++) {
							
							if ((hash[nomerelem] == NULL) || (hash[nomerelem] == -1)) {
								hash[nomerelem] == randelem;
							}
							else {
								while ((hash[nomerelem] != NULL) || (hash[nomerelem] == -1))
								{
									int nomerelem0 = ((randelem * randelem) % 10000 / 100);
									
									nomerelem = (nomerelem0 + nomerpr) % n1;
									nomerpr++;

								}
								

							}
							

						}
						cout << "число добавлено в ячейку  " << nomerelem << endl;
						for (int ht = 0; ht < n1; ht++) {
							if (hash[nomerelem] = randelem)
							{
								
								cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

							}
							


						}
					}
				}


			}
			}
			break;
		}




		//////////////////////////ЗАМЕНА ЭЛЕМЕНТА//////////////////////////////




		case 4:
		{
			int nampr = 1;
			int ybr, vsv;
			cout << "введите число, которое хотите заменить" << endl;
			cin >> ybr;
			cout << "введите число на которое хотите заменть" << endl;
			cin >> vsv;
			int nomerybr = ((ybr * ybr) % 10000 / 100);

			if (ybr == hash[nomerybr])
			{
				ybr = vsv;

				for (int ht = 0; ht < n1; ht++) {
					if (hash[nomerybr] = vsv)
					{
						cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

					}

				}



			}
			else {

				for (int v = 0; v < 100 - nomerybr; v++) {
					if (ybr != hash[nomerybr])
					{
						int nomerybr0 = ((ybr * ybr) % 10000 / 100);
						nomerybr = (nomerybr0 + nampr) % n1;
						nampr++;
						if (ybr == hash[nomerybr]) {
							ybr = vsv;

							for (int ht = 0; ht < n1; ht++) {
								if (hash[nomerybr] = ybr)
								{
									cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

								}

							}
						}
					}



				}

				if (ybr != hash[nomerybr]) {
					cout << "такого элемента нет" << endl;
				}
			}
			break;
			/*int nampr = 1;
			int ybr, vsv;
			cout << "введите число, которое хотите заменить" << endl;
			cin >> ybr;
			cout << "введите число на которое хотите заменть" << endl;
			cin >> vsv;
			int nomerybr = ((ybr * ybr) % 10000 / 100);

			if (ybr == hash[nomerybr])
			{
				for (int i = 0; i < 100; i++) {
					if (vsv = hash[nomerybr])
					cout << "это число уже существует";
					return 0;
				}
				ybr = vsv;

				for (int ht = 0; ht < n1; ht++) {
					if (hash[nomerybr] = vsv)
					{
						cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

					}

				}



			}
			else {

				for (int v = 0; v < 100; v++) {
					if (ybr != hash[nomerybr])
					{
						
						int nomerybr0 = ((ybr * ybr) % 10000 / 100);
						nomerybr = (nomerybr0 + nampr) % n1;
						nampr++;
						if (ybr == hash[nomerybr]) {
							for (int i = 0; i < 100; i++) {
								if (vsv = hash[nomerybr])
									cout << "это число уже существует";
								return 0;
							}
							ybr = vsv;

							for (int ht = 0; ht < n1; ht++) {
								if (hash[nomerybr] = ybr)
								{
									cout << "" << "" << ht << "." << "" << "" << hash[ht] << "\t" << "	";

								}

							}
						}
					}


				}

				if (ybr != hash[nomerybr]) {
					cout << "такого элемента нет" << endl;
				}
			}
			
			break;*/
		}

		}

	}


	// конец while 
	return 0;
}

