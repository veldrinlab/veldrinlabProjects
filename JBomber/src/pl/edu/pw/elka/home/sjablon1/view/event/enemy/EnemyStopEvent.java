package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyMoveStop Event, which is
 * fired when user controls Enemy Bomberman is stopped. Every Events in JBomber
 * extends GameEvent class.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyStopEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyMoveStopEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyStopEvent(Object source)
	{
		super(source);
	}

}