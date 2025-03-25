#ifndef CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_HPP_
#define CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_HPP_

#include <cstdlib>
#include <nlohmann/json.hpp>
#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include <cadmium/modeling/celldevs/grid/config.hpp>
#include "walk_cell_state.hpp"

using namespace cadmium::celldevs;

static constexpr int EMPTY = 0;
static constexpr int NORTH = 1;
static constexpr int EAST  = 2;
static constexpr int SOUTH = 3;
static constexpr int WEST  = 4;


class walkcell : public GridCell<walkCellState, double> {
	public:
	walkcell(const std::vector<int>& id, 
			 const std::shared_ptr<const GridCellConfig<walkCellState, double>>& config
			): GridCell<walkCellState, double>(id, config), myCoordinates(id) { }

	[[nodiscard]] walkCellState localComputation(
		walkCellState state,
		const std::unordered_map<std::vector<int>, NeighborData<walkCellState, double>>& neighborhood
	) const override {
		walkCellState nextState = state;

		// If the cell is empty, check if any neighbor wants to move into it.
		if (state.direction == EMPTY) {
			int maxRandom = 0;
			int chosenDir = EMPTY;
			for (const auto& [nbrCoord, nbrData] : neighborhood) {
				const auto& nbrState = nbrData.state;
				if (nbrState->direction != EMPTY && nbrState->randomVal > maxRandom) {
					int rOffset = 0;
					int cOffset = 0;
					switch (nbrState->direction) {
						case NORTH: rOffset = -1; break;
						case EAST:  cOffset =  1; break;
						case SOUTH: rOffset =  1; break;
						case WEST:  cOffset = -1; break;
					}
					if (nbrCoord[0] + rOffset == myCoordinates[0] &&
						nbrCoord[1] + cOffset == myCoordinates[1]) {
						chosenDir = nbrState->direction;
						maxRandom = nbrState->randomVal;
					}
				}
			}
			nextState.direction = chosenDir;
			nextState.randomVal = maxRandom;
		} 
		
		else {
			int rOffset = 0;
			int cOffset = 0;
			switch (state.direction) {
				case NORTH: rOffset = -1; break;
				case EAST:  cOffset =  1; break;
				case SOUTH: rOffset =  1; break;
				case WEST:  cOffset = -1; break;
				default: break;
			}
			int targetRow = myCoordinates[0] + rOffset;
			int targetCol = myCoordinates[1] + cOffset;
			bool canMove = false;

			for (const auto& [coord, data] : neighborhood) {
				if (coord[0] == targetRow && coord[1] == targetCol) {
					if (data.state->direction == EMPTY) {
						canMove = true;
					}
					break;
				}
			}
			if (canMove) {
				nextState.direction = EMPTY;
				nextState.randomVal = 0;
			} else {
				nextState.direction = 1 + std::rand() % 4;  // random direction 
				nextState.randomVal = 1 + std::rand() % 8;  // random value   
			}
		}
        
		return nextState;
	}

	[[nodiscard]] double outputDelay(const walkCellState& state) const override {
		return 1.;
	}

	private:
	std::vector<int> myCoordinates;
};

#endif 












//JSON file 
/*{
  "scenario": {
      "shape": [16, 16],
      "origin": [0, 0],
      "wrapped": true
  },

  "cells": {
      "default": {
          "delay": "transport",
          "model": "WalkCell",
          "state": {
              "direction": 0,
              "randomVal": 0
          },
          "neighborhood": [
              {
                  "type": "relative",
                  "neighbors": [
                      [-2, 0],
                      [-1, -1], [-1, 0], [-1, 1],
                      [0, -2], [0, -1], [0, 0], [0, 1], [0, 2],
                      [1, -1], [1, 0], [1, 1],
                      [2, 0]
                  ]
              }
          ]
      },

      "antsGroup1": {
          "state": {
              "direction": 2,
              "randomVal": 7
          },
          "cell_map": [
              [3, 5],
              [4, 6]
          ]
      },

      "antsGroup2": {
          "state": {
              "direction": 3,
              "randomVal": 5
          },
          "cell_map": [
              [7, 10],
              [2, 6]
          ]
      }
  },

  "viewer": [
  {
    "colors": [
      [0, 0, 0],    
      [255, 0, 0], 
      [0, 255, 0], 
      [0, 0, 255], 
      [255, 255, 0]
    ],
    "breaks": [0, 1, 2, 3, 4, 5],
    "field": "direction"
  }
]

}*/