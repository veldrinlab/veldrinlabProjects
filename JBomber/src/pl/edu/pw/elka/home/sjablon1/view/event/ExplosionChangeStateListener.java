package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.concurrent.BlockingQueue;
/**
 * Class represents Listener of ExplosionChangeStateEvent for ExplosionAnimation object. It implements
 * ExplosionChangeStateEventListener interface and define what will happen when ExplosionChangeStateEvent
 * will be fired and caught by ExplosionChangeStateListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class  ExplosionChangeStateListener implements ExplosionChangeStateEventListener
{
	/**
	 * Method defines what will happen when Listener have caught ExplosionChangeStateEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void explosionChangeStateEventOccurred(ExplosionChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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