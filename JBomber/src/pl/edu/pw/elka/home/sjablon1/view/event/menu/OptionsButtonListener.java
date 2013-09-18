package pl.edu.pw.elka.home.sjablon1.view.event.menu;

import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

/**
 * Class represents Listener of OptionsEvent for OptionsButton object. It implements
 * OptionsButtonEventListener interface and define what will happen when OptionsEvent
 * will be fired and caught by OptionsEventListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class OptionsButtonListener implements OptionsEventListener
{
	/**
	 * Method defines what will happen when Listener have caught OptionsEvent
	 * 
	 * @param event that Listener have caught. 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred
	 */
	@Override
	public void optionsEventOccurred(OptionsEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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