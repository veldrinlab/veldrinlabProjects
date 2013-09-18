package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyChangeState Event, which
 * is fired when Player BombermanState is changed. Every Events in JBomber
 * extends GameEvent class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyChangeStateEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyChangeStateEvent
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyChangeStateEvent(Object source)
	{
		super(source);
	}

}