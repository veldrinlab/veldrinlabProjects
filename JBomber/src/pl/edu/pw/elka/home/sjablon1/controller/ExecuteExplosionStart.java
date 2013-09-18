package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.LinkedList;
import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Explosion;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.PositionStatic;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.utility.Pair;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents ExplosionStart event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteExplosionStart extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** Explosion position array */
	private PositionStatic[] explosionPosition;
	/** Array of Explosion on GameBoard */
	private Explosion[] explosionArray;
	
	
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
	 * Method used to get Explosion Data.
	 */
	public void getExplosionData()
	{
		explosionPosition = this.getModel().getExplosionPositionArray();
		explosionArray = this.getModel().getExplosionArray();
	}
	
	
	/**
	 * Method used to execute Explosion Start.

	 */
	public void executeExplosionStart()
	{
		for(int i = 0; i<explosionArray.length; i++)
		{
			if(explosionArray[i]!=null && explosionArray[i].getExplosionState()==ExplosionState.Start)
			{
				/** Set ExplosionAnimation position and range */
				LinkedList<Pair> explosionRange = new LinkedList<Pair>();
				LinkedList<Vertex> explosionVertex = new LinkedList<Vertex>();
				
				/** Set center explosion */
				int positionId = explosionPosition[i].getPositionVertex().getVertexId();
				int explosionPositionX = (positionId%this.getModel().getBoardDimension().getX())*40;
				int explosionPositionY = positionId/this.getModel().getBoardDimension().getX()*40; 

				explosionRange.add(new Pair(explosionPositionX,explosionPositionY));
				
				/** Set left,right,up,down explosions */
				if(explosionPosition[i].getPositionVertex().getLeftDestination()!=null)
				{
					explosionVertex.add(explosionPosition[i].getPositionVertex().getLeftDestination());
					explosionRange.add(new Pair(explosionPositionX-40,explosionPositionY));
				}
				if(explosionPosition[i].getPositionVertex().getRightDestination()!=null)
				{
					explosionVertex.add(explosionPosition[i].getPositionVertex().getRightDestination());
					explosionRange.add(new Pair(explosionPositionX+40,explosionPositionY));
				}
				if(explosionPosition[i].getPositionVertex().getUpDestination()!=null)
				{
					explosionVertex.add(explosionPosition[i].getPositionVertex().getUpDestination());
					explosionRange.add(new Pair(explosionPositionX,explosionPositionY-40));
				}
				if(explosionPosition[i].getPositionVertex().getDownDestination()!=null)
				{
					explosionVertex.add(explosionPosition[i].getPositionVertex().getDownDestination());
					explosionRange.add(new Pair(explosionPositionX,explosionPositionY+40));
				}
				
				this.getModel().updateExplosionRangeData(i, explosionVertex);
				this.getModel().increaseExposionNumber();
				this.getView().startExplosionAnimation(i, explosionRange);
			}
		}
	}

	/**
	 * @param model the model to set
	 */
	public void setModel(Model model)
	{
		this.model = model;
	}

	/**
	 * @return the model
	 */
	public Model getModel()
	{
		return model;
	}

	/**
	 * @param view the view to set
	 */
	public void setView(View view)
	{
		this.view = view;
	}

	/**
	 * @return the view
	 */
	public View getView()
	{
		return view;
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
