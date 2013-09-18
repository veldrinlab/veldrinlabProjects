package pl.edu.pw.elka.home.sjablon1.view.event.player;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;
/**
 * Class represents Listener of PlayerMoveLeftEvent for PlayerAnimation object. It implements
 * PlayerMoveLeftListener interface and define what will happen when PlayerMoveLeftEvent
 * will be fired and caught by PlayerMoveLeftKeyListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerMoveLeftKeyListener implements PlayerMoveLeftEventListener
{
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

}