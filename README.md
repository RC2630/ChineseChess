# ChineseChess

This is a program that allows 2 players to fight against each other in Chinese Chess! To get started, type `/help` after you run the program to learn how to move pieces on the board, as well as use special commands. This repository is designed to work only on Windows, as it uses Windows-specific code; to run it on Windows, load the repository into [Visual Studio](https://visualstudio.microsoft.com/). Additionally, the Chinese characters used in the board display may not render for all devices; if the render is incorrect, changing the console's font type may fix the issue. There is also a [platform-independent version](https://github.com/RC2630/ChineseChessEng) of this program that can be run on [Replit](https://replit.com/), which bypasses some of the platform restrictions and also facilitates online multiplayer, but cannot display any Chinese characters at all (the piece names on the board have been reconfigured to display in English).

Current status: COMPLETE (all core gameplay, user interface, special command, and move validity checking logic implemented)

Features:
  - colourful board display in console
  - every move is checked for validity
  - easy to use console user interface
  - special commands for actions such as saving and loading games, skipping a turn, inspecting eaten pieces, etc.
