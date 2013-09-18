package pl.edu.pw.elka.home.sjablon1.view.event.player;


import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents interface PlayerMoveLeftEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface PlayerMoveLeftEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveLeftEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void playerMoveLeftEventOccurred(PlayerMoveLeftEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}