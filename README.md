# Treasure-Hunter-Game

* A treasure hunter is trying to find diamonds in a 10x10 field. Each diamond is guarded by a soldier. 
The aim of the hunter is to collect the diamonds without being caught by the soldiers.

* The hunter's starting position on the board is fixed. So each time the game starts, the hunter's position will be (2,4).

* There are 5 diamonds on the field and these diamonds must be placed in random cells when the game first starts. The player will not see the diamonds on the board. While diamonds are randomly assigned to cells, it should be prevented that more than one diamond coincide with the same cell. (You can use the rand() function to determine a random position).

* Every diamond has a guardian. This guard will be randomly placed in one of the cells adjacent to the diamond. Even if 2 diamonds are randomly placed on adjacent positions on the board, they will each have a separate guardian and a guardian cannot be in the same cell with another guardian or diamond.

* What the player has to do is to move on the board using the right, left, up and down keys and find the cell with the diamond without being caught by the guard. The player cannot go diagonally.

* If the player hits the guard, he returns to the starting position (2,4) as a penalty. It can come across as a guard up to 3 times. If he hits the guard again for the 4th time, he loses the game.

* A single user will play the game. In other words, you will choose which direction the hunter will advance with the arrow keys during the game. Therefore, the locations of the diamonds and guards will be randomly determined when the game first starts, and the player must not see their location. However, he can decide where to go with the distance information to the diamonds at every step.

* After each step of the hunter, information about the game board and the location of the diamonds should be printed on the screen. (Diamonds and guards will not be visible in this printed chart.)

* Diamonds or guards cannot be outside the game board. The hunter cannot leave the game board.
