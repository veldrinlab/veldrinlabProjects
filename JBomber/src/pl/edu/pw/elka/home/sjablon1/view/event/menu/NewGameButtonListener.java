package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents Listener of NewGameEvent for NewGameButton object. It implements
 * NewGameEventListener interface and define what will happen when NewGameEvent will be fired
 * and caught by NewGameEventListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class NewGameButtonListener implements NewGameEventListener
{
	/**
	 * Method defines what will happen when Listener have caught NewGameEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void newGameEventOccurred(NewGameEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
