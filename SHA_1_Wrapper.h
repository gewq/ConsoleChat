/**
\file SHA_1_Wrapper.h
\brief ������ ��� ������� ������� ���� (sha-1) ������ 
*/

#pragma once

#include <string>

namespace sha_1 {
	std::string hash(const std::string value);
}