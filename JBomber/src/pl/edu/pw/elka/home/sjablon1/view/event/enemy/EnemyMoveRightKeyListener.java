package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents Listener of EnemyMoveDownEvent for EnemyAnimation object.
 * It implements EnemyMoveDownListener interface and define what will happen
 * when EnemyMoveDownEvent will be fired and caught by
 * EnemyMoveDownKeyListener.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveRightKeyListener implements EnemyMoveRightEventListener
{
	/**
	 * Method defines what will happen when Listener have caught EnemyMoveRightEvent
	 * .
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyMoveRightEventOccurred(EnemyMoveRightEvent event, BlockingQueue<GameEvent> blockingEventQueue)
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
