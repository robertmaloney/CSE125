#ifndef I_EATABLE_H
#define I_EATABLE_H
#include "Resource.h"
#include "GameObject.h"

class IEatable {
public:

	virtual int getPoints() = 0;
	virtual void setPoints(int points) = 0;
};

#endif