#include "Dynamic_Vector.h"
#include "Comparator.h"

void generic_sort(dynamic_vector<Rock_Tshirt>& dv, Comparator<Rock_Tshirt>& c)
{
	int pos = 0;
	Rock_Tshirt rt;
	while (pos < dv.get_size())
	{
		if (pos == 0 || c.compare(dv[pos], dv[pos-1]) > 0)
			pos = pos + 1;
		else
		{
			rt = dv.get_element(pos);
			dv.set_element(pos, dv.get_element(pos - 1));
			dv.set_element(pos - 1, rt);
			pos = pos - 1;
		}
	}
}