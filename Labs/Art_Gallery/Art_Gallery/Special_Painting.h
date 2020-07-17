#pragma once
#include "Painting.h"
#include <string>

class Special_Painting : public Painting
{
private:
	double temperature;

public:

	Special_Painting(const std::string& title, const std::string artist, const int year, const double temperature);

	std::string to_string() override;
	bool is_special() override;

};