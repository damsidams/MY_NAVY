## MY_NAVY ⚓

**Classic Battleship with a Signal Twist!**

This remake of Battleship challenges you to conquer the seas with strategic thinking and clever communication. ⚔️

**Features:**

* 2-player combat on an 8x8 grid
* Ships of varying sizes (2, 3, 4, and 5 squares)
* Signal-based communication (SIGUSER1 & SIGUSER2) for a unique twist

**Playing the Game:**

1. Compile: `make`
2. **Player 1:** `./my_navy [map_file]`
3. **Player 2:** `./my_navy [PID of Player 1] [map_file]`
   - Find Player 1's PID from their terminal output.

**Ship Placement:**

* Define ship positions in a file using the format:
```txt
LENGTH:FIRST_SQUARE:LAST_SQUARE
```

- Replace `LENGTH` with the ship's size (2-5).
- Replace `FIRST_SQUARE` and `LAST_SQUARE` with coordinates (e.g., A1:A3).

  *Map File Exemple:*
  ```txt
  2:D1:D2
  3:A1:A3
  4:B3:E3
  5:C5:G5
  ```

**Communication & Gameplay:**

* Players take turns attacking via signals.
* Hit markers and miss markers track the battle.
* The first player to sink all opponent's ships wins!

**Epitech Project:**

This project is part of the curriculum for first-year students at [École pour l'informatique et les nouvelles technologies (Epitech)](https://www.epitech.eu/). It serves as an exercise in understanding and implementing fundamental concepts in C programming.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
