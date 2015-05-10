#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include "../network/Packet.h"
#include "Serializable.h"
#include "IdGenerator.h"

using glm::mat4;
using glm::vec2;
using glm::vec4;
using namespace std;

enum ObjectType {
	PLAYER,
	MOVEABLE,
	GAMEOBJECT
};

class GameObject : public Serializable  {

public:

protected:

	vec4 loc;
	ObjectId id;
	ObjectType type;
	float modelRadius;

public:

	GameObject(float radius = 505, float theta = 0, float azimuth = 0, float direction = 0);
	GameObject(const vec4 & loc) : GameObject(loc.r, loc.g, loc.b, loc.a) {};

	virtual ~GameObject();

	ObjectId getId();
	void setId(ObjectId theId);

	vec4 getLoc();
	void setLoc(vec4 & newLoc);

	float getModelRadius();
	void setModelRadius(float radius);

	ObjectType getType() const;

	void serialize(Packet & p);
	void deserialize(Packet & p);

	virtual void update(float dt);
	virtual void collide(const GameObject & target);

};

#endif