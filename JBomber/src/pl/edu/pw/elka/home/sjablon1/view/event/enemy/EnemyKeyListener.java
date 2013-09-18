package pl.edu.pw.elka.home.sjablon1.view.event.enemy;


import java.util.concurrent.BlockingQueue;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents Listener of all Events that EnemyAnimation object can
 * occurred. It implements all Listeners connected with Enemy Events: Enemy
 * Move Events, Enemy Plant Bomb Events etc. interfaces and define what will
 * happen when each Events occurred. will be fired and caught by
 * EnemyKeyListener.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyKeyListener implements EnemyMoveUpEventListener,
		EnemyMoveDownEventListener, EnemyMoveLeftEventListener,
		EnemyMoveRightEventListener, EnemyStopEventListener,
		EnemyPlantBombEventListener
{
	/**
	 * Method defines what will happen when Listener have caught EnemyMoveUpEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyMoveUpEventOccurred(EnemyMoveUpEvent event, BlockingQueue<GameEvent> blockingEventQueue)
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

	/**
	 * Method defines what will happen when Listener have caught EnemyMoveDownEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyMoveDownEventOccurred(EnemyMoveDownEvent event, BlockingQueue<GameEvent> blockingEventQueue)
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

	/**
	 * Method defines what will happen when Listener have caught EnemyMoveRightEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyMoveRightEventOccurred(EnemyMoveRightEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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

	/**
	 * Method defines what will happen when Listener have caught EnemyMoveLeftEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyPlantBombEventOccurred(EnemyPlantBombEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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

	/**
	 * Method defines what will happen when Listener have caught EnemyStoptEvent
	 * 
	 * @param event that Listener have caught.
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 *        Controller Unit.
	 * @throws InterruptedExcenption when adding to queue error occurred.
	 */
	@Override
	public void enemyStopEventOccurred(EnemyStopEvent event,BlockingQueue<GameEvent> blockingEventQueue)
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
