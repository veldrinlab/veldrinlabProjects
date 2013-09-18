package pl.edu.pw.elka.home.sjablon1.view.event.player;
import pl.edu.pw.elka.home.sjablon1.view.event.*;


/**
 * Class represents one of Player Event in Game - PlayerDie Event, witch is fired
 * when user Bomberman collides with Explosion and die. Every Events in JBomber extends GameEvent
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerDieEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveDownEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerDieEvent(Object source)
	{
		super(source);
    }

}