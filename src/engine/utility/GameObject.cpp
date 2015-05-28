#include "GameObject.h"


//TODO Config file
GameObject::GameObject(float radius, float theta, float azimuth, float direction) {
	//this->loc = vec4(radius, theta, azimuth, direction);
	this->modelRadius = 1.f;
	this->type = GAMEOBJECT;
	this->angle = direction;
	this->height = radius;
	this->orientation = glm::quat(glm::vec3(theta, azimuth, 0.f));
	this->visible = true;
}

GameObject::~GameObject() {
	// have to remove from tree
	//delete node;
}


void GameObject::serialize(Packet & p) {
	p.writeUInt(id);
	for (int i = 0; i < 4; ++i) {
		//p.writeFloat(this->loc[i]);
		p.writeFloat(this->orientation[i]);
	}
	p.writeFloat(this->angle);
	p.writeFloat(this->height);
	//p.writeFloat(this->score);
	p.writeByte(this->visible);
    p.writeInt(static_cast<int>(this->rm));
}


void GameObject::deserialize(Packet & p) {
	this->id = p.readUInt();
	for (int i = 0; i < 4; ++i) {
		//this->loc[i] = p.readFloat();
		this->orientation[i] = p.readFloat();
	}
	this->angle = p.readFloat();
	this->height = p.readFloat();
	//this->score = p.readFloat();
	this->visible = p.readBool();
    this->rm = static_cast<Model>(p.readInt());
}

quat & GameObject::getOrientation() {
	return orientation;
}

void GameObject::moveAngle(float delta) {
	angle += delta;
}

float GameObject::getAngle() {
	return angle;
}

float GameObject::getHeight() {
	return this->height;
}

void GameObject::setHeight(float height) {
	this->height = height;
}

void GameObject::setModelHeight(float mheight) {
	assert(!(mheight < 0.f));
	this->modelHeight = mheight;
}
float GameObject::getModelHeight() {
	return this->modelHeight;
}

ObjectId GameObject::getId() {
	return id;
}

void GameObject::setId(ObjectId theId) {
	this->id = theId;
}

void GameObject::setModel(Model model) {
   this->rm = model;
}

Model GameObject::getModel() {

   return rm;
}

bool GameObject::getVisible(){
	return this->visible;
}

void GameObject::setVisible(bool v){
	this->visible = v;
}

float GameObject::getModelRadius() {
	return this->modelRadius;
}

void GameObject::setModelRadius(float radius) {
	assert(radius > 0);
	this->modelRadius = radius;
}

ObjectType GameObject::getType() const {
	return this->type;
}

void GameObject::collide(float dt, GameObject & target) {

}
