package pl.edu.pw.elka.home.sjablon1.view.event.player;
import pl.edu.pw.elka.home.sjablon1.view.event.*;

/**
 * Class represents one of Player Event in Game - PlayerChangeState Event, which is fired
 * when Player BombermanState is changed. Every Events in JBomber extends GameEvent 
 * class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerChangeStateEvent extends GameEvent
{
	/**
	 * Default constructor of PlayerMoveStopEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public PlayerChangeStateEvent(Object source)
	{
		super(source);
    }

}