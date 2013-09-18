package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

/**
 * Class represents interface ExplosionChangeStateEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface ExplosionChangeStateEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught ExplosionChangeStateEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void explosionChangeStateEventOccurred(ExplosionChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}