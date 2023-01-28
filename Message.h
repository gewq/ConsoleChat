/**
\file Message.h
\brief ����� ������������� ������ � ���������
<<<<<<< HEAD
=======
>>>>>>> origin/svetlana
�������� ����:
- ��� ������������ �� ���� ���������
- ��� ������������ ���� ���������
- ����� ���������
*/

#pragma once

#include <string>

class Message {
public:
    /**
    ����������� ��-���������
    */
    Message() = delete;

    /**
    ����������������� �����������
    \param[in] nameUserFrom ��� ������������ �� �������� ���������
    \param[in] nameUserTo ��� ������������ ���� ���������� ���������
    \param[in] text ����� ���������
    */
    Message(const std::string& nameUserFrom,
        const std::string& nameUserTo,
        const std::string& text);
    /**
    \return ��� ������������ �� �������� ���������
    */
    const std::string& getNameFrom() const;

    /**
    \return ��� ������������ ���� ���������
    */
    const std::string& getNameTo() const;

    /**
    \return ��� ������������ ���� ���������
    */
    const std::string& getText() const;

private:
    const std::string nameUserFrom_;	///<��� ������������ �� �������� ���������
    const std::string nameUserTo_;		///<��� ������������ ���� ���������� ���������
    const std::string text_;			///<����� ���������
};