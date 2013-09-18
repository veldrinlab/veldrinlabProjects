package pl.edu.pw.elka.home.sjablon1.view;

import java.util.concurrent.BlockingQueue;

import javax.swing.JButton;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.NewGameButtonListener;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.NewGameEvent;


/**
 * Class represents object of NewGameButton that generate NewGameEvent. It is one of
 * four buttons from MenuButtonPanel.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class NewGameButton extends JButton
{
	
	/**List of objects listeners*/
	private EventListenerList listenerList;
	
	/**
	 * Default constructor of NewGameButton object. It creates instance of NewGameButton class
	 * with custom backgroundImage, and add additional Listener for NewGameEvent witch is fired
	 * by actionPerformed method of JButton
	 */
	public NewGameButton()
	{
		super("New Game");
		listenerList = new EventListenerList();
		this.addNewGameButtonListener(new NewGameButtonListener());
		
	}
		
	/**
	 * Method that allows classes to register for NewGameEvents
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addNewGameButtonListener(final NewGameButtonListener listener)
	{ 
		listenerList.add(NewGameButtonListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for NewGameEvent
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeNewGameButtonListener(final NewGameButtonListener listener) 
	{ 
		listenerList.remove(NewGameButtonListener.class, listener); 
	}
	
	/**
	 * Method that fire defined NewGameEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireNewGameEvent(final NewGameEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==NewGameButtonListener.class) 
			{ 
				((NewGameButtonListener)listeners[i+1]).newGameEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
}
