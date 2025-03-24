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
cd AntRandomWalk
source build_sim.sh

NOTE: Running build_sim.sh will update the contents of the build/ and bin/ directories.

./bin/walk_ants config/ant_config.json
