package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.SwingUtilities;

import pl.edu.pw.elka.home.sjablon1.model.Destination;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents PlayerMoveDown event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecutePlayerMoveDown extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/** Player actual destination */
	private Destination actualDestination;
	/** Player actual position on Graph */
	private Vertex actualPosition;
	/** Player actual destination Vertex on Graph */
	private Vertex destination;
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		this.setView(view);
		v.visit( this );
	}
	
	/**
	 * Method used to get Player actual data from Game Model.
	 */
	public void getPlayerData()
	{
		this.actualDestination = this.getModel().getPlayerActualDestination();
		this.actualPosition = this.getModel().getPlayerActualPosition();
		this.destination = this.getModel().getPlayerActualDestinationVertex();
	}
	
	/**
	 * Method used to check if Player wants to move in forbidden way.
	 * 
	 * @return true if Player wants to in forbidden destination.
	 */
	public boolean checkForbiddenDestination()
	{
		return (actualPosition == null &&(actualDestination == Destination.Left || 
				actualDestination == Destination.Right));
		
	}
	
	/**
	 * Method used to change Player actual move destination data.
	 */
	public void changeDestination()
	{
		if(actualPosition != null && actualDestination != Destination.Down)
		{
			this.getModel().setPlayerActualDestination(Destination.Down);
			this.getModel().setPlayerActualDestinationVertex(actualPosition.getDownDestination());

		}
		
		if(actualPosition == null && actualDestination == Destination.Up)
		{
			Boolean changeDestination = this.getModel().isPlayerChangedDestination();
			this.getModel().setPlayerActualDestination(Destination.Down);
			this.getModel().setPlayerActualDestinationVertex(destination.getDownDestination());
			this.getModel().setPlayerChangeDestination(!changeDestination);
		}
	}
	
	/**
	 * Method used to update Player Animation data.
	 */
	public void updateAnimationSpriteData()
	{
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				view.setPlayerAnimationDestination(0, 8);

			}
		});
	}
	
	/**
	 * Method used to check if moving Player wants to move opposite side.
	 * 
	 * @return true if it wants to.
	 */
	public boolean checkMovingOppositeSide()
	{
		return (this.getModel().getPlayerActualDestination() == Destination.Up);
	}
	
	/**
	 * Method that executes Player moving event.
	 */
	public void executePlayerMoving()
	{
		if(this.getModel().getPlayerActualDestinationVertex()!=null 
				&& this.getModel().getPlayerActualDestinationVertex().isStateActive())
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				view.startPlayerAnimation();

			}
		});
	}
	
	/**
	 * Method used to check if Player is actually moving.
	 * 
	 * @return true if moving
	 */
	public boolean checkIsPlayerMoving()
	{
		return this.getView().isPlayerMoving();
		
	}
	
	/**
	 * @return the model
	 */
	public Model getModel()
	{
		return model;
	}

	/**
	 * @param model the model to set
	 */
	public void setModel(Model model)
	{
		this.model = model;
	}

	/**
	 * @return the view
	 */
	public View getView()
	{
		return view;
	}

	/**
	 * @param view the view to set
	 */
	public void setView(View view)
	{
		this.view = view;
	}

	/**
	 * @return the actualDestination
	 */
	public Destination getActualDestination()
	{
		return actualDestination;
	}

	/**
	 * @param actualDestination the actualDestination to set
	 */
	public void setActualDestination(Destination actualDestination)
	{
		this.actualDestination = actualDestination;
	}

	/**
	 * @return the actualPosition
	 */
	public Vertex getActualPosition()
	{
		return actualPosition;
	}

	/**
	 * @param actualPosition the actualPosition to set
	 */
	public void setActualPosition(Vertex actualPosition)
	{
		this.actualPosition = actualPosition;
	}

	/**
	 * @return the destination
	 */
	public Vertex getDestination()
	{
		return destination;
	}

	/**
	 * @param destination the destination to set
	 */
	public void setDestination(Vertex destination)
	{
		this.destination = destination;
	}
		
}
