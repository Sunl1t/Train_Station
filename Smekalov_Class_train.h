#pragma once
class Smekalov_Class_train
{
public:
	Smekalov_Class_train();
	~Smekalov_Class_train();
};
/**
@file      Smekalov_Class_Person.h
@brief     ЗАголовочный файл класса Поезд
@author    Смекалов С.В.
@date      27-11-2023
@version   1.0.0
\par Использует классы:
@ref Traim
\par Содержит класс
@ref Train
*/

/// Класс описания поезда
/// Содержит информацию о расписании поездов и методы работы 
class Train
{
private:
	std::string destination;     ///< Пункт назначения
	int trainNumber;             ///< Номер поезда
	std::string departureTime;   ///< Время отправления
	int totalSeats;              ///< Число общих мест
	int coupeSeats;              ///< Число купейных мест
	int platzSeats;              ///< Число плацкартных мест

public:
/**
@brief Конструктор с заполнением полей класса
Создаёт сам рейс и инициализиреет поля
@param dest место назначения
@param num Номер поезда
@param depTime Время отправления
@param total Всего мест
@param coupe Купейных мест
@param platz Плацкартных мест
*/
	Train(std::string dest, int num, std::string depTime, int total, int coupe, int platz) {
		destination = dest;
		trainNumber = num;
		departureTime = depTime;
		totalSeats = total;
		coupeSeats = coupe;
		platzSeats = platz;
	}
	//функция для использования значения пункта назначения в расписании
	std::string getDestination() {
		return destination;
	}
	//функция для использования значения номера поезда в расписании
	int getTrainNumber() {
		return trainNumber;
	}
	//функция для использования значения вмерени отправления поезда в расписании
	std::string getDepartureTime() {
		return departureTime;
	}
	//функция для использования значения всех мест в поезде в расписании
	int getTotalSeats() {
		return totalSeats;
	}
	//функция для использования значения количества купейных мест в расписании
	int getCoupeSeats() {
		return coupeSeats;
	}
	//функция для использования значения количества плацкартных мест в расписании
	int getPlatzSeats() {
		return platzSeats;
	}
};
/**
@brief Класс для вывода расписания поездов

Осуществляет вызов функций для вывода в консоль разных списков: 
списка поездов, отправляющихся сейчас;
списка поездов после определённого времени;
списка поездов со свободными местами.
Осуществляет вызов функцкии 
*/
class TrainSchedule {
private:
	std::vector<Train> trains;

public:
/**
Функция добавления нового поезда
@param train название поезда
*/
	void addTrain(Train train) {
		trains.push_back(train);
	}
/**
Функция вывода в консоль информации о поездах в конкретный город
@param dest место назначения
@return информация об отправлении поезда
*/
	void showTrainsToDestination(std::string dest) {
		std::cout << "Поезда в" << dest << ":" << std::endl;
		for (Train train : trains) {
			if (train.getDestination() == dest) {
				std:: << "Номер поезда" << train.getTrainNumber() << std::endl;
				std:: << "Время отправления" << train.getDepartureTime() << std::endl;
				std:: << "Всего мест" << train.getTotalSeats() << std::endl;
				std:: << "Купейных мест" << train.getCoupeSeats() << std::endl;
				std:: << "Плацкартных мест" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
/**
Функция вывода в консоль информации о поездах в конкретный город после определённого времени
@param dest место назначения
@param time время 
@return информация об отправлении поезда
*/
	void showTrainsToDestinationAfterTime(std::string dest, std::string time) {
		std::cout << "Поезда в" << dest << " отправляются после " << time << ":" << std::endl;
		for (Train train : trains)
		{
			if (train.getDestination() == dest && train.getDepartureTime() > time) {
				std:: << "Номер поезда" << train.getTrainNumber() << std::endl;
				std:: << "Время отправления" << train.getDepartureTime() << std::endl;
				std:: << "Всего мест" << train.getTotalSeats() << std::endl;
				std:: << "Купейных мест" << train.getCoupeSeats() << std::endl;
				std:: << "Плацкартных мест" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
/**
Функция вывода в консоль информации о свободных местах в конкретный город
@param dest место назначения
@return информация об отправлении поезда
*/
	void showTrainsWithAvailableSeats(std::string dest) {
		std::cout << "Поезда в" << sets << "со списком свободных мест:" << std::endl;
		for (Train train : trains)
		{
			if (train.getDestination() == dest && train.getDepartureTime() > 0) {
				std:: << "Номер поезда" << train.getTrainNumber() << std::endl;
				std:: << "Время отправления" << train.getDepartureTime() << std::endl;
				std:: << "Всего мест" << train.getTotalSeats() << std::endl;
				std:: << "Купейных мест" << train.getCoupeSeats() << std::endl;
				std:: << "Плацкартных мест" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
};
/**
Пример использования класса
@code
int main() {
	TrainSchedule schedule;

	Train train1("Москва", 1, "08:00", 100, 20, 80);
	Train train2("Санкт-Петербург", 2, "12:30", 150, 30, 120);
	Train train3("Казань", 3, "10:45", 120, 25, 95);

	schedule.addTrain(train1);
	schedule.addTrain(train2);
	schedule.addTrain(train3);

	schedule.showTrainsToDestination("Москва");
	schedule.showTrainsToDestinationAfterTime("Санкт-Петербург", "10:00");
	schedule.showTrainsWithAvailableSeats("Казань");

	return 0;
}
@endcode
*/




