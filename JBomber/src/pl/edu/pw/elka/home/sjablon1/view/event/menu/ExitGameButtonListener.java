package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents Listener of ExitGameEvent for ExitGameButton object. It implements
 * ExitGameEventListener interface and define what will happen when ExitGameEvent will be fired
 * and caught by ExitGameEventListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExitGameButtonListener implements ExitGameEventListener
{
	/**
	 * Method defines what will happen when Listener have caught ExitGameEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred. 
	 */
	@Override
	public void exitGameEventOccurred(ExitGameEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
