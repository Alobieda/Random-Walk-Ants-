
#ifndef CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_FACTORY_HPP_
#define CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_FACTORY_HPP_

#include <memory>
#include <stdexcept>
#include <cadmium/modeling/celldevs/grid/cell.hpp>
#include "walk_cell.hpp"

// Factory function that creates a walkcell if the JSON cellModel name is "walkCell".
std::shared_ptr<cadmium::celldevs::GridCell<walkCellState, double>> walkcellFactory(
    const cadmium::celldevs::coordinates& cell_id,
    const std::shared_ptr<const cadmium::celldevs::GridCellConfig<walkCellState, double>>& cell_config
) {
    if (cell_config->cellModel == "walkCell") {
        return std::make_shared<walkcell>(cell_id, cell_config);
    }
    throw std::runtime_error("Unknown cell model: " + cell_config->cellModel);
}

#endif // CADMIUM_EXAMPLE_CELLDEVS_WALKCELL_FACTORY_HPP_
