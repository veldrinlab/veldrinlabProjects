package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyMoveRight Event, which
 * is fired when user controls Enemy Bomberman to move Right. Every Events in
 * JBomber extends GameEvent class.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveRightEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyMoveRightEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyMoveRightEvent(Object source)
	{
		super(source);
	}
}
