package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Toolkit;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import javax.swing.event.EventListenerList;

import pl.edu.pw.elka.home.sjablon1.view.event.BombBlowUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.BombBlowUpListener;
import pl.edu.pw.elka.home.sjablon1.view.event.BombChangeStateEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.BombChangeStateListener;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;

;

/**
 * Class represents BombAnimation view. There are one of static animation, Bomb can be plant only on
 * GameGraph Vertex. After small amount of time, Bomb blow generates Explosion Object. When Bomb is placed
 * on Vertex it stateActive is false.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BombAnimation extends Animation
{	
	/** List of objects listeners*/
	private EventListenerList listenerList;
	/** Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	/**
	 * Default constructor of BombAnimation object.
	 * 
	 * @param bombSpriteScheetFileName name of file contains animation SpriteSheet
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public BombAnimation(final String bombSpriteScheetFileName, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
        this.setBackground(Color.WHITE);
        this.setDoubleBuffered(true);
        this.setSize(680, 520);
        this.setOpaque(false);
      
		this.setAnimatingSprite(new Sprite(bombSpriteScheetFileName));
		
		this.setBlockingEventQueue(blockingEventQueue);
		this.setListenerList(new EventListenerList());
		this.addBombChangeStateListener(new BombChangeStateListener());
		this.addBombBlowUpListener(new BombBlowUpListener());
		this.setAnimationRolling(false);
	}
	

	@Override
	/**
	 * Method defines what parameters change in each animationCycle. 
	 */
	public void animationCycle()
	{
		int newFrameX = this.getAnimatingSprite().getSpritePositionX();
		int newFrameY = this.getAnimatingSprite().getSpritePositionY();
		
		if(newFrameX == 0)
			newFrameX += 40;
		else if(newFrameX == 40)
			newFrameX += 40;
		else
			newFrameX = 0;
			
		
		this.getAnimatingSprite().setSpritePositionX(newFrameX);
		this.getAnimatingSprite().setSpritePositionY(newFrameY);
	}

	@Override
	/**
	 * Method used to start animation.
	 */
	public void startAnimation()
	{
		this.setAnimationRolling(true);
		this.runAnimation();
		
	}

	@Override
	/**
	 * Method used to stop animation.
	 */
	public void stopAnimation()
	{
		this.setAnimationRolling(false);
	}
	
	@Override
	/**
	 * Override method that paints Animation Frame.
	 * 
	 * @param g is Graphics context. 
	 */
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D)g;
        
        Image drawSource = this.getAnimatingSprite().getSpriteSheet();
        int destX1 = this.getxPosition();
        int destY1 = this.getyPosition();
        int destX2 = destX1 + this.getAnimatingSprite().getSpriteWidth();
        int destY2 = destY1 + this.getAnimatingSprite().getSpriteHeight();
        int srcX1 = this.getAnimatingSprite().getSpritePositionX();
        int srcY1 = this.getAnimatingSprite().getSpritePositionY();
        int srcX2 = srcX1 + this.getAnimatingSprite().getSpriteWidth();
        int srcY2 = srcY1 + this.getAnimatingSprite().getSpriteHeight();
        
        g2d.drawImage(drawSource,destX1,destY1,destX2,destY2,srcX1,srcY1,srcX2,srcY2,this);
        Toolkit.getDefaultToolkit().sync();
        g.dispose();
    }

	
	/**
	 * Method that runs animation
	 *
	*/
	public void runAnimation()
	{
		animationCycle();
	    repaint();
  
	}
	
	/**
	 * Method that allows classes to register for BombBlowUpListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addBombBlowUpListener(final BombBlowUpListener listener)
	{ 
		listenerList.add(BombBlowUpListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for BombBlowUpListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeBombBlowUpListener(final BombBlowUpListener listener) 
	{ 
		listenerList.remove(BombBlowUpListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to register for BombChangeStateListener
	 * 
	 * @param listener is object of listener that will added to ListenerList
	 */
	public void addBombChangeStateListener(final BombChangeStateListener listener)
	{ 
		listenerList.add(BombChangeStateListener.class, listener); 
	}
	
	/**
	 * Method that allows classes to unregister for BombChangeStateListener
	 * 
	 * @param listener is object of listener that will be removed from ListenerList
	 */
	public void removeBombChangeStateListener(final BombChangeStateListener listener) 
	{ 
		listenerList.remove(BombChangeStateListener.class, listener); 
	}
	
	
	/**
	 * Method that fire defined BombChangeStateEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireBombChangeStateEvent(final BombChangeStateEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==BombChangeStateListener.class) 
			{ 
				((BombChangeStateListener)listeners[i+1]).bombChangeStateEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * Method that fire defined BombBlowUpEvent
	 * 
	 * @param event is object of Event that will be fired  
	 */
	public void fireBombBlowUpEvent(final BombBlowUpEvent event,BlockingQueue<GameEvent> blockingEventQueue)
	{ 
		Object[] listeners = listenerList.getListenerList(); 
		for (int i=0; i<listeners.length; i+=2) 
		{
			if (listeners[i]==BombBlowUpListener.class) 
			{ 
				((BombBlowUpListener)listeners[i+1]).bombBlowUpEventOccurred(event,blockingEventQueue); 
			} 
		} 
	}
	
	/**
	 * @param listenerList the listenerList to set
	 */
	public void setListenerList(final EventListenerList listenerList)
	{
		this.listenerList = listenerList;
	}

	/**
	 * @return the listenerList
	 */
	public EventListenerList getListenerList()
	{
		return listenerList;
	}


	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	public void setBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}

	/**
	 * @return the blockingEventQueue
	 */
	public ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

}
