package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents Listener of EnemyMoveLeftEvent for EnemyAnimation object.
 * It implements EnemyMoveLeftListener interface and define what will happen
 * when EnemyMoveLeftEvent will be fired and caught by
 * EnemyMoveLeftKeyListener.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveLeftKeyListener implements EnemyMoveLeftEventListener
{
	/**
	 * Method defines what will happen when Listener have caught EnemyMoveLeftEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyMoveLeftEventOccurred(EnemyMoveLeftEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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