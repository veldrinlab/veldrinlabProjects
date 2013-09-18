package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Enumeration that defines Enemy AI state in witch is Enemy.
 * @author Szymon Jablonski
 * @version 1.0
 */
public enum EnemyAIState
{
	Thinking 
	{
		@Override
		public EnemyAIState getNextState()
		{
			return EnemyAIState.Thinking;
		}
	}, 
	PlantingBomb 
	{
		@Override
		public EnemyAIState getNextState()
		{
			return EnemyAIState.Runnig;
		}
	}, 
	Runnig 
	{
		@Override
		public EnemyAIState getNextState()
		{

			return EnemyAIState.Safe;
		}
	},
	Safe 
	{
		@Override
		public EnemyAIState getNextState()
		{
			return EnemyAIState.Thinking;
		}
	};
	
	/**
	 * Abstract method of State pattern implemented by EnemyAItate, use to get next state.
	 * 
	 * @return next AI state
	 */
	public abstract EnemyAIState getNextState();
}
