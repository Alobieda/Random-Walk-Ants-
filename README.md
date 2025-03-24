# Ant Random-Walk Simulation

## Introduction
This project simulates a **random-walk ants** system using the **Cadmium DEVS** modeling framework. It employs a cellular grid where each cell may be occupied by an ant that moves randomly based on local interactions. The simulation demonstrates how simple local rules lead to emergent global behavior.

## Dependencies
This project assumes that Cadmium is installed and accessible via the environment variable `$CADMIUM`.  
_Check by running `echo $CADMIUM` in the terminal._

## Build
To clone this project, run:

git clone https://github.com/YourUsername/AntRandomWalk.git

To build the project, run:
```sh
cd Ant_Random_Walk
source build_sim.sh
```
NOTE: Running build_sim.sh will update the contents of the build/ and bin/ directories.

## Execute
To run the project, run:
```sh
./bin/walk_ants config/ant_config.json
```
## Additional Testing
- **The simulation is tested using various initial ant configurations defined in the JSON file.
- **To experiment with different scenarios, modify the JSON configuration or adjust the input parameters in the provided scripts.

## Features
- **Random Walk Behavior: Ants move randomly across a grid based on local cell interactions.

- **Cellular Interaction: Each cell's state is updated by considering the states of its neighboring cells.

- **Configurable Grid: Grid dimensions and initial ant positions are defined in a JSON file.

- **Test Framework: Includes scripts and log files to facilitate automated testing and result analysis.

  ## Model Descriptions

  ### **Atomic Models**

  ### **walkcell.hpp**

- **Inputs:** Neighbor cell states.

- **Outputs:** Updated cell state.

- **Function:**
   - If the cell is empty, an ant from a neighbor with the highest random value may move in.
   - If the cell is occupied, the ant attempts to move to the target cell; if blocked, it picks a new random direction.
   - 
  ### **walkcell_factory.hpp**

- **Function:**
   - Instantiates a walkcell model based on the JSON configuration.

   - Maps cell models correctly within the simulation grid.
 
  ### **Coupled Models**

  ### **randomWalkGrid.hpp** (Grid System)

  - **Submodels:** Array of walkcell models (e.g., forming a 16×16 grid).

  - **Inputs:** None (all interactions are internal).
  - 
  - **Outputs:** Logs of cell state updates.

  - **Function:**

    - Couples individual cell models to create a complete simulation grid.

    - Supports wrapped boundary conditions for continuous simulation.
   
  ## Authors
Developed by **Belal Alobieda 101170694*.
