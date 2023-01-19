/**
\file DataBase.h
\brief ������ "���� ������" - �������� ������ � �������������

������������� ������� ������ � ����� ������ �������������:
- ��������� ���� �� �������� ����� � ����
- ��������� ���������� �� ������
- �������� ������������ � ����
*/

#pragma once
#ifndef DATA_BASE_H_SENTRY
#define DATA_BASE_H_SENTRY

#include <string>


namespace database {
	/**
	��������� ���� ���������� ����������
	*/
	void initialize();

	/**
	��������� ���� �� � ���� �������� �����
	\param[in] login �����
	\return ������� ������� ��������� ������ � ����
	*/
	bool isExistLogin(std::string login);

	/**
	��������� ������������� �� ������ ��������� ������
	\param[in] login �����
	\param[in] password ������
	\return ������� ���������� �� ������
	*/
	bool isCorrectPassword(std::string login, std::string password);

	/**
	�������� � ���� ��������� ������������
	\param[in] user ������������ �������� ��������
	*/
	//void addUser(User user);

	/**
	��������� ����� ������� ������
	*/
	void test();
}

#endif