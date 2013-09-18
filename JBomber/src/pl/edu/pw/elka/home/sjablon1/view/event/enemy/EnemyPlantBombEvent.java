package pl.edu.pw.elka.home.sjablon1.view.event.enemy;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Enemy Event in Game - EnemyPlantBombEvent Event,
 * which is fired when user controls Enemy Bomberman to plant Bomb. Every
 * Events in JBomber extends GameEvent class.
 * identification.
 * 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyPlantBombEvent extends GameEvent
{
	/**
	 * Default constructor of EnemyPlantBombEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public EnemyPlantBombEvent(Object source)
	{
		super(source);
	}

}
