package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents interface EnemyMoveRightEventListener. It extends
 * EventListener like all Listener classes. Other class must implement this
 * interface to respond to fired event.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
interface EnemyMoveRightEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught EnemyMoveRightEvent
	 * 
	 * @param event that Listener have caught.
	 */
	public void enemyMoveRightEventOccurred(EnemyMoveRightEvent event, BlockingQueue<GameEvent> blockingEventQueue);

}
