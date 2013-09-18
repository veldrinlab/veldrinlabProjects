package pl.edu.pw.elka.home.sjablon1.view;

import java.util.concurrent.BlockingQueue;
import javax.swing.JButton;
import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.OptionsButtonListener;
import pl.edu.pw.elka.home.sjablon1.view.event.menu.OptionsEvent;


/**
 * Class represents object of OptionsButton that generate OptionsEvent. It is one of
 * four buttons from MenuButtonPanel.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class OptionsButton extends JButton
{
		
	/**List of objects listeners*/
	private EventListenerList listenerList;

	/**
	 * Default constructor of OptionsButton object. It creates instance of OptionsButton class
	 * with custom backgroundImage, and add additional Listener for OptionsEvent witch is fired
	 * by actionPerformed method of JButton
	 */
	public OptionsButton()
	{
		super("   Options  ");
		listenerList = new EventListenerList();
		this.addOptionsButtonListener(new OptionsButtonListener());
		
	}
		
	/**
	 * Method that allows classes to register for OptionsEvents
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addOptionsButtonListener(final OptionsButtonListener listener)
	{ 
		listenerList.add(OptionsButtonListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for OptionsEvent
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeOptionsButtonListener(final OptionsButtonListener listener) 
	{ 
		listenerList.remove(OptionsButtonListener.class, listener); 
	}
	
	/**
	 * Method that fire defined OptionsEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireOptionsEvent(final OptionsEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==OptionsButtonListener.class) 
			{ 
				((OptionsButtonListener)listeners[i+1]).optionsEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
}
