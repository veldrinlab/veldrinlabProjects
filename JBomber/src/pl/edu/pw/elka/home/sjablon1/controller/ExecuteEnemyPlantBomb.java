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
 * Class represents EnemyPlantBomb event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteEnemyPlantBomb extends ExecuteClass
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
	/** Enemy actual position */
	private PositionDynamic EnemyPosition;
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
	 * Method used to check if Enemy have Bomb to plant.
	 * 
	 * @return true if not.
	 */
	public boolean checkBombToPlant()
	{
		return (!this.getModel().isEnemyBombToPlant());
		
	}
	
	/**
	 * Method used to update Bomb number.
	 */
	public void updateBombNumber()
	{
		this.getModel().decreaseEnemyBombNumber();
		this.getModel().setEnemyWaiting(true);
		this.getModel().decreaseGameSpaceBombNumber();
	}
	
	/**
	 * Method used to get Model data.
	 */
	public void getModelData()
	{
		bombAnimation = new BombAnimation("bombAnimation.png",this.getBlockingEventQueue());
		EnemyPosition = this.getModel().getEnemyPosition();
		bombPosition = null;
	}
	
	/**
	 * Method used to set Bomb Data.
	 */
	public void setBombData()
	{
		if(EnemyPosition.getPositionVertex()==null)
		{
			this.getModel().disactivateVertexState(EnemyPosition.getDestinationVertex());
			bombPosition = new PositionStatic(EnemyPosition.getDestinationVertex());
			int positionId = EnemyPosition.getDestinationVertex().getVertexId();
			int bombPositionX = (positionId%this.getModel().getBoardDimension().getX())*40;
			int bombPositionY = positionId/this.getModel().getBoardDimension().getX()*40; 
			bombAnimation.setxPosition(bombPositionX);
			bombAnimation.setyPosition(bombPositionY);
			
		}
		else
		{
			this.getModel().disactivateVertexState(EnemyPosition.getPositionVertex());
			bombPosition = new PositionStatic(EnemyPosition.getPositionVertex());
			
			SwingUtilities.invokeLater(new Runnable() 
			{
				public void run() 
				{
					bombAnimation.setxPosition(view.getEnemyAnimationDimension().getX());
					bombAnimation.setyPosition(view.getEnemyAnimationDimension().getY());

				}
			});
		}
	}
	
	/**
	 * Method used to update Game View and Model Data.
	 */
	public void updateModelViewData()
	{
		if(EnemyPosition.getPositionVertex()==null)
		{
			this.getModel().disactivateVertexState(EnemyPosition.getDestinationVertex());
			bombPosition = new PositionStatic(EnemyPosition.getDestinationVertex());
			int positionId = EnemyPosition.getDestinationVertex().getVertexId();
			int bombPositionX = (positionId%this.getModel().getBoardDimension().getX())*40;
			int bombPositionY = positionId/this.getModel().getBoardDimension().getX()*40; 
			bombAnimation.setxPosition(bombPositionX);
			bombAnimation.setyPosition(bombPositionY);
			
		}
		else
		{
			this.getModel().disactivateVertexState(EnemyPosition.getPositionVertex());
			bombPosition = new PositionStatic(EnemyPosition.getPositionVertex());
			
			SwingUtilities.invokeLater(new Runnable() 
			{
				public void run() 
				{
					bombAnimation.setxPosition(view.getEnemyAnimationDimension().getX());
					bombAnimation.setyPosition(view.getEnemyAnimationDimension().getY());

				}
			});
		}
		
		
		int iterator = 0;
		PositionStatic[] bombPositionArray = this.getModel().getBombPositionArray();
		Bomb[] bombArray = this.getModel().getBombArray();
		final BombAnimation[] bombAnimationArray = this.getView().getBombAnimationArray();
		
		while(iterator < bombArray.length)
		{
			if(bombPositionArray[iterator]==null)
				break;
			iterator++;
		}
		
		bombPositionArray[iterator] = bombPosition;
		bombArray[iterator] = new Bomb(this.getModel().getEnemyBombExplosionLevel(),BombExploadingState.Planted);
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
	 * @return the blockingEventQueue
	 */
	public ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	public void setBlockingEventQueue(
			ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}

	/**
	 * @return the bombAnimation
	 */
	public BombAnimation getBombAnimation()
	{
		return bombAnimation;
	}

	/**
	 * @param bombAnimation the bombAnimation to set
	 */
	public void setBombAnimation(BombAnimation bombAnimation)
	{
		this.bombAnimation = bombAnimation;
	}

	/**
	 * @return the enemyPosition
	 */
	public PositionDynamic getEnemyPosition()
	{
		return EnemyPosition;
	}

	/**
	 * @param enemyPosition the enemyPosition to set
	 */
	public void setEnemyPosition(PositionDynamic enemyPosition)
	{
		EnemyPosition = enemyPosition;
	}

	/**
	 * @return the bombPosition
	 */
	public PositionStatic getBombPosition()
	{
		return bombPosition;
	}

	/**
	 * @param bombPosition the bombPosition to set
	 */
	public void setBombPosition(PositionStatic bombPosition)
	{
		this.bombPosition = bombPosition;
	}
	
}
