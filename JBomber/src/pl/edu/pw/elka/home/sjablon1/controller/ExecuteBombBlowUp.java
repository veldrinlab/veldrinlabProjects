package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.Bomb;
import pl.edu.pw.elka.home.sjablon1.model.BombExploadingState;
import pl.edu.pw.elka.home.sjablon1.model.Explosion;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionState;
import pl.edu.pw.elka.home.sjablon1.model.Model;
import pl.edu.pw.elka.home.sjablon1.model.PositionStatic;
import pl.edu.pw.elka.home.sjablon1.view.BombAnimation;
import pl.edu.pw.elka.home.sjablon1.view.ExplosionAnimation;
import pl.edu.pw.elka.home.sjablon1.view.View;
import pl.edu.pw.elka.home.sjablon1.view.event.ExplosionStartEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents BombBlowUp event execute visitable class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExecuteBombBlowUp extends ExecuteClass
{
	/**Game Model object */
	private Model model;
	/**Game View object */
	private View view;
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	/** Array of Bombs on GameBoard */
	private Bomb[] bombArray;
	/** Array of Bombs positions */
	private PositionStatic[] bombPosition;
	/** Array of BombAnimations */
	private BombAnimation[] bombAnimationArray;
	
	/**
	 * This is the entry point which enables an object to be visited the visitor object. 
	 */
	public void accept(Visitor v,Model model, View view, ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setModel(model);
		this.setView(view);
		this.setBlockingEventQueue(blockingEventQueue);
		v.visit( this );
	}
	
	/**
	 * Method used to get Bomb data.
	 */
	public void getBombData()
	{
		bombArray = this.getModel().getBombArray();
		bombPosition = this.getModel().getBombPositionArray();
		bombAnimationArray = this.getView().getBombAnimationArray();
	}
	
	/**
	 * Method used to execute Bomb Blow up event.
	 */
	public void executeBombBlow()
	{
		int number = 0;
		for(int i = 0; i<bombArray.length; i++)
		{
			if(bombArray[i] != null && bombArray[i].getBombState() == BombExploadingState.Blow)
			{
				number++;
				/** Make new ExplosionAnimation object instance*/
				ExplosionAnimation explosionAnimation = new ExplosionAnimation("explosion.png",this.getBlockingEventQueue());
				explosionAnimation.setVisible(false);
				PositionStatic explosionPosition = bombPosition[i];

				int iterator = 0;
				PositionStatic[] explosionPositionArray = this.getModel().getExplosionPositionArray();
				Explosion[] explosionArray = this.getModel().getExplosionArray();
				ExplosionAnimation[] explosionAnimationArray = this.getView().getExposionAnimationArray();
				
				while(explosionPositionArray[iterator]!=null)
					iterator++;
				
				
				explosionPositionArray[iterator] = explosionPosition;
				explosionArray[iterator] = new Explosion(bombArray[i].getBombExplosionPower(), ExplosionState.Start);
				explosionAnimationArray[iterator] = explosionAnimation;
					
				this.getModel().updateExplosionData(explosionPositionArray, explosionArray);
				this.getView().udpateExplosionViewData(explosionAnimation, explosionAnimationArray);
	
				bombAnimationArray[i].stopAnimation();
				bombAnimationArray[i].setVisible(false);
				bombAnimationArray[i] = null;
				this.getModel().activateVertexState(bombPosition[i].getPositionVertex());
				bombArray[i] = null;
				bombPosition[i] = null;

				this.getModel().updateBombData(bombPosition, bombArray);
				
				/** Return bomb to Player/Enemy */
				if(this.getModel().isPlayerWaitig())
				{
					this.getModel().increasePlayerBombNumber();
					this.getModel().setPlayerWaiting(false);
				}
				else
				{
					this.getModel().increaseEnemyBombNumber();
					this.getModel().setEnemyWaiting(false);
				}

			}
		}
		if(number>0)
			this.getBlockingEventQueue().add(new ExplosionStartEvent(this));
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
