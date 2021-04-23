#	Instructions

## Purpose of Tic Tac Toe

​	Tic Tac Toe is a small mini game between 2 players (x and o). The goal is to get the 3 of same **x** or **o**  in a column, a row, or diagonally. Once the goal is reached, the player wins! For more information about Tic Tac Toe, please refer to [this](https://en.wikipedia.org/wiki/Tic-tac-toe).

## How to run the game

​	This game is terminal-based game made by using C++ codes. In order to run the game, you could:

- **Run on Online Compiler website**

  ​	To run it online, please copy all the codes in the **sj_ttt.cpp** file, then head to [JDoodle C++ Compiler IDE](https://www.jdoodle.com/online-compiler-c++/). Then, replace all the workspace code with the **sj_ttt.cpp** codes. Once replaced, turn on the **Interactive** switch and click **Execute**. By then, you can start playing the game in the **Result** section.

- **Run on Local Machine**

  ​	First, you must have [Visual Studio Code](https://code.visualstudio.com/download) and **sj_ttt.cpp** downloaded.  Then, go into Visual Studio Code and install these extensions:

  - C/C++
  - C/C++ Compile Run
  - Code Runner

  Once it is installed, you also need to turn on **Code-runner: Run In Terminal** in  _File > Preference > Search for "Code-runner: Run In Terminal" and check the box._ Then, you can open **sj_ttt.cpp** and click the run button to play.

  > If you wanted to run the .exe file, you must have **Mingw** installed and added to PATH. To see more about **Mingw** please go [here](https://code.visualstudio.com/docs/cpp/config-mingw)!

## Playing SJ Tic Tac Toe

​	Once the game is running, it requires 2 players to input their names. After the names are entered, the first player (x) initiates by entering a number from 1 to 9 to place on the Tic Tac Toe Board. Then, the 2nd player (o) gets to enter. If a player gets the 3 x(s) or 3(o) on the board horizontally, vertically, or diagonally, that player wins the game. Otherwise, if none of the player gets that, the game became draw.

​	When the game ends, players can enter 0 (To quit playing) or 1 (To restart the game from entering names).

## Important

​	This sj_ttt.cpp game is made for educational purpose only! It is not shared commercially. Thank you!