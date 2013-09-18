package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Enumeration that defines animation states in which is Explosion.
 * @author Szymon Jablonski
 * @version 1.0
 */
public enum ExplosionState
{
	Start
	{
		@Override
		public ExplosionState getNextState()
		{
			return ExplosionState.Full;
		}
	},
	Full 
	{
		@Override
		public ExplosionState getNextState()
		{
			return ExplosionState.End;
		}
	},
	End 
	{
		@Override
		public ExplosionState getNextState()
		{
			return null;
		}
	};
	
	/**
	 * Abstract method of State pattern implemented by ExplosionState, use to get next state
	 * 
	 * @return next Explosion state
	 */
	public abstract ExplosionState getNextState();
}
