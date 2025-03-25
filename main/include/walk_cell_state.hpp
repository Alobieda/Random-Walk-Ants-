
#ifndef CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_STATE_HPP_
#define CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_STATE_HPP_

#include <iostream>
#include <nlohmann/json.hpp>

// Random-walk cell state.
struct walkCellState {
	int direction;  //< 0=empty, 1=north, 2=east, 3=south, 4=west
	int randomVal;  //< priority

	walkCellState() : direction(0), randomVal(0) {}
};

std::ostream& operator<<(std::ostream& os, const walkCellState& x) {
	os << "<" << x.direction << "," << x.randomVal << ">";
	return os;
}


bool operator!=(const walkCellState& x, const walkCellState& y) {
	return (x.direction != y.direction) || (x.randomVal != y.randomVal);
}


void from_json(const nlohmann::json& j, walkCellState& s) {
	j.at("direction").get_to(s.direction);
	j.at("randomVal").get_to(s.randomVal);
}

#endif
