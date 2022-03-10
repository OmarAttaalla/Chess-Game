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
  * Main menu
  * Functioning GUI to display the board and its pieces
* Want to have:
  * Display possible places to move after Chess piece selected
  * Animations for Chess pieces when moving

## Class Diagram
![UML Diagram (4)](https://user-images.githubusercontent.com/51334912/157558253-2bf08bd2-33ab-42dd-b876-0b2e8dc233f2.png)
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
* MainMenu
  * MainMenu is a class that allows a user to start or quit a game. 
* InGame
  * InGame is a class that stores a list of PlayerMoves, who’s turn it is, the players, and the state of the game. Additionally, it has a board() function which initializes a game. An on_clicked() function which makes the pieces/squares on the board clickable. 
* ScanAlg
  * ScanAlg is a class implemented using the Strategy Design Pattern(Strategy class). It is an abstract class that has one pure virtual function Scan().
    * StraightScan
      * StraightScan inherits from ScanAlg and implements the Scan method that represents the Straight Movement Algorithm.
    * DiagonalScan
      * DiagonalScan inherits from ScanAlg and implements the Scan method that represents the Diagonal Movement Algorithm.
## Design Pattern
* The main design pattern we used is the Strategy Design Pattern. For the various moves of a chess piece, we decided it would be better to create Strategy class that includes all the different moves (Straight Moves, Diagonal Moves, etc.). Since many pieces use the same type of moves, such as the Queen using the Straight Move while the Rook also uses the Straight Move, using the strategy design pattern makes it so that the different Move Algorithms are not written multiple times. This will also make it much easier in the future, since adding new algorithms and editing an existing algorithm will only require the change of one method.

 ## Screenshots
 ![ChessBoard(1)](https://user-images.githubusercontent.com/51334912/157558719-4083bb40-f9ee-4c35-8a88-4f8da4ef8d55.png)
 ![ChessBoard(2)](https://user-images.githubusercontent.com/51334912/157558826-c419740c-41cb-4fee-b9cb-68cef44ced1a.png)
 ![Checkmate](https://user-images.githubusercontent.com/51334912/157611943-9d8f0c27-8de9-4174-b720-cdb258b83b30.png)
 ## Installation/Usage
 * Windows Users:
   * To run our program you need to download and install QT
   * Clone this repository
   * Open QT, click on open project, and click on the CMakeLists.txt file attached to the project
   * Once CMake has ran the main menu window should be ready to start a game or quit and exit the game.
 > 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 * The code is tested and validated using the googletest framework. 
 * We have created unit tests for the logic portion of this project. 
 
