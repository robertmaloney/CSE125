#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Location.h"
#include "BlobModel.h"
#include "GameObject.h"

#include <glm.hpp>

using namespace std;


class Player {
	//TODO put it outside
protected:

	ObjectId pid;
	int speed;
	int power;
	static int numOfPlayers;

	BlobModel bm;

	glm::vec4 orientation;

public:

	Player() :Player(OB_TYPE) {};
	Player(BlobModel thebm) : Player(thebm, 0, 0, 0, 0) {};
	Player(BlobModel, float, float, float, float);

	virtual ~Player();

	int getSpeed();
	int getPower();

	ObjectId getPid();

	glm::vec4 & getOrientation();

	void setSpeed(int newSpeed);
	void setPower(int newPower);

};

#endif