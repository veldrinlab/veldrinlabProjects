package pl.edu.pw.elka.home.sjablon1.view.event;

import java.util.concurrent.BlockingQueue;
/**
 * Class represents Listener of BombBlowUpEvent for BombAnimation object. It implements
 * BombBlowUpEventListener interface and define what will happen when BombBlowUpEvent
 * will be fired and caught by BombBlowUpListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BombBlowUpListener implements BombBlowUpEventListener
{
	/**
	 * Method defines what will happen when Listener have caught BombBlowUpEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void bombBlowUpEventOccurred(BombBlowUpEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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