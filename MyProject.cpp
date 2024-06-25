#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
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

struct CarSalesInfo {
	string carName;
	int salesCount;

	CarSalesInfo(string name) : carName(name), salesCount(0){}
};

vector <Employee> employees;
vector <Car> cars;
vector <Sale> sales;

int Menu() {
	int userChoice;
	cout << "1. Додати співробітника\n";
	cout << "2. Видалити співробітника\n";
	cout << "3. Додати автомобіль\n";
	cout << "4. Видалити автомобіль\n";
	cout << "5. Додати продаж\n";
	cout << "6. Видалити продаж\n";
	cout << "7. Звіти\n";
	cout << "8. Вихід\n";
	cout << "\nВведіть ваш вибір: ";
	cin >> userChoice;
	return userChoice;
};

void addEmployee() {
	Employee emp;
	cin.ignore();
	cout << "Введіть повне ім'я співробітника: ";
	getline(cin, emp.workerFullName);
	cout << "Введіть посаду: ";
	getline(cin, emp.workerPost);
	cout << "Введіть контактний номер: ";
	getline(cin, emp.workerPhonenumber);
	cout << "Введіть email: ";
	getline(cin, emp.workerEmail);

	employees.push_back(emp);
	cout << "Співробітник додан!\n\n";
}

void deleteEmployee(int index) {
	if (index >= 0 && index < employees.size()) {
		employees.erase(employees.begin() + index);
		cout << "Співробітник видалений!\n\n";
	}
	else {
		cout << "Некоректний індекс, введіть ще раз!\n\n";
	}
};

void addCar() {
	Car car;
	cin.ignore();
	cout << "Введіть виробника: ";
	getline(cin, car.manufacturer);
	cout << "Введіть рік випуску: ";
	cin >> car.carYear;
	cin.ignore();
	cout << "Введіть модель: ";
	getline(cin, car.carModel);
	cout << "Введіть вартість: ";
	cin >> car.costPrice;
	cout << "Введіть потенційну ціну продажу: ";
	cin >> car.potentialSalePrice;

	cars.push_back(car);
	cout << "Автомобіль додано!\n\n";

};

void deleteCar(int index) {
	if (index >= 0 && index < cars.size()) {
		cars.erase(cars.begin() + index);
		cout << "Автомобіль видалено!\n\n";
	}
	else {
		cout << "Некоректний індекс, введіть ще раз!\n\n";
	}
};

void addSale() {
	if (employees.empty() || cars.empty()) {
		cout << "Немає доступних працівників або автомобілів, спочатку додайте іх\n\n";
		return;
	}

	Sale sale;
	cout << "Оберіть співробітника за індексом:\n";
	for (int i = 0; i < employees.size(); i++) {
		cout << i << ") " << employees[i].workerFullName << endl;
	}
	int empIndex;
	cout << "Введіть індекс працівника: ";
	cin >> empIndex;
	if (empIndex < 0 || empIndex >= employees.size()) {
		cout << "Некоректний індекс працівника\n\n";
	}
	sale.employee = employees[empIndex];

	cout << "Оберіть автомобіль за індексом\n";
	for (int i = 0; i < cars.size(); i++) {
		cout << i << ") " << cars[i].manufacturer << " " << cars[i].carModel << endl;
	}
	int carIndex;
	cout << "Введіть індекс автомобіля: ";
	cin >> carIndex;
	if (carIndex < 0 || carIndex > cars.size()) {
		cout << "Некоректний індекс автомобіля\n\n";
	}
	sale.car = cars[carIndex];
	cin.ignore();
	cout << "Введіть дату продажу: ";
	getline(cin, sale.saleDate);
	cout << "Введіть фактичну ціну продажу: ";
	cin >> sale.actualSalePrice;

	sales.push_back(sale);
	cout << "Продаж додано!\n\n";

	cars.erase(cars.begin() + carIndex);
	cout << "Автомобіль видалено оскільки його продали\n\n";
};

void deleteSale(int index) {
	if (index >= 0 && index < sales.size()) {
		sales.erase(sales.begin() + index);
		cout << "Продаж видалено!\n\n";
	}
	else {
		cout << "Некоректний індекс, введіть ще раз!\n\n";	
	}
}

void employeeReport() {
	for (const auto& emp : employees) {
		cout << "Повна інформація про співробітника:\n";
		cout << "Ім'я: " << emp.workerFullName << endl;
		cout << "Посада: " << emp.workerPost << endl;
		cout << "Контактний номер: " << emp.workerPhonenumber << endl;
		cout << "Email: " << emp.workerEmail << endl;
	}
}

void carReport() {
	for (const auto& car : cars) {
		cout << "Повна інформація про автомобіль:\n";
		cout << "Виробник: " << car.manufacturer << endl;
		cout << "Модель:" << car.carModel << endl;
		cout << "Рік випуску: " << car.carYear << endl;
		cout << "Вартість: " << car.costPrice << endl;
		cout << "Потенційна ціна продажу: " << car.potentialSalePrice << endl << endl;
	}
}

