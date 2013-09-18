package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents interface EnemyPlantBombEventListener. It extends
 * EventListener like all Listener classes. Other class must implement this
 * interface to respond to fired event.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
interface EnemyPlantBombEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught EnemyPlantBomb
	 * 
	 * @param event that Listener have caught.
	 */
	public void enemyPlantBombEventOccurred(EnemyPlantBombEvent event, BlockingQueue<GameEvent> blockingEventQueue);

}