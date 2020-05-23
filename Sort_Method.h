#pragma once
#include <vector>
#include "Auto.h"

enum class Sort_Method_Type {
	Library_Sort, Bubble_Sort
};

class Sort_Method {
public:
	static Sort_Method* Create(Sort_Method_Type type);
	virtual void sort_authos(std::vector <Auto>& autos) = 0;
};

