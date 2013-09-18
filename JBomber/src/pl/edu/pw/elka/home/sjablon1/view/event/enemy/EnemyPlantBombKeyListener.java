package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents Listener of EnemyPlantBombEvent for EnemyAnimation object.
 * It implements EnemyPlantBombEventListener interface and define what will
 * happen when EnemyPlantBombEvent will be fired and caught by
 * EnemyPlantBombtKeyListener.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyPlantBombKeyListener implements EnemyPlantBombEventListener
{
	/**
	 * Method defines what will happen when Listener have caught
	 * EnemyPlantBombEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyPlantBombEventOccurred(EnemyPlantBombEvent event, BlockingQueue<GameEvent> blockingEventQueue)
	{
		try
		{
			blockingEventQueue.put(event);
		} catch (InterruptedException e)
		{
			System.out.println("Cannot add to Queue!");
			e.printStackTrace();
		}

	}

}