void saleReport() {
	for (const auto& sale : sales) {
		cout << "Повна інформація про продаж:\n";
		cout << "Продавець: " << sale.employee.workerFullName;
		cout << "Покупець: " << sale.car.manufacturer << " " << sale.car.carModel << endl;
		cout << "Дата продажу: " << sale.saleDate << endl;
		cout << "Фактична ціна продажу: " << sale.actualSalePrice << endl << endl;
	}
}

void salesbyDate() {
	string date;
	cout << "Введіть дату (формат: DD.MM.YYYY): ";
	cin.ignore();
	getline(cin, date);

	bool found = false;
	for (const auto& sale : sales) {
		if (sale.saleDate == date) {
			cout << "Продаж на : " << date << ":\n";
			cout << "Продавець: " << sale.employee.workerFullName << endl;
			cout << "Покупець: " << sale.car.manufacturer << " " << sale.car.carModel << endl;
			cout << "Фактична ціна продажу: " << sale.actualSalePrice << endl;
			found = true;
		}
	}
}

void EmployeesSales(int empIndex) {
	if (empIndex < 0 || empIndex >= employees.size()) {
		cout << "Некоректний індекс співробітника\n\n";
		return;
	}

	string empName = employees[empIndex].workerFullName;
	bool found = false;
	for (const auto& sale : sales) {
		if (sale.employee.workerFullName == empName) {
			cout << "Продажі співробітника " << empName << ":\n";
			cout << "Продавець: " << sale.employee.workerFullName << endl;
			cout << "Автомобіль: " << sale.car.manufacturer << " " << sale.car.carModel << endl;
			cout << "Дата продажу: " << sale.saleDate << endl;
			cout << "Фактична ціна продажу: " << sale.actualSalePrice << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Продажі спіробітника " << empName << " не знайдено\n\n";
	}
}

void mostSaleCar(string startDate, string endDate) {
	map<string, int> soldCars;
	for (const auto& sale : sales) {
		if (sale.saleDate >= startDate && sale.saleDate <= endDate) {
			string carName = sale.car.manufacturer + " " + sale.car.carModel;
			soldCars[carName]++;
		}
	}
	string mostPopularCar;
	int maxSales = 0;
	for (const auto& pair : soldCars) {
		if (pair.second > maxSales) {
			maxSales = pair.second;
			mostPopularCar = pair.first;
		}
	}
	cout << "Найпопулярніший автомобіль за період з " << startDate << " по " << endDate << ": " << mostPopularCar << endl << endl;
}


void mostSuccessfulEmployee(string startDate, string endDate) {
	map<string, double>  employeeSales;
	for (const auto& sale : sales) {
		if (sale.saleDate >= startDate && sale.saleDate <= endDate){
			employeeSales[sale.employee.workerFullName] += sale.actualSalePrice;
		}
	}
	string mostSuccessfulEmp;
	double maxSales = 0.0;
	for (const auto& pair : employeeSales) {
		if (pair.second > maxSales) {
			maxSales = pair.second;
			mostSuccessfulEmp = pair.first;
		}
	}
	cout << "Найуспішніший співробітник за період з " << startDate << " по " << endDate << ": " << mostSuccessfulEmp << endl;
	cout << "Сумарна величина продажів: " << maxSales << endl << endl;
}

void totalProfit(string startDate, string endDate){
	double total = 0.0;
	for (const auto& sale : sales) {
		if (sale.saleDate >= startDate && sale.saleDate <= endDate) {
			total += (sale.actualSalePrice - sale.car.costPrice);
		}
	}
	cout << "Сумарний прибуток за період з " << startDate << " по " << endDate << ": " << total << endl << endl;
}

void saveInfo() {
	ofstream outFile("user.txt");
	if (outFile.is_open()) {
		outFile << employees.size() << endl;
		for (const auto& emp : employees) {
			outFile << emp.workerFullName << endl;
			outFile << emp.workerPost << endl;
			outFile << emp.workerPhonenumber << endl;
			outFile << emp.workerEmail << endl;
		}

		outFile << cars.size() << endl;
		for (const auto& car : cars) {
			outFile << car.manufacturer << endl;
			outFile << car.carYear << endl;
			outFile << car.carModel << endl;
			outFile << car.costPrice << endl;
			outFile << car.potentialSalePrice << endl;
		}

		outFile << sales.size() << endl;
		for (const auto& sale : sales) {
			outFile << sale.employee.workerFullName << endl;
			outFile << sale.employee.workerPost << endl;
			outFile << sale.employee.workerPhonenumber << endl;
			outFile << sale.employee.workerEmail << endl;

			outFile << sale.car.manufacturer << endl;
			outFile << sale.car.carYear << endl;
			outFile << sale.car.carModel << endl;
			outFile << sale.car.costPrice << endl;
			outFile << sale.car.potentialSalePrice << endl;

			outFile << sale.saleDate << endl;
			outFile << sale.actualSalePrice << endl;

			outFile.close();
			cout << "Дані збережено у файл\n\n";
		}
	}
	else {
		cout << "Помилка при відкритті файлу\n\n";
	}
}

void loadInfo() {
	ifstream inFile("user.txt");
	if (inFile.is_open()) {
		employees.clear();
		cars.clear();
		sales.clear();

		int numEmployees;
		inFile >> numEmployees;
		inFile.ignore();
		for (int i = 0; i < numEmployees; i++) {
			Employee emp;
			getline(inFile, emp.workerFullName);
			getline(inFile, emp.workerPost);
			getline(inFile, emp.workerPhonenumber);
			getline(inFile, emp.workerEmail);
			employees.push_back(emp);
		}

		int numCars;
		inFile >> numCars;
		inFile.ignore();
		for (int i = 0; i < numCars; i++) {
			Car car;
			getline(inFile, car.manufacturer);
			inFile >> car.carYear;
			inFile.ignore();
			getline(inFile, car.carModel);
			inFile >> car.costPrice;
			inFile >> car.potentialSalePrice;
			inFile.ignore(); 
			cars.push_back(car);
		}
		
		int numSales;
		inFile >> numSales;
		inFile.ignore();
		for (int i = 0; i < numSales; i++) {
			Sale sale;
			getline(inFile, sale.employee.workerFullName);
			getline(inFile, sale.employee.workerPost);
			getline(inFile, sale.employee.workerPhonenumber);
			getline(inFile, sale.employee.workerEmail);
			getline(inFile, sale.car.manufacturer);
			inFile >> sale.car.carYear;
			inFile.ignore();
			getline(inFile, sale.car.carModel);
			inFile >> sale.car.costPrice;
			inFile >> sale.car.potentialSalePrice;
			inFile.ignore();
			getline(inFile, sale.saleDate);
			inFile >> sale.actualSalePrice;
			inFile.ignore();
			sales.push_back(sale);
		}
		inFile.close();
		cout << "Дані збережено у файл\n\n";
	}
	else {
		cout << "Помилка при відкритті файлу\n\n";
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	while ((choice = Menu()) != 8) {
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
			if (!sales.empty()) {
				int index;
				cout << "Введіть індекс продажу: ";
				cin >> index;
				deleteSale(index);
			}
			else {
				cout << "Немає продажів для видалення\n\n";
			}
			break;
		case 7:
			int reportChoice;
			cout << "Оберіть тип звіту.\n";
			cout << "1. Повна інформація про співробітників\n";
			cout << "2. Повна інформація про автомобіль\n";
			cout << "3. Повна інформація про продаж\n";
			cout << "4. Усі продажі за певну дату\n";
			cout << "5. Всі продажі конкретного співробітника \n";
			cout << "6. Назва найпопулярнішого автомобіля, який продали за вказаний період час \n";
			cout << "7. Інформація про найуспішнішого співробітника за вказаний період часу \n";
			cout << "8. Сумарний прибуток за вказаний період часу \n";
			cout << "9. Зберегти дані у файл\n";
			cout << "10. Завантажити дані з файлу\n";
			cout << "11. Вихід\n";
			cout << "Ваш вибір: ";
			cin >> reportChoice;

			switch (reportChoice) {
			case 1:
				employeeReport();
				break;
			case 2:
				carReport();
				break;
			case 3:
				saleReport();
				break;
			case 4:
				salesbyDate();
				break;
			case 5:
				int empIndex;
				cout << "Введіть індекс співробітника: ";
				cin >> empIndex;
				EmployeesSales(empIndex);
				break;
			case 6: {
				string startDate, endDate;
				cout << "Введіть початкову дату: ";
				cin.ignore();
				getline(cin, startDate);
				cout << "Введіть кінцеву дату: ";
				getline(cin, endDate);
				mostSaleCar(startDate, endDate);
				break;
			}
			case 7: {
				string empStartDate, empEndDate;
				cout << "Введіть початкову дату: ";
				cin.ignore();
				getline(cin, empStartDate);
				cout << "Введіть кінцеву дату: ";
				getline(cin, empEndDate);
				mostSuccessfulEmployee(empStartDate, empEndDate);
				break;
			}
			case 8: {
				string profitStartDate, profitEndDate;
				cout << "Введіть початкову дату: ";
				cin.ignore();
				getline(cin, profitStartDate);
				cout << "Введіть кінцеву дату: ";
				getline(cin, profitEndDate);
				totalProfit(profitStartDate, profitEndDate);
				break;
			}
			case 9:
				saveInfo();
				break;
			case 10:
				loadInfo();
				break;
			case 11:
				break;
			default:
				cout << "Некоректний вибір\n\n";
			}
		case 8:
			break;
		default:
			cout << "Некоректний вибір, спробуйте ще раз\n";
		}
	}
	cout << "Завершення програми\n";
	return 0;
}
