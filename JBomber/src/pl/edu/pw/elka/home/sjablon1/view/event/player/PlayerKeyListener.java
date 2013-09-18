package pl.edu.pw.elka.home.sjablon1.view.event.player;

import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents Listener of all Events that PlayerAnimation object can occurred. It implements
 * all Listeners connected with Player Events: Player Move Events, Player Plant Bomb Events etc.
 * interfaces and define what will happen when each Events occurred.
 * will be fired and caught by PlayerKeyListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerKeyListener implements PlayerMoveUpEventListener, PlayerMoveDownEventListener,
										  PlayerMoveLeftEventListener, PlayerMoveRightEventListener,
										  PlayerStopEventListener, PlayerPlantBombEventListener
{
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveUpEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerMoveUpEventOccurred(PlayerMoveUpEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
	
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveDownEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerMoveDownEventOccurred(PlayerMoveDownEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
	
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveLeftEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerMoveLeftEventOccurred(PlayerMoveLeftEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
	
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveRightEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred. 
	 */
	@Override
	public void playerMoveRightEventOccurred(PlayerMoveRightEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
	
	/**
	 * Method defines what will happen when Listener have caught PlayerMoveLeftEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerPlantBombEventOccurred(PlayerPlantBombEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
	
	/**
	 * Method defines what will happen when Listener have caught PlayerStoptEvent
	 * 
	 * @param event that Listener have caught.
 	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void playerStopEventOccurred(PlayerStopEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
