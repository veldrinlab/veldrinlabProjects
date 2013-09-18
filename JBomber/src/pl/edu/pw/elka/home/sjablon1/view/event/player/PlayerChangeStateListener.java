package pl.edu.pw.elka.home.sjablon1.view.event.player;
import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;
/**
 * Class represents Listener of PlayerChangeStateEvent for PlayerAnimation object. It implements
 * PlayerChangeStateEventListener interface and define what will happen when PlayerChangeStateEvent
 * will be fired and caught by PlayerChangeStateListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerChangeStateListener implements PlayerChangeStateEventListener
{
	/**
	 * Method defines what will happen when Listener have caught PlayerStoptEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerChangeStateEventOccurred(PlayerChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{
		try
		{
			blockingEventQueue.put(event);
		}
		catch (InterruptedException e)
		{
			System.out.println("Cannot add to Queue!");
			e.printStackTrace();
		}
		
	}

}