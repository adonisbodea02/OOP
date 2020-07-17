#pragma once
#include <string>

class Error {
protected:
	std::string message;

public:
	Error();
	const std::string get_message() const;
};

class File_Error : public Error {
public:
	File_Error(std::string message);
};

class Controller_Error : public Error {
public:
	Controller_Error(std::string message);
};

class Validator {
public:
	void validate_rock_tshirt(int id, const std::string& size, const std::string& colour, int quantity, int price, const std::string& photo, const std::string& formation);
};

class Rock_Tshirt_Error : public Error
{
public:
	Rock_Tshirt_Error(std::string message);
};



