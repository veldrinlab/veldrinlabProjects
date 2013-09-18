package pl.edu.pw.elka.home.sjablon1.view.event.player;


import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents interface PlayerMoveRightEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface PlayerMoveRightEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveRightEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void playerMoveRightEventOccurred(PlayerMoveRightEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}
