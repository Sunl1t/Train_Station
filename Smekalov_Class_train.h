#pragma once
class Smekalov_Class_train
{
public:
	Smekalov_Class_train();
	~Smekalov_Class_train();
};
/**
@file      Smekalov_Class_Person.h
@brief     ������������ ���� ������ �����
@author    �������� �.�.
@date      27-11-2023
@version   1.0.0
\par ���������� ������:
@ref Traim
\par �������� �����
@ref Train
*/

/// ����� �������� ������
/// �������� ���������� � ���������� ������� � ������ ������ 
class Train
{
private:
	std::string destination;     ///< ����� ����������
	int trainNumber;             ///< ����� ������
	std::string departureTime;   ///< ����� �����������
	int totalSeats;              ///< ����� ����� ����
	int coupeSeats;              ///< ����� �������� ����
	int platzSeats;              ///< ����� ����������� ����

public:
/**
@brief ����������� � ����������� ����� ������
������ ��� ���� � �������������� ����
@param dest ����� ����������
@param num ����� ������
@param depTime ����� �����������
@param total ����� ����
@param coupe �������� ����
@param platz ����������� ����
*/
	Train(std::string dest, int num, std::string depTime, int total, int coupe, int platz) {
		destination = dest;
		trainNumber = num;
		departureTime = depTime;
		totalSeats = total;
		coupeSeats = coupe;
		platzSeats = platz;
	}
	//������� ��� ������������� �������� ������ ���������� � ����������
	std::string getDestination() {
		return destination;
	}
	//������� ��� ������������� �������� ������ ������ � ����������
	int getTrainNumber() {
		return trainNumber;
	}
	//������� ��� ������������� �������� ������� ����������� ������ � ����������
	std::string getDepartureTime() {
		return departureTime;
	}
	//������� ��� ������������� �������� ���� ���� � ������ � ����������
	int getTotalSeats() {
		return totalSeats;
	}
	//������� ��� ������������� �������� ���������� �������� ���� � ����������
	int getCoupeSeats() {
		return coupeSeats;
	}
	//������� ��� ������������� �������� ���������� ����������� ���� � ����������
	int getPlatzSeats() {
		return platzSeats;
	}
};
/**
@brief ����� ��� ������ ���������� �������

������������ ����� ������� ��� ������ � ������� ������ �������: 
������ �������, �������������� ������;
������ ������� ����� ������������ �������;
������ ������� �� ���������� �������.
������������ ����� �������� 
*/
class TrainSchedule {
private:
	std::vector<Train> trains;

public:
/**
������� ���������� ������ ������
@param train �������� ������
*/
	void addTrain(Train train) {
		trains.push_back(train);
	}
/**
������� ������ � ������� ���������� � ������� � ���������� �����
@param dest ����� ����������
@return ���������� �� ����������� ������
*/
	void showTrainsToDestination(std::string dest) {
		std::cout << "������ �" << dest << ":" << std::endl;
		for (Train train : trains) {
			if (train.getDestination() == dest) {
				std:: << "����� ������" << train.getTrainNumber() << std::endl;
				std:: << "����� �����������" << train.getDepartureTime() << std::endl;
				std:: << "����� ����" << train.getTotalSeats() << std::endl;
				std:: << "�������� ����" << train.getCoupeSeats() << std::endl;
				std:: << "����������� ����" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
/**
������� ������ � ������� ���������� � ������� � ���������� ����� ����� ������������ �������
@param dest ����� ����������
@param time ����� 
@return ���������� �� ����������� ������
*/
	void showTrainsToDestinationAfterTime(std::string dest, std::string time) {
		std::cout << "������ �" << dest << " ������������ ����� " << time << ":" << std::endl;
		for (Train train : trains)
		{
			if (train.getDestination() == dest && train.getDepartureTime() > time) {
				std:: << "����� ������" << train.getTrainNumber() << std::endl;
				std:: << "����� �����������" << train.getDepartureTime() << std::endl;
				std:: << "����� ����" << train.getTotalSeats() << std::endl;
				std:: << "�������� ����" << train.getCoupeSeats() << std::endl;
				std:: << "����������� ����" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
/**
������� ������ � ������� ���������� � ��������� ������ � ���������� �����
@param dest ����� ����������
@return ���������� �� ����������� ������
*/
	void showTrainsWithAvailableSeats(std::string dest) {
		std::cout << "������ �" << sets << "�� ������� ��������� ����:" << std::endl;
		for (Train train : trains)
		{
			if (train.getDestination() == dest && train.getDepartureTime() > 0) {
				std:: << "����� ������" << train.getTrainNumber() << std::endl;
				std:: << "����� �����������" << train.getDepartureTime() << std::endl;
				std:: << "����� ����" << train.getTotalSeats() << std::endl;
				std:: << "�������� ����" << train.getCoupeSeats() << std::endl;
				std:: << "����������� ����" << train.getPlatzSeats() << std::endl;
				std:: << std::endl;
			}
		}
	}
};
/**
������ ������������� ������
@code
int main() {
	TrainSchedule schedule;

	Train train1("������", 1, "08:00", 100, 20, 80);
	Train train2("�����-���������", 2, "12:30", 150, 30, 120);
	Train train3("������", 3, "10:45", 120, 25, 95);

	schedule.addTrain(train1);
	schedule.addTrain(train2);
	schedule.addTrain(train3);

	schedule.showTrainsToDestination("������");
	schedule.showTrainsToDestinationAfterTime("�����-���������", "10:00");
	schedule.showTrainsWithAvailableSeats("������");

	return 0;
}
@endcode
*/




