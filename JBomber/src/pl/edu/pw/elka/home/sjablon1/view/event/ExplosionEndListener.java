package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.concurrent.BlockingQueue;
/**
 * Class represents Listener of ExplosionEndEvent for ExplosionAnimation object. It implements
 * ExplosionEndEventListener interface and define what will happen when ExplosionEndEvent
 * will be fired and caught by ExplosionEndListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class  ExplosionEndListener implements ExplosionEndEventListener
{
	/**
	 * Method defines what will happen when Listener have caught ExplosionEndEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void explosionEndEventOccurred(ExplosionEndEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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