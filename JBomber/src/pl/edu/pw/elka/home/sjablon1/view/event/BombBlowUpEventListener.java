package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

/**
 * Class represents interface BombBlowUpEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface BombBlowUpEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught BombBlowUpEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void bombBlowUpEventOccurred(BombBlowUpEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}