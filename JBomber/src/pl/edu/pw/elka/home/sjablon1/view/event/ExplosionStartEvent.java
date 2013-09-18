package pl.edu.pw.elka.home.sjablon1.view.event;

/**
 * Class represents one of Explosion Event in Game - Explosion Event, which is fired
 * when Explosion change state to Start. Every Events in JBomber extStarts GameEvent 
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionStartEvent extends GameEvent
{
	/**
	 * Default constructor of ExplosionStartEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public ExplosionStartEvent(Object source)
	{
		super(source);
    }

}