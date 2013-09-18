package pl.edu.pw.elka.home.sjablon1.view.event.player;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;
/**
 * Class represents Listener of PlayerPlantBombEvent for PlayerAnimation object. It implements
 * PlayerPlantBombEventListener interface and define what will happen when PlayerPlantBombEvent
 * will be fired and caught by PlayerPlantBombtKeyListener.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerPlantBombKeyListener implements PlayerPlantBombEventListener
{
	/**
	 * Method defines what will happen when Listener have caught PlayerPlantBombEvent
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

}