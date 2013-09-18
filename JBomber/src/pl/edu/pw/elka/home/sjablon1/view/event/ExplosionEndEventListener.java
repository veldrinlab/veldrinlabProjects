
package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

/**
 * Class represents interface ExplosionEndEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface ExplosionEndEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught ExplosionEndEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void explosionEndEventOccurred(ExplosionEndEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}