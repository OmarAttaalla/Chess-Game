# Chess Game
 
Authors: [Ethan Wan](https://github.com/ELW123),
         [Bobby Nguyen](https://github.com/HollowGrimm),
         [Lucyann Lacdan](https://github.com/Llucy14),
         [Omar Attaalla](https://github.com/OmarAttaalla)
 
## Project Description
Why is it important or interesting to you?
* The learning experience we will get from making a user interface game

What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
* Languages:
  * C++
* Tools
  * VS Code
  * Qt Creator
* Technologies
  * Windows OS  
Input will always be mouse click. Output will be either the movement of a chess piece or execution of a main menu button (e.g. "new game" sets up a fresh board)  

Features:
* Must have:
  * 2-player Chess game
  * Option to undo moves
  * Main menu
  * Functioning GUI to display the board and its pieces
* Want to have:
  * Saving and loading game
  * Display possible places to move after Chess piece selected
  * Animations for Chess pieces when moving

## Class Diagram
![UML Diagram (3)](https://user-images.githubusercontent.com/51334912/155409991-dd7555f3-43f9-4700-a321-74ac01e69200.png)
* ChessBoard
  * ChessBoard is a class that encapsulates a list of squares and a list of setPieces. It includes an InitialCreate() function which initializes 2 SetPieces objects and a list of 64 Squares.
  * SetPieces
    * SetPieces is a class that initializes a list of the of the chess pieces that will appear on the board and the color of the team they will be a part of. It also includes a function for creating singular pieces (which is meant to be used by the pawn) and a getter function to call the color variable.
  * Square
    * Square is a class that determines the position of the squares that appear on the chess board. It includes getter functions that call the row and column of a square. This class can be used to determine the positions of the pieces during the game.
* ChessPiece
  * ChessPiece is an abstract class that encapsulates the virtual functions, Moves() and scan(). The Moves() function allows the player to move a piece to a square of their choice. The scan helper function calculates all the possible spaces that a piece can move towards and stores it in an array. It also includes the pieceDeath() function that determines whether or not a piece has been captured or not. This class is inherited by the subclasses of each piece.
  * King
    * King is a subclass of ChessPiece and encapsulates a boolean for if the King is in check, a function for checking if the King is in check, and a checkmate function that checks if the King is in checkmate. (This includes inherited methods and attributes).
  * Pawn
    * Pawn is a subclass of ChessPiece and encapsulates an initialMove attribute that checks if the pawn was moved before or not. Pawn has a separate attack function as it’s move and attack are separate in game. Additionally, Pawn has a unique “transform” function that lets it transform into another piece if it reaches the other side of the board
  * Queen, Rook, Knight, and Bishop only differ in their move function; they have no unique functions outside of ChessPiece
* Game
  * Game is a class that stores a list of PlayerMoves, who’s turn it is, the players, and the state of the game. Additionally, it has a create() function which initializes a game. An addMove() function adds the player’s moves to the list of PlayerMoves and a gameEnd() function ends the game.
* MainMenu
  * MainMenu is a class that allows a user to start, resume, or quit a game. 
* InGame
  * InGame is a class that gives the player the option of saving, undoing, or quitting the game.
* Player
  * Player is a class that represents a player. It stores what color the player is, the wins of the player, the losses of the player, and the draws of the player. Additionally, Player has a makeMove() function that is called when a player makes a move.
* PlayerMoves
  * PlayerMoves stores a Square object for the beginningSquare of where a piece was and an endSquare of where the Piece was moved to. It will also store the ChessPiece that was moved.
* ScanAlg
  * ScanAlg is a class implemented using the Strategy Design Pattern(Strategy class). It is an abstract class that has one pure virtual function Scan().
    * StraightScan
      * StraightScan inherits from ScanAlg and implements the Scan method that represents the Straight Movement Algorithm.
    * DiagonalScan
      * DiagonalScan inherits from ScanAlg and implements the Scan method that represents the Diagonal Movement Algorithm.
## Design Pattern
* The main design pattern we used is the Strategy Design Pattern. For the various moves of a chess piece, we decided it would be better to create Strategy class that includes all the different moves (Straight Moves, Diagonal Moves, etc.). Since many pieces use the same type of moves, such as the Queen using the Straight Move while the Rook also uses the Straight Move, using the strategy design pattern makes it so that the different Move Algorithms are not written multiple times. This will also make it much easier in the future, since adding new algorithms and editing an existing algorithm will only require the change of one method.

 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ![MainMenu](https://user-images.githubusercontent.com/51334912/157161168-30fdc432-3288-40fd-baaa-855b9f05ae82.png)
 ![ChessBoard](https://user-images.githubusercontent.com/51334912/157161263-07365a85-9952-4424-9bef-8a2d54ea6c5e.png)
 ## Installation/Usage
 > Instructions on installing and running your application
 * Windows Users:
   * To run our program you need to download and install QT
   * Clone this repository
   * Open QT, click on open project, and click on the CMakeLists.txt file attached to the project
   * Once CMake has ran the main menu window should be ready to start a game or quit and exit the game.
 > 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
