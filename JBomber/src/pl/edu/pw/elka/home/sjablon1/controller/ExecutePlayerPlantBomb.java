package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.SwingUtilities;

import pl.edu.pw.elka.home.sjablon1.model.Bomb;
import pl.edu.pw.elka.home.sjablon1.model.BombExploadingState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.PositionDynamic;
import pl.edu.pw.elka.home.sjablon1.model.PositionStatic;
import pl.edu.pw.elka.home.sjablon1.view.BombAnimation;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents PlayerPlantBomb event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecutePlayerPlantBomb extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** New Bomb Animation */
	private BombAnimation bombAnimation;
	/** Player actual position */
	private PositionDynamic playerPosition;
	/** Position to plant bomb */
	private PositionStatic bombPosition;
	
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setBlockingEventQueue(blockingEventQueue);
		this.setModel(model);
		this.setView(view);
		v.visit( this );
	}

	/**
	 * Method used to check if Player have Bomb to plant.
	 * 
	 * @return true if not.
	 */
	public boolean checkBombToPlant()
	{
		return (!this.getModel().isPlayerBombToPlant());
		
	}
	
	/**
	 * Method used to update Bomb number.
	 */
	public void updateBombNumber()
	{
		this.getModel().decreasePlayerBombNumber();
		this.getModel().setPlayerWaiting(true);
		this.getModel().decreaseGameSpaceBombNumber();
	}
	
	/**
	 * Method used to get Model data.
	 */
	public void getModelData()
	{
		bombAnimation = new BombAnimation("bombAnimation.png",this.getBlockingEventQueue());
		playerPosition = this.getModel().getPlayerPosition();
		bombPosition = null;
	}
	
	/**
	 * Method used to set Bomb Data.
	 */
	public void setBombData()
	{
		if(playerPosition.getPositionVertex()==null)
		{
			this.getModel().disactivateVertexState(playerPosition.getDestinationVertex());
			bombPosition = new PositionStatic(playerPosition.getDestinationVertex());
			int positionId = playerPosition.getDestinationVertex().getVertexId();
			int bombPositionX = (positionId%this.getModel().getBoardDimension().getX())*40;
			int bombPositionY = positionId/this.getModel().getBoardDimension().getX()*40; 
			bombAnimation.setxPosition(bombPositionX);
			bombAnimation.setyPosition(bombPositionY);
			
		}
		else
		{
			this.getModel().disactivateVertexState(playerPosition.getPositionVertex());
			bombPosition = new PositionStatic(playerPosition.getPositionVertex());
			
			SwingUtilities.invokeLater(new Runnable() 
			{
				public void run() 
				{
					bombAnimation.setxPosition(view.getPlayerAnimationDimension().getX());
					bombAnimation.setyPosition(view.getPlayerAnimationDimension().getY());

				}
			});
		}
	}
	
	/**
	 * Method used to update Game View and Model Data.
	 */
	public void updateModelViewData()
	{
		if(playerPosition.getPositionVertex()==null)
		{
			this.getModel().disactivateVertexState(playerPosition.getDestinationVertex());
			bombPosition = new PositionStatic(playerPosition.getDestinationVertex());
			int positionId = playerPosition.getDestinationVertex().getVertexId();
			int bombPositionX = (positionId%this.getModel().getBoardDimension().getX())*40;
			int bombPositionY = positionId/this.getModel().getBoardDimension().getX()*40; 
			bombAnimation.setxPosition(bombPositionX);
			bombAnimation.setyPosition(bombPositionY);
			
		}
		else
		{
			this.getModel().disactivateVertexState(playerPosition.getPositionVertex());
			bombPosition = new PositionStatic(playerPosition.getPositionVertex());
			
			SwingUtilities.invokeLater(new Runnable() 
			{
				public void run() 
				{
					bombAnimation.setxPosition(view.getPlayerAnimationDimension().getX());
					bombAnimation.setyPosition(view.getPlayerAnimationDimension().getY());

				}
			});
		}
		
		
		int iterator = 0;
		PositionStatic[] bombPositionArray = this.getModel().getBombPositionArray();
		Bomb[] bombArray = this.getModel().getBombArray();
		
		final BombAnimation[] bombAnimationArray = this.getView().getBombAnimationArray();
		
		while(iterator < 10)
		{
			if(bombPositionArray[iterator]==null)
				break;
			iterator++;
		}
		
		bombPositionArray[iterator] = bombPosition;
		bombArray[iterator] = new Bomb(this.getModel().getPlayerBombExplosionLevel(),BombExploadingState.Planted);
		bombAnimationArray[iterator] = bombAnimation;
		
		this.getModel().updateBombData(bombPositionArray, bombArray);
		
		SwingUtilities.invokeLater(new Runnable() 
		{
			public void run() 
			{
				view.udpateBombViewData(bombAnimation, bombAnimationArray);

			}
		});
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
