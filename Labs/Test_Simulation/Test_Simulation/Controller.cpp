#include "Controller.h"
#include <algorithm>

std::vector<Offer> Controller::filter_by_string_ctrl(std::string s)
{
	std::vector<Offer> v = this->get_repo().get_vector();
	std::vector<Offer> v2(v.size());
	std::vector<Offer>::iterator it = std::copy_if(v.begin(), v.end(), v2.begin(), [&](Offer o) {return o.get_address().find(s) != std::string::npos; });
	v2.resize(std::distance(v2.begin(), it));
	std::sort(v2.begin(), v2.end(), [&](Offer o1, Offer o2) {return o1.get_price() < o2.get_price(); });
	return v2;
}