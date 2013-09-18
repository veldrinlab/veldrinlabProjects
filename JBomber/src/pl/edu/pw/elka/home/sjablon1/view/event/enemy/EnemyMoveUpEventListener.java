package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents interface EnemyMoveUpEventListener. It extends
 * EventListener like all Listener classes. Other class must implement this
 * interface to respond to fired event.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
interface EnemyMoveUpEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caughtEnemyMoveUpEvent
	 * 
	 * @param event that Listener have caught.
	 */
	public void enemyMoveUpEventOccurred(EnemyMoveUpEvent event, BlockingQueue<GameEvent> blockingEventQueue);

}