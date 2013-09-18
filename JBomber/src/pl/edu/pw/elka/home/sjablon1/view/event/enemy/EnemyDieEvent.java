package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyDie Event, which is
 * fired when user Bomberman collides with Explosion and die. Every Events in
 * JBomber extends GameEvent class.
 * @version 1.0
 */
public class EnemyDieEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyDieEvent
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyDieEvent(Object source)
	{
		super(source);
	}

}