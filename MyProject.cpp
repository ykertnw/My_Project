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
	cout << "1.\n������ �����������\n";
	cout << "2. �������� �����������\n";
	cout << "3. ������ ���������\n";
	cout << "4. �������� ���������\n";
	cout << "5. ������ ������\n";
	cout << "6. �����\n";
	cout << "\n������ ��� ����: ";
	cin >> userChoice;
	return userChoice;
};

void addEmployee() {
	Employee emp;
	cout << "\n    ������ ����� ��'� �����������: ";
	getline(cin, emp.workerFullName);
	cout << "\n������ ������: ";
	getline(cin, emp.workerPost);
	cout << "\n������ ���������� �����: ";
	getline(cin, emp.workerPhonenumber);
	cout << "\n������ email: ";
	getline(cin, emp.workerEmail);

	employees.push_back(emp);
	cout << "���������� �����!\n";
}

void deleteEmployee(int index) {
	if (index >= 0 && index < employees.size()) {
		employees.erase(employees.begin() + index);
		cout << "���������� ���������!";
	}
	else {
		cout << "����������� ������, ������ �� ���!\n";
	}
};

void addCar() {
	Car car;
	cout << "������ ���������: ";
	getline(cin, car.manufacturer);
	cout << "������ �� �������: ";
	cin >> car.carYear;
	cout << "������ ������: ";
	getline(cin, car.carModel);
	cout << "������ �������: ";
	cin >> car.costPrice;
	cout << "������ ���������� ���� �������: ";
	cin >> car.potentialSalePrice;

	cars.push_back(car);
	cout << "��������� ������!\n";

};

void deleteCar(int index) {
	if (index >= 0 && index < cars.size()) {
		cars.erase(cars.begin() + index);
		cout << "��������� ��������!";
	}
	else {
		cout << "����������� ������, ������ �� ���!";
	}
};

void addSale() {
	if (employees.empty() || cars.empty()) {
		cout << "���� ��������� ���������� ��� ���������, �������� ������� ��\n";
	}

	Sale sale;
	cout << "������ ����������� �� ��������:\n";
	for (int i = 0; i < employees.size(); i++) {
		cout << i << ": " << employees[i].workerFullName << endl;
	}
	int empIndex;
	cout << "������ ������ ����������";
	cin >> empIndex;
	if (empIndex < 0 || empIndex >= employees.size()) {
		cout << "����������� ������ ����������\n";
	}
	sale.employee = employees[empIndex];

	cout << "������ ��������� �� ��������\n";
	for (int i = 0; i < cars.size(); i++) {
		cout << i << ": " << cars[i].manufacturer << " " << cars[i].carModel << endl;
	}
	int carIndex;
	cout << "������ ������ ���������: ";
	cin >> carIndex;
	if (carIndex < 0 || carIndex > cars.size()) {
		cout << "����������� ������ ���������\n";
	}
	sale.car = cars[carIndex];
	
	cout << "������ ���� �������: ";
	getline(cin, sale.saleDate);
	cout << "������ �������� ���� �������";
	cin >> sale.actualSalePrice;

	sales.push_back(sale);
	cout << "������ ������!\n";
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
					cout << "������ ������ ����������� ��� ���������: ";
					cin >> index;
					deleteEmployee(index);
				}
				else {
					cout << "���� ����������� ��� ���������\n";
				}
				break;
			case 3:
				addCar();
				break;
			case 4:
				if (!cars.empty()) {
					int index;
					cout << "������ ������ ��������� ��� ���������: ";
					cin >> index;
					deleteCar(index);
				}
				else {
					cout << "���� ��������� ��� ���������\n";
				}
				break;
			case 5:
				addSale();
				break;
			case 6:
				break;
			default:
				cout << "����������� ����, ��������� �� ���\n";
		}
	}
	cout << "���������� ��������\n";



	return 0;
}