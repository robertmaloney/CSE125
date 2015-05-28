#include "GameEngine.h"


GameEngine::GameEngine() {
	gstate = &GameState::getInstance();
}


GameEngine::~GameEngine() {
}

void GameEngine::calculatePercent(){
	int total = gstate->getTotal();
	int occupied = 0;
	int max = 0;

	for (auto it = gstate->getPlayers().begin(); it != gstate->getPlayers().end(); ++it) {
		int s = (*it)->getScore();
		occupied = occupied + s;
		int p = s / total;
		//std::cout << (*it)->getId() << ": " << p << endl;
		(*it)->setPercent(p);

		if (s > max){
			max = s;
			gstate->top = (*it);
		}
	}	
	//std::cout << occupied << "  " << total << endl;
	if (occupied == total){
		//Win or lose
		for (auto it = gstate->getPlayers().begin(); it != gstate->getPlayers().end(); ++it) {
			if ((*it) == gstate->top){//win
				(*it)->setStatus(GStatus::WIN);
				std::cout << (*it)->getId() << ": YOU WIN "  << endl;
			}
			else{//lose
				(*it)->setStatus(GStatus::LOSE);
				std::cout << (*it)->getId() << ": YOU LOSE " << endl;
			}
			
		}
		endGame();
	}
}

void GameEngine::endGame(){
	std::cout << "GAME END" << endl;
}


void GameEngine::generateResources(int num) {
	int total = 0;
	for (int i = 0; i < num; i++)
	{
		float radius = 505;
		float theta = (float)(rand() % 180);
		float azimuth = (float)(rand() % 360);
		float direction = (float)(rand() % 360);
		Resource * newRe = new Tree(30, radius, theta, azimuth, direction);
		newRe->setModelRadius(3.f);
		newRe->setModelHeight(17.f);


		int pick = rand() % 5;


		// tree      xy 6.f z 16.f
		// trunk     xyz      4.f
		// rock      xy 8.f z 4.f
		// mushroom  xy 2.f z 4.f
		// flower    xy 2.f z 1.5f
		//Scores are placeholder, need to handle them differently...
		if (pick == 0){
			newRe = new Tree(30, radius, theta, azimuth, direction);
			newRe->setModelRadius(3.f);
			newRe->setModelHeight(17.f);
			total = total + 30;
		}
		else if (pick == 1) {
			newRe = new Rock(radius, theta, azimuth, direction);
			newRe->setModelRadius(2.f);
			newRe->setModelHeight(4.5f);
		}
		else if (pick == 2){
			newRe = new Stump(10, radius, theta, azimuth, direction);
			newRe->setModelRadius(2.f);
			newRe->setModelHeight(4.f);
			total = total + 10;
		}
		else if (pick == 3){
			newRe = new Mushroom(25, radius, theta, azimuth, direction);
			newRe->setModelRadius(1.f);
			newRe->setModelHeight(4.f);
			total = total + 25;
		}
		else if (pick == 4){
			newRe = new Flower(40, radius, theta, azimuth, direction);
			newRe->setModelRadius(1.f);
			newRe->setModelHeight(1.5f);
			total = total + 40;
		}


		ObjectId resourceId = IdGenerator::getInstance().createId();
		gstate->addResource(resourceId, newRe);

		//radius is always 505
		//randomize resource model?? (maybe we should separate blob model from resource model)
		//randomize other coords
	}
	gstate->setTotal(total);
}

void GameEngine::generateClouds(int num) {
   for (int i = 0; i < num; i++)
   {
      int floor = 700, ceiling = 800, range = (ceiling - floor);
      int radius = floor + int((range * rand()) / (RAND_MAX + 1.0));

      float theta = (float)(rand() % 180);
      float azimuth = (float)(rand() % 360);
      float direction = (float)(0);
      Resource * newRe = new Cloud(radius, theta, azimuth, direction);
      newRe->setModelRadius(3.f);
      newRe->setModelHeight(17.f);

      ObjectId resourceId = IdGenerator::getInstance().createId();
      gstate->addResource(resourceId, newRe);
   }
}

void GameEngine::generateClusterTree(float radius, float theta, float azimuth, int num)
{
   float dist = 5;
   for (int i = 0; i < num; i++)
   {
      int floor = theta - dist, ceiling = theta + dist, range = (ceiling - floor);
      float theta = floor + float((range * rand()) / (RAND_MAX + 1.0));

      floor = azimuth - dist, ceiling = azimuth + dist, range = (ceiling - floor);
      float azimuth = floor + float((range * rand()) / (RAND_MAX + 1.0));

      float direction = (float)(rand() % 360);
      Resource * newRe = new Tree(30, radius, theta, azimuth, direction);
      newRe->setModelRadius(3.f);
      newRe->setModelHeight(17.f);

      ObjectId resourceId = IdGenerator::getInstance().createId();
      gstate->addResource(resourceId, newRe);
   }
   gstate->setTotal(100);
}