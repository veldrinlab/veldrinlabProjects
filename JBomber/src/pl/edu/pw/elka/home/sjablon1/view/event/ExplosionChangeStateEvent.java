package pl.edu.pw.elka.home.sjablon1.view.event;

/**
 * Class represents one of Explosion Event in Game -  ExplosionChangeState Event, which is fired
 * when Explosion change state. Every Events in JBomber extends GameEvent 
 * class and known is's name for identification.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionChangeStateEvent extends GameEvent
{
	/**
	 * Default constructor of  ExplosionChangeStateEvent.
	 * 
	 * @param source is object witch has generated event.
	 */
	public ExplosionChangeStateEvent(Object source)
	{
		super(source);
    }

}