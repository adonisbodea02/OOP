#include "Exception_Class.h"

Error::Error() : message("") {}

const std::string Error::get_message() const
{
	return this->message;
}

File_Error::File_Error(std::string message)
{
	this->message = message;
}

Controller_Error::Controller_Error(std::string message)
{
	this->message = message;
}

void Validator::validate_rock_tshirt(int id, const std::string & size, const std::string & colour, int quantity, int price, const std::string & photo, const std::string & formation)
{
	std::string message;
	if (id < 1)
		message = message + "ID is not positive\n";
	if (size.empty())
		message = message + "Size can not be empty\n";
	if (colour.empty())
		message = message + "Colour can not be empty\n";
	if (price < 1)
		message = message + "Price is not positive\n";
	if (quantity < 1)
		message = message + "Quantity is not positive\n";
	if (photo.empty())
		message = message + "The link of the photo can not be empty\n";
	else if (photo.find("http", 0) == std::string::npos)
		message = message + "The link of the photo is invalid\n";
	if (!message.empty())
		throw Rock_Tshirt_Error(message);

}

Rock_Tshirt_Error::Rock_Tshirt_Error(std::string message)
{
	this->message = message;
}
