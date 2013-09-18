package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyMoveDown Event, which is
 * fired when user controls Enemy Bomberman to move Down. Every Events in
 * JBomber extends GameEvent class.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyMoveDownEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyMoveDownEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyMoveDownEvent(Object source)
	{
		super(source);
	}

}
