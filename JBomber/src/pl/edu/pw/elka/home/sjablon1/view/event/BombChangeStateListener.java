package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.concurrent.BlockingQueue;
/**
 * Class represents Listener of BombChangeStateEvent for BombAnimation object. It implements
 * BombChangeStateEventListener interface and define what will happen when BombChangeStateEvent
 * will be fired and caught by BombChangeStateListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class  BombChangeStateListener implements  BombChangeStateEventListener
{
	/**
	 * Method defines what will happen when Listener have caught  BombChangeStateEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void bombChangeStateEventOccurred(BombChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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