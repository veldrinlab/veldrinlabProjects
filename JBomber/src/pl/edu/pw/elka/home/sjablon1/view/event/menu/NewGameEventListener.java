package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import java.util.EventListener;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents interface of NewGameEventListener. It extends EventListener
 * like all Listener classes. Other class must implement this interface to respond
 * to fired event.
 * @author Szymon Jablonski
 * @version 1.0
 */
interface NewGameEventListener extends EventListener
{
	/**
	 * Method defines what will happen when Listener have caught NewGameEvent
	 * 
	 * @param event that Listener have caught. 
	 */
	public void newGameEventOccurred(NewGameEvent event,BlockingQueue<GameEvent> blockingEventQueue);

}
