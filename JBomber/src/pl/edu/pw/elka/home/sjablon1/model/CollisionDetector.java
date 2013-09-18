package pl.edu.pw.elka.home.sjablon1.model;

import java.util.LinkedList;

/**
 * Class represents main Game collision detector. Controller run CollsisionDetector each time
 * when Game TimeQuantumExceeded object is created. Class is used to check all type of Collision
 * and to generate unique collision objects for each type of collision for example Explosion with 
 * brick collision. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class CollisionDetector
{
	/** Game MVC Model unit */
	private Model model;

	/**
	 * Default constructor of CollisionDetector object
	 * 
	 * @param model is game Model Unit
	 */
	public CollisionDetector(Model model)
	{
		this.setModel(model);
	}
	
	/**
	 * Method used to check Explosion with Brick collision.
	 * 
	 * @return detected collision object list.
	 */
	public LinkedList<ExplosionBrickCollision> detectExplosionWithBrickCollision()
	{
		LinkedList<ExplosionBrickCollision> collisionList = new LinkedList<ExplosionBrickCollision>();
		Explosion[] explosionArray = this.getModel().getExplosionArray();
		for(int i=0; i<explosionArray.length;i++)
		{
			if(explosionArray[i]!= null)
			{				
				LinkedList<Vertex> rangeList = explosionArray[i].getExplosionVertex();
				if(rangeList != null)
				{
					for(int j=0; j < rangeList.size(); j++)
					{
						Vertex vertex = rangeList.get(j);
						if(!vertex.isStateActive())
							collisionList.add(new ExplosionBrickCollision(vertex));
					}
				}
			}
		}
		
		return collisionList;	
	}
	
	/**
	 * Method used to check Explosion with Player collision.
	 * 
	 * @return detected collision object.
	 */
	public ExplosionPlayerCollision detectExplosionWithPlayerCollision()
	{
		Explosion[] explosionArray = this.getModel().getExplosionArray();
		for(int i=0; i<explosionArray.length; i++)
		{
			if(explosionArray[i]!= null)
			{
				LinkedList<Vertex> rangeList = explosionArray[i].getExplosionVertex();
				if(rangeList != null)
				{
					for(int j=0; j < rangeList.size(); j++)
					{
						Vertex vertex = rangeList.get(j);
						if(this.getModel().getPlayerActualPosition()!= null &&
							this.getModel().getPlayerActualPosition().getVertexId() == vertex.getVertexId())
						return new ExplosionPlayerCollision(vertex);
					}
				}
			}
		}
		return null;	
	}
	
	/**
	 * Method used to check Explosion with Enemy collision.
	 * 
	 * @return detected collision object.
	 */
	public ExplosionEnemyCollision detectExplosionWithEnemyCollision()
	{
		Explosion[] explosionArray = this.getModel().getExplosionArray();
		for(int i=0; i<explosionArray.length; i++)
		{
			if(explosionArray[i]!= null)
			{
				LinkedList<Vertex> rangeList = explosionArray[i].getExplosionVertex();
				if(rangeList != null)
				{
					for(int j=0; j < rangeList.size(); j++)
					{
						Vertex vertex = rangeList.get(j);
						if(this.getModel().getEnemyActualPosition() != null &&
							this.getModel().getEnemyActualPosition().getVertexId() == vertex.getVertexId())
						return new ExplosionEnemyCollision(vertex);
					}
				}
			}
		}
		return null;	
	}
	
	/**
	 * Method used to check Player with PowerUp collision.
	 * 
	 * @return detected collision object.
	 */
	public PlayerPowerUpCollision detectPlayerPowerUpCollision()
	{
		if(this.getModel().getBombPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getBombPowerUpPosition().length; i++)
			{
				if(this.getModel().getBombPowerUpPosition()[i]!= null &&
						this.getModel().getBombPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getPlayerActualPosition())
					return new PlayerPowerUpCollision(this.getModel().getPlayerActualPosition(),i,1);
			}
		}
		if(this.getModel().getSpeedPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getSpeedPowerUpPosition().length; i++)
			{
				if(this.getModel().getSpeedPowerUpPosition()[i]!=null &&
						this.getModel().getSpeedPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getPlayerActualPosition())
					return new PlayerPowerUpCollision(this.getModel().getPlayerActualPosition(),i,2);

			}
		}
		if(this.getModel().getExplosionPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getExplosionPowerUpPosition().length; i++)
			{
				if(this.getModel().getExplosionPowerUpPosition()[i]!=null &&
						this.getModel().getExplosionPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getPlayerActualPosition())
					return new PlayerPowerUpCollision(this.getModel().getPlayerActualPosition(),i,3);
			}
		}
		
		return null;
	}
	
	/**
	 * Method used to check Enemy with PowerUp collision.
	 * 
	 * @return detected collision object.
	 */
	public EnemyPowerUpCollision detectEnemyPowerUpCollision()
	{
		if(this.getModel().getBombPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getBombPowerUpPosition().length; i++)
			{
				if(this.getModel().getBombPowerUpPosition()[i]!= null &&
						this.getModel().getBombPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getEnemyActualPosition())
					return new EnemyPowerUpCollision(this.getModel().getEnemyActualPosition(),i,1);
			}
		}
		if(this.getModel().getSpeedPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getSpeedPowerUpPosition().length; i++)
			{
				if(this.getModel().getSpeedPowerUpPosition()[i]!=null &&
						this.getModel().getSpeedPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getEnemyActualPosition())
					return new EnemyPowerUpCollision(this.getModel().getEnemyActualPosition(),i,2);

			}
		}
		if(this.getModel().getExplosionPowerUpNumber()!=0)
		{
			for(int i = 0; i<this.getModel().getExplosionPowerUpPosition().length; i++)
			{
				if(this.getModel().getExplosionPowerUpPosition()[i]!=null &&
						this.getModel().getExplosionPowerUpPosition()[i].getPositionVertex()
						==this.getModel().getEnemyActualPosition())
					return new EnemyPowerUpCollision(this.getModel().getEnemyActualPosition(),i,3);
			}
		}
		
		return null;
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
	
}
