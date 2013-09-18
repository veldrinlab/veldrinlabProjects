package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.SwingUtilities;

import pl.edu.pw.elka.home.sjablon1.model.Destination;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents EnemyMoveLeft event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteEnemyMoveLeft extends ExecuteClass
{
	/**Game Model object */
	 private Model model;
	/**Game View object */
	 private View view;
	/** Enemy actual destination */
	 private Destination actualDestination;
	/** Enemy actual position on Graph */
	 private Vertex actualPosition;
	/** Enemy actual destination Vertex on Graph */
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
	 * Method used to get Enemy actual data from Game Model.
	 */
	public void getEnemyData()
	{
		this.actualDestination = this.getModel().getEnemyActualDestination();
		this.actualPosition = this.getModel().getEnemyActualPosition();
		this.destination = this.getModel().getEnemyActualDestinationVertex();
	}
	
	/**
	 * Method used to check if Enemy wants to move in forbidden way.
	 * 
	 * @return true if Enemy wants to in forbidden destination.
	 */
	public boolean checkForbiddenDestination()
	{
		return (actualPosition == null &&(actualDestination == Destination.Up || 
				actualDestination == Destination.Down));
		
	}
	
	/**
	 * Method used to change Enemy actual move destination data.
	 */
	public void changeDestination()
	{
		if(actualPosition != null && actualDestination != Destination.Left)
		{
			this.getModel().setEnemyActualDestination(Destination.Left);
			this.getModel().setEnemyActualDestinationVertex(actualPosition.getLeftDestination());

		}
		
		if(actualPosition == null && actualDestination == Destination.Right)
		{
			Boolean changeDestination = this.getModel().isEnemyChangedDestination();
			this.getModel().setEnemyActualDestination(Destination.Left);
			this.getModel().setEnemyActualDestinationVertex(destination.getLeftDestination());
			this.getModel().setEnemyChangeDestination(!changeDestination);
		}
	}
	
	/**
	 * Method used to update Enemy Animation data.
	 */
	public void updateAnimationSpriteData()
	{
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				view.setEnemyAnimationDestination(-8, 0);

			}
		});
	}
	
	/**
	 * Method used to check if moving Enemy wants to move opposite side.
	 * 
	 * @return true if it wants to.
	 */
	public boolean checkMovingOppositeSide()
	{
		return (this.getModel().getEnemyActualDestination() == Destination.Right);
	}
	
	/**
	 * Method used to check if Enemy is actually moving.
	 * 
	 * @return true if moving
	 */
	public boolean checkIsEnemyMoving()
	{
		return this.getView().isEnemyMoving();
		
	}
	/**
	 * Method that executes Enemy moving event.
	 */
	public void executeEnemyMoving()
	{
		if(this.getModel().getEnemyActualDestinationVertex()!=null 
				&& this.getModel().getEnemyActualDestinationVertex().isStateActive())
			SwingUtilities.invokeLater(new Runnable() 
			{
				public void run() 
				{
						view.startEnemyAnimation();

				}
			});
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