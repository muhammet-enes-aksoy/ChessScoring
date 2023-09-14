# Chess Scoring

## About Project
The score of the current positions of the two sides (black - white) according to the pieces on the chessboard 
calculation.

The algorithm for calculating the current score is as follows:
- Checking whether a piece is threatened occurs when there is one or more pieces of the opposite color threatening that piece.
- The points of the pieces are given. If a piece is not threatened, it receives the score in the table. If a piece is threatened by any of the opponent's pieces, the score of the threatened piece is taken half of its score.
- The threat status of all pieces is checked. Two separate scores are calculated for black and white pieces.

  
## Project Compilation and Execution

### Requirements:

- C++ compiler (e.g., g++, Visual C++, Xcode, etc.)
- CMake (optional)

### Downloading the Project:

Download your project to a directory or navigate to the directory where your project is located.

### Compilation Instructions:

- #### Compiling Using CMake (Recommended):

Open the terminal or command prompt and navigate to the root directory of your project.

Execute the following commands sequentially:

```bash
mkdir build
cd build
cmake ..
make
```
These steps will compile your project and create an executable file.

- #### Compiling Directly Without Using CMake:
Open the terminal or command prompt and navigate to the root directory of your project.

Compile directly with the C++ compiler using the following command:

```bash
g++ -o ChessScoring Main.cpp ThreatStatus.cpp ChessPiece.cpp 
```
This command will compile your project and create an executable file named "myChessGame."

### Running the Project:
Once the compilation process is complete, you can run the project using the following command:

```bash
./ChessScoring
```
![runproject](https://github.com/enessaks/ChessScoring/assets/97848966/feb8195c-eb29-406d-973d-d5e98bac7b99)


When the program runs, it will display a dialog prompting the user to enter the name of a board file (e.g., "board1.txt").

### Output
After running, the program will calculate the total score of the board and print it on the screen.

![output](https://github.com/enessaks/ChessScoring/assets/97848966/eab86ebe-4016-47d8-ae0a-9a24fc4787f0)



