# Guilds

Rafael is playing a new and exciting RPG game, and just now noticed the existence of something called Guild. For those who don't know, Guild is about a group of players that get together with a common goal inside the game, taking advantage of working as a team.

The game that Rafael plays has a GVG system (Guild versus Guild) very disputed, and soon he realized that he should take some arrangements to do well at these battles.

The GVG system works as follows: the battle happens between two guilds, and wins the guild that has the greatest amount of points. The number of points that a guild has is given by the sum of the number of points of the players from the guild. Each player has a number of points, that correspond to his current level.

Consider that initially, all the players are part of a guild, containing only the player itself. The union between two guilds makes all the players from both guilds be part of an unique guild, and the other no longer exists.

Given a list of actions in the game, between them union between two guilds and battles between two guilds, say the number of times that the guild in which Rafael is part was victorious of a battle.

## Input
There will be several test cases. Each test case starts with two integers N and M (1 ≤ N ≤ 10⁵, 1 ≤ M ≤ 5 * 10⁵), representing the number of players in the game, and the number of actions in the game, respectively.

Following there will be N integers Pi (1 ≤ Pi ≤ 100), where the i-th number represents the number of points that the i-th player has, for all 1 ≤ i ≤ N. Rafael is always the player 1.

Following, there will be M lines, containing three integers each, Q, A and B (1 ≤ Q ≤ 2, 1 ≤ A, B ≤ N), representing the kind of action, and the two guilds involved at such action. If Q is equal to 1, that means that the guild with the player number A and the guild with the player number B are uniting. If Q is equal to 2, that means that the guild with the player number A and the guild with the player number B will battle.

The last test case is indicated when N = M = 0, which should not be processed.

## Output
For each test case print one line, containing one integer, representing the number of battles at which the guild which Rafael is part won a battle. Notice that ties are not considered victories.

