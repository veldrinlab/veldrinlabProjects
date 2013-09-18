/**
 * File contains definition of LevelManager class. 
 * @file    LevelManager.hpp
 * @author  Adam Sznajder
 * @date    2010-01-08
 * @version 1.0
 */

#include "LevelManager.hpp"

namespace game
{

/**
 * Constructor.
 * @param current level.
 */
LevelManager::LevelManager(Level initLevel)
{
	currentLevel = initLevel;
}

/**
 * Destructor.
 */
LevelManager::~LevelManager()
{

}

/**
 * Method which is responsible for preparing current level's scene.
 * @param sceneManager pointer to sceneManager.
 */
void LevelManager::prepareLevelScene(SceneManager* sceneManager)
{
	if (currentLevel == FIRST)
	{
			/* Level 1 - Battle of Mindor */

		sceneManager->skyBox = new SkyBox(Vector3D(0,0,0),Vector3D(2000,2000,2000),0);
	
			EnemyPrototypeFactory* enemyFactory = EnemyPrototypeFactory::getInstance();
			StarDestroyer* destroyerPrototype = new StarDestroyer("Data/destroyer.vel","Data/destroyerTexture.jpg",Vector3D(0.0f,0.0f,0.0f),Quaternion::IDENTITY);
			Asteroid* asteroidPrototype = new Asteroid("Data/asteroid.vel","Data/asteroidTexture.jpg",Vector3D(100.0f,-100.0f,100.0f));
			TieFighter* enemyPrototype = new TieFighter("Data/tieFighter.vel","Data/tieFighter.jpg",Vector3D(0.0f,-30.0f,10.0f));

			enemyFactory->registerEnemy("StarDestroyer", destroyerPrototype);
			enemyFactory->registerEnemy("Asteroid", asteroidPrototype);
			enemyFactory->registerEnemy("TieFighter", enemyPrototype);

			StarDestroyer* destroyer = (StarDestroyer*)enemyFactory->createEnemy("StarDestroyer");
			StarDestroyer* destroyer2 = (StarDestroyer*)enemyFactory->createEnemy("StarDestroyer");

			destroyer->position = Vector3D(-200.0f,-200.0f,300.0f);

			destroyer->setScene(sceneManager->shootedLasers);
			destroyer->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			destroyer->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			destroyer2->position = Vector3D(200.0f,-200.0f,-300.0f);
			destroyer2->setScene(sceneManager->shootedLasers);
			destroyer2->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			destroyer2->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			Asteroid* asteroid = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid->position = Vector3D(100.0f,-100.0f,100.0f);
			Asteroid* asteroid2 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid2->position = Vector3D(300.0f,-100.0f,200.0f);
			Asteroid* asteroid3 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid3->position = Vector3D(400.0f,-200.0f,300.0f);
			Asteroid* asteroid4 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid4->position = Vector3D(500.0f,-150.0f,100.0f);
			Asteroid* asteroid5 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid5->position = Vector3D(500.0f,-100.0f,-500.0f);
			Asteroid* asteroid6 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid6->position = Vector3D(500.0f,-100.0f,-400.0f);
			Asteroid* asteroid7 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid7->position = Vector3D(300.0f,-100.0f,100.0f);
			Asteroid* asteroid8 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid8->position = Vector3D(400.0f,150.0f,100.0f);
			Asteroid* asteroid9 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid9->position = Vector3D(350.0f,-200.0f,100.0f);
			Asteroid* asteroid10 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid10->position = Vector3D(500.0f,300.0f,500.0f);
			Asteroid* asteroid11 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid11->position = Vector3D(-500.0f,250.0f,-500.0f);
			Asteroid* asteroid12 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid12->position = Vector3D(-300.0f,200.0f,-340.0f);
			Asteroid* asteroid13 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid13->position = Vector3D(200.0f,-300.0f,-600.0f);
			Asteroid* asteroid14 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid14->position = Vector3D(300.0f,0.0f,-400.0f);
			Asteroid* asteroid15 = (Asteroid*)enemyFactory->createEnemy("Asteroid");
			asteroid15->position = Vector3D(200.0f,-100.0f,150.0f);

			//sceneManager->addEntityToScene(sceneManager->getCamera());
			//sceneManager->addEntityToScene(skyBox);
			//sceneManager->addEntityToScene(new SkyBox(Vector3D(0,0,0),Vector3D(2000,2000,2000),0));
			//sceneManager->addEntityToScene(new SkyBox(Vector3D(0,0,0),Vector3D(2000,2000,2000),0));
			//sceneManager->addEntityToScene(sceneManager->getPlayerShip());
			sceneManager->addEntityToScene(destroyer);
			sceneManager->addEntityToScene(destroyer2);

			sceneManager->addEntityToScene(asteroid);
			sceneManager->addEntityToScene(asteroid2);
			sceneManager->addEntityToScene(asteroid3);
			sceneManager->addEntityToScene(asteroid4);
			sceneManager->addEntityToScene(asteroid5);
		  sceneManager->addEntityToScene(asteroid6);
			sceneManager->addEntityToScene(asteroid7);
			sceneManager->addEntityToScene(asteroid8);
			sceneManager->addEntityToScene(asteroid9);
			sceneManager->addEntityToScene(asteroid10);
			sceneManager->addEntityToScene(asteroid11);
			sceneManager->addEntityToScene(asteroid12);
			sceneManager->addEntityToScene(asteroid13);
			sceneManager->addEntityToScene(asteroid14);
			sceneManager->addEntityToScene(asteroid15);


			// jak wygl¹da przekazywanie mu pozycji: w wektorze x - y stanowi¹ œrodek okrêgu/trajektorii, z stanowi
			// promieñ

			TieFighter* enemy = (TieFighter*)enemyFactory->createEnemy("TieFighter");
			enemy->position = Vector3D(0.0f,-30.0f,10.0f);
			enemy->setScene(sceneManager->shootedLasers);
			enemy->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			enemy->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			TieFighter* enemy2 = (TieFighter*)enemyFactory->createEnemy("TieFighter");
			enemy2->position = Vector3D(50.0f,-30.0f,30.0f);
			enemy2->setScene(sceneManager->shootedLasers);
			enemy2->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			enemy2->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			TieFighter* enemy3 = (TieFighter*)enemyFactory->createEnemy("TieFighter");
			enemy3->position = Vector3D(10.0f,0.0f,50.0f);
			enemy3->setScene(sceneManager->shootedLasers);
			enemy3->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			enemy3->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			TieFighter* enemy4 = (TieFighter*)enemyFactory->createEnemy("TieFighter");
			enemy4->position = Vector3D(10.0f,30.0f,20.0f);
			enemy4->setScene(sceneManager->shootedLasers);
			enemy4->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			enemy4->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

			TieFighter* enemy5 = (TieFighter*)enemyFactory->createEnemy("TieFighter");
			enemy5->position = Vector3D(0.0f,0.0f,100.0f);
			enemy5->setScene(sceneManager->shootedLasers);
			enemy5->setEnemyPosition(&sceneManager->getPlayerShip()->position);
			enemy5->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());
	
			sceneManager->addEntityToScene(enemy);
			sceneManager->addEntityToScene(enemy2);
			sceneManager->addEntityToScene(enemy3);
			sceneManager->addEntityToScene(enemy4);
			sceneManager->addEntityToScene(enemy5);
	} else if (currentLevel == SECOND)
	{
		/* Level 2 - Battle of Hoth */

		sceneManager->skyBox = new SkyBox(Vector3D(0,0,0),Vector3D(2000,2000,2000),1);
		sceneManager->terrain = new Terrain("Data/hothTerrain.raw","Data/hothTexture.jpg");

		EnemyPrototypeFactory* enemyFactory = EnemyPrototypeFactory::getInstance();
		ATST* enemyPrototype = new ATST("Data/atst.vel","Data/atst.jpg",Vector3D(200.0f,-750.0f,100.0f));
		enemyFactory->registerEnemy("ATST", enemyPrototype);

		ATST* enemy = (ATST*)enemyFactory->createEnemy("ATST");
		enemy->setScene(sceneManager->shootedLasers);
		enemy->setEnemyPosition(&sceneManager->getPlayerShip()->position);
		enemy->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());
		ATST* enemy2 = (ATST*)enemyFactory->createEnemy("ATST");
		enemy2->position = Vector3D(-200.0f,-750.0f,-100.0f);
		enemy2->setScene(sceneManager->shootedLasers);
		enemy2->setEnemyPosition(&sceneManager->getPlayerShip()->position);
		enemy2->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());
		ATST* enemy3 = (ATST*)enemyFactory->createEnemy("ATST");
		enemy3->position = Vector3D(100.0f,-750.0f,400.0f);
		enemy3->setScene(sceneManager->shootedLasers);
		enemy3->setEnemyPosition(&sceneManager->getPlayerShip()->position);
		enemy3->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());
		ATST* enemy4 = (ATST*)enemyFactory->createEnemy("ATST");
		enemy4->position = Vector3D(-200.0f,-750.0f,350.0f);
		enemy4->setScene(sceneManager->shootedLasers);
		enemy4->setEnemyPosition(&sceneManager->getPlayerShip()->position);
		enemy4->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());
		ATST* enemy5 = (ATST*)enemyFactory->createEnemy("ATST");
		enemy5->position = Vector3D(-500.0f,-750.0f,450.0f);
		enemy5->setScene(sceneManager->shootedLasers);
		enemy5->setEnemyPosition(&sceneManager->getPlayerShip()->position);
		enemy5->setEnemyOrientation(&sceneManager->getCamera()->getOrientation());

		//sceneManager->addEntityToScene(sceneManager->getCamera());
		//sceneManager->addEntityToScene(skyBox);
		//sceneManager->addEntityToScene(terrain);
		//sceneManager->addEntityToScene(sceneManager->getPlayerShip());

		sceneManager->addEntityToScene(enemy);
		sceneManager->addEntityToScene(enemy2);
		sceneManager->addEntityToScene(enemy3);
		sceneManager->addEntityToScene(enemy4);
		sceneManager->addEntityToScene(enemy5);

	}
}

/**
 * Method used to change current level of game.
 */
void LevelManager::nextLevel()
{
	if (currentLevel == INTRO)
		currentLevel = FIRST;
	else if (currentLevel == FIRST)
		currentLevel = SECOND;
	else currentLevel = GAME_OVER;
}
/**
 * Accessor to currentLevel.
 * @return current level.
 */
Level LevelManager::getLevel()
{
	return currentLevel;
}

}