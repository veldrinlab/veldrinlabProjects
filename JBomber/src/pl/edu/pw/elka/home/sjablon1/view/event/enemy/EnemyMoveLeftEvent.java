package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyMoveLeft Event, which is
 * fired when user controls Enemy Bomberman to move Left. Every Events in
 * JBomber extends GameEvent class.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveLeftEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyMoveLeftEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyMoveLeftEvent(Object source)
	{
		super(source);
	}

}
