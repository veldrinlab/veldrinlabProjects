package pl.edu.pw.elka.home.sjablon1.view.event.player;

import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerPlantBombEvent Event, witch is fired
 * when user controls Player Bomberman to plant Bomb. Every Events in JBomber extends GameEvent
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerPlantBombEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerPlantBombEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerPlantBombEvent(Object source)
	{
		super(source);
    }

}
