#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


struct Employee {
	string workerFullName;
	string workerPost;
	string workerPhonenumber;
	string workerEmail;
};

struct Car {
	string manufacturer;
	int carYear;
	string carModel;
	double costPrice;
	double potentialSalePrice;
};

struct Sale {
	Employee employee;
	Car car;
	string saleDate;
	double actualSalePrice;
};

vector <Employee> employees;
vector <Car> cars;
vector <Sale> sales;

int Menu() {
	int userChoice;
	cout << "1.\nДодати співробітника\n";
	cout << "2. Видалити співробітника\n";
	cout << "3. Додати автомобіль\n";
	cout << "4. Видалити автомобіль\n";
	cout << "5. Додати продаж\n";
	cout << "6. Вихід\n";
	cout << "\nВведіть ваш вибір: ";
	cin >> userChoice;
	return userChoice;
};

void addEmployee() {
	Employee emp;
	cout << "\n    Введіть повне ім'я співробітника: ";
	getline(cin, emp.workerFullName);
	cout << "\nВведіть посаду: ";
	getline(cin, emp.workerPost);
	cout << "\nВведіть контактний номер: ";
	getline(cin, emp.workerPhonenumber);
	cout << "\nВведіть email: ";
	getline(cin, emp.workerEmail);

	employees.push_back(emp);
	cout << "Співробітник додан!\n";
}

void deleteEmployee(int index) {
	if (index >= 0 && index < employees.size()) {
		employees.erase(employees.begin() + index);
		cout << "Співробітник видалений!";
	}
	else {
		cout << "Некоректний індекс, введіть ще раз!\n";
	}
};

void addCar() {
	Car car;
	cout << "Введіть виробника: ";
	getline(cin, car.manufacturer);
	cout << "Введіть рік випуску: ";
	cin >> car.carYear;
	cout << "Введіть модель: ";
	getline(cin, car.carModel);
	cout << "Введіть вартість: ";
	cin >> car.costPrice;
	cout << "Введіть потенційну ціну продажу: ";
	cin >> car.potentialSalePrice;

	cars.push_back(car);
	cout << "Автомобіль додано!\n";

};

void deleteCar(int index) {
	if (index >= 0 && index < cars.size()) {
		cars.erase(cars.begin() + index);
		cout << "Автомобіль видалено!";
	}
	else {
		cout << "Некоректний індекс, введіть ще раз!";
	}
};

void addSale() {
	if (employees.empty() || cars.empty()) {
		cout << "Немає доступних працівників або автомобілів, спочатку додайте іх\n";
	}

	Sale sale;
	cout << "Оберіть співробітника за індексом:\n";
	for (int i = 0; i < employees.size(); i++) {
		cout << i << ": " << employees[i].workerFullName << endl;
	}
	int empIndex;
	cout << "Введіть індекс працівника";
	cin >> empIndex;
	if (empIndex < 0 || empIndex >= employees.size()) {
		cout << "Некоректний індекс працівника\n";
	}
	sale.employee = employees[empIndex];

	cout << "Оберіть автомобіль за індексом\n";
	for (int i = 0; i < cars.size(); i++) {
		cout << i << ": " << cars[i].manufacturer << " " << cars[i].carModel << endl;
	}
	int carIndex;
	cout << "Введіть індекс автомобіля: ";
	cin >> carIndex;
	if (carIndex < 0 || carIndex > cars.size()) {
		cout << "Некоректний індекс автомобіля\n";
	}
	sale.car = cars[carIndex];
	
	cout << "Введіть дату продажу: ";
	getline(cin, sale.saleDate);
	cout << "Введіть фактичну ціну продажу";
	cin >> sale.actualSalePrice;

	sales.push_back(sale);
	cout << "Продаж додано!\n";
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	while ((choice = Menu()) != 6) {
		switch (choice) {
			case 1: 
				addEmployee();
				break;
			case 2:
				if (!employees.empty()) {
					int index;
					cout << "Введіть індекс співробітника для видалення: ";
					cin >> index;
					deleteEmployee(index);
				}
				else {
					cout << "Немає співробітника для видалення\n";
				}
				break;
			case 3:
				addCar();
				break;
			case 4:
				if (!cars.empty()) {
					int index;
					cout << "Введіть індекс автомобіля для видалення: ";
					cin >> index;
					deleteCar(index);
				}
				else {
					cout << "Немає автомобілів для видалення\n";
				}
				break;
			case 5:
				addSale();
				break;
			case 6:
				break;
			default:
				cout << "Некоректний вибір, спробуйте ще раз\n";
		}
	}
	cout << "Завершення програми\n";



	return 0;
}